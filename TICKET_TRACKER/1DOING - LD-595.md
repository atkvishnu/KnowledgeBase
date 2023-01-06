#### (Panic - flashdb - Niyo)

-   use branch - customer/niyo-release
-   branched out → hotfix/LD-595-panic-flashdb (check @Kumar Vishnu )


```
time="2022-08-16T07:45:40.251652239Z" level=error msg=Recovered File=flash/flashdb/flashdbstats.go Line=647 
time="2022-08-16T07:45:40.251713588Z" level=error msg="reflect: slice index out of range" File=flash/flashdb/flashdbstats.go Line=648 
panic: runtime error: invalid memory address or nil pointer dereference 
[signal SIGSEGV: segmentation violation code=0x1 addr=0x0 pc=0xbd88e4] 

goroutine 10505582 [running]: 
bitbucket.org/logiqcloud/flash/flashdb.(*DBStat).filterDuplicateFacets(0xc000561c00, {0xc03848e000, 0x1f6, 0x80}, {0xc03b260000, 0x95d, 0x20300e}) 
/go/src/bitbucket.org/logiqcloud/flash/flashdb/flashdbstats.go:227 +0xe4 
bitbucket.org/logiqcloud/flash/flashdb.(*DBStat).setFacets(0xc0355da7e8, {0xc06148bbc0, 0xc05e5ad140}, {0xc03848e000, 0x1f6, 0x200}) 
/go/src/bitbucket.org/logiqcloud/flash/flashdb/flashdbstats.go:218 +0x6f 
bitbucket.org/logiqcloud/flash/flashdb.(*FlashDB).InsertData(0xc00009c320, {0x2d0e6e8, 0xc0655c94d0}, {0xc06148bbc0, 0x29}, {0xc03f9f8000, 0x1f4, 0x500}, {0xc03e9d0000, 0x1f4, ...}, ...) 
/go/src/bitbucket.org/logiqcloud/flash/flashdb/flashdb.go:228 +0x1687 
bitbucket.org/logiqcloud/flash/wings.(*QueryService).splitAndInsertToFlashDb(0x0, {0x2d0e6e8, 0xc0655c94a0}, 0xc02e94e000, {0x2894691, 0x8}, {0xc03f9f8000, 0x48a, 0x500}, {0xc03e9d0000, ...}, ...) 
/go/src/bitbucket.org/logiqcloud/flash/wings/processor.go:813 +0x56f 
bitbucket.org/logiqcloud/flash/wings.(*QueryService).sortAndInsertPrevious(0x0, {0x2d0e6e8, 0xc0655c9410}, {0xc03f9f8000, 0xc, 0x500}, {0xc03e9d0000, 0x48a, 0x500}, 0xc02e94e000, ...) 
/go/src/bitbucket.org/logiqcloud/flash/wings/processor.go:772 +0x494 
bitbucket.org/logiqcloud/flash/wings.(*QueryService).insertProcessedData(0x0, {0x2d0e6e8, 0xc0655c93e0}, {0xc03f9f8000, 0x0, 0x500}, 0xc02e94e000, {0x2894691, 0x23db4c0}, {{0xc00054c9a8, ...}, ...}, ...) 
/go/src/bitbucket.org/logiqcloud/flash/wings/processor.go:701 +0x92a 
bitbucket.org/logiqcloud/flash/wings.(*QueryService).processAndInsertData(0x200000003, {0x2d0e6e8, 0xc02b45e5a0}, {0xc03f9f8000, 0x48a, 0x500}, 0xc02e94e000, {{0xc00054c9a8, 0x11}, 0x0, ...}, ...) 
/go/src/bitbucket.org/logiqcloud/flash/wings/processor.go:1226 +0x44d 
bitbucket.org/logiqcloud/flash/wings.(*QueryService).parseIndividualFileContentV2(0x0, {0x2d0e6e8, 0xc044f07d10}, 0xc02e94e000, {{0xc00054c9a8, 0x11}, 0x0, 0x12c, {0xc02ec07efb, 0x83}}, ...) 
/go/src/bitbucket.org/logiqcloud/flash/wings/processor.go:1199 +0x539 
bitbucket.org/logiqcloud/flash/wings.(*QueryService).LoadData.func1(0xc02e94e000, 0x0, {0xc02ec07efb, 0x83}, {0x2894691, 0x8}, 0xc0405e0630, 0xc02e2d35f0) 
/go/src/bitbucket.org/logiqcloud/flash/wings/processor.go:623 +0x6db 
created by bitbucket.org/logiqcloud/flash/wings.(*QueryService).LoadData 
/go/src/bitbucket.org/logiqcloud/flash/wings/processor.go:582 +0x1bba
```


reflect: slice index out of range

-   [](https://go.dev/src/reflect/value.go)[https://go.dev/src/reflect/value.go](https://go.dev/src/reflect/value.go) :1412
-   [](https://go.dev/src/reflect/swapper.go)[https://go.dev/src/reflect/swapper.go](https://go.dev/src/reflect/swapper.go) :25 :29 :70

-   Check `pull request #283` : In this tito made changes for to these 3 files.
    
    In `processor.go`, in indexMapper struct we have removed a element from the struct after pull request #283.


```
func (s *DBStat) setFacets(tableName string, in []*utils.FacetItem) {
	err, info := s.getTable(tableName)
	if err == nil {
		ts := info.Table
		uniq := s.filterDuplicateFacets(in, ts.Facets)   // TODO: here we are passing nil object which is causing the problem
		ts.Facets = uniq
	}
}

func (s *DBStat) filterDuplicateFacets(in []*utils.FacetItem, existing []*utils.FacetItem) []*utils.FacetItem {
	var uniq []*utils.FacetItem
	fMap := make(map[string][]string)
	for _, e := range existing {
		fMap[e.K] = e.V    // TODO: add a check here, or before this line to make sure elements are not nil, if they are nil then log it out and return.
	}
  // TODO: check for edge cases here also, if possible get some ideas about the code.
	for _, inn := range in {
		var uniqVals []string
		if v, ok := fMap[inn.K]; ok {
			uniqVals = append(uniqVals, getUniqueItems(v, inn.V)...)
			sort.Strings(uniqVals)
			if len(uniqVals) > maxNumFacets {
				fMap[inn.K] = uniqVals[:maxNumFacets]
			} else {
				fMap[inn.K] = uniqVals
			}
		} else {
			if len(inn.V) > maxNumFacets {
				sort.Strings(inn.V)
				fMap[inn.K] = inn.V[:maxNumFacets]
			} else {
				fMap[inn.K] = inn.V
			}
		}
	}
	for k, v := range fMap {
		fi := utils.GetFacetItem()
		fi.K = k
		fi.V = v
		uniq = append(uniq, fi)
	}
	return uniq
}
```






























