
Dashboard -> LOGIQ Monitoring
`https://centralize-logger.fnpass.com/dashboard/logiq-monitoring`


### Mover graph -> 
query: `sum by (pod, operation) logiq_mover_counter{operation=~"inc|mdone"}`

1. data coming into queue
2. processed and written to disk
3. indexed
4. written to file
5. done
6. 

inc ->  
mdone -> all processing done


----


### Batch size -> 
how big the batch size 
if there is too many logs being generated on the system then collecters will try to send the logs in big batches.
We have a switch for this, we can break the batch sizes into parts and then push those broken batches to different pods. 



---

Backpressurecounter
 if it is 0, then it is good.
 If it increases then the logs are sitting in the queue, waiting to be ingested. logiq - pod - 61



---

## `Ingestdb files` graph

---

3 main folders

/tmp/flash/node`/db/keycache/
/tmp/flash/node`/db/metadata/
/tmp/flash/node`/db/hash/?

---

Bloom Filter
- If key is in local, use it, otherwise look into object storage,

---

We have 6 databases at any given point of time, we rotate it hourly.
19%6 = 1 , so we are using DB number 1.
After an hour we switch to DB 2, data in DB 1 is pushed to object storage after an hour.

---


LOCAL TEST ENV:

-   On [`localhost:9090](<http://localhost:9090>)/graph` we can see the prometheus graph.

## In GoLand:

Steps to connect to postgres DB:

-   Name: `flash`
-   Host: `localhost`
-   User: `postgres`
-   Password: `postgres`
-   Database: `flash`
-   URL: `jdbc:postgresql://localhost:5432/flash`

```go
{
  "MsgId": "1oNLSw2GIvOqchXoUnCh3GYL0o8",
  "PartitionId": 1,
  "Timestamp": "2021-02-12T09:28:24Z",
  "Hostname": "logiq-test-framework",
  "Priority": 29,
  "Facility": 3,
  "FacilityString": "system daemon",
  "Severity": 5,
  "SeverityString": "notice",
  "AppName": "finite-test-engine",
  "ProcId": "20876",
  "Message": "flash test message 2021-02-12T14:58:24+05:30 #:9:# time=0.209802s Facet1.time.seconds=v24 Facet2=v58 Facet4=v-34 FacetU.label.uuid=3b0a7bd7-327b-42a8-aafa-66511bcdc590 count=56 confluence: abc POST ewojdqpowe/upload.action xyz and filename=../../../../../ ",
  "StructuredData": "{\\"count\\":[\\"56\\"],\\"facet1.time.seconds\\":[\\"v24\\"],\\"facet2\\":[\\"v58\\"],\\"facet4\\":[\\"v-34\\"],\\"facetu.label.uuid\\":[\\"3b0a7bd7-327b-42a8-aafa-66511bcdc590\\"],\\"filename\\":[\\"../../../../../\\"]}",
  "Tag": "",
  "Sender": "127.0.0.1",
  "Groupings": "[{\\"Name\\":\\"Environment\\",\\"Value\\":\\"Production\\"},{\\"Name\\":\\"Tier\\",\\"Value\\":\\"Web\\"}]",
  "Event": "",
  "EventId": "",
  "NanoTimeStamp": "1613122104913318491",
  "Namespace": "logiq-test-framework"
}
```

---

```
	type Table struct { 
	Name string `json:"name"`
	Files []*File `json:"files"`
	CurrentDataOffset int64 `json:"dataOffset"`
	Size int `json:"size"` //Current Size 
	UniqFieldName string `json:"ufn"` 
	LastUsed time.Time `json:"lu"` 
	Consumers map[string]*Consumer `json:"con"` 
	Facets []*utils.FacetItem `json:"fts"` 
	CurrentMetadataOffset int64 `json:"metadataOffset"` 
	TotalMetadataSize int64 `json:"totalMetadata"` 
	LastFetchTime int64 `json:"lft"` 
	Progress int `json:"pgs"` //Available
	IDs []string `json:"-"` //TODO this breaks the messsage look up by id //TODO OffsetManagementType [FLash_Managed Or Client_Managed]- in this version offset is managed internally 
	//We would want the client to manage offset as well, in such cases client need to do an explicit commit. 
}
```


