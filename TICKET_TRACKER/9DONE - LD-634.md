### Add prometheus counter to track inmemory distributed cache stats

# LD-634 (Add prometheus counter to track inmemory distributed cache stats)

Created by: Kumar Vishnu
Created time: October 6, 2022 12:34 AM
Last edited by: Kumar Vishnu
Last edited time: November 7, 2022 4:13 PM

<aside>
💡 `func (g *InMemoryCacheGroup) PeriodicCacheStats() {`
in inmemorydistributed cache print periodic stats in logs.

Create prometheus metrics so we can visualize this in the UI
Two types of metrics are reported

`1"types":     "HotCache",
2"Items":     hotStats.Items,
3"Bytes":     hotStats.Bytes,
4"Gets":      hotStats.Gets,
5"Hits":      hotStats.Hits,
6"Evict":     hotStats.Evictions,`

HotCacheItemsCount = prometheus.NewGaugeVec(

prometheus.GaugeOpts{

Name: “”

Help: “”

},

[]string{

HotCacheBytesCount

HotCacheGetsCounter

HotCacheHitsCounter

HotCacheEvictionsCounter

MainCacheItemsCount

MainCacheBytesCount

MainCacheGetsCounter

MainCacheHitsCounter

MainCacheEvictionsCounter
 
and

`1"types":     "MainCache",
2"Items":     mainStats.Items,
3"Bytes":     mainStats.Bytes,
4"Gets":      mainStats.Gets,
5"Hits":      mainStats.Hits,
6"Evict":     mainStats.Evictions,`

We should create a prometheus counter/counters to track both above

</aside>

- *~~Logging is happening, make that as an generic object which can be used for both NewCounter and logging using logrus.~~*

- prometheus counter uses NewCounter() for counting, it can be used just for the values which increase.
- For decreasing values, use Guage()
- NewCounterVec() creates a bit vector, this is more efficient maybe.
- Do `grep "NewCounter"`
- We also have to register the counters.

NewGaugeVec → `Items`, `Bytes`

NewCounterVec → `Gets`, `Hits`, `Evictions`    

HotStats

`prommetrics.LocalCachesCollector.WithLabelValues(ic.Which).Dec()`

`prommetrics.LocalCachesCollector.WithLabelValues(ic.Which).Dec()`      

`prommetrics.LocalCachesCollector.WithLabelValues(svc.Which).Dec()`    svc → method

`prommetrics.MetadataCacheHitCountCollector.WithLabelValues("nocache").Inc()`

`prommetrics.IOPSCountersCollector.WithLabelValues("write").Inc()`

`prommetrics.BackgroundCountersCollector.WithLabelValues("mcache-ttl-gc-r").Inc()`

`prommetrics.BackgroundCountersCollector.WithLabelValues("mcache-old-gc-r").Inc()`

`prommetrics.BackgroundCountersCollector.WithLabelValues("mcache-gc-r").Inc()`

```go
func (g *InMemoryCacheGroup) PeriodicCacheStats() {
	tickerStats := time.NewTicker(time.Second * 60)
	for {
		select {
		case <-tickerStats.C:
			mainStats := g.Group.CacheStats(groupcache.MainCache)
			logEntry.ContextLogger().WithFields(logrus.Fields{
				"cacheName": g.Group.Name(),
				"types":     "MainCache",
				"Items":     mainStats.Items,
				"Bytes":     mainStats.Bytes,
				"Gets":      mainStats.Gets,
				"Hits":      mainStats.Hits,
				"Evict":     mainStats.Evictions,
			}).Info("Stats")
			hotStats := g.Group.CacheStats(groupcache.HotCache)
			logEntry.ContextLogger().WithFields(logrus.Fields{
				"cacheName": g.Group.Name(),
				"types":     "HotCache",
				"Items":     hotStats.Items,
				"Bytes":     hotStats.Bytes,
				"Gets":      hotStats.Gets,
				"Hits":      hotStats.Hits,
				"Evict":     hotStats.Evictions,
			}).Info("Stats")
		}
	}
}
```

```go
func GetMetadataCachePoolHandler() *inmemdistributedcache.InMemoryCachePool {
	metaCacheOnce.Do(func() {
		metaCachePool = inmemdistributedcache.NewInMemoryCache(hostinfo.GetMyHostName(), hostinfo.GetApiPort())
		metaCacheGroup = metaCachePool.CreateNewInMemDistributedCache(
			"metadata", *metaCacheSizeBytes, MetacacheGetterFunc)
		go metaCachePool.PeriodicallyUpdateInMemoryCachePool()
		go metaCacheGroup.PeriodicCacheStats()
	})
	return metaCachePool
}
```

```go
func (p *InMemoryCachePool) PeriodicallyUpdateInMemoryCachePool() {
	logEntry.ContextLogger().Info("Periodically updating In Memory Cache pool")
	ticker := time.NewTicker(time.Second * 15)
	for {
		select {

		case <-ticker.C:
			// Get list of nodes including ourselves
			var peerlist = []string{}
			var nodes = map[string]string{}
			var nodetype string
			if utils.IsCombinedNode() || utils.IsIngestNode() {
				nodes = hostinfo.GetIngestNodesAsMap()
				nodetype = "ingest|combined"
			} else if utils.IsSideCarNode() {
				nodes = hostinfo.GetIngestSidecarNodesAsMap()
				nodetype = "sidecar"
			} else if utils.IsApiNode() {
				nodes = hostinfo.GetApiNodesWithApiPortAsMap()
				nodetype = "api"
			}

			for node, _ := range nodes {
				peerlist = append(peerlist,
					fmt.Sprintf("http://%s:%s", node, hostinfo.GetApiPort()))
			}
			logEntry.ContextLogger().WithFields(logrus.Fields{
				"nodes": peerlist,
				"type":  nodetype,
			}).Info("Refreshed nodes for In Memory Cache pool")
			p.Pool.Set(
				peerlist...)
		}
	}
}
```

```go
// CacheType represents a type of cache.
type CacheType int

const (
	// The MainCache is the cache for items that this peer is the
	// owner for.
	MainCache CacheType = iota + 1

	// The HotCache is the cache for items that seem popular
	// enough to replicate to this node, even though it's not the
	// owner.
	HotCache
)

// CacheStats returns stats about the provided cache within the group.
func (g *Group) CacheStats(which CacheType) CacheStats {
	switch which {
	case MainCache:
		return g.mainCache.stats()
	case HotCache:
		return g.hotCache.stats()
	default:
		return CacheStats{}
	}
}

// cache is a wrapper around an *lru.Cache that adds synchronization,
// makes values always be ByteView, and counts the size of all keys and
// values.
type cache struct {
	mu         sync.RWMutex
	nbytes     int64 // of all keys and values
	lru        *lru.Cache
	nhit, nget int64
	nevict     int64 // number of evictions
}

func (c *cache) stats() CacheStats {
	c.mu.RLock()
	defer c.mu.RUnlock()
	return CacheStats{
		Bytes:     c.nbytes,
		Items:     c.itemsLocked(),
		Gets:      c.nget,
		Hits:      c.nhit,
		Evictions: c.nevict,
	}
}
```