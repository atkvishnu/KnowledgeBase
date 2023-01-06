```
~/go/src/bitbucket.org/logiqcloud/flash-test-framework random-time ≡
❯ ./flash-test-framework                                                                           
Usage of ./flash-test-framework:
  -ApplicationName string
    	--ApplicationName (default "finite-test-engine")
  -ProcessId string
    	--ProcessId (default "338205")
  -apachelog
    	Send apache log sample
  -dck
    	--dck
  -events
    	-events; Ingest data with events
  -file string
    	file
  -finite
    	--finite, Send finite number of messages and validates its order and check for targeted line, has events as well
  -fluent
    	--fluent
  -fp int
    	Fluent forwarder Port (default 24224)
  -gp string
    	GrpcPort (default "50054")
  -host string
    	Host (default "127.0.0.1")
  -idur int
    	duration to run in seconds (default 5)
  -ingest
    	-ingest; just ingest data. Control this using -idur and -mps
  -it string
    	-it 7Sv5PovfXGvh0EcaXGo9D1T2OIsN-wIEyQ5YOzQoMSFHRdo_39et4LJWJ2fs8vGdZ4cuOev9d2gbB7y_LCwr0sw3BSGhuWJiJwk0UzdwNQRef5qvdww (default "7Sv5PovfXGvh0EcaXGo9D1T2OIsN-wIEyQ5YOzQoMSFHRdo_39et4LJWJ2fs8vGdZ4cuOev9d2gbB7y_LCwr0sw3BSGhuWJiJwk0UzdwNQRef5qvdww")
  -jsonb
    	--jsonb
  -lhp int
    	logstash json Port (default 9999)
  -long -count
    	-long; sends -count long messages 
  -mps int
    	logs per second (default 300)
  -n int
    	duration to run in seconds (default 1)
  -namespace string
    	--namespace (default "logiq-test-framework")
  -one
    	-one; sends just one message
  -pc
    	-pc; Plot Chart with ingest performance
  -random
    	-random; Invokes query API randomly and validate its response for duplicates
  -relp
    	--relp
  -rns
    	-rns; sends messages with random namespace
  -rp string
    	Relp Port (default "20514")
  -sp string
    	Syslog Port (default "3514")
  -ts string
    	Timestamp format to send (syslog only) (default "2006/01/02 15:04:05.999999-07:00")
  -tsgrok
    	Enable tsgrok test data for timestamp format provided in -ts (syslog only)
  -verifyFile
    	VerifyFile validates the response data for duplicates and invalid json line use --file to specify file
```