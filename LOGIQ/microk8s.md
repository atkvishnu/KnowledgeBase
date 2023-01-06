
```
microk8s kubectl delete namespace logiq
microk8s kubectl create namespace logiq
```

```
helm install logiq -n logiq --set global.persistence.storageClass=microk8s-hostpath logiq-repo/logiq -f  ~/.kube/values.microk8s.yaml --debug --timeout 20m
```

```
helm upgrade logiq -n logiq --set global.persistence.storageClass=microk8s-hostpath logiq-repo/logiq -f  ~/.kube/values.microk8s.yaml --debug --timeout 20m
```


```
microk8s kubectl get pods -n logiq
```

```
 microk8s kubectl get service -n logiq  
```


```ad-info
title: ID-PASSWORD

Your LOGIQ PaaS UI is now available in your web browser. You can log into LOGIQ PaaS using the following default credentials.

-   **Username**: `flash-admin@foo.com`
-   **Password**: `flash-password`
```


```ad-important
title: get all services
> microk8s kubectl get services -n logiq
```


```
❯ microk8s kubectl get service -n logiq
NAME                                       TYPE           CLUSTER-IP       EXTERNAL-IP    PORT(S)                                                                                                                                                                                                                                              AGE
coffee                                     NodePort       10.152.183.166   <none>         80:30869/TCP                                                                                                                                                                                                                                         33m
flash-discovery                            ClusterIP      10.152.183.7     <none>         8081/TCP,4000/TCP                                                                                                                                                                                                                                    33m
logiq-kubernetes-ingress-default-backend   ClusterIP      10.152.183.221   <none>         80/TCP                                                                                                                                                                                                                                               33m
logiq-kubernetes-ingress                   LoadBalancer   10.152.183.33    10.64.140.43   80:32433/TCP,14250:31379/TCP,20514:31476/TCP,7514:32724/TCP,7515:31276/TCP,8081:31263/TCP,9998:32669/TCP                                                                                                                                             33m
logiq-flash-ml                             ClusterIP      None             <none>         16686/TCP,8081/TCP,9998/TCP,9999/TCP,8080/TCP                                                                                                                                                                                                        33m
logiq-flash-sync                           ClusterIP      None             <none>         8081/TCP,9998/TCP,9999/TCP,8080/TCP                                                                                                                                                                                                                  33m
logiq-flash-headless                       ClusterIP      None             <none>         14250/TCP,8081/TCP,9999/TCP,9998/TCP,514/TCP,7514/TCP,515/TCP,7515/TCP,20514/TCP,2514/TCP,24225/TCP,24224/TCP,25224/TCP,25225/TCP,8080/TCP,517/TCP                                                                                                   33m
logiq-flash                                NodePort       10.152.183.62    <none>         14250:32716/TCP,8081:32431/TCP,9998:30123/TCP,9999:32740/TCP,514:30502/TCP,7514:32207/TCP,515:32015/TCP,7515:30938/TCP,2514:32211/TCP,20514:31804/TCP,24225:30670/TCP,24224:30782/TCP,8080:32611/TCP,25224:30446/TCP,25225:30359/TCP,517:30281/TCP   33m
postgres-metrics                           ClusterIP      10.152.183.192   <none>         9187/TCP                                                                                                                                                                                                                                             33m
postgres-headless                          ClusterIP      None             <none>         5432/TCP                                                                                                                                                                                                                                             33m
postgres                                   ClusterIP      10.152.183.127   <none>         5432/TCP                                                                                                                                                                                                                                             33m
logiq-kube-state-metrics                   ClusterIP      10.152.183.12    <none>         8080/TCP                                                                                                                                                                                                                                             33m
logiq-node-exporter                        ClusterIP      10.152.183.143   <none>         9100/TCP                                                                                                                                                                                                                                             33m
logiq-prometheus-alertmanager              ClusterIP      10.152.183.105   <none>         9093/TCP                                                                                                                                                                                                                                             33m
logiq-prometheus-operator                  ClusterIP      10.152.183.74    <none>         8080/TCP                                                                                                                                                                                                                                             33m
logiq-prometheus-prometheus                ClusterIP      10.152.183.128   <none>         9090/TCP                                                                                                                                                                                                                                             33m
logiq-prometheus-prometheus-thanos         ClusterIP      None             <none>         10901/TCP                                                                                                                                                                                                                                            33m
redis-headless                             ClusterIP      None             <none>         6379/TCP                                                                                                                                                                                                                                             33m
redis-metrics                              ClusterIP      10.152.183.135   <none>         9121/TCP                                                                                                                                                                                                                                             33m
redis-master                               ClusterIP      10.152.183.185   <none>         6379/TCP                                                                                                                                                                                                                                             33m
s3-gateway                                 ClusterIP      10.152.183.63    <none>         9000/TCP                                                                                                                                                                                                                                             33m
s3-gateway-svc                             ClusterIP      None             <none>         9000/TCP                                                                                                                                                                                                                                             33m
logiq-thanos-bucketweb                     ClusterIP      10.152.183.222   <none>         8080/TCP                                                                                                                                                                                                                                             33m
logiq-thanos-compactor                     ClusterIP      10.152.183.178   <none>         9090/TCP                                                                                                                                                                                                                                             33m
logiq-thanos-query                         ClusterIP      10.152.183.129   <none>         9090/TCP,10901/TCP                                                                                                                                                                                                                                   33m
logiq-thanos-receive                       ClusterIP      10.152.183.30    <none>         10902/TCP,10901/TCP,19291/TCP                                                                                                                                                                                                                        33m
logiq-thanos-ruler                         ClusterIP      10.152.183.25    <none>         9090/TCP,10901/TCP                                                                                                                                                                                                                                   33m
logiq-thanos-storegateway                  ClusterIP      10.152.183.109   <none>         9090/TCP,10901/TCP                                                                                                                                                                                                                                   33m
alertmanager-operated                      ClusterIP      None             <none>         9093/TCP,9094/TCP,9094/UDP                                                                                                                                                                                                                           33m
prometheus-operated                        ClusterIP      None             <none>         9090/TCP                                                                                                                                                                                                                                             33m

```