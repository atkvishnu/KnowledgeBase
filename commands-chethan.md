
```
 9586  ./flash-test-framework -mps 1000 -idur 100 -ingest --jsonb --namespace ns9 --host http://10.64.140.43:9999
 9587  ./flash-test-framework -mps 1000 -idur 100 -ingest --jsonb --namespace ns9 --host http://10.64.140.43:9998
 9588  microk8s kubectl get service -n logiq
 9589  ./flash-test-framework -mps 1000 -idur 100 -ingest --jsonb --namespace ns9 --host http://10.64.140.43:20514
 9590  ./flash-test-framework -mps 1000 -idur 100 -ingest --jsonb --namespace ns9 --host http://10.64.140.43:8081
 9591  ./flash-test-framework -mps 1000 -idur 100 -ingest --jsonb --namespace ns9 --host http://10.64.140.43:20514
 9592  source .zshrckl
 9593  kl
 9594  alias kl="microk8s kubectl -n logiq"
 9595  ./flash-test-framework -mps 1000 -idur 100 -ingest --jsonb --namespace ns9 --host http://10.64.140.43 -sp 443
 9596  ./flash-test-framework -mps 10 -idur 100 -ingest --jsonb --namespace ns9 --host http://10.64.140.43 -sp 443
 9597  kl edit sts logiq-flash -nlogiq
 9598  kl get pod -w
 9599  ./flash-test-framework -mps 10 -idur 100 -ingest --jsonb --namespace ns9 --host http://10.64.140.43 -sp 443
 9600  td-agent
 9601  td-agent-bit
 9602  snap info fluent-bit
 9603  sudo snap install fluent-bit --classic
 9604  ./flash-test-framework -mps 10 -idur 100 -ingest --namespace ns99 --host http://10.64.140.43 -sp 514
 9605  ./flash-test-framework -mps 10 -idur 100 -ingest --namespace ns99 --host http://10.64.140.43 -sp 1514
 9606  ./flash-test-framework -mps 10 -idur 100 -ingest --namespace ns99 --host http://10.64.140.43 -sp 3514
 9607  git switch master
 9608  go build .
 9609  ./flash-test-framework -mps 10 -idur 100 -ingest --namespace ns99 --host 10.64.140.43 -sp 3514
 9610  ./flash-test-framework -mps 10 -idur 100 -ingest --namespace ns99 --host 10.64.140.43 -sp 514
 9611  ./flash-test-framework -mps 10 -idur 100 -ingest --namespace ns99 --host 10.64.140.43 -sp 1514
 9612  ./flash-test-framework -mps 10 -idur 100 -ingest --namespace ns99 --host 10.64.140.43 -sp 7514
 9613  ./flash-test-framework -mps 10 -idur 100 -ingest --namespace ns99 --host lq5955.logiq.ai -sp 514
 9614  sudo apt install mlocate
 9615  locate td-agent-bit
 9616  locate td-bit
 9617  locate fluent-bit
 9618  locate fluent-bit | grep etc
 9619  locate fluent-bit | grep conf
 9620  cd /snap/fluent-bit/17/10.64.140.43
 9621  cd /snap/fluent-bit/17//etc/fluent-bit/fluent-bit.conf
 9622  cd /snap/fluent-bit/17/etc/fluent-bit/fluent-bit.conf
 9623  cd /snap/fluent-bit/17/etc/fluent-bit/

```


FLASH TEST FRAMEWORK
```
./flash-test-framework -mps 10 -idur 100 -ingest --namespace ns99 --host lq5955.logiq.ai -sp 514
```