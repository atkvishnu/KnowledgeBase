###  (Improve Tracing Search performance)
```
const initialDelay = 50
.
.
.
.
var varTimeGatherNumTraces int = initialDelay
..
..
..
..
if drResp.Remaining <= 0 {
					time.Sleep(time.Second)
					time.Sleep(time.Duration(varTimeGatherNumTraces) * time.Millisecond)
					updateQueryInterval(&varTimeGatherNumTraces)
}
..
..
..
..
var varTimeSendSpanForTrace int = initialDelay
..
..
..
if drTraceIdExprResp.Remaining <= 0 {
				time.Sleep(time.Second)
				time.Sleep(time.Duration(varTimeSendSpanForTrace) * time.Millisecond)
				updateQueryInterval(&varTimeSendSpanForTrace)
}
..
..
..
..
func updateQueryInterval(dynamicQueryInterval *int) {
	if *dynamicQueryInterval < 500 {
		*dynamicQueryInterval += 50
	}
}
```