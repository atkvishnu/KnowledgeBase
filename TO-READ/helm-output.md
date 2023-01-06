~/.kube
❯ helm install logiq -n logiq --set global.persistence.storageClass=microk8s-hostpath logiq-repo/logiq -f  ~/.kube/values.microk8s.yaml --debug --timeout 20m
WARNING: Kubernetes configuration file is group-readable. This is insecure. Location: /home/tito/.kube/config
WARNING: Kubernetes configuration file is world-readable. This is insecure. Location: /home/tito/.kube/config
install.go:178: [debug] Original chart version: ""
install.go:199: [debug] CHART PATH: /home/tito/.cache/helm/repository/logiq-v3.0.5.tgz

client.go:128: [debug] creating 1 resource(s)
install.go:151: [debug] CRD alertmanagerconfigs.monitoring.coreos.com is already present. Skipping.
client.go:128: [debug] creating 1 resource(s)
install.go:151: [debug] CRD alertmanagers.monitoring.coreos.com is already present. Skipping.
client.go:128: [debug] creating 1 resource(s)
install.go:151: [debug] CRD podmonitors.monitoring.coreos.com is already present. Skipping.
client.go:128: [debug] creating 1 resource(s)
install.go:151: [debug] CRD probes.monitoring.coreos.com is already present. Skipping.
client.go:128: [debug] creating 1 resource(s)
install.go:151: [debug] CRD prometheuses.monitoring.coreos.com is already present. Skipping.
client.go:128: [debug] creating 1 resource(s)
install.go:151: [debug] CRD prometheusrules.monitoring.coreos.com is already present. Skipping.
client.go:128: [debug] creating 1 resource(s)
install.go:151: [debug] CRD servicemonitors.monitoring.coreos.com is already present. Skipping.
client.go:128: [debug] creating 1 resource(s)
install.go:151: [debug] CRD thanosrulers.monitoring.coreos.com is already present. Skipping.
W1107 14:06:28.159472  520126 warnings.go:70] policy/v1beta1 PodSecurityPolicy is deprecated in v1.21+, unavailable in v1.25+
W1107 14:06:28.161414  520126 warnings.go:70] policy/v1beta1 PodSecurityPolicy is deprecated in v1.21+, unavailable in v1.25+
W1107 14:06:28.163091  520126 warnings.go:70] policy/v1beta1 PodSecurityPolicy is deprecated in v1.21+, unavailable in v1.25+
W1107 14:06:28.164792  520126 warnings.go:70] policy/v1beta1 PodSecurityPolicy is deprecated in v1.21+, unavailable in v1.25+
W1107 14:06:28.166480  520126 warnings.go:70] policy/v1beta1 PodSecurityPolicy is deprecated in v1.21+, unavailable in v1.25+
W1107 14:06:28.168154  520126 warnings.go:70] policy/v1beta1 PodSecurityPolicy is deprecated in v1.21+, unavailable in v1.25+
W1107 14:06:28.169822  520126 warnings.go:70] policy/v1beta1 PodSecurityPolicy is deprecated in v1.21+, unavailable in v1.25+
W1107 14:06:28.171436  520126 warnings.go:70] policy/v1beta1 PodSecurityPolicy is deprecated in v1.21+, unavailable in v1.25+
W1107 14:06:28.173052  520126 warnings.go:70] policy/v1beta1 PodSecurityPolicy is deprecated in v1.21+, unavailable in v1.25+
W1107 14:06:28.174821  520126 warnings.go:70] policy/v1beta1 PodSecurityPolicy is deprecated in v1.21+, unavailable in v1.25+
W1107 14:06:28.176512  520126 warnings.go:70] policy/v1beta1 PodSecurityPolicy is deprecated in v1.21+, unavailable in v1.25+
W1107 14:06:28.178359  520126 warnings.go:70] policy/v1beta1 PodSecurityPolicy is deprecated in v1.21+, unavailable in v1.25+
W1107 14:06:28.180111  520126 warnings.go:70] policy/v1beta1 PodSecurityPolicy is deprecated in v1.21+, unavailable in v1.25+
W1107 14:06:28.181824  520126 warnings.go:70] policy/v1beta1 PodSecurityPolicy is deprecated in v1.21+, unavailable in v1.25+
W1107 14:06:28.183663  520126 warnings.go:70] policy/v1beta1 PodSecurityPolicy is deprecated in v1.21+, unavailable in v1.25+
client.go:299: [debug] Starting delete for "flash-discovery-license" Secret
client.go:328: [debug] secrets "flash-discovery-license" not found
client.go:128: [debug] creating 1 resource(s)
client.go:299: [debug] Starting delete for "logiq-kubernetes-ingress-default-cert" Secret
client.go:328: [debug] secrets "logiq-kubernetes-ingress-default-cert" not found
client.go:128: [debug] creating 1 resource(s)
client.go:299: [debug] Starting delete for "logiq-shared-secret" Secret
client.go:328: [debug] secrets "logiq-shared-secret" not found
client.go:128: [debug] creating 1 resource(s)
client.go:299: [debug] Starting delete for "logiq-shared-secret" Secret
client.go:128: [debug] creating 1 resource(s)
client.go:299: [debug] Starting delete for "thanos-objectstorage-config" Secret
client.go:328: [debug] secrets "thanos-objectstorage-config" not found
client.go:128: [debug] creating 1 resource(s)
client.go:218: [debug] checking 167 resources for changes
W1107 14:06:28.798111  520126 warnings.go:70] policy/v1beta1 PodSecurityPolicy is deprecated in v1.21+, unavailable in v1.25+
W1107 14:06:28.800061  520126 warnings.go:70] policy/v1beta1 PodSecurityPolicy is deprecated in v1.21+, unavailable in v1.25+
W1107 14:06:28.806858  520126 warnings.go:70] policy/v1beta1 PodSecurityPolicy is deprecated in v1.21+, unavailable in v1.25+
W1107 14:06:28.808779  520126 warnings.go:70] policy/v1beta1 PodSecurityPolicy is deprecated in v1.21+, unavailable in v1.25+
W1107 14:06:28.810595  520126 warnings.go:70] policy/v1beta1 PodSecurityPolicy is deprecated in v1.21+, unavailable in v1.25+
W1107 14:06:28.813325  520126 warnings.go:70] policy/v1beta1 PodSecurityPolicy is deprecated in v1.21+, unavailable in v1.25+
W1107 14:06:28.815304  520126 warnings.go:70] policy/v1beta1 PodSecurityPolicy is deprecated in v1.21+, unavailable in v1.25+
W1107 14:06:28.817157  520126 warnings.go:70] policy/v1beta1 PodSecurityPolicy is deprecated in v1.21+, unavailable in v1.25+
W1107 14:06:28.820140  520126 warnings.go:70] policy/v1beta1 PodSecurityPolicy is deprecated in v1.21+, unavailable in v1.25+
W1107 14:06:28.821983  520126 warnings.go:70] policy/v1beta1 PodSecurityPolicy is deprecated in v1.21+, unavailable in v1.25+
W1107 14:06:28.823924  520126 warnings.go:70] policy/v1beta1 PodSecurityPolicy is deprecated in v1.21+, unavailable in v1.25+
client.go:501: [debug] Looks like there are no changes for PodSecurityPolicy "logiq-kubernetes-ingress-backend"
W1107 14:06:28.825985  520126 warnings.go:70] policy/v1beta1 PodSecurityPolicy is deprecated in v1.21+, unavailable in v1.25+
W1107 14:06:28.827640  520126 warnings.go:70] policy/v1beta1 PodSecurityPolicy is deprecated in v1.21+, unavailable in v1.25+
W1107 14:06:28.829406  520126 warnings.go:70] policy/v1beta1 PodSecurityPolicy is deprecated in v1.21+, unavailable in v1.25+
W1107 14:06:28.831973  520126 warnings.go:70] policy/v1beta1 PodSecurityPolicy is deprecated in v1.21+, unavailable in v1.25+
W1107 14:06:28.833702  520126 warnings.go:70] policy/v1beta1 PodSecurityPolicy is deprecated in v1.21+, unavailable in v1.25+
W1107 14:06:28.835490  520126 warnings.go:70] policy/v1beta1 PodSecurityPolicy is deprecated in v1.21+, unavailable in v1.25+
W1107 14:06:28.838020  520126 warnings.go:70] policy/v1beta1 PodSecurityPolicy is deprecated in v1.21+, unavailable in v1.25+
W1107 14:06:28.839752  520126 warnings.go:70] policy/v1beta1 PodSecurityPolicy is deprecated in v1.21+, unavailable in v1.25+
W1107 14:06:28.841533  520126 warnings.go:70] policy/v1beta1 PodSecurityPolicy is deprecated in v1.21+, unavailable in v1.25+
W1107 14:06:28.844082  520126 warnings.go:70] policy/v1beta1 PodSecurityPolicy is deprecated in v1.21+, unavailable in v1.25+
W1107 14:06:28.845861  520126 warnings.go:70] policy/v1beta1 PodSecurityPolicy is deprecated in v1.21+, unavailable in v1.25+
W1107 14:06:28.848171  520126 warnings.go:70] policy/v1beta1 PodSecurityPolicy is deprecated in v1.21+, unavailable in v1.25+
W1107 14:06:28.850842  520126 warnings.go:70] policy/v1beta1 PodSecurityPolicy is deprecated in v1.21+, unavailable in v1.25+
W1107 14:06:28.852705  520126 warnings.go:70] policy/v1beta1 PodSecurityPolicy is deprecated in v1.21+, unavailable in v1.25+
W1107 14:06:28.854623  520126 warnings.go:70] policy/v1beta1 PodSecurityPolicy is deprecated in v1.21+, unavailable in v1.25+
W1107 14:06:28.857508  520126 warnings.go:70] policy/v1beta1 PodSecurityPolicy is deprecated in v1.21+, unavailable in v1.25+
W1107 14:06:28.859327  520126 warnings.go:70] policy/v1beta1 PodSecurityPolicy is deprecated in v1.21+, unavailable in v1.25+
W1107 14:06:28.861070  520126 warnings.go:70] policy/v1beta1 PodSecurityPolicy is deprecated in v1.21+, unavailable in v1.25+
W1107 14:06:28.863644  520126 warnings.go:70] policy/v1beta1 PodSecurityPolicy is deprecated in v1.21+, unavailable in v1.25+
W1107 14:06:28.865417  520126 warnings.go:70] policy/v1beta1 PodSecurityPolicy is deprecated in v1.21+, unavailable in v1.25+
W1107 14:06:28.867197  520126 warnings.go:70] policy/v1beta1 PodSecurityPolicy is deprecated in v1.21+, unavailable in v1.25+
W1107 14:06:28.869787  520126 warnings.go:70] policy/v1beta1 PodSecurityPolicy is deprecated in v1.21+, unavailable in v1.25+
W1107 14:06:28.871582  520126 warnings.go:70] policy/v1beta1 PodSecurityPolicy is deprecated in v1.21+, unavailable in v1.25+
W1107 14:06:28.873469  520126 warnings.go:70] policy/v1beta1 PodSecurityPolicy is deprecated in v1.21+, unavailable in v1.25+
W1107 14:06:28.876049  520126 warnings.go:70] policy/v1beta1 PodSecurityPolicy is deprecated in v1.21+, unavailable in v1.25+
W1107 14:06:28.877724  520126 warnings.go:70] policy/v1beta1 PodSecurityPolicy is deprecated in v1.21+, unavailable in v1.25+
W1107 14:06:28.879481  520126 warnings.go:70] policy/v1beta1 PodSecurityPolicy is deprecated in v1.21+, unavailable in v1.25+
W1107 14:06:28.882228  520126 warnings.go:70] policy/v1beta1 PodSecurityPolicy is deprecated in v1.21+, unavailable in v1.25+
W1107 14:06:28.884110  520126 warnings.go:70] policy/v1beta1 PodSecurityPolicy is deprecated in v1.21+, unavailable in v1.25+
W1107 14:06:28.886065  520126 warnings.go:70] policy/v1beta1 PodSecurityPolicy is deprecated in v1.21+, unavailable in v1.25+
W1107 14:06:28.888753  520126 warnings.go:70] policy/v1beta1 PodSecurityPolicy is deprecated in v1.21+, unavailable in v1.25+
W1107 14:06:28.890576  520126 warnings.go:70] policy/v1beta1 PodSecurityPolicy is deprecated in v1.21+, unavailable in v1.25+
W1107 14:06:28.892423  520126 warnings.go:70] policy/v1beta1 PodSecurityPolicy is deprecated in v1.21+, unavailable in v1.25+
W1107 14:06:28.895016  520126 warnings.go:70] policy/v1beta1 PodSecurityPolicy is deprecated in v1.21+, unavailable in v1.25+
client.go:239: [debug] Created a new ServiceAccount called "flash-coffee" in logiq

client.go:239: [debug] Created a new ServiceAccount called "flash-discovery" in logiq

client.go:239: [debug] Created a new ServiceAccount called "ingress-nginx" in logiq

client.go:239: [debug] Created a new ServiceAccount called "logiq-kubernetes-ingress-backend" in logiq

client.go:239: [debug] Created a new ServiceAccount called "logiq-flash" in logiq

client.go:239: [debug] Created a new ServiceAccount called "logiqctl" in logiq

client.go:239: [debug] Created a new ServiceAccount called "postgres" in logiq

client.go:239: [debug] Created a new ServiceAccount called "logiq-kube-state-metrics" in logiq

client.go:239: [debug] Created a new ServiceAccount called "logiq-node-exporter" in logiq

client.go:239: [debug] Created a new ServiceAccount called "logiq-prometheus-alertmanager" in logiq

client.go:239: [debug] Created a new ServiceAccount called "logiq-prometheus-operator" in logiq

client.go:239: [debug] Created a new ServiceAccount called "logiq-prometheus-prometheus" in logiq

client.go:239: [debug] Created a new ServiceAccount called "redis" in logiq

client.go:239: [debug] Created a new ServiceAccount called "s3-gateway-update-prometheus-secret" in logiq

client.go:239: [debug] Created a new ServiceAccount called "s3-gateway-job" in logiq

client.go:239: [debug] Created a new ServiceAccount called "s3-gateway" in logiq

client.go:239: [debug] Created a new ServiceAccount called "logiq-thanos-bucketweb" in logiq

client.go:239: [debug] Created a new ServiceAccount called "logiq-thanos-compactor" in logiq

client.go:239: [debug] Created a new ServiceAccount called "logiq-thanos-query" in logiq

client.go:239: [debug] Created a new ServiceAccount called "logiq-thanos-receive" in logiq

client.go:239: [debug] Created a new ServiceAccount called "logiq-thanos-ruler" in logiq

client.go:239: [debug] Created a new ServiceAccount called "logiq-thanos-storegateway" in logiq

client.go:239: [debug] Created a new Secret called "logiq-flash-coffee" in logiq

client.go:239: [debug] Created a new Secret called "flash-discovery" in logiq

client.go:239: [debug] Created a new Secret called "logiq-logiq-flash" in logiq

client.go:239: [debug] Created a new Secret called "logiq-logiqctl" in logiq

client.go:239: [debug] Created a new Secret called "postgres" in logiq

client.go:239: [debug] Created a new Secret called "alertmanager-logiq-prometheus-alertmanager" in logiq

client.go:239: [debug] Created a new Secret called "s3-gateway" in logiq

client.go:239: [debug] Created a new Secret called "logiq-thanos-objstore-secret" in logiq

client.go:239: [debug] Created a new ConfigMap called "logiq-kubernetes-ingress" in logiq

client.go:239: [debug] Created a new ConfigMap called "logiq-kubernetes-ingress-tcp" in logiq

client.go:239: [debug] Created a new ConfigMap called "logiq-config" in logiq

client.go:239: [debug] Created a new ConfigMap called "logiq-logiqctl" in logiq

client.go:239: [debug] Created a new ConfigMap called "postgres-extended-configuration" in logiq

client.go:239: [debug] Created a new ConfigMap called "logiq-prometheus-operator" in logiq

client.go:239: [debug] Created a new ConfigMap called "redis" in logiq

client.go:239: [debug] Created a new ConfigMap called "redis-health" in logiq

client.go:239: [debug] Created a new ConfigMap called "s3-gateway" in logiq

client.go:239: [debug] Created a new ConfigMap called "logiq-thanos-receive" in logiq

client.go:239: [debug] Created a new ConfigMap called "logiq-thanos-ruler-configmap" in logiq

client.go:239: [debug] Created a new ConfigMap called "ingress-tcp-ports" in logiq

client.go:239: [debug] Created a new PersistentVolumeClaim called "logiq-thanos-compactor" in logiq

client.go:501: [debug] Looks like there are no changes for ClusterRole "logiq-kubernetes-ingress"
client.go:501: [debug] Looks like there are no changes for ClusterRole "logiq-logiq-flash"
client.go:501: [debug] Looks like there are no changes for ClusterRole "logiq-kube-state-metrics"
client.go:501: [debug] Looks like there are no changes for ClusterRole "logiq-kube-state-metrics-psp"
client.go:501: [debug] Looks like there are no changes for ClusterRole "logiq-node-exporter-psp"
client.go:501: [debug] Looks like there are no changes for ClusterRole "logiq-prometheus-alertmanager-psp"
client.go:501: [debug] Looks like there are no changes for ClusterRole "logiq-prometheus-operator"
client.go:501: [debug] Looks like there are no changes for ClusterRole "logiq-prometheus-operator-psp"
client.go:501: [debug] Looks like there are no changes for ClusterRole "logiq-prometheus-prometheus"
client.go:501: [debug] Looks like there are no changes for ClusterRole "logiq-prometheus-prometheus-psp"
client.go:501: [debug] Looks like there are no changes for ClusterRoleBinding "logiq-kubernetes-ingress"
client.go:501: [debug] Looks like there are no changes for ClusterRoleBinding "logiq-logiq-flash"
client.go:501: [debug] Looks like there are no changes for ClusterRoleBinding "logiq-kube-state-metrics"
client.go:501: [debug] Looks like there are no changes for ClusterRoleBinding "logiq-kube-state-metrics-psp"
client.go:501: [debug] Looks like there are no changes for ClusterRoleBinding "logiq-node-exporter-psp"
client.go:501: [debug] Looks like there are no changes for ClusterRoleBinding "logiq-prometheus-alertmanager-psp"
client.go:501: [debug] Looks like there are no changes for ClusterRoleBinding "logiq-prometheus-operator"
client.go:501: [debug] Looks like there are no changes for ClusterRoleBinding "logiq-prometheus-operator-psp"
client.go:501: [debug] Looks like there are no changes for ClusterRoleBinding "logiq-prometheus-prometheus"
client.go:501: [debug] Looks like there are no changes for ClusterRoleBinding "logiq-prometheus-prometheus-psp"
client.go:239: [debug] Created a new Role called "flash-coffee" in logiq

client.go:239: [debug] Created a new Role called "flash-discovery" in logiq

client.go:239: [debug] Created a new Role called "logiq-kubernetes-ingress" in logiq

client.go:239: [debug] Created a new Role called "logiq-kubernetes-ingress-backend" in logiq

client.go:239: [debug] Created a new Role called "logiq-flash" in logiq

client.go:239: [debug] Created a new Role called "logiqctl" in logiq

client.go:239: [debug] Created a new Role called "postgres" in logiq

client.go:239: [debug] Created a new Role called "redis" in logiq

client.go:239: [debug] Created a new Role called "s3-gateway-update-prometheus-secret" in logiq

client.go:239: [debug] Created a new Role called "s3-gateway-job" in logiq

client.go:239: [debug] Created a new Role called "s3-gateway" in logiq

client.go:239: [debug] Created a new RoleBinding called "flash-coffee" in logiq

client.go:239: [debug] Created a new RoleBinding called "flash-discovery" in logiq

client.go:239: [debug] Created a new RoleBinding called "logiq-kubernetes-ingress" in logiq

client.go:239: [debug] Created a new RoleBinding called "logiq-kubernetes-ingress-backend" in logiq

client.go:239: [debug] Created a new RoleBinding called "logiq-flash" in logiq

client.go:239: [debug] Created a new RoleBinding called "logiqctl" in logiq

client.go:239: [debug] Created a new RoleBinding called "postgres" in logiq

client.go:239: [debug] Created a new RoleBinding called "redis" in logiq

client.go:239: [debug] Created a new RoleBinding called "s3-gateway-update-prometheus-secret" in logiq

client.go:239: [debug] Created a new RoleBinding called "s3-gateway-job" in logiq

client.go:239: [debug] Created a new RoleBinding called "s3-gateway" in logiq

client.go:239: [debug] Created a new Service called "coffee" in logiq

client.go:239: [debug] Created a new Service called "flash-discovery" in logiq

client.go:239: [debug] Created a new Service called "logiq-kubernetes-ingress" in logiq

client.go:239: [debug] Created a new Service called "logiq-kubernetes-ingress-default-backend" in logiq

client.go:239: [debug] Created a new Service called "logiq-flash-ml" in logiq

client.go:239: [debug] Created a new Service called "logiq-flash-sync" in logiq

client.go:239: [debug] Created a new Service called "logiq-flash-headless" in logiq

client.go:239: [debug] Created a new Service called "logiq-flash" in logiq

client.go:239: [debug] Created a new Service called "postgres-metrics" in logiq

client.go:239: [debug] Created a new Service called "postgres-headless" in logiq

client.go:239: [debug] Created a new Service called "postgres" in logiq

client.go:239: [debug] Created a new Service called "logiq-kube-state-metrics" in logiq

client.go:239: [debug] Created a new Service called "logiq-node-exporter" in logiq

client.go:239: [debug] Created a new Service called "logiq-prometheus-alertmanager" in logiq

client.go:239: [debug] Created a new Service called "logiq-prometheus-operator" in logiq

client.go:239: [debug] Created a new Service called "logiq-prometheus-prometheus" in logiq

client.go:239: [debug] Created a new Service called "logiq-prometheus-prometheus-thanos" in logiq

client.go:239: [debug] Created a new Service called "redis-headless" in logiq

client.go:239: [debug] Created a new Service called "redis-metrics" in logiq

client.go:239: [debug] Created a new Service called "redis-master" in logiq

client.go:239: [debug] Created a new Service called "s3-gateway" in logiq

client.go:239: [debug] Created a new Service called "s3-gateway-svc" in logiq

client.go:239: [debug] Created a new Service called "logiq-thanos-bucketweb" in logiq

client.go:239: [debug] Created a new Service called "logiq-thanos-compactor" in logiq

client.go:239: [debug] Created a new Service called "logiq-thanos-query" in logiq

client.go:239: [debug] Created a new Service called "logiq-thanos-receive" in logiq

client.go:239: [debug] Created a new Service called "logiq-thanos-ruler" in logiq

client.go:239: [debug] Created a new Service called "logiq-thanos-storegateway" in logiq

client.go:239: [debug] Created a new DaemonSet called "logiq-node-exporter" in logiq

client.go:239: [debug] Created a new Deployment called "logiq-kubernetes-ingress" in logiq

client.go:239: [debug] Created a new Deployment called "logiq-kubernetes-ingress-default-backend" in logiq

client.go:239: [debug] Created a new Deployment called "logiq-kube-state-metrics" in logiq

client.go:239: [debug] Created a new Deployment called "logiq-prometheus-operator" in logiq

client.go:239: [debug] Created a new Deployment called "logiq-thanos-bucketweb" in logiq

client.go:239: [debug] Created a new Deployment called "logiq-thanos-compactor" in logiq

client.go:239: [debug] Created a new Deployment called "logiq-thanos-query" in logiq

client.go:239: [debug] Created a new StatefulSet called "coffee-server" in logiq

client.go:239: [debug] Created a new StatefulSet called "coffee-worker" in logiq

client.go:239: [debug] Created a new StatefulSet called "flash-discovery" in logiq

client.go:239: [debug] Created a new StatefulSet called "logiq-flash" in logiq

client.go:239: [debug] Created a new StatefulSet called "logiq-flash-ml" in logiq

client.go:239: [debug] Created a new StatefulSet called "logiq-flash-sync" in logiq

client.go:239: [debug] Created a new StatefulSet called "postgres" in logiq

client.go:239: [debug] Created a new StatefulSet called "redis-master" in logiq

client.go:239: [debug] Created a new StatefulSet called "s3-gateway" in logiq

client.go:239: [debug] Created a new StatefulSet called "logiq-thanos-receive" in logiq

client.go:239: [debug] Created a new StatefulSet called "logiq-thanos-ruler" in logiq

client.go:239: [debug] Created a new StatefulSet called "logiq-thanos-storegateway" in logiq

client.go:239: [debug] Created a new Ingress called "logiq-ingress" in logiq

client.go:239: [debug] Created a new Alertmanager called "logiq-prometheus-alertmanager" in logiq

client.go:239: [debug] Created a new Prometheus called "logiq-prometheus-prometheus" in logiq

client.go:239: [debug] Created a new PrometheusRule called "logiq-prometheus-alertmanager" in logiq

client.go:239: [debug] Created a new ServiceMonitor called "prometheus-logiq-logiq-flash" in logiq

client.go:239: [debug] Created a new ServiceMonitor called "postgres" in logiq

client.go:239: [debug] Created a new ServiceMonitor called "logiq-kube-state-metrics" in logiq

client.go:239: [debug] Created a new ServiceMonitor called "logiq-node-exporter" in logiq

client.go:239: [debug] Created a new ServiceMonitor called "logiq-prometheus-alertmanager" in logiq

client.go:239: [debug] Created a new ServiceMonitor called "logiq-prometheus-kubelet" in logiq

client.go:239: [debug] Created a new ServiceMonitor called "logiq-prometheus-operator" in logiq

client.go:239: [debug] Created a new ServiceMonitor called "logiq-prometheus-prometheus" in logiq

client.go:239: [debug] Created a new ServiceMonitor called "redis" in logiq

client.go:239: [debug] Created a new ServiceMonitor called "logiq-thanos-bucketweb" in logiq

client.go:239: [debug] Created a new ServiceMonitor called "logiq-thanos-compactor" in logiq

client.go:239: [debug] Created a new ServiceMonitor called "logiq-thanos-query" in logiq

client.go:239: [debug] Created a new ServiceMonitor called "logiq-thanos-receive" in logiq

client.go:239: [debug] Created a new ServiceMonitor called "logiq-thanos-ruler" in logiq

client.go:239: [debug] Created a new ServiceMonitor called "logiq-thanos-storegateway" in logiq

client.go:299: [debug] Starting delete for "s3-gateway-make-bucket-job" Job
client.go:328: [debug] jobs.batch "s3-gateway-make-bucket-job" not found
client.go:128: [debug] creating 1 resource(s)
client.go:528: [debug] Watching for changes to Job s3-gateway-make-bucket-job with timeout of 20m0s
client.go:556: [debug] Add/Modify event for s3-gateway-make-bucket-job: ADDED
client.go:595: [debug] s3-gateway-make-bucket-job: Jobs active: 0, jobs failed: 0, jobs succeeded: 0
client.go:556: [debug] Add/Modify event for s3-gateway-make-bucket-job: MODIFIED
client.go:595: [debug] s3-gateway-make-bucket-job: Jobs active: 1, jobs failed: 0, jobs succeeded: 0
client.go:556: [debug] Add/Modify event for s3-gateway-make-bucket-job: MODIFIED
client.go:299: [debug] Starting delete for "logiq-logiqctl-upload-dashboard-job" Job
client.go:328: [debug] jobs.batch "logiq-logiqctl-upload-dashboard-job" not found
client.go:128: [debug] creating 1 resource(s)
client.go:528: [debug] Watching for changes to Job logiq-logiqctl-upload-dashboard-job with timeout of 20m0s
client.go:556: [debug] Add/Modify event for logiq-logiqctl-upload-dashboard-job: ADDED
client.go:595: [debug] logiq-logiqctl-upload-dashboard-job: Jobs active: 0, jobs failed: 0, jobs succeeded: 0
client.go:556: [debug] Add/Modify event for logiq-logiqctl-upload-dashboard-job: MODIFIED
client.go:595: [debug] logiq-logiqctl-upload-dashboard-job: Jobs active: 1, jobs failed: 0, jobs succeeded: 0
client.go:556: [debug] Add/Modify event for logiq-logiqctl-upload-dashboard-job: MODIFIED
client.go:299: [debug] Starting delete for "s3-gateway-make-bucket-job" Job
client.go:299: [debug] Starting delete for "logiq-logiqctl-upload-dashboard-job" Job
NAME: logiq
LAST DEPLOYED: Mon Nov  7 14:06:24 2022
NAMESPACE: logiq
STATUS: deployed
REVISION: 1
TEST SUITE: None
USER-SUPPLIED VALUES:
alertmenager:
  replicaCount: 1
flash-coffee:
  coffee:
    image:
      pullPolicy: IfNotPresent
      tag: brew.2.1.37-rc60
    replicaCount: 1
    resources:
      requests:
        cpu: 100m
        memory: 0.2Gi
  coffee_worker:
    image:
      pullPolicy: IfNotPresent
      tag: brew.2.1.37-rc60
    replicaCount: 1
    resources:
      requests:
        cpu: 100m
        memory: 0.2Gi
  service:
    type: NodePort
flash-discovery:
  fullnameOverride: flash-discovery
  image:
    pullPolicy: IfNotPresent
    tag: 2.0.1
  persistence:
    enabled: true
    size: 0.5Gi
  replicaCountDiscovery: 1
global:
  chart:
    grafana: false
    postgres: true
    prometheus: true
    redis: true
    s3-gateway: true
  cloudProvider: aws
  domain: null
  enableMetricsServer: false
  environment:
    admin_email: flash-admin@foo.com
    admin_name: flash-admin@foo.com
    admin_org: flash-org
    admin_password: flash-password
    awsServiceEndpoint: https://s3.us-east-1.amazonaws.com
    cluster_id: LOGIQ
    license: license/license.jws
    logiq_flash_host: logiq-flash
    logiq_flash_port: 9999
    postgres_coffee_db: coffee
    postgres_db: postgres
    postgres_host: postgres
    postgres_password: postgres
    postgres_port: "5432"
    postgres_user: postgres
    redis_host: redis-master
    redis_opts: true
    redis_port: "6379"
    s3_access: logiq_access
    s3_bucket: logiq
    s3_region: us-east-1
    s3_secret: logiq_secret
    s3_url: http://s3-gateway:9000
    upload_dashboard: true
  job:
    ttlSecondsAfterFinished: 100
  kubeDistributor:
    enabled: false
  persistence:
    storageClass: microk8s-hostpath
  sharedSecretName: logiq-shared-secret
  taints:
    enabled: false
  toolbox:
    image:
      repository: logiqai/toolbox
      tag: 2.0.1
ingress:
  enabled: true
  name: logiq-ingress
  tlsEnabled: false
  tlsSecretName: null
kubernetes-ingress:
  controller:
    defaultTLSSecret:
      enabled: false
      secret: null
    ingressClass: logiq-ingress
    replicaCount: 1
    service:
      type: LoadBalancer
  defaultBackend:
    replicaCount: 1
  podSecurityPolicy:
    enabled: true
  serviceAccount:
    create: true
    name: ingress-nginx
logiq-flash:
  image:
    pullPolicy: IfNotPresent
    tag: v3.1
  metrics:
    selector:
      release: prometheus
    serviceMonitor:
      enabled: true
  persistence:
    enabled: true
    ml_size: 10Gi
    size: 10Gi
  replicaCount: 1
  replicaCountMl: 1
  replicaCountSync: 1
  resources:
    ingest:
      limits:
        cpu: 1250m
      requests:
        cpu: 1250m
        memory: 512Mi
    ml:
      limits:
        cpu: 1000m
      requests:
        cpu: 500m
    sync:
      requests:
        cpu: 100m
  service:
    type: NodePort
logiqctl:
  image:
    pullPolicy: IfNotPresent
    repository: logiqai/logiqctl
    tag: 2.0.4
postgres:
  enabled: true
  fullnameOverride: postgres
  metrics:
    additionalLabels:
      release: prometheus
    enabled: true
    serviceMonitor:
      enabled: true
  persistence:
    size: 1Gi
  postgresqlDatabase: postgres
  postgresqlExtendedConf:
    maxConnections: "400"
    sharedBuffers: 1024MB
  postgresqlPassword: postgres
  postgresqlPostgresPassword: postgres
  postgresqlUsername: postgres
  resources:
    requests:
      cpu: 100m
      memory: 0.5Gi
  securityContext:
    enabled: true
    fsGroup: 1001
    runAsUser: 1001
  serviceAccount:
    enabled: true
    name: postgres
prometheus:
  replicaCount: 1
prometheus-operator:
  alertmenager:
    replicaCount: 1
  fullnameOverride: prometheus
  persistence:
    enabled: true
    size: 10Gi
  prometheus:
    replicaCount: 1
redis:
  cluster:
    enabled: false
    slaveCount: 1
  enabled: true
  fullnameOverride: redis
  master:
    affinity:
      podAntiAffinity:
        requiredDuringSchedulingIgnoredDuringExecution:
        - labelSelector:
            matchExpressions:
            - key: app
              operator: In
              values:
              - redis
          topologyKey: kubernetes.io/hostname
    disableCommands: []
  metrics:
    enabled: true
    selector:
      release: prometheus
    serviceMonitor:
      enabled: true
  podSecurityPolicy:
    create: true
    rbac:
      create: true
      role:
        rules:
        - apiGroups:
          - policy
          resourceNames:
          - redis
          resources:
          - podsecuritypolicies
          verbs:
          - use
  securityContext:
    enable: true
    fsGroup: 1001
    runAsUser: 1001
  serviceAccount:
    create: true
    name: redis
  slave:
    affinity:
      podAntiAffinity:
        requiredDuringSchedulingIgnoredDuringExecution:
        - labelSelector:
            matchExpressions:
            - key: app
              operator: In
              values:
              - redis
          topologyKey: kubernetes.io/hostname
    disableCommands: []
  usePassword: false
s3-gateway:
  accessKey: logiq_access
  buckets:
  - name: logiq
    policy: none
    purge: false
  defaultBucket:
    enabled: true
  fullnameOverride: s3-gateway
  gcsgateway:
    enabled: false
    replicas: 1
  metrics:
    serviceMonitor:
      enabled: false
  mode: standalone
  persistence:
    enabled: true
    size: 1Gi
  resources:
    requests:
      cpu: 100m
      memory: 0.2Gi
  s3gateway:
    enabled: false
    replicas: 1
  secretKey: logiq_secret
  securityContext:
    enabled: true
    fsGroup: 1000
    runAsGroup: 1000
    runAsUser: 1000
  serviceAccount:
    create: true
    name: s3-gateway

COMPUTED VALUES:
alertmenager:
  replicaCount: 1
flash-coffee:
  affinity: {}
  coffee:
    image:
      pullPolicy: IfNotPresent
      repository: logiqai/flash-brew-coffee
      tag: brew.2.1.37-rc60
    name: coffee
    port: 80
    replicaCount: 1
    resources:
      requests:
        cpu: 100m
        memory: 0.2Gi
    targetPort: 5000
    web_workers: 4
  coffee_worker:
    image:
      pullPolicy: IfNotPresent
      repository: logiqai/flash-brew-coffee
      tag: brew.2.1.37-rc60
    replicaCount: 1
    resources:
      requests:
        cpu: 100m
        memory: 0.2Gi
  global:
    chart:
      grafana: false
      postgres: true
      prometheus: true
      redis: true
      s3-gateway: true
      s3gateway: true
      thanos: true
    cloudProvider: aws
    createStorageClass: false
    enableAwsAlb:
      albType: internet-facing
      enabled: false
    enableMetricsServer: false
    environment:
      admin_email: flash-admin@foo.com
      admin_name: flash-admin@foo.com
      admin_org: flash-org
      admin_password: flash-password
      awsServiceEndpoint: https://s3.us-east-1.amazonaws.com
      cluster_id: LOGIQ
      gacode: ""
      license: license/license.jws
      logiq_flash_host: logiq-flash
      logiq_flash_port: 9999
      mail_default_sender: flash-admin@foo.com
      mail_password: password
      mail_port: "587"
      mail_server: smtp-mail-server
      mail_username: user
      postgres_coffee_db: coffee
      postgres_db: postgres
      postgres_host: postgres
      postgres_password: postgres
      postgres_port: "5432"
      postgres_user: postgres
      redis_host: redis-master
      redis_opts: true
      redis_port: "6379"
      s3_access: logiq_access
      s3_bucket: logiq
      s3_region: us-east-1
      s3_secret: logiq_secret
      s3_url: http://s3-gateway:9000
      upload_dashboard: true
    job:
      ttlSecondsAfterFinished: 100
    kubeDistributor:
      enabled: false
    nodeSelectors:
      cache: cache
      db: db
      enabled: false
      infra: infra
      ingest: flash
      ingest_sync: sync
      other: coffee
    persistence:
      createStorageClass:
        enabled: true
      storageClass: microk8s-hostpath
    sharedSecretName: logiq-shared-secret
    taints:
      cache: cache
      db: db
      enabled: false
      infra: infra
      ingest: flash
      ingest_sync: sync
      other: coffee
    toolbox:
      image:
        repository: logiqai/toolbox
        tag: 2.0.1
  ingress:
    annotations: {}
    enabled: false
    hosts:
    - a
    - b
    - 192.168.99.100
    path: /
    tls: []
  nodeSelector: {}
  replicaCount: 1
  service:
    port: 80
    type: NodePort
  tolerations: []
  useSecret: false
flash-discovery:
  affinity: {}
  configurationFiles: false
  discoveryAPI:
    name: discovery-api
    port: 4000
  discoveryHealth:
    name: discovery-health
    port: 8081
  discoveryService:
    type: LoadBalancer
  fullnameOverride: flash-discovery
  global:
    chart:
      grafana: false
      postgres: true
      prometheus: true
      redis: true
      s3-gateway: true
      s3gateway: true
      thanos: true
    cloudProvider: aws
    createStorageClass: false
    domain: null
    enableAwsAlb:
      albType: internet-facing
      enabled: false
    enableMetricsServer: false
    environment:
      admin_email: flash-admin@foo.com
      admin_name: flash-admin@foo.com
      admin_org: flash-org
      admin_password: flash-password
      awsServiceEndpoint: https://s3.us-east-1.amazonaws.com
      cluster_id: LOGIQ
      license: license/license.jws
      logiq_flash_host: logiq-flash
      logiq_flash_port: 9999
      postgres_coffee_db: coffee
      postgres_db: postgres
      postgres_host: postgres
      postgres_password: postgres
      postgres_port: "5432"
      postgres_user: postgres
      redis_host: redis-master
      redis_opts: true
      redis_port: "6379"
      s3_access: logiq_access
      s3_bucket: logiq
      s3_region: us-east-1
      s3_secret: logiq_secret
      s3_url: http://s3-gateway:9000
      upload_dashboard: true
    job:
      ttlSecondsAfterFinished: 100
    kubeDistributor:
      enabled: false
    nodeSelectors:
      cache: cache
      db: db
      enabled: false
      infra: infra
      ingest: flash
      ingest_sync: sync
      other: coffee
    persistence:
      createStorageClass:
        enabled: true
      storageClass: microk8s-hostpath
    sharedSecretName: logiq-shared-secret
    taints:
      cache: cache
      db: db
      enabled: false
      infra: infra
      ingest: flash
      ingest_sync: sync
      other: coffee
    toolbox:
      image:
        repository: logiqai/toolbox
        tag: 2.0.1
  image:
    pullPolicy: IfNotPresent
    repository: logiqai/flash-discovery
    tag: 2.0.1
  nodeSelector: {}
  persistence:
    accessMode: ReadWriteOnce
    enabled: true
    size: 0.5Gi
    storageClassName: standard
  podPerNode: true
  replicaCountDiscovery: 1
  resources:
    requests:
      cpu: 100m
      memory: 100Mi
  secrets: false
  tolerations: []
  useSecret: false
global:
  chart:
    grafana: false
    postgres: true
    prometheus: true
    redis: true
    s3-gateway: true
    s3gateway: true
    thanos: true
  cloudProvider: aws
  createStorageClass: false
  enableAwsAlb:
    albType: internet-facing
    enabled: false
  enableMetricsServer: false
  environment:
    admin_email: flash-admin@foo.com
    admin_name: flash-admin@foo.com
    admin_org: flash-org
    admin_password: flash-password
    awsServiceEndpoint: https://s3.us-east-1.amazonaws.com
    cluster_id: LOGIQ
    license: license/license.jws
    logiq_flash_host: logiq-flash
    logiq_flash_port: 9999
    postgres_coffee_db: coffee
    postgres_db: postgres
    postgres_host: postgres
    postgres_password: postgres
    postgres_port: "5432"
    postgres_user: postgres
    redis_host: redis-master
    redis_opts: true
    redis_port: "6379"
    s3_access: logiq_access
    s3_bucket: logiq
    s3_region: us-east-1
    s3_secret: logiq_secret
    s3_url: http://s3-gateway:9000
    upload_dashboard: true
  job:
    ttlSecondsAfterFinished: 100
  kubeDistributor:
    enabled: false
  nodeSelectors:
    cache: cache
    db: db
    enabled: false
    infra: infra
    ingest: flash
    ingest_sync: sync
    other: coffee
  persistence:
    createStorageClass:
      enabled: true
    storageClass: microk8s-hostpath
  sharedSecretName: logiq-shared-secret
  taints:
    cache: cache
    db: db
    enabled: false
    infra: infra
    ingest: flash
    ingest_sync: sync
    other: coffee
  toolbox:
    image:
      repository: logiqai/toolbox
      tag: 2.0.1
grafana:
  admin:
    existingSecretPasswordKey: password
    user: admin
  affinity: {}
  clusterDomain: cluster.local
  config:
    grafanaIniConfigMap: null
    grafanaIniSecret: null
    useGrafanaIniFile: false
  dashboardsConfigMaps: []
  dashboardsProvider:
    configMapName: null
    enabled: false
  datasources:
    secretName: null
  extraConfigmaps: {}
  extraEnvVars: {}
  extraVolumeMounts: []
  extraVolumes: []
  fullnameOverride: grafana
  global:
    chart:
      grafana: false
      postgres: true
      prometheus: true
      redis: true
      s3-gateway: true
      s3gateway: true
      thanos: true
    cloudProvider: aws
    createStorageClass: false
    enableAwsAlb:
      albType: internet-facing
      enabled: false
    enableMetricsServer: false
    environment:
      admin_email: flash-admin@foo.com
      admin_name: flash-admin@foo.com
      admin_org: flash-org
      admin_password: flash-password
      awsServiceEndpoint: https://s3.us-east-1.amazonaws.com
      cluster_id: LOGIQ
      license: license/license.jws
      logiq_flash_host: logiq-flash
      logiq_flash_port: 9999
      postgres_coffee_db: coffee
      postgres_db: postgres
      postgres_host: postgres
      postgres_password: postgres
      postgres_port: "5432"
      postgres_user: postgres
      redis_host: redis-master
      redis_opts: true
      redis_port: "6379"
      s3_access: logiq_access
      s3_bucket: logiq
      s3_region: us-east-1
      s3_secret: logiq_secret
      s3_url: http://s3-gateway:9000
      upload_dashboard: true
    job:
      ttlSecondsAfterFinished: 100
    kubeDistributor:
      enabled: false
    nodeSelectors:
      cache: cache
      db: db
      enabled: false
      infra: infra
      ingest: flash
      ingest_sync: sync
      other: coffee
    persistence:
      createStorageClass:
        enabled: true
      storageClass: microk8s-hostpath
    sharedSecretName: logiq-shared-secret
    taints:
      cache: cache
      db: db
      enabled: false
      infra: infra
      ingest: flash
      ingest_sync: sync
      other: coffee
    toolbox:
      image:
        repository: logiqai/toolbox
        tag: 2.0.1
  image:
    pullPolicy: IfNotPresent
    registry: docker.io
    repository: bitnami/grafana
    tag: 7.3.6-debian-10-r0
  imageRenderer:
    affinity: {}
    enabled: false
    image:
      pullPolicy: IfNotPresent
      pullSecrets: []
      registry: docker.io
      repository: bitnami/grafana-image-renderer
      tag: 2.0.0-debian-10-r153
    metrics:
      annotations:
        prometheus.io/path: /metrics
        prometheus.io/port: "8080"
        prometheus.io/scrape: "true"
      enabled: false
      serviceMonitor:
        enabled: false
    nodeSelector: {}
    podAnnotations: {}
    replicaCount: 1
    securityContext:
      enabled: true
      fsGroup: 1001
      runAsNonRoot: true
      runAsUser: 1001
    service:
      port: 8080
    tolerations: []
  ingress:
    certManager: false
    enabled: false
    hosts:
    - extraPaths: []
      name: grafana.local
      paths:
      - /
      tls: false
      tlsSecret: grafana.local-tls
  ldap:
    allowSignUp: false
    enabled: false
  livenessProbe:
    enabled: true
    failureThreshold: 6
    initialDelaySeconds: 120
    periodSeconds: 10
    successThreshold: 1
    timeoutSeconds: 5
  metrics:
    enabled: false
    service:
      annotations:
        prometheus.io/path: /metrics
        prometheus.io/port: "3000"
        prometheus.io/scrape: "true"
    serviceMonitor:
      enabled: false
  nodeAffinityPreset:
    key: ""
    type: ""
    values: []
  nodeSelector: {}
  persistence:
    accessMode: ReadWriteOnce
    enabled: true
    size: 10Gi
  podAffinityPreset: ""
  podAnnotations: {}
  podAntiAffinityPreset: soft
  readinessProbe:
    enabled: true
    failureThreshold: 6
    initialDelaySeconds: 30
    periodSeconds: 10
    successThreshold: 1
    timeoutSeconds: 5
  replicaCount: 1
  resources:
    limits: {}
    requests: {}
  securityContext:
    enabled: true
    fsGroup: 1001
    runAsNonRoot: true
    runAsUser: 1001
  service:
    annotations: {}
    port: 3000
    type: ClusterIP
  serviceAccount:
    annotations: {}
    create: true
  sidecars: {}
  smtp:
    enabled: false
    existingSecretPasswordKey: password
    existingSecretUserKey: user
    password: password
    user: user
  tolerations: []
  updateStrategy:
    type: RollingUpdate
ingress:
  enabled: true
  name: logiq-ingress
  tlsEnabled: false
kubernetes-ingress:
  controller:
    addHeaders: {}
    admissionWebhooks:
      enabled: false
      failurePolicy: Fail
      patch:
        enabled: true
        image:
          pullPolicy: IfNotPresent
          repository: jettech/kube-webhook-certgen
          tag: v1.0.0
        nodeSelector: {}
        podAnnotations: {}
        priorityClassName: ""
      port: 8443
      service:
        annotations: {}
        externalIPs: []
        loadBalancerIP: ""
        loadBalancerSourceRanges: []
        omitClusterIP: false
        servicePort: 443
        type: ClusterIP
    affinity: {}
    autoscaling:
      enabled: false
      maxReplicas: 11
      minReplicas: 2
      targetCPUUtilizationPercentage: 50
      targetMemoryUtilizationPercentage: 50
    computeFullForwardedFor: "true"
    config:
      disable-access-log: "false"
    configMapNamespace: ""
    containerPort:
      http: 80
      https: 443
    customTemplate:
      configMapKey: ""
      configMapName: ""
    daemonset:
      hostPorts:
        http: 80
        https: 443
      useHostPort: false
    defaultBackendService: ""
    defaultTLSSecret:
      enabled: false
    deploymentAnnotations: {}
    deploymentLabels: {}
    dnsConfig: {}
    dnsPolicy: ClusterFirst
    electionID: ingress-controller-leader
    extraArgs: {}
    extraContainers: []
    extraEnvs: []
    extraInitContainers: []
    extraVolumeMounts: []
    extraVolumes: []
    hostNetwork: false
    image:
      allowPrivilegeEscalation: true
      pullPolicy: IfNotPresent
      repository: k8s.gcr.io/ingress-nginx/controller
      runAsUser: 101
      tag: v1.2.0
    ingressClass: logiq-ingress
    kind: Deployment
    lifecycle: {}
    livenessProbe:
      failureThreshold: 15
      initialDelaySeconds: 10
      periodSeconds: 10
      port: 10254
      successThreshold: 1
      timeoutSeconds: 1
    maxmindLicenseKey: ""
    metrics:
      enabled: false
      port: 10254
      prometheusRule:
        additionalLabels: {}
        enabled: false
        namespace: ""
        rules: []
      service:
        annotations: {}
        externalIPs: []
        loadBalancerIP: ""
        loadBalancerSourceRanges: []
        omitClusterIP: false
        servicePort: 9913
        type: ClusterIP
      serviceMonitor:
        additionalLabels: {}
        enabled: false
        namespace: ""
        namespaceSelector: {}
        scrapeInterval: 30s
    minAvailable: 1
    minReadySeconds: 0
    name: ""
    nodeSelector: {}
    podAnnotations: {}
    podLabels: {}
    podSecurityContext: {}
    priorityClassName: ""
    proxySetHeaders: {}
    publishService:
      enabled: false
      pathOverride: ""
    readinessProbe:
      failureThreshold: 3
      initialDelaySeconds: 10
      periodSeconds: 10
      port: 10254
      successThreshold: 1
      timeoutSeconds: 1
    replicaCount: 1
    reportNodeInternalIp: false
    resources: {}
    scope:
      enabled: false
      namespace: ""
    service:
      annotations: {}
      enableHttp: true
      enableHttps: true
      enabled: true
      externalIPs: []
      externalTrafficPolicy: ""
      healthCheckNodePort: 0
      labels: {}
      loadBalancerIP: ""
      loadBalancerSourceRanges: []
      nodePorts:
        http: ""
        https: ""
        tcp: {}
        udp: {}
      omitClusterIP: false
      ports:
        http: 80
        https: 443
      sessionAffinity: ""
      targetPorts:
        http: http
        https: https
      type: LoadBalancer
    tcp:
      configMapNamespace: ""
    terminationGracePeriodSeconds: 60
    tolerations: []
    udp:
      configMapNamespace: ""
    updateStrategy: {}
    useComponentLabel: false
    useForwardedHeaders: "true"
    useProxyProtocol: "true"
  defaultBackend:
    affinity: {}
    deploymentLabels: {}
    enabled: true
    extraArgs: {}
    extraEnvs: []
    image:
      pullPolicy: IfNotPresent
      repository: k8s.gcr.io/defaultbackend-amd64
      runAsUser: 65534
      tag: "1.5"
    livenessProbe:
      failureThreshold: 15
      initialDelaySeconds: 30
      periodSeconds: 10
      successThreshold: 1
      timeoutSeconds: 5
    minAvailable: 1
    name: default-backend
    nodeSelector: {}
    podAnnotations: {}
    podLabels: {}
    podSecurityContext: {}
    port: 8080
    priorityClassName: ""
    readinessProbe:
      failureThreshold: 6
      initialDelaySeconds: 0
      periodSeconds: 5
      successThreshold: 1
      timeoutSeconds: 5
    replicaCount: 1
    resources: {}
    service:
      annotations: {}
      externalIPs: []
      loadBalancerIP: ""
      loadBalancerSourceRanges: []
      omitClusterIP: false
      servicePort: 80
      type: ClusterIP
    serviceAccount:
      create: true
    tolerations: []
    useComponentLabel: false
  global:
    chart:
      grafana: false
      postgres: true
      prometheus: true
      redis: true
      s3-gateway: true
      s3gateway: true
      thanos: true
    cloudProvider: aws
    createStorageClass: false
    domain: null
    enableAwsAlb:
      albType: internet-facing
      enabled: false
    enableMetricsServer: false
    environment:
      admin_email: flash-admin@foo.com
      admin_name: flash-admin@foo.com
      admin_org: flash-org
      admin_password: flash-password
      awsServiceEndpoint: https://s3.us-east-1.amazonaws.com
      cluster_id: LOGIQ
      license: license/license.jws
      logiq_flash_host: logiq-flash
      logiq_flash_port: 9999
      postgres_coffee_db: coffee
      postgres_db: postgres
      postgres_host: postgres
      postgres_password: postgres
      postgres_port: "5432"
      postgres_user: postgres
      redis_host: redis-master
      redis_opts: true
      redis_port: "6379"
      s3_access: logiq_access
      s3_bucket: logiq
      s3_region: us-east-1
      s3_secret: logiq_secret
      s3_url: http://s3-gateway:9000
      upload_dashboard: true
    job:
      ttlSecondsAfterFinished: 100
    kubeDistributor:
      enabled: false
    nodeSelectors:
      cache: cache
      db: db
      enabled: false
      infra: infra
      ingest: flash
      ingest_sync: sync
      other: coffee
    persistence:
      createStorageClass:
        enabled: true
      storageClass: microk8s-hostpath
    sharedSecretName: logiq-shared-secret
    taints:
      cache: cache
      db: db
      enabled: false
      infra: infra
      ingest: flash
      ingest_sync: sync
      other: coffee
    toolbox:
      image:
        repository: logiqai/toolbox
        tag: 2.0.1
  imagePullSecrets: []
  podSecurityPolicy:
    enabled: true
  rbac:
    create: true
    scope: false
  releaseLabelOverride: ""
  revisionHistoryLimit: 10
  serviceAccount:
    create: true
    name: ingress-nginx
  tcp:
    "7514": logiq-flash:7514
    "7515": logiq-flash:7515
    "8081": logiq-flash-ml:8081
    "9998": logiq-flash:9998
    "14250": logiq-flash:14250
    "20514": logiq-flash:20514
  udp: {}
logiq-flash:
  affinity: {}
  api:
    name: api
    port: 9999
  cefport:
    containerPort: 1515
    name: cefport
    port: 515
  cefportls:
    name: cefportls
    port: 7515
  configurationFiles: true
  discoveryService:
    name: flash-discovery
  filebeat:
    name: filebeat
    port: 25224
  filebeatls:
    name: filebeatls
    port: 25225
  fluentforward:
    name: fluentforward
    port: 24224
  fluentfwdtls:
    name: fluentfwdtls
    port: 24225
  global:
    chart:
      grafana: false
      postgres: true
      prometheus: true
      redis: true
      s3-gateway: true
      s3gateway: true
      thanos: true
    cloudProvider: aws
    createStorageClass: false
    domain: null
    enableAwsAlb:
      albType: internet-facing
      enabled: false
      flashAlbMlPort: "30923"
      flashAlbPort: "30444"
    enableMetricsServer: false
    environment:
      AWS_ACCESS_KEY_ID: AWS_ACCESS
      AWS_SECRET_ACCESS_KEY: AWS_SECRET
      admin_email: flash-admin@foo.com
      admin_name: flash-admin@foo.com
      admin_org: flash-org
      admin_password: flash-password
      awsServiceEndpoint: https://s3.us-east-1.amazonaws.com
      cluster_id: LOGIQ
      extraflag: ""
      license: license/license.jws
      logiq_flash_host: logiq-flash
      logiq_flash_port: 9999
      postgres_coffee_db: coffee
      postgres_db: postgres
      postgres_host: postgres
      postgres_password: postgres
      postgres_port: "5432"
      postgres_user: postgres
      redis_host: redis-master
      redis_opts: true
      redis_port: "6379"
      s3_access: logiq_access
      s3_bucket: logiq
      s3_region: us-east-1
      s3_secret: logiq_secret
      s3_url: http://s3-gateway:9000
      upload_dashboard: true
    job:
      ttlSecondsAfterFinished: 100
    kubeDistributor:
      enabled: false
    nodeSelectors:
      cache: cache
      db: db
      enabled: false
      infra: infra
      ingest: flash
      ingest_sync: sync
      other: coffee
    persistence:
      createStorageClass:
        enabled: true
      storageClass: microk8s-hostpath
    sharedSecretName: logiq-shared-secret
    taints:
      cache: cache
      db: db
      enabled: false
      infra: infra
      ingest: flash
      ingest_sync: sync
      other: coffee
    toolbox:
      image:
        repository: logiqai/toolbox
        tag: 2.0.1
  grpc:
    name: grpc
    port: 8081
  image:
    pullPolicy: IfNotPresent
    repository: logiqai/flash
    tag: v3.1
  liveness_port:
    name: liveness-port
    port: 8080
  metrics:
    selector:
      release: prometheus
    serviceMonitor:
      enabled: true
      selector:
        release: prometheus
  nodeSelector: {}
  persistence:
    accessMode: ReadWriteOnce
    enabled: true
    ml_size: 10Gi
    size: 10Gi
    storageClassName: standard
  podPerNode: false
  raft:
    name: raft
    port: 4002
  raftHttp:
    name: raft-http
    port: 4001
  rawtcp:
    containerPort: 1517
    name: rawtcp
    port: 517
  relp:
    name: relp
    port: 20514
  relptls:
    name: relptls
    port: 2514
  replicaCount: 1
  replicaCountMl: 1
  replicaCountSync: 1
  resources:
    ingest:
      limits:
        cpu: 1250m
      requests:
        cpu: 1250m
        memory: 512Mi
    ml:
      limits:
        cpu: 1000m
      requests:
        cpu: 500m
    sidecar:
      limits:
        memory: 1Gi
      requests:
        cpu: 500m
        memory: 1Gi
    sidecarTracing:
      limits:
        memory: 1Gi
      requests:
        cpu: 50m
        memory: 1Gi
    sidecarTracingMl:
      limits:
        memory: 1Gi
      requests:
        cpu: 50m
        memory: 1Gi
    sync:
      requests:
        cpu: 100m
  service:
    type: NodePort
  sidecarTracing:
    image: logiqai/tracing
    imagePullPolicy: Always
    tag: v1.35.2-lq1
  sidecarTracingMl:
    image: logiqai/tracing
    imagePullPolicy: Always
    tag: v1.35.2-lq1-q
  syslog:
    containerPort: 1514
    name: syslog
    port: 514
  syslogtls:
    name: syslogtls
    port: 7514
  tolerations: []
  tracinggrpc:
    name: tracinggrpc
    port: 14250
  tracingui:
    name: tracingui
    port: 16686
  webcli:
    name: webcli
    port: 9998
logiqctl:
  affinity: {}
  configurationFiles: true
  global:
    chart:
      grafana: false
      postgres: true
      prometheus: true
      redis: true
      s3-gateway: true
      s3gateway: true
      thanos: true
    cloudProvider: aws
    createStorageClass: false
    domain: null
    enableAwsAlb:
      albType: internet-facing
      enabled: false
    enableMetricsServer: false
    environment:
      admin_email: flash-admin@foo.com
      admin_name: flash-admin@foo.com
      admin_org: flash-org
      admin_password: flash-password
      awsServiceEndpoint: https://s3.us-east-1.amazonaws.com
      cluster_id: LOGIQ
      license: license/license.jws
      logiq_flash_host: logiq-flash
      logiq_flash_port: 9999
      postgres_coffee_db: coffee
      postgres_db: postgres
      postgres_host: postgres
      postgres_password: postgres
      postgres_port: "5432"
      postgres_user: postgres
      redis_host: redis-master
      redis_opts: true
      redis_port: "6379"
      s3_access: logiq_access
      s3_bucket: logiq
      s3_region: us-east-1
      s3_secret: logiq_secret
      s3_url: http://s3-gateway:9000
      upload_dashboard: true
    job:
      ttlSecondsAfterFinished: 100
    kubeDistributor:
      enabled: false
    nodeSelectors:
      cache: cache
      db: db
      enabled: false
      infra: infra
      ingest: flash
      ingest_sync: sync
      other: coffee
    persistence:
      createStorageClass:
        enabled: true
      storageClass: microk8s-hostpath
    sharedSecretName: logiq-shared-secret
    taints:
      cache: cache
      db: db
      enabled: false
      infra: infra
      ingest: flash
      ingest_sync: sync
      other: coffee
    toolbox:
      image:
        repository: logiqai/toolbox
        tag: 2.0.1
  image:
    pullPolicy: IfNotPresent
    repository: logiqai/logiqctl
    tag: 2.0.4
  nodeSelector: {}
  podPerNode: false
  resources:
    requests:
      cpu: 100m
      memory: 100Mi
  secrets: true
  service:
    nodePort: 318080
    port: 8080
    portName: http
    type: ClusterIP
  tolerations: []
  uploadDashboardJob: {}
postgres:
  enabled: true
  extraEnv: []
  fullnameOverride: postgres
  global:
    chart:
      grafana: false
      postgres: true
      prometheus: true
      redis: true
      s3-gateway: true
      s3gateway: true
      thanos: true
    cloudProvider: aws
    createStorageClass: false
    domain: null
    enableAwsAlb:
      albType: internet-facing
      enabled: false
    enableMetricsServer: false
    environment:
      admin_email: flash-admin@foo.com
      admin_name: flash-admin@foo.com
      admin_org: flash-org
      admin_password: flash-password
      awsServiceEndpoint: https://s3.us-east-1.amazonaws.com
      cluster_id: LOGIQ
      license: license/license.jws
      logiq_flash_host: logiq-flash
      logiq_flash_port: 9999
      postgres_coffee_db: coffee
      postgres_db: postgres
      postgres_host: postgres
      postgres_password: postgres
      postgres_port: "5432"
      postgres_user: postgres
      redis_host: redis-master
      redis_opts: true
      redis_port: "6379"
      s3_access: logiq_access
      s3_bucket: logiq
      s3_region: us-east-1
      s3_secret: logiq_secret
      s3_url: http://s3-gateway:9000
      upload_dashboard: true
    job:
      ttlSecondsAfterFinished: 100
    kubeDistributor:
      enabled: false
    nodeSelectors:
      cache: cache
      db: db
      enabled: false
      infra: infra
      ingest: flash
      ingest_sync: sync
      other: coffee
    persistence:
      createStorageClass:
        enabled: true
      storageClass: microk8s-hostpath
    postgresql: {}
    sharedSecretName: logiq-shared-secret
    taints:
      cache: cache
      db: db
      enabled: false
      infra: infra
      ingest: flash
      ingest_sync: sync
      other: coffee
    toolbox:
      image:
        repository: logiqai/toolbox
        tag: 2.0.1
  image:
    debug: false
    pullPolicy: IfNotPresent
    registry: docker.io
    repository: bitnami/postgresql
    tag: 12.3.0-debian-10-r18
  ldap:
    baseDN: ""
    bindDN: ""
    enabled: false
    port: ""
    prefix: ""
    scheme: ""
    search_attr: ""
    search_filter: ""
    server: ""
    suffix: ""
    tls: false
    url: ""
  livenessProbe:
    enabled: true
    failureThreshold: 6
    initialDelaySeconds: 30
    periodSeconds: 10
    successThreshold: 1
    timeoutSeconds: 5
  master:
    affinity: {}
    annotations: {}
    extraInitContainers: []
    extraVolumeMounts: []
    extraVolumes: []
    labels: {}
    nodeSelector: {}
    podAnnotations: {}
    podLabels: {}
    priorityClassName: ""
    service: {}
    sidecars: []
    tolerations: []
  metrics:
    additionalLabels:
      release: prometheus
    enabled: true
    image:
      pullPolicy: IfNotPresent
      registry: docker.io
      repository: bitnami/postgres-exporter
      tag: 0.8.0-debian-10-r72
    livenessProbe:
      enabled: true
      failureThreshold: 6
      initialDelaySeconds: 5
      periodSeconds: 10
      successThreshold: 1
      timeoutSeconds: 5
    prometheusRule:
      additionalLabels: {}
      enabled: false
      namespace: ""
      rules: []
    readinessProbe:
      enabled: true
      failureThreshold: 6
      initialDelaySeconds: 5
      periodSeconds: 10
      successThreshold: 1
      timeoutSeconds: 5
    securityContext:
      enabled: true
      runAsUser: 1001
    service:
      annotations:
        prometheus.io/port: "9187"
        prometheus.io/scrape: "true"
      type: ClusterIP
    serviceMonitor:
      additionalLabels: {}
      enabled: true
      interval: 1m
      scrapeTimeout: 10s
  networkPolicy:
    allowExternal: true
    enabled: false
    explicitNamespacesSelector: {}
  persistence:
    accessModes:
    - ReadWriteOnce
    annotations: {}
    enabled: true
    mountPath: /bitnami/postgresql
    size: 1Gi
    subPath: ""
  postgresqlDataDir: /bitnami/postgresql/data
  postgresqlDatabase: postgres
  postgresqlExtendedConf:
    maxConnections: "400"
    sharedBuffers: 1024MB
  postgresqlPassword: postgres
  postgresqlPostgresPassword: postgres
  postgresqlUsername: postgres
  readinessProbe:
    enabled: true
    failureThreshold: 6
    initialDelaySeconds: 5
    periodSeconds: 10
    successThreshold: 1
    timeoutSeconds: 5
  replication:
    applicationName: my_application
    enabled: false
    numSynchronousReplicas: 0
    password: repl_password
    slaveReplicas: 1
    synchronousCommit: "off"
    user: repl_user
  resources:
    requests:
      cpu: 100m
      memory: 0.5Gi
  securityContext:
    enabled: true
    fsGroup: 1001
    runAsUser: 1001
  service:
    annotations: {}
    port: 5432
    type: ClusterIP
  serviceAccount:
    enabled: true
    name: postgres
  shmVolume:
    chmod:
      enabled: true
    enabled: true
  slave:
    affinity: {}
    annotations: {}
    extraInitContainers: |
      # - name: do-something
      #   image: busybox
      #   command: ['do', 'something']
    extraVolumeMounts: []
    extraVolumes: []
    labels: {}
    nodeSelector: {}
    podAnnotations: {}
    podLabels: {}
    priorityClassName: ""
    service: {}
    sidecars: []
    tolerations: []
  updateStrategy:
    type: RollingUpdate
  volumePermissions:
    enabled: false
    image:
      pullPolicy: IfNotPresent
      registry: docker.io
      repository: bitnami/minideb
      tag: buster
    securityContext:
      runAsUser: 0
prometheus:
  alertmanager:
    additionalPeers: []
    affinity: {}
    config:
      global:
        resolve_timeout: 5m
      receivers:
      - name: "null"
      route:
        group_by:
        - job
        group_interval: 5m
        group_wait: 30s
        receiver: "null"
        repeat_interval: 12h
        routes:
        - match:
            alertname: Watchdog
          receiver: "null"
    configMaps: []
    configNamespaceSelector: {}
    configSelector: {}
    containerSecurityContext:
      allowPrivilegeEscalation: false
      capabilities:
        drop:
        - ALL
      enabled: true
      readOnlyRootFilesystem: false
      runAsNonRoot: true
    containers: []
    enabled: true
    externalConfig: false
    externalUrl: ""
    image:
      pullSecrets: []
      registry: docker.io
      repository: bitnami/alertmanager
      tag: 0.23.0-debian-10-r113
    ingress:
      annotations: {}
      apiVersion: ""
      enabled: false
      extraHosts: []
      extraPaths: []
      extraTls: []
      hostname: alertmanager.local
      ingressClassName: ""
      path: /
      pathType: ImplementationSpecific
      secrets: []
      tls: false
    listenLocal: false
    livenessProbe:
      enabled: true
      failureThreshold: 120
      initialDelaySeconds: 0
      path: /-/healthy
      periodSeconds: 25
      successThreshold: 1
      timeoutSeconds: 25
    logFormat: logfmt
    logLevel: info
    nodeAffinityPreset:
      key: ""
      type: ""
      values: []
    nodeSelector: {}
    paused: false
    persistence:
      accessModes:
      - ReadWriteOnce
      enabled: true
      size: 20Gi
      storageClass: ""
    podAffinityPreset: ""
    podAntiAffinityPreset: soft
    podDisruptionBudget:
      enabled: false
      maxUnavailable: ""
      minAvailable: 1
    podMetadata:
      annotations: {}
      labels: {}
    podSecurityContext:
      enabled: true
      fsGroup: 1001
      runAsUser: 1001
    portName: web
    priorityClassName: ""
    readinessProbe:
      enabled: true
      failureThreshold: 120
      initialDelaySeconds: 0
      path: /-/ready
      periodSeconds: 25
      successThreshold: 1
      timeoutSeconds: 25
    replicaCount: 1
    resources: {}
    retention: 120h
    routePrefix: /
    secrets: []
    service:
      annotations: {}
      clusterIP: ""
      externalTrafficPolicy: Cluster
      healthCheckNodePort: ""
      loadBalancerIP: ""
      loadBalancerSourceRanges: []
      nodePort: ""
      port: 9093
      stickySessions: ""
      type: ClusterIP
    serviceAccount:
      create: true
      name: ""
    serviceMonitor:
      enabled: true
      interval: ""
      metricRelabelings: []
      relabelings: []
    storageSpec: {}
    tolerations: []
    volumeMounts: []
    volumes: []
  common:
    exampleValue: common-chart
    global:
      chart:
        grafana: false
        postgres: true
        prometheus: true
        redis: true
        s3-gateway: true
        s3gateway: true
        thanos: true
      cloudProvider: aws
      createStorageClass: false
      domain: null
      enableAwsAlb:
        albType: internet-facing
        enabled: false
      enableMetricsServer: false
      environment:
        admin_email: flash-admin@foo.com
        admin_name: flash-admin@foo.com
        admin_org: flash-org
        admin_password: flash-password
        awsServiceEndpoint: https://s3.us-east-1.amazonaws.com
        cluster_id: LOGIQ
        license: license/license.jws
        logiq_flash_host: logiq-flash
        logiq_flash_port: 9999
        postgres_coffee_db: coffee
        postgres_db: postgres
        postgres_host: postgres
        postgres_password: postgres
        postgres_port: "5432"
        postgres_user: postgres
        redis_host: redis-master
        redis_opts: true
        redis_port: "6379"
        s3_access: logiq_access
        s3_bucket: logiq
        s3_region: us-east-1
        s3_secret: logiq_secret
        s3_url: http://s3-gateway:9000
        upload_dashboard: true
      imagePullSecrets: []
      imageRegistry: ""
      job:
        ttlSecondsAfterFinished: 100
      kubeDistributor:
        enabled: false
      labels: {}
      nodeSelectors:
        cache: cache
        db: db
        enabled: false
        infra: infra
        ingest: flash
        ingest_sync: sync
        other: coffee
      persistence:
        createStorageClass:
          enabled: true
        storageClass: microk8s-hostpath
      sharedSecretName: logiq-shared-secret
      storageClass: ""
      taints:
        cache: cache
        db: db
        enabled: false
        infra: infra
        ingest: flash
        ingest_sync: sync
        other: coffee
      toolbox:
        image:
          repository: logiqai/toolbox
          tag: 2.0.1
  coreDns:
    enabled: true
    namespace: kube-system
    service:
      enabled: true
      port: 9153
      selector: {}
      targetPort: 9153
    serviceMonitor:
      interval: ""
      metricRelabelings: []
      relabelings: []
  exporters:
    kube-state-metrics:
      enabled: true
    node-exporter:
      enabled: true
  extraDeploy: []
  fullnameOverride: prometheus
  global:
    chart:
      grafana: false
      postgres: true
      prometheus: true
      redis: true
      s3-gateway: true
      s3gateway: true
      thanos: true
    cloudProvider: aws
    createStorageClass: false
    domain: null
    enableAwsAlb:
      albType: internet-facing
      enabled: false
    enableMetricsServer: false
    environment:
      admin_email: flash-admin@foo.com
      admin_name: flash-admin@foo.com
      admin_org: flash-org
      admin_password: flash-password
      awsServiceEndpoint: https://s3.us-east-1.amazonaws.com
      cluster_id: LOGIQ
      license: license/license.jws
      logiq_flash_host: logiq-flash
      logiq_flash_port: 9999
      postgres_coffee_db: coffee
      postgres_db: postgres
      postgres_host: postgres
      postgres_password: postgres
      postgres_port: "5432"
      postgres_user: postgres
      redis_host: redis-master
      redis_opts: true
      redis_port: "6379"
      s3_access: logiq_access
      s3_bucket: logiq
      s3_region: us-east-1
      s3_secret: logiq_secret
      s3_url: http://s3-gateway:9000
      upload_dashboard: true
    imagePullSecrets: []
    imageRegistry: ""
    job:
      ttlSecondsAfterFinished: 100
    kubeDistributor:
      enabled: false
    labels: {}
    nodeSelectors:
      cache: cache
      db: db
      enabled: false
      infra: infra
      ingest: flash
      ingest_sync: sync
      other: coffee
    persistence:
      createStorageClass:
        enabled: true
      storageClass: microk8s-hostpath
    sharedSecretName: logiq-shared-secret
    storageClass: ""
    taints:
      cache: cache
      db: db
      enabled: false
      infra: infra
      ingest: flash
      ingest_sync: sync
      other: coffee
    toolbox:
      image:
        repository: logiqai/toolbox
        tag: 2.0.1
  kube-state-metrics:
    affinity: {}
    common:
      exampleValue: common-chart
      global:
        chart:
          grafana: false
          postgres: true
          prometheus: true
          redis: true
          s3-gateway: true
          s3gateway: true
          thanos: true
        cloudProvider: aws
        createStorageClass: false
        domain: null
        enableAwsAlb:
          albType: internet-facing
          enabled: false
        enableMetricsServer: false
        environment:
          admin_email: flash-admin@foo.com
          admin_name: flash-admin@foo.com
          admin_org: flash-org
          admin_password: flash-password
          awsServiceEndpoint: https://s3.us-east-1.amazonaws.com
          cluster_id: LOGIQ
          license: license/license.jws
          logiq_flash_host: logiq-flash
          logiq_flash_port: 9999
          postgres_coffee_db: coffee
          postgres_db: postgres
          postgres_host: postgres
          postgres_password: postgres
          postgres_port: "5432"
          postgres_user: postgres
          redis_host: redis-master
          redis_opts: true
          redis_port: "6379"
          s3_access: logiq_access
          s3_bucket: logiq
          s3_region: us-east-1
          s3_secret: logiq_secret
          s3_url: http://s3-gateway:9000
          upload_dashboard: true
        imagePullSecrets: []
        imageRegistry: ""
        job:
          ttlSecondsAfterFinished: 100
        kubeDistributor:
          enabled: false
        labels: {}
        nodeSelectors:
          cache: cache
          db: db
          enabled: false
          infra: infra
          ingest: flash
          ingest_sync: sync
          other: coffee
        persistence:
          createStorageClass:
            enabled: true
          storageClass: microk8s-hostpath
        sharedSecretName: logiq-shared-secret
        storageClass: ""
        taints:
          cache: cache
          db: db
          enabled: false
          infra: infra
          ingest: flash
          ingest_sync: sync
          other: coffee
        toolbox:
          image:
            repository: logiqai/toolbox
            tag: 2.0.1
    commonAnnotations: {}
    commonLabels: {}
    extraArgs: {}
    extraDeploy: []
    fullnameOverride: ""
    global:
      chart:
        grafana: false
        postgres: true
        prometheus: true
        redis: true
        s3-gateway: true
        s3gateway: true
        thanos: true
      cloudProvider: aws
      createStorageClass: false
      domain: null
      enableAwsAlb:
        albType: internet-facing
        enabled: false
      enableMetricsServer: false
      environment:
        admin_email: flash-admin@foo.com
        admin_name: flash-admin@foo.com
        admin_org: flash-org
        admin_password: flash-password
        awsServiceEndpoint: https://s3.us-east-1.amazonaws.com
        cluster_id: LOGIQ
        license: license/license.jws
        logiq_flash_host: logiq-flash
        logiq_flash_port: 9999
        postgres_coffee_db: coffee
        postgres_db: postgres
        postgres_host: postgres
        postgres_password: postgres
        postgres_port: "5432"
        postgres_user: postgres
        redis_host: redis-master
        redis_opts: true
        redis_port: "6379"
        s3_access: logiq_access
        s3_bucket: logiq
        s3_region: us-east-1
        s3_secret: logiq_secret
        s3_url: http://s3-gateway:9000
        upload_dashboard: true
      imagePullSecrets: []
      imageRegistry: ""
      job:
        ttlSecondsAfterFinished: 100
      kubeDistributor:
        enabled: false
      labels: {}
      nodeSelectors:
        cache: cache
        db: db
        enabled: false
        infra: infra
        ingest: flash
        ingest_sync: sync
        other: coffee
      persistence:
        createStorageClass:
          enabled: true
        storageClass: microk8s-hostpath
      sharedSecretName: logiq-shared-secret
      storageClass: ""
      taints:
        cache: cache
        db: db
        enabled: false
        infra: infra
        ingest: flash
        ingest_sync: sync
        other: coffee
      toolbox:
        image:
          repository: logiqai/toolbox
          tag: 2.0.1
    hostAliases: []
    hostNetwork: false
    image:
      pullPolicy: IfNotPresent
      pullSecrets: []
      registry: docker.io
      repository: bitnami/kube-state-metrics
      tag: 2.3.0-debian-10-r0
    kubeResources:
      certificatesigningrequests: true
      configmaps: true
      cronjobs: true
      daemonsets: true
      deployments: true
      endpoints: true
      horizontalpodautoscalers: true
      ingresses: true
      jobs: true
      limitranges: true
      mutatingwebhookconfigurations: true
      namespaces: true
      networkpolicies: true
      nodes: true
      persistentvolumeclaims: true
      persistentvolumes: true
      poddisruptionbudgets: true
      pods: true
      replicasets: true
      replicationcontrollers: true
      resourcequotas: true
      secrets: true
      services: true
      statefulsets: true
      storageclasses: true
      validatingwebhookconfigurations: false
      verticalpodautoscalers: false
      volumeattachments: true
    livenessProbe:
      enabled: true
      failureThreshold: 6
      initialDelaySeconds: 120
      periodSeconds: 10
      successThreshold: 1
      timeoutSeconds: 5
    minReadySeconds: 0
    nameOverride: ""
    namespaces: ""
    nodeAffinityPreset:
      key: ""
      type: ""
      values: []
    nodeSelector: {}
    podAffinityPreset: ""
    podAnnotations: {}
    podAntiAffinityPreset: soft
    podLabels: {}
    priorityClassName: ""
    rbac:
      apiVersion: v1beta1
      create: true
      pspEnabled: true
    readinessProbe:
      enabled: true
      failureThreshold: 6
      initialDelaySeconds: 30
      periodSeconds: 10
      successThreshold: 1
      timeoutSeconds: 5
    replicaCount: 1
    resources:
      limits: {}
      requests: {}
    securityContext:
      enabled: true
      fsGroup: 1001
      runAsUser: 1001
    service:
      annotations: {}
      clusterIP: ""
      labels: {}
      loadBalancerIP: ""
      loadBalancerSourceRanges: []
      nodePort: ""
      port: 8080
      type: ClusterIP
    serviceAccount:
      create: true
      name: ""
    serviceMonitor:
      enabled: true
      honorLabels: true
      interval: ""
      jobLabel: ""
      metricRelabelings: []
      namespace: ""
      relabelings: []
      scrapeTimeout: ""
      selector: {}
    tolerations: []
    updateStrategy: {}
  kubeApiServer:
    enabled: true
    serviceMonitor:
      interval: ""
      metricRelabelings: []
      relabelings: []
  kubeControllerManager:
    enabled: true
    endpoints: []
    namespace: kube-system
    service:
      enabled: true
      port: 10252
      selector: {}
      targetPort: 10252
    serviceMonitor:
      https: false
      insecureSkipVerify: ""
      interval: ""
      metricRelabelings: []
      relabelings: []
      serverName: ""
  kubeProxy:
    enabled: true
    endpoints: []
    namespace: kube-system
    service:
      enabled: true
      port: 10249
      selector: {}
      targetPort: 10249
    serviceMonitor:
      https: false
      interval: ""
      metricRelabelings: []
      relabelings: []
  kubeScheduler:
    enabled: true
    endpoints: []
    namespace: kube-system
    service:
      enabled: true
      port: 10251
      selector: {}
      targetPort: 10251
    serviceMonitor:
      https: false
      insecureSkipVerify: ""
      interval: ""
      metricRelabelings: []
      relabelings: []
      serverName: ""
  kubelet:
    enabled: true
    namespace: kube-system
    serviceMonitor:
      cAdvisorMetricRelabelings: []
      cAdvisorRelabelings: []
      https: true
      interval: ""
      metricRelabelings: []
      relabelings: []
  nameOverride: ""
  node-exporter:
    affinity: {}
    common:
      exampleValue: common-chart
      global:
        chart:
          grafana: false
          postgres: true
          prometheus: true
          redis: true
          s3-gateway: true
          s3gateway: true
          thanos: true
        cloudProvider: aws
        createStorageClass: false
        domain: null
        enableAwsAlb:
          albType: internet-facing
          enabled: false
        enableMetricsServer: false
        environment:
          admin_email: flash-admin@foo.com
          admin_name: flash-admin@foo.com
          admin_org: flash-org
          admin_password: flash-password
          awsServiceEndpoint: https://s3.us-east-1.amazonaws.com
          cluster_id: LOGIQ
          license: license/license.jws
          logiq_flash_host: logiq-flash
          logiq_flash_port: 9999
          postgres_coffee_db: coffee
          postgres_db: postgres
          postgres_host: postgres
          postgres_password: postgres
          postgres_port: "5432"
          postgres_user: postgres
          redis_host: redis-master
          redis_opts: true
          redis_port: "6379"
          s3_access: logiq_access
          s3_bucket: logiq
          s3_region: us-east-1
          s3_secret: logiq_secret
          s3_url: http://s3-gateway:9000
          upload_dashboard: true
        imagePullSecrets: []
        imageRegistry: ""
        job:
          ttlSecondsAfterFinished: 100
        kubeDistributor:
          enabled: false
        labels: {}
        nodeSelectors:
          cache: cache
          db: db
          enabled: false
          infra: infra
          ingest: flash
          ingest_sync: sync
          other: coffee
        persistence:
          createStorageClass:
            enabled: true
          storageClass: microk8s-hostpath
        sharedSecretName: logiq-shared-secret
        storageClass: ""
        taints:
          cache: cache
          db: db
          enabled: false
          infra: infra
          ingest: flash
          ingest_sync: sync
          other: coffee
        toolbox:
          image:
            repository: logiqai/toolbox
            tag: 2.0.1
    commonLabels: {}
    extraArgs:
      collector.filesystem.ignored-fs-types: ^(autofs|binfmt_misc|cgroup|configfs|debugfs|devpts|devtmpfs|fusectl|hugetlbfs|mqueue|overlay|proc|procfs|pstore|rpc_pipefs|securityfs|sysfs|tracefs)$
      collector.filesystem.ignored-mount-points: ^/(dev|proc|sys|var/lib/docker/.+)($|/)
    extraDeploy: []
    extraVolumeMounts: []
    extraVolumes: []
    fullnameOverride: ""
    global:
      chart:
        grafana: false
        postgres: true
        prometheus: true
        redis: true
        s3-gateway: true
        s3gateway: true
        thanos: true
      cloudProvider: aws
      createStorageClass: false
      domain: null
      enableAwsAlb:
        albType: internet-facing
        enabled: false
      enableMetricsServer: false
      environment:
        admin_email: flash-admin@foo.com
        admin_name: flash-admin@foo.com
        admin_org: flash-org
        admin_password: flash-password
        awsServiceEndpoint: https://s3.us-east-1.amazonaws.com
        cluster_id: LOGIQ
        license: license/license.jws
        logiq_flash_host: logiq-flash
        logiq_flash_port: 9999
        postgres_coffee_db: coffee
        postgres_db: postgres
        postgres_host: postgres
        postgres_password: postgres
        postgres_port: "5432"
        postgres_user: postgres
        redis_host: redis-master
        redis_opts: true
        redis_port: "6379"
        s3_access: logiq_access
        s3_bucket: logiq
        s3_region: us-east-1
        s3_secret: logiq_secret
        s3_url: http://s3-gateway:9000
        upload_dashboard: true
      imagePullSecrets: []
      imageRegistry: ""
      job:
        ttlSecondsAfterFinished: 100
      kubeDistributor:
        enabled: false
      labels: {}
      nodeSelectors:
        cache: cache
        db: db
        enabled: false
        infra: infra
        ingest: flash
        ingest_sync: sync
        other: coffee
      persistence:
        createStorageClass:
          enabled: true
        storageClass: microk8s-hostpath
      sharedSecretName: logiq-shared-secret
      storageClass: ""
      taints:
        cache: cache
        db: db
        enabled: false
        infra: infra
        ingest: flash
        ingest_sync: sync
        other: coffee
      toolbox:
        image:
          repository: logiqai/toolbox
          tag: 2.0.1
    hostAliases: []
    hostNetwork: true
    image:
      pullPolicy: IfNotPresent
      pullSecrets: []
      registry: docker.io
      repository: bitnami/node-exporter
      tag: 1.3.1-debian-10-r0
    livenessProbe:
      failureThreshold: 6
      initialDelaySeconds: 120
      periodSeconds: 10
      successThreshold: 1
      timeoutSeconds: 5
    minReadySeconds: 0
    nameOverride: ""
    nodeAffinityPreset:
      key: ""
      type: ""
      values: []
    nodeSelector: {}
    podAffinityPreset: ""
    podAnnotations: {}
    podAntiAffinityPreset: soft
    podLabels: {}
    priorityClassName: ""
    rbac:
      apiVersion: v1beta1
      create: true
      pspEnabled: true
    readinessProbe:
      failureThreshold: 6
      initialDelaySeconds: 30
      periodSeconds: 10
      successThreshold: 1
      timeoutSeconds: 5
    replicaCount: 1
    resources:
      limits: {}
      requests: {}
    securityContext:
      enabled: true
      fsGroup: 1001
      runAsUser: 1001
    service:
      addPrometheusScrapeAnnotation: true
      annotations: {}
      clusterIP: ""
      labels:
        jobLabel: node-exporter
      loadBalancerIP: ""
      loadBalancerSourceRanges: []
      nodePort: ""
      port: 9100
      targetPort: 9100
      type: ClusterIP
    serviceAccount:
      create: true
      name: ""
    serviceMonitor:
      enabled: true
      interval: ""
      jobLabel: jobLabel
      metricRelabelings: []
      namespace: ""
      relabelings: []
      scrapeTimeout: ""
      selector: {}
    tolerations: []
    updateStrategy:
      rollingUpdate:
        maxUnavailable: 1
      type: RollingUpdate
  operator:
    affinity: {}
    configReloaderResources: {}
    containerSecurityContext:
      allowPrivilegeEscalation: false
      capabilities:
        drop:
        - ALL
      enabled: true
      readOnlyRootFilesystem: false
      runAsNonRoot: true
    enabled: true
    extraArgs: []
    hostAliases: []
    image:
      pullPolicy: IfNotPresent
      pullSecrets: []
      registry: docker.io
      repository: bitnami/prometheus-operator
      tag: 0.53.1-debian-10-r0
    kubeletService:
      enabled: true
      namespace: kube-system
    livenessProbe:
      enabled: true
      failureThreshold: 6
      initialDelaySeconds: 120
      path: /metrics
      periodSeconds: 25
      successThreshold: 1
      timeoutSeconds: 25
    logFormat: logfmt
    logLevel: info
    nodeAffinityPreset:
      key: ""
      type: ""
      values: []
    nodeSelector: {}
    podAffinityPreset: ""
    podAntiAffinityPreset: soft
    podSecurityContext:
      enabled: true
      fsGroup: 1001
      runAsUser: 1001
    priorityClassName: ""
    prometheusConfigReloader:
      containerSecurityContext:
        allowPrivilegeEscalation: false
        capabilities:
          drop:
          - ALL
        enabled: true
        readOnlyRootFilesystem: false
        runAsNonRoot: true
      image: {}
      livenessProbe:
        enabled: true
        failureThreshold: 6
        initialDelaySeconds: 10
        periodSeconds: 10
        successThreshold: 1
        timeoutSeconds: 5
      readinessProbe:
        enabled: true
        failureThreshold: 6
        initialDelaySeconds: 15
        periodSeconds: 20
        successThreshold: 1
        timeoutSeconds: 5
    readinessProbe:
      enabled: true
      failureThreshold: 6
      initialDelaySeconds: 30
      path: /metrics
      periodSeconds: 25
      successThreshold: 1
      timeoutSeconds: 25
    replicaCount: 1
    resources: {}
    schedulerName: ""
    service:
      annotations: {}
      clusterIP: ""
      externalTrafficPolicy: Cluster
      healthCheckNodePort: ""
      loadBalancerIP: ""
      loadBalancerSourceRanges: []
      nodePort: ""
      port: 8080
      type: ClusterIP
    serviceAccount:
      create: true
      name: ""
    serviceMonitor:
      enabled: true
      interval: ""
      metricRelabelings: []
      relabelings: []
    tolerations: []
  persistence:
    enabled: true
    size: 20Gi
  prometheus:
    additionalAlertRelabelConfigsExternal:
      enabled: false
      key: ""
      name: ""
    additionalPrometheusRules: []
    additionalScrapeConfigs:
      enabled: false
      external:
        key: ""
        name: ""
      internal:
        jobList: []
      type: external
    additionalScrapeConfigsExternal:
      enabled: false
      key: ""
      name: ""
    affinity: {}
    alertingEndpoints: []
    configMaps: []
    containerSecurityContext:
      allowPrivilegeEscalation: false
      capabilities:
        drop:
        - ALL
      enabled: true
      readOnlyRootFilesystem: false
      runAsNonRoot: true
    containers: []
    disableCompaction: false
    enableAdminAPI: false
    enableFeatures: []
    enabled: true
    evaluationInterval: ""
    externalLabels: {}
    externalUrl: ""
    image:
      pullSecrets: []
      registry: docker.io
      repository: bitnami/prometheus
      tag: 2.32.1-debian-10-r2
    ingress:
      annotations: {}
      apiVersion: ""
      enabled: false
      extraHosts: []
      extraPaths: []
      extraTls: []
      hostname: prometheus.local
      ingressClassName: ""
      path: /
      pathType: ImplementationSpecific
      secrets: []
      tls: false
    listenLocal: false
    livenessProbe:
      enabled: true
      failureThreshold: 10
      initialDelaySeconds: 0
      path: /-/healthy
      periodSeconds: 10
      successThreshold: 1
      timeoutSeconds: 3
    logFormat: logfmt
    logLevel: info
    matchLabels: {}
    nodeAffinityPreset:
      key: ""
      type: ""
      values: []
    nodeSelector: {}
    paused: false
    persistence:
      accessModes:
      - ReadWriteOnce
      enabled: true
      size: 20Gi
      storageClass: ""
    podAffinityPreset: ""
    podAntiAffinityPreset: soft
    podDisruptionBudget:
      enabled: false
      maxUnavailable: ""
      minAvailable: 1
    podMetadata:
      annotations: {}
      labels: {}
    podMonitorNamespaceSelector: {}
    podMonitorSelector: {}
    podSecurityContext:
      enabled: true
      fsGroup: 1001
      runAsUser: 1001
    portName: web
    priorityClassName: ""
    probeNamespaceSelector: {}
    probeSelector: {}
    prometheusExternalLabelName: ""
    prometheusExternalLabelNameClear: false
    querySpec: {}
    readinessProbe:
      enabled: true
      failureThreshold: 10
      initialDelaySeconds: 0
      path: /-/ready
      periodSeconds: 10
      successThreshold: 1
      timeoutSeconds: 3
    remoteRead: []
    remoteWrite: []
    replicaCount: 1
    replicaExternalLabelName: ""
    replicaExternalLabelNameClear: false
    resources: {}
    retention: 30d
    retentionSize: ""
    routePrefix: /
    ruleNamespaceSelector: {}
    ruleSelector: {}
    scrapeInterval: ""
    secrets: []
    service:
      annotations: {}
      clusterIP: ""
      externalTrafficPolicy: Cluster
      healthCheckNodePort: ""
      loadBalancerIP: ""
      loadBalancerSourceRanges: []
      nodePort: ""
      port: 9090
      stickySessions: ""
      type: ClusterIP
    serviceAccount:
      annotations: {}
      create: true
      name: ""
    serviceMonitor:
      enabled: true
      interval: ""
      metricRelabelings: []
      relabelings: []
    serviceMonitorNamespaceSelector: {}
    serviceMonitorSelector: {}
    storageSpec: {}
    thanos:
      containerSecurityContext:
        allowPrivilegeEscalation: false
        capabilities:
          drop:
          - ALL
        enabled: true
        readOnlyRootFilesystem: false
        runAsNonRoot: true
      create: true
      extraArgs: []
      extraVolumeMounts: []
      image:
        pullPolicy: IfNotPresent
        pullSecrets: []
        registry: docker.io
        repository: bitnami/thanos
        tag: 0.23.1-scratch-r4
      ingress:
        annotations: {}
        enabled: false
        hosts:
        - name: thanos.prometheus.local
          path: /
        ingressClassName: ""
        tls: {}
      livenessProbe:
        enabled: true
        failureThreshold: 120
        initialDelaySeconds: 0
        path: /-/healthy
        periodSeconds: 25
        successThreshold: 1
        timeoutSeconds: 25
      objectStorageConfig:
        secretKey: thanos.yaml
        secretName: thanos-objectstorage-config
      prometheusUrl: ""
      readinessProbe:
        enabled: true
        failureThreshold: 120
        initialDelaySeconds: 0
        path: /-/ready
        periodSeconds: 25
        successThreshold: 1
        timeoutSeconds: 25
      resources:
        limits: {}
        requests: {}
      service:
        annotations: {}
        clusterIP: None
        extraPorts: []
        loadBalancerIP: ""
        loadBalancerSourceRanges: []
        nodePort: ""
        port: 10901
        type: ClusterIP
    tolerations: []
    volumeMounts: []
    volumes: []
    walCompression: false
  rbac:
    apiVersion: v1beta1
    create: true
    pspEnabled: true
  replicaCount: 1
prometheus-operator:
  alertmenager:
    replicaCount: 1
  fullnameOverride: prometheus
  persistence:
    enabled: true
    size: 10Gi
  prometheus:
    replicaCount: 1
redis:
  cluster:
    enabled: false
    slaveCount: 1
  clusterDomain: cluster.local
  configmap: |-
    # Enable AOF https://redis.io/topics/persistence#append-only-file
    appendonly no
    # Disable RDB persistence, AOF persistence already enabled.
    save ""
    repl-diskless-sync yes
  enabled: true
  fullnameOverride: redis
  global:
    chart:
      grafana: false
      postgres: true
      prometheus: true
      redis: true
      s3-gateway: true
      s3gateway: true
      thanos: true
    cloudProvider: aws
    createStorageClass: false
    domain: null
    enableAwsAlb:
      albType: internet-facing
      enabled: false
    enableMetricsServer: false
    environment:
      admin_email: flash-admin@foo.com
      admin_name: flash-admin@foo.com
      admin_org: flash-org
      admin_password: flash-password
      awsServiceEndpoint: https://s3.us-east-1.amazonaws.com
      cluster_id: LOGIQ
      license: license/license.jws
      logiq_flash_host: logiq-flash
      logiq_flash_port: 9999
      postgres_coffee_db: coffee
      postgres_db: postgres
      postgres_host: postgres
      postgres_password: postgres
      postgres_port: "5432"
      postgres_user: postgres
      redis_host: redis-master
      redis_opts: true
      redis_port: "6379"
      s3_access: logiq_access
      s3_bucket: logiq
      s3_region: us-east-1
      s3_secret: logiq_secret
      s3_url: http://s3-gateway:9000
      upload_dashboard: true
    job:
      ttlSecondsAfterFinished: 100
    kubeDistributor:
      enabled: false
    nodeSelectors:
      cache: cache
      db: db
      enabled: false
      infra: infra
      ingest: flash
      ingest_sync: sync
      other: coffee
    persistence:
      createStorageClass:
        enabled: true
      storageClass: microk8s-hostpath
    redis: {}
    sharedSecretName: logiq-shared-secret
    taints:
      cache: cache
      db: db
      enabled: false
      infra: infra
      ingest: flash
      ingest_sync: sync
      other: coffee
    toolbox:
      image:
        repository: logiqai/toolbox
        tag: 2.0.1
  image:
    pullPolicy: IfNotPresent
    registry: docker.io
    repository: bitnami/redis
    tag: 6.0.4-debian-10-r6
  master:
    affinity:
      podAntiAffinity:
        requiredDuringSchedulingIgnoredDuringExecution:
        - labelSelector:
            matchExpressions:
            - key: app
              operator: In
              values:
              - redis
          topologyKey: kubernetes.io/hostname
    command: /run.sh
    customLivenessProbe: {}
    customReadinessProbe: {}
    disableCommands: []
    extraFlags: []
    livenessProbe:
      enabled: true
      failureThreshold: 5
      initialDelaySeconds: 5
      periodSeconds: 5
      successThreshold: 1
      timeoutSeconds: 5
    persistence:
      accessModes:
      - ReadWriteOnce
      enabled: false
      matchExpressions: {}
      matchLabels: {}
      path: /data
      size: 8Gi
      subPath: ""
    podAnnotations: {}
    podLabels: {}
    readinessProbe:
      enabled: true
      failureThreshold: 5
      initialDelaySeconds: 5
      periodSeconds: 5
      successThreshold: 1
      timeoutSeconds: 1
    service:
      annotations: {}
      labels: {}
      port: 6379
      type: ClusterIP
    statefulset:
      updateStrategy: RollingUpdate
  metrics:
    enabled: true
    image:
      pullPolicy: IfNotPresent
      registry: docker.io
      repository: bitnami/redis-exporter
      tag: 1.5.2-debian-10-r24
    podAnnotations:
      prometheus.io/port: "9121"
      prometheus.io/scrape: "true"
    prometheusRule:
      additionalLabels: {}
      enabled: false
      namespace: ""
      rules: []
    selector:
      release: prometheus
    service:
      annotations: {}
      labels: {}
      type: ClusterIP
    serviceMonitor:
      enabled: true
      interval: 1m
      selector:
        prometheus: kube-prometheus
        release: prometheus
  networkPolicy:
    enabled: false
    ingressNSMatchLabels: {}
    ingressNSPodMatchLabels: {}
  password: ""
  persistence: {}
  podSecurityPolicy:
    create: true
    rbac:
      create: true
      role:
        rules:
        - apiGroups:
          - policy
          resourceNames:
          - redis
          resources:
          - podsecuritypolicies
          verbs:
          - use
  rbac:
    create: true
    role:
      rules: []
  redisPort: 6379
  securityContext:
    enable: true
    enabled: true
    fsGroup: 1001
    runAsUser: 1001
  sentinel:
    customLivenessProbe: {}
    customReadinessProbe: {}
    downAfterMilliseconds: 60000
    enabled: false
    failoverTimeout: 18000
    image:
      pullPolicy: IfNotPresent
      registry: docker.io
      repository: bitnami/redis-sentinel
      tag: 5.0.8-debian-10-r28
    initialCheckTimeout: 5
    livenessProbe:
      enabled: true
      failureThreshold: 5
      initialDelaySeconds: 5
      periodSeconds: 5
      successThreshold: 1
      timeoutSeconds: 5
    masterSet: mymaster
    parallelSyncs: 1
    port: 26379
    quorum: 2
    readinessProbe:
      enabled: true
      failureThreshold: 5
      initialDelaySeconds: 5
      periodSeconds: 5
      successThreshold: 1
      timeoutSeconds: 1
    service:
      annotations: {}
      labels: {}
      redisPort: 6379
      sentinelPort: 26379
      type: ClusterIP
    staticID: false
    usePassword: true
  serviceAccount:
    create: true
    name: redis
  slave:
    affinity:
      podAntiAffinity:
        requiredDuringSchedulingIgnoredDuringExecution:
        - labelSelector:
            matchExpressions:
            - key: app
              operator: In
              values:
              - redis
          topologyKey: kubernetes.io/hostname
    command: /run.sh
    customLivenessProbe: {}
    customReadinessProbe: {}
    disableCommands: []
    extraFlags: []
    livenessProbe:
      enabled: true
      failureThreshold: 5
      initialDelaySeconds: 30
      periodSeconds: 10
      successThreshold: 1
      timeoutSeconds: 5
    persistence:
      accessModes:
      - ReadWriteOnce
      enabled: false
      matchExpressions: {}
      matchLabels: {}
      path: /data
      size: 8Gi
      subPath: ""
    podAnnotations: {}
    podLabels: {}
    port: 6379
    readinessProbe:
      enabled: true
      failureThreshold: 5
      initialDelaySeconds: 5
      periodSeconds: 10
      successThreshold: 1
      timeoutSeconds: 10
    service:
      annotations: {}
      labels: {}
      port: 6379
      type: ClusterIP
    statefulset:
      updateStrategy: RollingUpdate
  sysctlImage:
    command: []
    enabled: false
    mountHostSys: false
    pullPolicy: IfNotPresent
    registry: docker.io
    repository: bitnami/minideb
    resources: {}
    tag: buster
  usePassword: false
  usePasswordFile: false
  volumePermissions:
    enabled: false
    image:
      pullPolicy: IfNotPresent
      registry: docker.io
      repository: bitnami/minideb
      tag: buster
    resources: {}
s3-gateway:
  accessKey: logiq_access
  buckets:
  - name: logiq
    policy: none
    purge: false
  defaultBucket:
    enabled: true
  fullnameOverride: s3-gateway
  gcsgateway:
    enabled: false
    replicas: 1
  metrics:
    serviceMonitor:
      enabled: false
  mode: standalone
  persistence:
    enabled: true
    size: 1Gi
  resources:
    requests:
      cpu: 100m
      memory: 0.2Gi
  s3gateway:
    enabled: false
    replicas: 1
  secretKey: logiq_secret
  securityContext:
    enabled: true
    fsGroup: 1000
    runAsGroup: 1000
    runAsUser: 1000
  serviceAccount:
    create: true
    name: s3-gateway
s3gateway:
  DeploymentUpdate:
    maxSurge: 100%
    maxUnavailable: 0
    type: RollingUpdate
  StatefulSetUpdate:
    updateStrategy: RollingUpdate
  accessKey: logiq_access
  affinity: {}
  azuregateway:
    enabled: false
    replicas: 4
  b2gateway:
    enabled: false
    replicas: 4
  bucketRoot: ""
  buckets:
  - name: logiq
    policy: none
    purge: false
  certsPath: /etc/minio/certs/
  clusterDomain: cluster.local
  configPathmc: /etc/minio/mc/
  defaultBucket:
    enabled: true
    name: bucket
    policy: none
    purge: false
  drivesPerNode: 1
  extraArgs: []
  fullnameOverride: s3-gateway
  gcsgateway:
    enabled: false
    gcsKeyJson: ""
    projectId: ""
    replicas: 4
  global:
    chart:
      grafana: false
      postgres: true
      prometheus: true
      redis: true
      s3-gateway: true
      s3gateway: true
      thanos: true
    cloudProvider: aws
    createStorageClass: false
    domain: null
    enableAwsAlb:
      albType: internet-facing
      enabled: false
    enableMetricsServer: false
    environment:
      admin_email: flash-admin@foo.com
      admin_name: flash-admin@foo.com
      admin_org: flash-org
      admin_password: flash-password
      awsServiceEndpoint: https://s3.us-east-1.amazonaws.com
      cluster_id: LOGIQ
      license: license/license.jws
      logiq_flash_host: logiq-flash
      logiq_flash_port: 9999
      postgres_coffee_db: coffee
      postgres_db: postgres
      postgres_host: postgres
      postgres_password: postgres
      postgres_port: "5432"
      postgres_user: postgres
      redis_host: redis-master
      redis_opts: true
      redis_port: "6379"
      s3_access: logiq_access
      s3_bucket: logiq
      s3_region: us-east-1
      s3_secret: logiq_secret
      s3_url: http://s3-gateway:9000
      upload_dashboard: true
    job:
      ttlSecondsAfterFinished: 100
    kubeDistributor:
      enabled: false
    nodeSelectors:
      cache: cache
      db: db
      enabled: false
      infra: infra
      ingest: flash
      ingest_sync: sync
      other: coffee
    persistence:
      createStorageClass:
        enabled: true
      storageClass: microk8s-hostpath
    sharedSecretName: logiq-shared-secret
    taints:
      cache: cache
      db: db
      enabled: false
      infra: infra
      ingest: flash
      ingest_sync: sync
      other: coffee
    toolbox:
      image:
        repository: logiqai/toolbox
        tag: 2.0.1
  helmKubectlJqImage:
    pullPolicy: IfNotPresent
    repository: bskim45/helm-kubectl-jq
    tag: 3.1.0
  image:
    pullPolicy: IfNotPresent
    repository: minio/minio
    tag: RELEASE.2020-09-17T04-49-20Z
  ingress:
    annotations: {}
    enabled: false
    hosts:
    - chart-example.local
    labels: {}
    path: /
    tls: []
  livenessProbe:
    failureThreshold: 3
    initialDelaySeconds: 5
    periodSeconds: 30
    successThreshold: 1
    timeoutSeconds: 1
  makeBucketJob: {}
  mcImage:
    pullPolicy: IfNotPresent
    repository: minio/mc
    tag: RELEASE.2020-03-14T01-23-37Z
  metrics:
    serviceMonitor:
      additionalLabels: {}
      enabled: false
      interval: 60s
      scrapeTimeout: 10s
  mode: distributed
  mountPath: /export
  nameOverride: ""
  nasgateway:
    enabled: false
    replicas: 4
  networkPolicy:
    allowExternal: true
    enabled: false
  nodeSelector: {}
  ossgateway:
    enabled: false
    endpointURL: ""
    replicas: 4
  persistence:
    VolumeName: ""
    accessMode: ReadWriteOnce
    enabled: true
    existingClaim: ""
    size: 25Gi
    storageClass: ""
    subPath: ""
  podAnnotations: {}
  podDisruptionBudget:
    enabled: false
    maxUnavailable: 1
  podLabels: {}
  priorityClassName: ""
  readinessProbe:
    failureThreshold: 3
    initialDelaySeconds: 60
    periodSeconds: 15
    successThreshold: 1
    timeoutSeconds: 1
  replicas: 4
  resources: {}
  s3gateway:
    enabled: false
    replicas: 4
    serviceEndpoint: ""
  secretKey: logiq_secret
  securityContext:
    enabled: true
    fsGroup: 1000
    runAsGroup: 1000
    runAsUser: 1000
  service:
    annotations: {}
    externalIPs: []
    nodePort: 31311
    port: 9000
    type: ClusterIP
  serviceAccount:
    create: true
    name: s3-gateway
  tls:
    certSecret: ""
    enabled: false
    privateKey: private.key
    publicCrt: public.crt
  tolerations: []
  updatePrometheusJob: {}
  zones: 1
thanos:
  bucketCacheConfig: ""
  bucketweb:
    affinity: {}
    args: []
    autoscaling:
      enabled: false
      maxReplicas: ""
      minReplicas: ""
      targetCPU: ""
      targetMemory: ""
    command: []
    containerSecurityContext:
      allowPrivilegeEscalation: false
      enabled: true
      readOnlyRootFilesystem: false
      runAsNonRoot: true
      runAsUser: 1001
    customLivenessProbe: {}
    customReadinessProbe: {}
    customStartupProbe: {}
    enabled: true
    extraEnvVars: []
    extraEnvVarsCM: ""
    extraEnvVarsSecret: ""
    extraFlags: []
    extraVolumeMounts: []
    extraVolumes: []
    hostAliases: []
    ingress:
      annotations: {}
      apiVersion: ""
      enabled: false
      extraHosts: []
      extraTls: []
      hostname: thanos-bucketweb.local
      ingressClassName: ""
      path: /
      pathType: ImplementationSpecific
      secrets: []
      selfSigned: false
      tls: false
    initContainers: []
    lifecycleHooks: {}
    livenessProbe:
      enabled: true
      failureThreshold: 6
      initialDelaySeconds: 30
      periodSeconds: 10
      successThreshold: 1
      timeoutSeconds: 30
    logFormat: logfmt
    logLevel: info
    nodeAffinityPreset:
      key: ""
      type: ""
      values: []
    nodeSelector: {}
    pdb:
      create: false
      maxUnavailable: ""
      minAvailable: 1
    podAffinityPreset: ""
    podAnnotations: {}
    podAntiAffinityPreset: soft
    podLabels: {}
    podSecurityContext:
      enabled: true
      fsGroup: 1001
    priorityClassName: ""
    readinessProbe:
      enabled: true
      failureThreshold: 6
      initialDelaySeconds: 30
      periodSeconds: 10
      successThreshold: 1
      timeoutSeconds: 30
    refresh: 30m
    replicaCount: 1
    resources:
      limits: {}
      requests: {}
    schedulerName: ""
    service:
      annotations: {}
      clusterIP: ""
      externalTrafficPolicy: Cluster
      extraPorts: []
      labelSelectorsOverride: {}
      loadBalancerIP: ""
      loadBalancerSourceRanges: []
      nodePorts:
        http: ""
      ports:
        http: 8080
      type: ClusterIP
    serviceAccount:
      annotations: {}
      automountServiceAccountToken: true
      existingServiceAccount: ""
    sidecars: []
    startupProbe:
      enabled: false
      failureThreshold: 15
      initialDelaySeconds: 5
      periodSeconds: 5
      successThreshold: 1
      timeoutSeconds: 1
    timeout: 5m
    tolerations: []
    topologySpreadConstraints: []
    updateStrategy:
      type: RollingUpdate
  clusterDomain: cluster.local
  commonAnnotations: {}
  commonLabels: {}
  compactor:
    affinity: {}
    args: []
    command: []
    consistencyDelay: 30m
    containerSecurityContext:
      allowPrivilegeEscalation: false
      enabled: true
      readOnlyRootFilesystem: false
      runAsNonRoot: true
      runAsUser: 1001
    customLivenessProbe: {}
    customReadinessProbe: {}
    customStartupProbe: {}
    enabled: true
    extraEnvVars: []
    extraEnvVarsCM: ""
    extraEnvVarsSecret: ""
    extraFlags: []
    extraVolumeMounts: []
    extraVolumes: []
    hostAliases: []
    ingress:
      annotations: {}
      apiVersion: ""
      enabled: false
      extraHosts: []
      extraTls: []
      hostname: thanos-compactor.local
      ingressClassName: ""
      path: /
      pathType: ImplementationSpecific
      secrets: []
      selfSigned: false
      tls: false
    initContainers: []
    lifecycleHooks: {}
    livenessProbe:
      enabled: true
      failureThreshold: 6
      initialDelaySeconds: 30
      periodSeconds: 10
      successThreshold: 1
      timeoutSeconds: 30
    logFormat: logfmt
    logLevel: info
    nodeAffinityPreset:
      key: ""
      type: ""
      values: []
    nodeSelector: {}
    persistence:
      accessModes:
      - ReadWriteOnce
      annotations: {}
      enabled: true
      existingClaim: ""
      size: 8Gi
      storageClass: ""
    podAffinityPreset: ""
    podAnnotations: {}
    podAntiAffinityPreset: soft
    podLabels: {}
    podSecurityContext:
      enabled: true
      fsGroup: 1001
    priorityClassName: ""
    readinessProbe:
      enabled: true
      failureThreshold: 6
      initialDelaySeconds: 30
      periodSeconds: 10
      successThreshold: 1
      timeoutSeconds: 30
    resources:
      limits: {}
      requests: {}
    retentionResolution1h: 10y
    retentionResolution5m: 30d
    retentionResolutionRaw: 30d
    schedulerName: ""
    service:
      annotations: {}
      clusterIP: ""
      externalTrafficPolicy: Cluster
      extraPorts: []
      labelSelectorsOverride: {}
      loadBalancerIP: ""
      loadBalancerSourceRanges: []
      nodePorts:
        http: ""
      ports:
        http: 9090
      type: ClusterIP
    serviceAccount:
      annotations: {}
      automountServiceAccountToken: true
      existingServiceAccount: ""
    sidecars: []
    startupProbe:
      enabled: false
      failureThreshold: 15
      initialDelaySeconds: 5
      periodSeconds: 5
      successThreshold: 1
      timeoutSeconds: 1
    tolerations: []
    topologySpreadConstraints: []
    updateStrategy:
      type: Recreate
  existingObjstoreSecret: ""
  existingObjstoreSecretItems: []
  existingServiceAccount: ""
  extraDeploy: []
  fullnameOverride: ""
  global:
    chart:
      grafana: false
      postgres: true
      prometheus: true
      redis: true
      s3-gateway: true
      s3gateway: true
      thanos: true
    cloudProvider: aws
    createStorageClass: false
    domain: null
    enableAwsAlb:
      albType: internet-facing
      enabled: false
      flashThanosPort: "30369"
    enableMetricsServer: false
    environment:
      admin_email: flash-admin@foo.com
      admin_name: flash-admin@foo.com
      admin_org: flash-org
      admin_password: flash-password
      awsServiceEndpoint: https://s3.us-east-1.amazonaws.com
      cluster_id: LOGIQ
      license: license/license.jws
      logiq_flash_host: logiq-flash
      logiq_flash_port: 9999
      postgres_coffee_db: coffee
      postgres_db: postgres
      postgres_host: postgres
      postgres_password: postgres
      postgres_port: "5432"
      postgres_user: postgres
      redis_host: redis-master
      redis_opts: true
      redis_port: "6379"
      s3_access: logiq_access
      s3_bucket: logiq
      s3_region: us-east-1
      s3_secret: logiq_secret
      s3_url: http://s3-gateway:9000
      upload_dashboard: true
    job:
      ttlSecondsAfterFinished: 100
    kubeDistributor:
      enabled: false
    nodeSelectors:
      cache: cache
      db: db
      enabled: false
      infra: infra
      ingest: flash
      ingest_sync: sync
      other: coffee
    persistence:
      createStorageClass:
        enabled: true
      storageClass: microk8s-hostpath
    sharedSecretName: logiq-shared-secret
    taints:
      cache: cache
      db: db
      enabled: false
      infra: infra
      ingest: flash
      ingest_sync: sync
      other: coffee
    toolbox:
      image:
        repository: logiqai/toolbox
        tag: 2.0.1
  image:
    pullPolicy: IfNotPresent
    pullSecrets: []
    registry: docker.io
    repository: bitnami/thanos
    tag: 0.24.0-scratch-r0
  indexCacheConfig: ""
  kubeVersion: ""
  metrics:
    enabled: true
    prometheusRule:
      additionalLabels: {}
      enabled: false
      namespace: ""
      rules: []
    serviceMonitor:
      enabled: true
      interval: ""
      jobLabel: ""
      labels: {}
      metricRelabelings: []
      namespace: ""
      relabelings: []
      scrapeTimeout: ""
      selector: {}
  minio:
    auth:
      rootPassword: ""
      rootUser: admin
    defaultBuckets: thanos
    enabled: false
  nameOverride: ""
  networkPolicy:
    allowExternal: true
    enabled: false
    explicitNamespacesSelector: {}
  objstoreConfig: |-
    type: s3
    config:
    {{ if .Values.global.environment.AWS_ACCESS_KEY_ID }}
      access_key: {{ if .Values.global.environment.AWS_ACCESS_KEY_ID }}{{ .Values.global.environment.AWS_ACCESS_KEY_ID }}{{ end }}
      secret_key: {{ if .Values.global.environment.AWS_SECRET_ACCESS_KEY }}{{ .Values.global.environment.AWS_SECRET_ACCESS_KEY }}{{ end }}
    {{ else }}
      access_key: {{ if .Values.global.environment.s3_access }}{{ .Values.global.environment.s3_access }} {{ end }}
      secret_key: {{ if .Values.global.environment.s3_secret }}{{ .Values.global.environment.s3_secret }} {{ end }}
    {{ end }}
      bucket: {{ if .Values.global.environment.s3_bucket }}{{ .Values.global.environment.s3_bucket }} {{ end }}
    {{ if .Values.global.chart.s3gateway }}
      endpoint: {{ if .Values.global.environment.s3_url }}{{ .Values.global.environment.s3_url | replace "http://" "" }} {{ end }}
      insecure: true
    {{ else if eq .Values.global.cloudProvider "aws" }}
      endpoint: {{ required "AWS S3 Endpoint" .Values.global.environment.awsServiceEndpoint | replace "http://" "" | replace "https://" "" }}
    {{ end }}
      region: {{ if .Values.global.environment.s3_region }}{{ .Values.global.environment.s3_region }} {{ end }}
  query:
    affinity: {}
    args: []
    autoscaling:
      enabled: false
      maxReplicas: ""
      minReplicas: ""
      targetCPU: ""
      targetMemory: ""
    command: []
    containerSecurityContext:
      allowPrivilegeEscalation: false
      enabled: true
      readOnlyRootFilesystem: false
      runAsNonRoot: true
      runAsUser: 1001
    customLivenessProbe: {}
    customReadinessProbe: {}
    customStartupProbe: {}
    dnsDiscovery:
      enabled: true
      sidecarsNamespace: logiq
      sidecarsService: logiq-prometheus-prometheus-thanos
    enabled: true
    existingSDConfigmap: ""
    extraEnvVars: []
    extraEnvVarsCM: ""
    extraEnvVarsSecret: ""
    extraFlags: []
    extraVolumeMounts: []
    extraVolumes: []
    grpc:
      client:
        serverName: ""
        tls:
          autoGenerated: false
          ca: ""
          cert: ""
          enabled: false
          existingSecret: {}
          key: ""
      server:
        tls:
          autoGenerated: false
          ca: ""
          cert: ""
          enabled: false
          existingSecret: {}
          key: ""
    hostAliases: []
    ingress:
      annotations: {}
      apiVersion: ""
      enabled: false
      extraHosts: []
      extraTls: []
      grpc:
        annotations: {}
        apiVersion: ""
        enabled: false
        extraHosts: []
        extraTls: []
        hostname: thanos-grpc.local
        ingressClassName: ""
        path: /
        pathType: ImplementationSpecific
        secrets: []
        selfSigned: false
        tls: false
      hostname: thanos.local
      ingressClassName: ""
      path: /
      pathType: ImplementationSpecific
      secrets: []
      selfSigned: false
      tls: false
    initContainers: []
    lifecycleHooks: {}
    livenessProbe:
      enabled: true
      failureThreshold: 6
      initialDelaySeconds: 30
      periodSeconds: 10
      successThreshold: 1
      timeoutSeconds: 30
    logFormat: logfmt
    logLevel: info
    nodeAffinityPreset:
      key: ""
      type: ""
      values: []
    nodeSelector: {}
    pdb:
      create: false
      maxUnavailable: ""
      minAvailable: 1
    podAffinityPreset: ""
    podAnnotations: {}
    podAntiAffinityPreset: soft
    podLabels: {}
    podSecurityContext:
      enabled: true
      fsGroup: 1001
    priorityClassName: ""
    pspEnabled: false
    rbac:
      create: false
      rules: []
    readinessProbe:
      enabled: true
      failureThreshold: 6
      initialDelaySeconds: 30
      periodSeconds: 10
      successThreshold: 1
      timeoutSeconds: 30
    replicaCount: 1
    replicaLabel:
    - replica
    resources:
      limits: {}
      requests: {}
    schedulerName: ""
    sdConfig: ""
    service:
      additionalHeadless: false
      annotations: {}
      clusterIP: ""
      externalTrafficPolicy: Cluster
      extraPorts: []
      labelSelectorsOverride: {}
      loadBalancerIP: ""
      loadBalancerSourceRanges: []
      nodePorts:
        grpc: ""
        http: ""
      ports:
        grpc: 10901
        http: 9090
      type: ClusterIP
    serviceAccount:
      annotations: {}
      automountServiceAccountToken: true
      existingServiceAccount: ""
    sidecars: []
    startupProbe:
      enabled: false
      failureThreshold: 15
      initialDelaySeconds: 5
      periodSeconds: 5
      successThreshold: 1
      timeoutSeconds: 1
    stores: []
    tolerations: []
    topologySpreadConstraints: []
    updateStrategy:
      type: RollingUpdate
  queryFrontend:
    affinity: {}
    args: []
    autoscaling:
      enabled: false
      maxReplicas: ""
      minReplicas: ""
      targetCPU: ""
      targetMemory: ""
    command: []
    config: ""
    containerSecurityContext:
      allowPrivilegeEscalation: false
      enabled: true
      readOnlyRootFilesystem: false
      runAsNonRoot: true
      runAsUser: 1001
    customLivenessProbe: {}
    customReadinessProbe: {}
    customStartupProbe: {}
    enabled: false
    existingConfigmap: ""
    extraEnvVars: []
    extraEnvVarsCM: ""
    extraEnvVarsSecret: ""
    extraFlags: []
    extraVolumeMounts: []
    extraVolumes: []
    hostAliases: []
    ingress:
      annotations: {}
      apiVersion: ""
      enabled: false
      extraHosts: []
      extraTls: []
      hostname: thanos.local
      ingressClassName: ""
      path: /
      pathType: ImplementationSpecific
      secrets: []
      selfSigned: false
      tls: false
    initContainers: []
    lifecycleHooks: {}
    livenessProbe:
      enabled: true
      failureThreshold: 6
      initialDelaySeconds: 30
      periodSeconds: 10
      successThreshold: 1
      timeoutSeconds: 30
    logFormat: logfmt
    logLevel: info
    nodeAffinityPreset:
      key: ""
      type: ""
      values: []
    nodeSelector: {}
    pdb:
      create: false
      maxUnavailable: ""
      minAvailable: 1
    podAffinityPreset: ""
    podAnnotations: {}
    podAntiAffinityPreset: soft
    podLabels: {}
    podSecurityContext:
      enabled: true
      fsGroup: 1001
    priorityClassName: ""
    pspEnabled: false
    rbac:
      create: false
      rules: []
    readinessProbe:
      enabled: true
      failureThreshold: 6
      initialDelaySeconds: 30
      periodSeconds: 10
      successThreshold: 1
      timeoutSeconds: 30
    replicaCount: 1
    resources:
      limits: {}
      requests: {}
    schedulerName: ""
    service:
      annotations: {}
      clusterIP: ""
      externalTrafficPolicy: Cluster
      extraPorts: []
      labelSelectorsOverride: {}
      loadBalancerIP: ""
      loadBalancerSourceRanges: []
      nodePorts:
        http: ""
      ports:
        http: 9090
      type: ClusterIP
    serviceAccount:
      annotations: {}
      automountServiceAccountToken: true
      existingServiceAccount: ""
    sidecars: []
    startupProbe:
      enabled: false
      failureThreshold: 15
      initialDelaySeconds: 5
      periodSeconds: 5
      successThreshold: 1
      timeoutSeconds: 1
    tolerations: []
    topologySpreadConstraints: []
    updateStrategy:
      type: RollingUpdate
  receive:
    affinity: {}
    args: []
    autoscaling:
      enabled: false
      maxReplicas: ""
      minReplicas: ""
      targetCPU: ""
      targetMemory: ""
    command: []
    config: []
    containerSecurityContext:
      allowPrivilegeEscalation: false
      enabled: true
      readOnlyRootFilesystem: false
      runAsNonRoot: true
      runAsUser: 1001
    customLivenessProbe: {}
    customReadinessProbe: {}
    customStartupProbe: {}
    enabled: true
    existingConfigmap: ""
    extraEnvVars: []
    extraEnvVarsCM: ""
    extraEnvVarsSecret: ""
    extraFlags: []
    extraVolumeMounts: []
    extraVolumes: []
    grpc:
      server:
        tls:
          autoGenerated: false
          ca: ""
          cert: ""
          enabled: false
          existingSecret: {}
          key: ""
    hostAliases: []
    ingress:
      annotations: {}
      apiVersion: ""
      enabled: false
      extraHosts: []
      extraTls: []
      hostname: thanos-receive.local
      ingressClassName: ""
      path: /
      pathType: ImplementationSpecific
      secrets: []
      selfSigned: false
      tls: false
    initContainers: []
    lifecycleHooks: {}
    livenessProbe:
      enabled: true
      failureThreshold: 6
      initialDelaySeconds: 30
      periodSeconds: 10
      successThreshold: 1
      timeoutSeconds: 30
    logFormat: logfmt
    logLevel: debug
    mode: standalone
    nodeAffinityPreset:
      key: ""
      type: ""
      values: []
    nodeSelector: {}
    pdb:
      create: false
      maxUnavailable: ""
      minAvailable: 1
    persistence:
      accessModes:
      - ReadWriteOnce
      annotations: {}
      enabled: true
      existingClaim: ""
      size: 8Gi
      storageClass: ""
    podAffinityPreset: ""
    podAnnotations: {}
    podAntiAffinityPreset: soft
    podLabels: {}
    podManagementPolicy: OrderedReady
    podSecurityContext:
      enabled: true
      fsGroup: 1001
    priorityClassName: ""
    readinessProbe:
      enabled: true
      failureThreshold: 6
      initialDelaySeconds: 30
      periodSeconds: 10
      successThreshold: 1
      timeoutSeconds: 30
    replicaCount: 1
    replicaLabel: replica
    replicationFactor: 1
    resources:
      limits: {}
      requests: {}
    schedulerName: ""
    service:
      additionalHeadless: false
      annotations: {}
      clusterIP: ""
      externalTrafficPolicy: Cluster
      extraPorts: []
      labelSelectorsOverride: {}
      loadBalancerIP: ""
      loadBalancerSourceRanges: []
      nodePorts:
        grpc: ""
        http: "30369"
        remote: ""
      ports:
        grpc: 10901
        http: 10902
        remote: 19291
      type: ClusterIP
    serviceAccount:
      annotations: {}
      automountServiceAccountToken: true
      existingServiceAccount: ""
    sidecars: []
    startupProbe:
      enabled: false
      failureThreshold: 15
      initialDelaySeconds: 5
      periodSeconds: 5
      successThreshold: 1
      timeoutSeconds: 1
    tolerations: []
    topologySpreadConstraints: []
    tsdbRetention: 30d
    updateStrategy:
      type: RollingUpdate
  receiveDistributor:
    affinity: {}
    args: []
    autoscaling:
      enabled: false
      maxReplicas: ""
      minReplicas: ""
      targetCPU: ""
      targetMemory: ""
    command: []
    containerSecurityContext:
      allowPrivilegeEscalation: false
      enabled: true
      readOnlyRootFilesystem: false
      runAsNonRoot: true
      runAsUser: 1001
    customLivenessProbe: {}
    customReadinessProbe: {}
    customStartupProbe: {}
    enabled: false
    extraEnvVars: []
    extraEnvVarsCM: ""
    extraEnvVarsSecret: ""
    extraFlags: []
    extraVolumeMounts: []
    extraVolumes: []
    hostAliases: []
    initContainers: []
    lifecycleHooks: {}
    livenessProbe:
      enabled: true
      failureThreshold: 6
      initialDelaySeconds: 30
      periodSeconds: 10
      successThreshold: 1
      timeoutSeconds: 30
    logFormat: logfmt
    logLevel: info
    nodeAffinityPreset:
      key: ""
      type: ""
      values: []
    nodeSelector: {}
    pdb:
      create: false
      maxUnavailable: ""
      minAvailable: 1
    podAffinityPreset: ""
    podAnnotations: {}
    podAntiAffinityPreset: soft
    podLabels: {}
    podSecurityContext:
      enabled: true
      fsGroup: 1001
    priorityClassName: ""
    readinessProbe:
      enabled: true
      failureThreshold: 6
      initialDelaySeconds: 30
      periodSeconds: 10
      successThreshold: 1
      timeoutSeconds: 30
    replicaCount: 1
    replicaLabel: replica
    resources:
      limits: {}
      requests: {}
    schedulerName: ""
    serviceAccount:
      annotations: {}
      automountServiceAccountToken: true
      existingServiceAccount: ""
    sidecars: []
    startupProbe:
      enabled: false
      failureThreshold: 15
      initialDelaySeconds: 5
      periodSeconds: 5
      successThreshold: 1
      timeoutSeconds: 1
    tolerations: []
    topologySpreadConstraints: []
    updateStrategy:
      type: RollingUpdate
  ruler:
    affinity: {}
    alertmanagers:
    - prometheus-alertmanager
    alertmanagersConfig: ""
    args: []
    autoscaling:
      enabled: false
      maxReplicas: ""
      minReplicas: ""
      targetCPU: ""
      targetMemory: ""
    clusterName: ""
    command: []
    config: |-
      groups:
        - name: "metamonitoring"
          rules:
            - alert: "PrometheusDown"
              expr: absent(up{prometheus="logiq/logiq-prometheus-prometheus"})
    containerSecurityContext:
      allowPrivilegeEscalation: false
      enabled: true
      readOnlyRootFilesystem: false
      runAsNonRoot: true
      runAsUser: 1001
    customLivenessProbe: {}
    customReadinessProbe: {}
    customStartupProbe: {}
    dnsDiscovery:
      enabled: true
    enabled: true
    evalInterval: 1m
    existingConfigmap: ""
    extraEnvVars: []
    extraEnvVarsCM: ""
    extraEnvVarsSecret: ""
    extraFlags: []
    extraVolumeMounts: []
    extraVolumes: []
    hostAliases: []
    ingress:
      annotations: {}
      apiVersion: ""
      enabled: false
      extraHosts: []
      extraTls: []
      hostname: thanos-ruler.local
      ingressClassName: ""
      path: /
      pathType: ImplementationSpecific
      secrets: []
    initContainers: []
    lifecycleHooks: {}
    livenessProbe:
      enabled: true
      failureThreshold: 6
      initialDelaySeconds: 30
      periodSeconds: 10
      successThreshold: 1
      timeoutSeconds: 30
    logFormat: logfmt
    logLevel: info
    nodeAffinityPreset:
      key: ""
      type: ""
      values: []
    nodeSelector: {}
    pdb:
      create: false
      maxUnavailable: ""
      minAvailable: 1
    persistence:
      accessModes:
      - ReadWriteOnce
      annotations: {}
      enabled: true
      existingClaim: ""
      size: 8Gi
      storageClass: ""
    podAffinityPreset: ""
    podAnnotations: {}
    podAntiAffinityPreset: soft
    podLabels: {}
    podManagementPolicy: OrderedReady
    podSecurityContext:
      enabled: true
      fsGroup: 1001
    priorityClassName: ""
    readinessProbe:
      enabled: true
      failureThreshold: 6
      initialDelaySeconds: 30
      periodSeconds: 10
      successThreshold: 1
      timeoutSeconds: 30
    replicaCount: 1
    replicaLabel: replica
    resources:
      limits: {}
      requests: {}
    schedulerName: ""
    service:
      additionalHeadless: false
      annotations: {}
      clusterIP: ""
      externalTrafficPolicy: Cluster
      extraPorts: []
      labelSelectorsOverride: {}
      loadBalancerIP: ""
      loadBalancerSourceRanges: []
      nodePorts:
        grpc: ""
        http: ""
      ports:
        grpc: 10901
        http: 9090
      type: ClusterIP
    serviceAccount:
      annotations: {}
      automountServiceAccountToken: true
      existingServiceAccount: ""
    sidecars: []
    startupProbe:
      enabled: false
      failureThreshold: 15
      initialDelaySeconds: 5
      periodSeconds: 5
      successThreshold: 1
      timeoutSeconds: 1
    tolerations: []
    topologySpreadConstraints: []
    updateStrategy:
      type: RollingUpdate
  storegateway:
    affinity: {}
    args: []
    autoscaling:
      enabled: false
      maxReplicas: ""
      minReplicas: ""
      targetCPU: ""
      targetMemory: ""
    command: []
    config: ""
    containerSecurityContext:
      allowPrivilegeEscalation: false
      enabled: true
      readOnlyRootFilesystem: false
      runAsNonRoot: true
      runAsUser: 1001
    customLivenessProbe: {}
    customReadinessProbe: {}
    customStartupProbe: {}
    enabled: true
    existingConfigmap: ""
    extraEnvVars: []
    extraEnvVarsCM: ""
    extraEnvVarsSecret: ""
    extraFlags: []
    extraVolumeMounts: []
    extraVolumes: []
    grpc:
      server:
        tls:
          autoGenerated: false
          ca: ""
          cert: ""
          enabled: false
          existingSecret: {}
          key: ""
    hostAliases: []
    ingress:
      annotations: {}
      apiVersion: ""
      enabled: false
      extraHosts: []
      extraTls: []
      grpc:
        annotations: {}
        apiVersion: ""
        enabled: false
        extraHosts: []
        extraTls: []
        hostname: thanos-grpc.local
        ingressClassName: ""
        path: /
        pathType: ImplementationSpecific
        secrets: []
        selfSigned: false
        tls: false
      hostname: thanos-storegateway.local
      ingressClassName: ""
      path: /
      pathType: ImplementationSpecific
      secrets: []
      selfSigned: false
      tls: false
    initContainers: []
    lifecycleHooks: {}
    livenessProbe:
      enabled: true
      failureThreshold: 6
      initialDelaySeconds: 30
      periodSeconds: 10
      successThreshold: 1
      timeoutSeconds: 30
    logFormat: logfmt
    logLevel: info
    nodeAffinityPreset:
      key: ""
      type: ""
      values: []
    nodeSelector: {}
    pdb:
      create: false
      maxUnavailable: ""
      minAvailable: 1
    persistence:
      accessModes:
      - ReadWriteOnce
      annotations: {}
      enabled: true
      existingClaim: ""
      size: 8Gi
      storageClass: ""
    podAffinityPreset: ""
    podAnnotations: {}
    podAntiAffinityPreset: soft
    podLabels: {}
    podManagementPolicy: OrderedReady
    podSecurityContext:
      enabled: true
      fsGroup: 1001
    priorityClassName: ""
    readinessProbe:
      enabled: true
      failureThreshold: 6
      initialDelaySeconds: 30
      periodSeconds: 10
      successThreshold: 1
      timeoutSeconds: 30
    replicaCount: 1
    resources:
      limits: {}
      requests: {}
    schedulerName: ""
    service:
      additionalHeadless: false
      annotations: {}
      clusterIP: ""
      externalTrafficPolicy: Cluster
      extraPorts: []
      labelSelectorsOverride: {}
      loadBalancerIP: ""
      loadBalancerSourceRanges: []
      nodePorts:
        grpc: ""
        http: ""
      ports:
        grpc: 10901
        http: 9090
      type: ClusterIP
    serviceAccount:
      annotations: {}
      automountServiceAccountToken: true
      existingServiceAccount: ""
    sharded:
      enabled: false
      hashPartitioning:
        shards: ""
      service:
        clusterIPs: []
        grpc:
          nodePorts: []
        http:
          nodePorts: []
        loadBalancerIPs: []
      timePartitioning:
      - max: ""
        min: ""
    sidecars: []
    startupProbe:
      enabled: false
      failureThreshold: 15
      initialDelaySeconds: 5
      periodSeconds: 5
      successThreshold: 1
      timeoutSeconds: 1
    tolerations: []
    topologySpreadConstraints: []
    updateStrategy:
      type: RollingUpdate
  volumePermissions:
    enabled: false
    image:
      pullPolicy: IfNotPresent
      pullSecrets: []
      registry: docker.io
      repository: bitnami/bitnami-shell
      tag: 10-debian-10-r287

HOOKS:
---
# Source: logiq/charts/flash-discovery/templates/license.yaml
apiVersion: v1
kind: Secret
metadata:
  name: flash-discovery-license
  namespace: logiq
  labels:
    app.kubernetes.io/name: flash-discovery
    helm.sh/chart: flash-discovery-1.0.0
    app.kubernetes.io/managed-by: Helm
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/version: 1.0.0
  annotations:
    "helm.sh/hook": "pre-install"
    "helm.sh/hook-delete-policy": "before-hook-creation"
data:
  license.jws: |-
    ZXlKaGJHY2lPaUpTVXpJMU5pSXNJblI1Y0NJNklrcFhWQ0o5LmV5SnNhV01pT25zaVpteDFaVzUwWkdadmNuZGhjbVF0Wlc1aFlteGxaQ0k2SW5SeWRXVWlMQ0ptYkhWbGJuUmtabTl5ZDJGeVpDMXlZWFJsTFd4cGJXbDBJam9pSWl3aWJuVnRZbVZ5TFc5bUxXRnNiRzkzWldRdFkyOW1abVZsTFhCdlpITWlPaUk0SWl3aWJuVnRZbVZ5TFc5bUxXRnNiRzkzWldRdFkyOW1abVZsTFhaamNIVWlPaUl4SWl3aWJuVnRZbVZ5TFc5bUxXRnNiRzkzWldRdFpHVnpkR2x1WVdsMGIyNHRZblZqYTJWMGN5STZJakVpTENKdWRXMWlaWEl0YjJZdFlXeHNiM2RsWkMxbWJHRnphQzF3YjJSeklqb2lNVFlpTENKdWRXMWlaWEl0YjJZdFlXeHNiM2RsWkMxbWJHRnphQzEyWTNCMUlqb2lOalFpTENKeVpXRnNMWFJwYldVdGMzUnlaV0Z0YVc1bklqb2lkSEoxWlNJc0luSmxiSEF0Wlc1aFlteGxaQ0k2SW5SeWRXVWlMQ0p5Wld4d0xYSmhkR1V0YkdsdGFYUWlPaUlpTENKek15MWpkWE4wYjIwdGNHRnlkR2wwYVc5dWFXNW5Jam9pZEhKMVpTSXNJbk41YzJ4dlp5MWxibUZpYkdWa0lqb2lkSEoxWlNJc0luTjVjMnh2WnkxeVlYUmxMV3hwYldsMElqb2lJbjBzSW1wMGFTSTZJbXRsZVVsa0lpd2lhV0YwSWpveE5qQXdPVGczTnpRMExDSnBjM01pT2lKc2IyZHBjUzVqYkc5MVpDSXNJbk4xWWlJNklsUnlhV0ZzTFV4cFkyVnVjMlVpZlEucDBkT2QtRmNBZDJjZjR3WC1hTmI0U2l5RkF6bW1VT3lReWxkZVo5UUVyc3dNSnIwMy1CSF9BLWQ0VXlPbE1pQm5yZmI2UVk4b1k3U3QwWDZZZ09Hbm1BSVlzODBmTG9ZQjB1RXNZczRMSjlESEkycnVKeUFzeDlheUg0eDhGZUtnQldoLUxDMGNhNnJuZ3VDRXp2WUp4dDFITnFyblY3ZVhTZTdPckMzT08wdmxfTC1VRXl5X1RFMmkyc1RFbVFvWU8zTGZLb0s3WXdZY3RjaC05bzExNkZiNHlBUTdGS3VpMkNfSDZ2aXdCc0VoZ1Z5UVFObW0tNk85SThwRUtNamxSUnlUNXZ6RkZKRHhQTTlWektLeGlVZnYyNVZvaE9SNHRyN0ZPMGxGVk9qZkkyWlYzamtVMWNrd1ZLcjRGQnllVEJjMU1NSlJqUzdVa0dOTWJmME1GVTBKUjJRLTVSVWlSeFVIbkp2NlNRc09XWjg0QlJKcWVoQUZsNldJQktsd0lJSzNia1hHallTbnd0Y2hIOERGckVUSDYxSXg5N3gwR1JIV1Fjb0FfcTRtTFVOWnBfRFl1RmhhTHl1cGpNcjBEa2lra3lpUmtFMUx0RGROS0xWdnhqRWpVSkZfdnNoaXNSVFhkYy1VdUZLV2ZPcFF2RTZZZTZ5TTFKUGhHTlU3MVFSQlZPTDlqRkNqZERFd21nMnp4cWJ2ZHYybnJoU242bFdBQ2ZvVTgwRkhPaWk0eEdlUkFKWUlFLTg2dlBaUnZQMExMLWJTdkthcUozdlJZTDFub3RQeFA3U1dnYzBMVWIzemc4dlh1QVo4aUlra3V1QlMtUFU3Q29RUkRmZm1fSTQxdEw0bWVpc19XZEVRMVFYMXJIWkhhU193MmtRRFZwbnM4RWY0OUU=
---
# Source: logiq/charts/kubernetes-ingress/templates/controller-defaultcertsecret.yaml
apiVersion: v1
kind: Secret
type: kubernetes.io/tls
metadata:
  name: logiq-kubernetes-ingress-default-cert
  namespace: logiq
  labels:
    app.kubernetes.io/name: kubernetes-ingress
    helm.sh/chart: kubernetes-ingress-1.37.0
    app.kubernetes.io/managed-by: Helm
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/version: 0.32.0
  annotations:
    "helm.sh/hook": "pre-install"
    "helm.sh/hook-delete-policy": "before-hook-creation"
data:
  tls.crt: LS0tLS1CRUdJTiBDRVJUSUZJQ0FURS0tLS0tCk1JSURIRENDQWdTZ0F3SUJBZ0lSQU9zRlpvUHhLeFI5byt2RC9HV01DalV3RFFZSktvWklodmNOQVFFTEJRQXcKR3pFWk1CY0dBMVVFQXhNUWJtZHBibmd0YVc1bmNtVnpjeTFqWVRBZUZ3MHlNakV4TURjd09ETTJNalphRncweQpNekV4TURjd09ETTJNalphTUJZeEZEQVNCZ05WQkFNVEMyeHZaMmx4TG14dloybHhNSUlCSWpBTkJna3Foa2lHCjl3MEJBUUVGQUFPQ0FROEFNSUlCQ2dLQ0FRRUF4VzhpTUhrWSsrUjdsdDNCdzFuNWhsVEhuMUpjcmZUbnNQSVYKVmFDR0toUVh0UVlhaEJpaFg2NlpXZG9DQ083UTI0c1VMOFRJRVRSMW01UEFJR0hndnNwazFLY3VBK1I4ekRlSQp6L2dRc2s0eFJLREtsV00vWHZSbjc3VEdlVVRSdDVBdFh5dTVIek1LUGRSODVKSTRHMWVNVlo5KzZnelZnSzFUCm5YZWs2NWo5bEJuU3pBYi9zcFIra3l3bkdWYzU4WGdpcURyUWVFUk5WQS9wZ0NVWDJyWFloQjFmZ0U0Y0JsK2kKaGt6bzhoWktTZjJpV0dvTnZ3RkgzaEt6cmQ3WFZmTEs3THpEdGhqcVV2RlhUSmw1QnJ6SHZuay9sckhmbGhxYgpsRmQzR1ZsR0p4ZSszZ1FLcWRNYkpuTjBzUU9SOXY3QVlBQmZJN00rVzhrTWFKYnFPd0lEQVFBQm8yQXdYakFPCkJnTlZIUThCQWY4RUJBTUNCYUF3SFFZRFZSMGxCQll3RkFZSUt3WUJCUVVIQXdFR0NDc0dBUVVGQndNQ01Bd0cKQTFVZEV3RUIvd1FDTUFBd0h3WURWUjBqQkJnd0ZvQVVFL3ozYmY4VWo5TXJGNVlpRXhUaC9ueHUyVU13RFFZSgpLb1pJaHZjTkFRRUxCUUFEZ2dFQkFBY0gwUGZPS2tXdDR3Y2FHaEcwb2R4K2pKcXpQbHVSclY4TW5XRkJpd3ArCnVkZGdLblJxYjAyYXd5TzRQM1V2NFJCU21vWDZqdEVvTUZWSW9HQmdmZ0NDZTY3VDBVT0R2ellmTUd3T29NMUEKaFNHWm1jaEdjbHRvV3Y2QWRQRGMyQ1lLNWFoYThGN09aRjg1TU1sVWpNUTVUdTZSbGZDVktkaHpZUE83azdCbAplWi9qOXZEbGovS0IzUlVRMGZOKytYL0p0VG5Eb1A3RXd4ZkhzRjVEcHBldjVIcis5d256ZCt5UjNkTGZieGpVClMwdWVxRVltOGptRkpkUG50QXlQbXNYOEZ4QXpxSmNNa2VqWTI3WVhGRkxaYWI5Sk91b1RkSGRVQUphM256UFUKbm5uOXlGcmxDYWxXT2RvdXRNZGZNKy92ajhDdjF4UUNWYkxRb3BtUUZEWT0KLS0tLS1FTkQgQ0VSVElGSUNBVEUtLS0tLQo=
  tls.key: LS0tLS1CRUdJTiBSU0EgUFJJVkFURSBLRVktLS0tLQpNSUlFcEFJQkFBS0NBUUVBeFc4aU1Ia1krK1I3bHQzQncxbjVobFRIbjFKY3JmVG5zUElWVmFDR0toUVh0UVlhCmhCaWhYNjZaV2RvQ0NPN1EyNHNVTDhUSUVUUjFtNVBBSUdIZ3ZzcGsxS2N1QStSOHpEZUl6L2dRc2s0eFJLREsKbFdNL1h2Um43N1RHZVVUUnQ1QXRYeXU1SHpNS1BkUjg1Skk0RzFlTVZaOSs2Z3pWZ0sxVG5YZWs2NWo5bEJuUwp6QWIvc3BSK2t5d25HVmM1OFhnaXFEclFlRVJOVkEvcGdDVVgyclhZaEIxZmdFNGNCbCtpaGt6bzhoWktTZjJpCldHb052d0ZIM2hLenJkN1hWZkxLN0x6RHRoanFVdkZYVEpsNUJyekh2bmsvbHJIZmxocWJsRmQzR1ZsR0p4ZSsKM2dRS3FkTWJKbk4wc1FPUjl2N0FZQUJmSTdNK1c4a01hSmJxT3dJREFRQUJBb0lCQVFDZ1JqR0pEQ1YrQnVOVgplN3dhSytabWFGaU5PNzFFOG5WTHJab29JdUlITXJ4MEZmcGNsZW9hMUpCazRwZVlUTlo4QXhGbUhlY1VJSFFBCjBoYTdzdmxScU5mbDBibUhLMnNzRlVFWkl4WGF5YU14UlI1djIxdk1aN2dnWGE1cEw3Ylh2MUUxMnpheTN5cEgKTzBJUUE2dE1kdXZUYm1FRysxZ3UxNFh6WlBjYTBXN0tmNXZRVWR3M3l4VTh6S0tGbkF4ZVFvRVdjZDBmVWplNwpwbXFlKzBQUE5sUjlwYzRSaVAxMGdBaHZ6STVRYjl1c1RJU21JdVBqUEE1ZzQ2a2hhLzNiUlREcHdQcW9BZVRKCkVzMVFWMGs5YWt3TlVmYjJBZUV5NElwT1VjWmI5NjFjRVBGaFRuZDVYQnhLcld4aUhzZkxuRGxpcDZacTk3TzAKbWExbVhGbHhBb0dCQVBrVjExTVhsVWcrVEI3Q2k5bCtWUmQxNThiY2cxWndnM3ZZSmR5NE5Oa2ppdzdxV1hJNwoxQUFlM0UvVU9lUWdLSFhLSFZ2WXZ1amZXUzZ1ZVdJTkZFNXp0MVZlRVBmbktUbUxGSkVPMUY2YlplM25TenJpCnFkTlJzNVVYbDZwYnY5c1lmMkcvdUhHZ3B1TjdEYUxKRkp1NFArZVp4UFE0RDk1R215T2I4ZGVGQW9HQkFNcnEKT2VKV3B6akhkclVaeVVGWC91dWxOZ2lmaWhMNzBEaUVGL3VIVTFPbmhMR0tvRGJ6SDI0RUpWekRSdFVQL2M0TgpCcVA0ZFRHSE9ZaVlUZmNYdm9tVWhvWHVxd0ZJVVQzK2hISTdBOEZvQlhUTm5SenRIWHZVd2xrNlRCVEdkbWtRCjdxbUFISDdqbXBMM085MTUwcmQ4c1hJZnJlekZJaGpSV3I4RjBnYS9Bb0dCQVBRWFdqWmNNdmRqelRhTGtYNm0KVlg2ekZWb0VPRlNaMTgraUpxQmdoN0dPS2pTSXBQVFQrbEhQN0RmeWtuU2lxdU9iR0NBc2pCRXE1bnRma1NYcwpDVTFFQ3BJR3AzdzROR2JtaTFZSGdVZmc0d2M3RkxiMDdsVmVpQ3gvdlNtOTFZcEFQSHd1NC9HOTdDMmFKZWV6ClE1WEIvaVhZdzNCTURBalhpaXBnSktQOUFvR0FBZnA4cS85S1RCeHR4T0JHZlJPZGtiQ2ZzVC9VK2RCb3ZGUlYKWTRkelFZcU5tYW1QWEZuTWdhY2FzaWZaUmZTTTlmaGNpemE5OWNpcXYvRTBPV2VLM1E2TXJUdWhnVGF5VEJkeQpOU2JzSjNPYk1nTmJOOC84REp3TGRSRkRjcVJvdlNlRUhEVDZraVluK0t6ZWNZOWhoWlo2cUhFMG9lMWVJcjNQCjA3TDcxRU1DZ1lBblFFbUE4VlJsMlRNaVgzUWsyOUMvbS9PRDJPVTJTOFlBeUlaRW5ZUUtGRHNEc0pjWWVTQWMKSFp6TzQzdUgvL3VlMDNLZmJwV001WUcxME5xMkRuQlJRZkppNGJCSE1nOE10K0YwM1d4VldlaVQ0bnU4eERCTApYRVBYSjlFeWNiY2I4dDlxb2MxZkx2YVN2TThMMUZNQXNuQzV3UXExbXZaUVFhQ1FMQis4RWc9PQotLS0tLUVORCBSU0EgUFJJVkFURSBLRVktLS0tLQo=
---
# Source: logiq/templates/license.yaml
apiVersion: v1
kind: Secret
type: kubernetes.io/tls
metadata:
  name: logiq-shared-secret
  namespace: logiq
  labels:
    app.kubernetes.io/name: logiq
    helm.sh/chart: logiq-v3.0.5
    app.kubernetes.io/managed-by: Helm
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/version: v3.0.5
  annotations:
    "helm.sh/hook": "pre-install"
    "helm.sh/hook-delete-policy": "before-hook-creation"
data:
  tls.crt: LS0tLS1CRUdJTiBDRVJUSUZJQ0FURS0tLS0tCk1JSURGRENDQWZ5Z0F3SUJBZ0lSQUt3M0Nicnd6ak1ndVpCOExmeVBrRFF3RFFZSktvWklodmNOQVFFTEJRQXcKRXpFUk1BOEdBMVVFQXhNSWJHOW5hWEV0WTJFd0hoY05Nakl4TVRBM01EZ3pOakkzV2hjTk1qa3hNVEExTURnegpOakkzV2pBV01SUXdFZ1lEVlFRREV3dHNiMmRwY1M1c2IyZHBjVENDQVNJd0RRWUpLb1pJaHZjTkFRRUJCUUFECmdnRVBBRENDQVFvQ2dnRUJBTmFqcmFjSnZVM1pid2JVbWVsYnRnREc4VGZReklKSVVYN0VTOFFTb1ZYTS81S1QKSVo1bzVyY0VBd3FLVEV4Q3BjcEhmbGcwdzNJTkZkUlMwUVIrRWtaTnlrYWtDeDJ5bXJqODRZVmlzM1ZDM0hBagpMVlR6cEM1ZHhMOXJvT2kyWGY4Ryt5OHpLVERnL0liU1Y1MmVNclBkUk1vYmxqMU1HVUhjVHpyTnJhQnBaZEx4CkF0SmNTRnp0Umc5S3JOL3EwNVBTZ2o2SWFOckZveTAvaUI3UldsUi9RUjhHSTdWSXUyODZLcDJTaWcrcmp4c3EKMWM3WUgxNnlsRmNDZ25qcUFEd2JUSUtSWW5nL21LL0pMQjU1SXVDMW5FK25RNkxvNzJ5QVdmTHdwS2Q5dzZtOApEV1JYMkZVL1FVQjJxSlJlL3hhWlNTY2cxdU1QN1lXNm40QXBPWjBDQXdFQUFhTmdNRjR3RGdZRFZSMFBBUUgvCkJBUURBZ1dnTUIwR0ExVWRKUVFXTUJRR0NDc0dBUVVGQndNQkJnZ3JCZ0VGQlFjREFqQU1CZ05WSFJNQkFmOEUKQWpBQU1COEdBMVVkSXdRWU1CYUFGSGNFUlpDeXAwRlhib1hENVdWbUJ0L2Q2RURrTUEwR0NTcUdTSWIzRFFFQgpDd1VBQTRJQkFRQTNwbmNGMUk0c1pLVWgzZG1pNHFUM2JKeVkycG5Cdm8wRnBvOVNVR2VhV2xadmtMQlkzY2FTCnQ3YURaVVBscTN5Z1phbGVDNGNleXRuWWx6Um5VM0U4ZDZBWEM3MDB5YUcyVHZTQS9Zc243bThuMW5LSHdDNTQKQnc3L1QvYVZvZndueVI1d21IVWNkbEZBbHdYZTZyTkR2dW5TZUMyODQzeG0rM3I2OW1rRXpabytWQjl3WjZvNwpObGVUOFB3VUM5eVVhd2h3OWRWZnlNM1lwSmJZYVp4NVBuS3hxMWJPMDhwWnNZeE9BTFc2a3h4ZFNRWkZTOVRFCmFuUlRLM2QwOEZiV0lvMHE2TzZ6eCtxV3d6SFJ3b1NVMnFEN09PS2hJM1BDQW9wb2duVXlXbXVEMk5xUmNqRk4KN0dHM2FieEN4cEJOeTVMY2tjWVVyeFBOaWRYSWhzNTcKLS0tLS1FTkQgQ0VSVElGSUNBVEUtLS0tLQo=
  tls.key: LS0tLS1CRUdJTiBSU0EgUFJJVkFURSBLRVktLS0tLQpNSUlFcEFJQkFBS0NBUUVBMXFPdHB3bTlUZGx2QnRTWjZWdTJBTWJ4TjlETWdraFJmc1JMeEJLaFZjei9rcE1oCm5tam10d1FEQ29wTVRFS2x5a2QrV0RURGNnMFYxRkxSQkg0U1JrM0tScVFMSGJLYXVQemhoV0t6ZFVMY2NDTXQKVlBPa0xsM0V2MnVnNkxaZC93YjdMek1wTU9EOGh0SlhuWjR5czkxRXlodVdQVXdaUWR4UE9zMnRvR2xsMHZFQwowbHhJWE8xR0QwcXMzK3JUazlLQ1BvaG8yc1dqTFQrSUh0RmFWSDlCSHdZanRVaTdiem9xblpLS0Q2dVBHeXJWCnp0Z2ZYcktVVndLQ2VPb0FQQnRNZ3BGaWVEK1lyOGtzSG5raTRMV2NUNmREb3VqdmJJQlo4dkNrcDMzRHFid04KWkZmWVZUOUJRSGFvbEY3L0ZwbEpKeURXNHcvdGhicWZnQ2s1blFJREFRQUJBb0lCQVFEUmZBQnhCZTF2dktaQworVjZhUmpzMU9QV1dyei9hYS9DMkU2bUszVS8vS012TFo3UXBJbU1DL25SbFppTWZUdkQyb3A1cVFsejZ4RkNvCjRJZEZwakg1MGRSNDY0UTU0T1puWTlCTDJkQWl3elhZY0V5L0crZ0NwTnZ3bzMveGdJUHU4d1pXdzgwUStwVWMKbE5DVWNpRTBNT0lCaTdrdmJFVStaV0lpbHprOVU3Wml4OVdxWkg0R0hXQkIwazVPbVg3ZSt1SmYwZ1VCNlFQKwo3RzNRK1Bxc0xEL2xIMEpjQlIxSHpaMGNjME9od2JLSllvQUlOTVRNTXA1ZnJ3Ujd3VGhCeUFkbFcyY09aR2YzCkF4YmR5L1dRd1MwcnRqOGVQRjlRclBudk5PV29BVmE1dnFNcHNPQWV0TWlmMWt4dHFqVjlQQUs4VzdkWHdRYWwKVjVnWTVsYzFBb0dCQU52M1lZeXhFTG5XMjFVUk83VWhiZTJPS1J4VXVKeTQ3TEhJMG5WYmcwTXRRSUE4aU8xWQpBUGg4eXFWNHhiQXVKNHlqK2t1WVUzWW1Nb25odlpRNjhWK2lFamJBbVJ3em5wbktlSzNhbzN0OFdjeWsvS2ZkCmd1SjRyQm9QV2N5NUNVWlBNd0tBRW5zY0xmU0xBQUFLTFo1dWlNYlNTMUNGdGZQU1JKLzJmanBuQW9HQkFQbk0KNXkycHl4M25lQUxLTjk3eU5laFlkbXBMQkxGU0xOOHdwSFpjNWc1RGVFSW9jT0VhR29TbHR6ZkhYVnU2Vi95cwpoVEgyanRyYWdSQXJEWU9RdUdEUERwZHFSSmJGZlZKV25Ka0RUVTQ3enVmeDlUNkxFekJBcnpLYzFEazRXSVRBCjY4ckExNklySDdmNTg0Kys0WHVXRjVQS3dLQS83dGdITURsZWhYRmJBb0dBVEFXUlowaUMyVmVTY2pJRWlyTkYKQk1jUEdrV0ZrRlN4S1RpWTFBcU9zUmJncGZGRitaRml0SDZjb3RlOHF3a29qZ2pXSm00ODJpYVZiT1hoMldzTgpwTm1rcGR1bWp3S2dHOUxJSm4zYjVuK3hvWEtjQjRBZERoeGFqcDhqa0FlYlZ2dGtTOGJybkRTL0JUZE5Cclo5CjBiV3QrOWtPUW9RVHdISzVXUGVkNUowQ2dZQnpPbkM5WUtDQVorQzFNTUM3Qi9HVC94S0lqNWhYajNlQmNQZTgKWGJnRmhsdjM4SjI1U0loSS9nUlpKNDdLSEZnd0J3amQ5a1VKY1ZldHRKNWtQU0xBRFdOR3QwOXlXU0VwRlNqaApjR045bmhzZ1pUMWluMWEzb0c3d291VkdpOVpSVG9pMkcyU2N1dFhEMFBub0tmM3JPMTRlMzUwaGpyeEhUSEdUClZTV3JGd0tCZ1FETWlldm9iby9tVVdvdlB2T01IdVNJWVpqTitUb0Y0RnRCbnd2YjU1RktsN3lkVXhDdnp2UjgKQmRKRDFzQ3JGS0JSaVVSdXJ4LzgwakpMNzJkOWh5Nnh6QXlZQzlKVCtKMEJhVVd2VjN0Yk9sM0xpZmZZMmxTTApZblR1dSttbjRpdmltenQzNjlDc2VKSU1JZnZvbzNHMHRnOU9kaWpuVE5hc0RrNTZIdnZ1UUE9PQotLS0tLUVORCBSU0EgUFJJVkFURSBLRVktLS0tLQo=
---
# Source: logiq/templates/shared-secret.yaml
apiVersion: v1
kind: Secret
type: kubernetes.io/tls
metadata:
  name: logiq-shared-secret
  namespace: logiq
  labels:
    app.kubernetes.io/name: logiq
    helm.sh/chart: logiq-v3.0.5
    app.kubernetes.io/managed-by: Helm
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/version: v3.0.5
  annotations:
    "helm.sh/hook": "pre-install"
    "helm.sh/hook-delete-policy": "before-hook-creation"
data:
  tls.crt: LS0tLS1CRUdJTiBDRVJUSUZJQ0FURS0tLS0tCk1JSURGRENDQWZ5Z0F3SUJBZ0lSQUlhY0RMSTFBd09IY2hka1R1T2dzWGd3RFFZSktvWklodmNOQVFFTEJRQXcKRXpFUk1BOEdBMVVFQXhNSWJHOW5hWEV0WTJFd0hoY05Nakl4TVRBM01EZ3pOakkyV2hjTk1qa3hNVEExTURnegpOakkyV2pBV01SUXdFZ1lEVlFRREV3dHNiMmRwY1M1c2IyZHBjVENDQVNJd0RRWUpLb1pJaHZjTkFRRUJCUUFECmdnRVBBRENDQVFvQ2dnRUJBS3YvQXRYemZhZjcxOXg0YkRBcUNnSEt5Mk54TzhCa2tzaXFlbFV2RXJha01ZOG0Kd2FMZUp0VWZScW85VVFjQVU0T0hOQnFBNkhtNmRubzFkdTFTWTl5SmZ1NWFJRkx5WDNiVmNteEVWeFV1bTZEcwpnQ2w1K3JYMGp3TlFxTjNQWDgyYWlFTkZPSGRnTFpKVzF4S1g3RkhiQnp3REREMkNXUWpzTmNjSkswUzA3bHFUCi91NmNBd0MzcUhlNFd1eUV2NDBLRVVRUTl1TnhPbnFhRFhSbUM3NnpzM1Ardk1NS2toRlRYTW5Va1FsVDdEeDMKTHBvNklqUW95bVM4QXJPc2I4NzBhVFZZd1JadlZ1TkFwdEp1bGp5dFlTZWlPZElPdVFHNU1xUGRqQ0dPWnVhaQpERVpQcUltRzk4VDR3a1NFbTliVG1XY3RKSVZ3YzZRbm1DR0NRSjBDQXdFQUFhTmdNRjR3RGdZRFZSMFBBUUgvCkJBUURBZ1dnTUIwR0ExVWRKUVFXTUJRR0NDc0dBUVVGQndNQkJnZ3JCZ0VGQlFjREFqQU1CZ05WSFJNQkFmOEUKQWpBQU1COEdBMVVkSXdRWU1CYUFGRXZMcEhwMnIwWjZWNjIvQ2FUcGwwbng3ZG9mTUEwR0NTcUdTSWIzRFFFQgpDd1VBQTRJQkFRQUpFQ3BZWWNMVHJhbkZIREJPOWtGbkNXR2xMOU1wR0JrVHFYanBHeHdMTVR6SExjdWJmY0gwCnZXSmljWGJjK2w4ZDR3ZW1uZlNFaHZJNURZNEVTZkE0M0crVHFDajNuMVFhWXR4eVNFUlE0YytXREdjOExRSzUKL2VtQjNGekJ0ZHd1ZmVEWFZEUU15WWRYMmFxd2ZvZll5cDBDTDFxOWVjVjBLSWRRRjZKa1Y3alEveC8zZElKZgpjeGdoTlNxdzdVVnRoY1lxeWhBTDVybnVWOTJ3aHdseCtrbDlSb0hwR1grUnNuOWV1T2FCM2ZoOHRDMXpLWkd4CjZoK2R4KzE3VVY3a1BiY3RNRWJ3a1VqTTROenBCVkJERkxNZndsNGttQXhScGVCUXdjNWRVc1FHZXJtZzhXbG0KNnNGOXIyVE43ZzJtNmNPckVmMHdBd2kyN1pZTTY5S3YKLS0tLS1FTkQgQ0VSVElGSUNBVEUtLS0tLQo=
  tls.key: LS0tLS1CRUdJTiBSU0EgUFJJVkFURSBLRVktLS0tLQpNSUlFb3dJQkFBS0NBUUVBcS84QzFmTjlwL3ZYM0hoc01Db0tBY3JMWTNFN3dHU1N5S3A2VlM4U3RxUXhqeWJCCm90NG0xUjlHcWoxUkJ3QlRnNGMwR29Eb2VicDJlalYyN1ZKajNJbCs3bG9nVXZKZmR0VnliRVJYRlM2Ym9PeUEKS1huNnRmU1BBMUNvM2M5ZnpacUlRMFU0ZDJBdGtsYlhFcGZzVWRzSFBBTU1QWUpaQ093MXh3a3JSTFR1V3BQKwo3cHdEQUxlb2Q3aGE3SVMvalFvUlJCRDI0M0U2ZXBvTmRHWUx2ck96Yy82OHd3cVNFVk5jeWRTUkNWUHNQSGN1Cm1qb2lOQ2pLWkx3Q3M2eHZ6dlJwTlZqQkZtOVc0MENtMG02V1BLMWhKNkk1MGc2NUFia3lvOTJNSVk1bTVxSU0KUmsrb2lZYjN4UGpDUklTYjF0T1paeTBraFhCenBDZVlJWUpBblFJREFRQUJBb0lCQUcvckIxaGJFZGYrTzQ5ZAoyT0JhYXBxUjhGanI5THFUZHlRV01uWTlwRXF1ZXdVd2JlM2g2cGpodWlUS3MyLy8yVmdMNFc2aGxTU29uYkdXCkdxWUE1N1E0MEJ5ZkRzdUtwVzM1SkhTbzM1V0w5MzcyaGNyM2NabDI0cHlBbnZGK29GTjBpOWhpTVlVVVUzTVgKQ09vemEzWTBOUGZxNzhzU2g0Y1QxVWFIZzkwM1lWa2pIekl2bTNXRDl0bHNpc2dWVnpKNVI2dGNPVFo1S2JHbApiOFZUS2JPSDNqTGY5QnFrOW1OaFJOM3ArLzZ0Z0hGTWVhV2dzbEQvWVpZOVVvQjJrdFlyVmpKclF3eDFnNE5sClh4K1dzeElGWVlxYlllc0hTZ3ZPZS9JckJoMWxhY3FCd0s4cjNGcXNFZi94b1U4bjhvcW1kSnhMWVR5OTltUFQKajJNWlc4RUNnWUVBMmxoQ3RsbW54eDR6bXRYeU04bUt1OE4vU3hETWxDVVhiNVl5aTVWYi8zS2xVVlVFOVJXVwpwUmVqUnYwaUcxS3lXSjJaL1kvYm1vVjc4alJ3MWFOMFlHQXRHVTV5SzI5Y3RxdWNvRlRRdkJUUGVOV29JZU1BCnMzNFRleEtDNDdSYmw0QWwxSjI1WkNPUzdtMFE1WnNEZ21VcjBqYnl2N3gxRmtqMnNrbnQ0QkVDZ1lFQXlhaC8KUUx2b3RFWjFRbkhGZEkzZlJvbEo0V0pjbDdMQnNUcjJKS3RhZUlEK1gvR0ZDM3AzOHBGdzRqSkFad2FtR0tHZApLZE1BUnNkNXY4Q2t2TEFGQ2VBZGRheXl5eUVrTU9FZERMamJFc1FpcmxsT25vZ2MvaUZDbTdRbmE1STF5VnNSCjlsb1I0UGo2TmFobGxSQ25NOXFTRisvWWNGSjhqS3JodS8ycm84MENnWUFMYXVBYUx2Z0NCb2RHU25lKzA0UW8KcTJGbHFIdzZKdkpoeUdYZVBMSXgybW5ncGVSN2VHU0hQNFF2T3g5a2RGK1ZHTENydkxFTUZIelZ2bjVEL2FjaApQd1k4czRodTB3VHpIR2cxVGhvWUs3SnByQ3A5a3lRL1BwR0FOd2lYSmFCQWZOZjlsVDNUaWJTdU9RL1FJZG4rCklKSTVETnlHd0RFVE9EK0dOUzEyTVFLQmdBS05CQmNRaVhBR1dDTmdCd3hqWXdpa1llL2M2NmpybFBHbCtra2EKZGNtQ2NEVk1lODlhWER3UVJPcEhrbkw3TFl5d05xbTV4bzRlcGRhY0hEbGF6S1dFVlRzUTFTNG1uQ3VXSFdUMAp6YWllSElZeUVRR0dYVCtGc2k4QUIyT2Y5Tmc0TTdEM0VMVFUwVzF1Vk9LZTFFNmVuQ3g3VnpTTWhwRE05SkFKCk5HdWRBb0dCQUw0ZUJCOURodGJ2ZlFFRndFUVkxQjFkMC9pckpIbVF5UnV2LzBGTXhjdVcxK2QvZ1QvckhRQjkKQnBjaFZ1MHVwUTBDem9FSndtd3Z0NTdPUGdoanRVak1QME4yM0ozNktFWElPQUwvSzNpZUVhTjAxNXJXc1p5RApGRTRlRTdRU2xUZml3d1dMak0xS0d1TmYyM09WQk1TcWlJNVBRd0pHUUZXeExCc3JlbUNOCi0tLS0tRU5EIFJTQSBQUklWQVRFIEtFWS0tLS0tCg==
  awsaccesskey: "RnBFdzFhQ0xDeFkxdXJHb0hPUVk="
  awssecretkey: "MXFja09MZXRRQkN5Q2h2NjRNS3VYYm4xT043bDJjVkJBRVVVcG5ZMQ=="
  s3_access: "bG9naXFfYWNjZXNz" 
  s3_secret: "bG9naXFfc2VjcmV0" 
  s3_bucket: "bG9naXE="
---
# Source: logiq/templates/thanos-secret.yaml
apiVersion: v1
kind: Secret
type: Opaque
metadata:
  name: thanos-objectstorage-config
  namespace: logiq
  labels:
    app.kubernetes.io/name: logiq
    helm.sh/chart: logiq-v3.0.5
    app.kubernetes.io/managed-by: Helm
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/version: v3.0.5
  annotations:
    "helm.sh/hook": "pre-install"
    "helm.sh/hook-delete-policy": "before-hook-creation"
data:
  thanos.yaml: dHlwZTogczMKY29uZmlnOiAKICAKICBhY2Nlc3Nfa2V5OiBsb2dpcV9hY2Nlc3MgCiAgc2VjcmV0X2tleTogbG9naXFfc2VjcmV0IAogIAogIGJ1Y2tldDogbG9naXEgCgogIGVuZHBvaW50OiBzMy1nYXRld2F5OjkwMDAgCiAgaW5zZWN1cmU6IHRydWUKCiAgcmVnaW9uOiB1cy1lYXN0LTEgCg==
---
# Source: logiq/charts/logiqctl/templates/post-install-upload-dashboard-job.yaml
apiVersion: batch/v1
kind: Job
metadata:
  name: logiq-logiqctl-upload-dashboard-job
  namespace: logiq
  labels:
    app: logiqctl-upload-dashboard-job
    chart: logiqctl-1.0.0
    release: logiq
    heritage: Helm
  annotations:
    "helm.sh/hook": post-install
    "helm.sh/hook-weight": "10"
    "helm.sh/hook-delete-policy": hook-succeeded,before-hook-creation
spec:
  template:
    metadata:
      labels:
        app: logiqctl-job
        release: logiq
    spec:
      serviceAccountName: logiqctl
      securityContext:
        fsGroup: 1000
        runAsUser: 1000
        runAsGroup: 1000
      restartPolicy: OnFailure


      volumes:
        - name: logiqctl-configuration
          projected:
            sources:
            - configMap:
                name: logiq-logiqctl
            - secret:
                name: logiq-logiqctl
      containers:
      - name: logiqctl
        image: "logiqai/logiqctl:2.0.4"
        imagePullPolicy: IfNotPresent
        command: ["/bin/sh", "-c"]
        args:
        - echo uploading;
          until $(curl --output /dev/null --silent --fail http://coffee); do echo "waiting for coffee"; sleep 10; done;
          /flash/bin/logiqctl config set-cluster coffee;
          export ACCESS=$(cat /flash/config/export/admin_email) ; export SECRET=$(cat /flash/config/export/admin_password) ;
          /flash/bin/logiqctl config set-credential $ACCESS $SECRET ; sleep 5;
          /flash/bin/logiqctl create dashboard -f /flash/config/export/logiq.json;
          while [ $? -ne 0 ]; do sleep 5; echo "Waiting for dashboard to create";/flash/bin/logiqctl create dashboard -f /flash/config/export/logiq.json; done;
          echo done;
        env:
          - name: LOGIQ_NS
            value: logiq
        volumeMounts:
          - name: logiqctl-configuration
            mountPath: /flash/config/export
        resources:
          requests:
            cpu: 100m
            memory: 100Mi
---
# Source: logiq/charts/s3gateway/templates/post-install-create-bucket-job.yaml
apiVersion: batch/v1
kind: Job
metadata:
  name: s3-gateway-make-bucket-job
  namespace: logiq
  labels:
    app: s3gateway-make-bucket-job
    chart: s3gateway-5.0.20
    release: logiq
    heritage: Helm
  annotations:
    "helm.sh/hook": post-install
    "helm.sh/hook-weight": "1"
    "helm.sh/hook-delete-policy": hook-succeeded,before-hook-creation
spec:
  template:
    metadata:
      labels:
        app: s3gateway-job
        release: logiq
    spec:
      restartPolicy: OnFailure      


      volumes:
        - name: minio-configuration
          projected:
            sources:
            - configMap:
                name: s3-gateway
            - secret:
                name: s3-gateway
      serviceAccountName: "s3-gateway"
      containers:
      - name: minio-mc
        image: "minio/mc:RELEASE.2020-03-14T01-23-37Z"
        imagePullPolicy: IfNotPresent
        command: ["/bin/sh", "/config/initialize"]
        env:
          - name: MINIO_ENDPOINT
            value: s3-gateway
          - name: MINIO_PORT
            value: "9000"
        volumeMounts:
          - name: minio-configuration
            mountPath: /config
        resources:
          {}
MANIFEST:
---
# Source: logiq/charts/flash-coffee/templates/psp.yaml
apiVersion: policy/v1beta1
kind: PodSecurityPolicy
metadata:
  annotations:
    seccomp.security.alpha.kubernetes.io/allowedProfileNames: 'docker/default'
    seccomp.security.alpha.kubernetes.io/defaultProfileName:  'docker/default'
  name:  logiq-flash-coffee
  namespace: logiq
  labels:
    app: flash-coffee
spec:
  allowPrivilegeEscalation: false
  fsGroup:
    rule: 'MustRunAs'
    ranges:
      # Forbid adding the root group.
      - min: 1
        max: 65535
  hostIPC: false
  hostNetwork: false
  hostPID: false
  requiredDropCapabilities:
  - NET_RAW
  privileged: false
  readOnlyRootFilesystem: false
  runAsUser:
    rule: 'MustRunAsNonRoot'
  seLinux:
    rule: 'RunAsAny'
  supplementalGroups:
    rule: 'MustRunAs'
    ranges:
      # Forbid adding the root group.
      - min: 1
        max: 65535
  volumes:
  - 'configMap'
  - 'downwardAPI'
  - 'emptyDir'
  - 'persistentVolumeClaim'
  - 'projected'
  - 'secret'
---
# Source: logiq/charts/flash-discovery/templates/psp.yaml
apiVersion: policy/v1beta1
kind: PodSecurityPolicy
metadata:
  annotations:
    seccomp.security.alpha.kubernetes.io/allowedProfileNames: 'docker/default'
    seccomp.security.alpha.kubernetes.io/defaultProfileName:  'docker/default'
  name: logiq-flash-discovery
  namespace: logiq
  labels:
    app: flash-discovery
spec:
  allowPrivilegeEscalation: false
  fsGroup:
    rule: 'MustRunAs'
    ranges:
      # Forbid adding the root group.
      - min: 1
        max: 65535
  hostIPC: false
  hostNetwork: false
  hostPID: false
  requiredDropCapabilities:
  - NET_RAW
  privileged: false
  readOnlyRootFilesystem: false
  runAsUser:
    rule: 'MustRunAsNonRoot'
  seLinux:
    rule: 'RunAsAny'
  supplementalGroups:
    rule: 'MustRunAs'
    ranges:
      # Forbid adding the root group.
      - min: 1
        max: 65535
  volumes:
  - 'configMap'
  - 'downwardAPI'
  - 'emptyDir'
  - 'persistentVolumeClaim'
  - 'projected'
  - 'secret'
---
# Source: logiq/charts/kubernetes-ingress/templates/controller-psp.yaml
apiVersion: policy/v1beta1
kind: PodSecurityPolicy
metadata:
  name: logiq-kubernetes-ingress
  labels:
    app: kubernetes-ingress
    chart: kubernetes-ingress-1.37.0
    heritage: Helm
    release: logiq
spec:
  allowedCapabilities:
    - NET_BIND_SERVICE
  privileged: false
  allowPrivilegeEscalation: true
  # Allow core volume types.
  volumes:
    - 'configMap'
    #- 'emptyDir'
    - 'projected'
    - 'secret'
    #- 'downwardAPI'
  hostNetwork: false
  hostIPC: false
  hostPID: false
  runAsUser:
    # Require the container to run without root privileges.
    rule: 'MustRunAsNonRoot'
  supplementalGroups:
    rule: 'MustRunAs'
    ranges:
      # Forbid adding the root group.
      - min: 1
        max: 65535
  fsGroup:
    rule: 'MustRunAs'
    ranges:
      # Forbid adding the root group.
      - min: 1
        max: 65535
  readOnlyRootFilesystem: false
  seLinux:
    rule: 'RunAsAny'
---
# Source: logiq/charts/kubernetes-ingress/templates/default-backend-psp.yaml
apiVersion: policy/v1beta1
kind: PodSecurityPolicy
metadata:
  name: logiq-kubernetes-ingress-backend
  labels:
    app: kubernetes-ingress
    chart: kubernetes-ingress-1.37.0
    heritage: Helm
    release: logiq
spec:
  allowPrivilegeEscalation: false
  fsGroup:
    ranges:
    - max: 65535
      min: 1
    rule: MustRunAs
  requiredDropCapabilities:
  - ALL
  runAsUser:
    rule: MustRunAsNonRoot
  seLinux:
    rule: RunAsAny
  supplementalGroups:
    ranges:
    - max: 65535
      min: 1
    rule: MustRunAs
  volumes:
  - configMap
  - emptyDir
  - projected
  - secret
  - downwardAPI
---
# Source: logiq/charts/logiq-flash/templates/psp.yaml
apiVersion: policy/v1beta1
kind: PodSecurityPolicy
metadata:
  annotations:
    seccomp.security.alpha.kubernetes.io/allowedProfileNames: 'docker/default'
    seccomp.security.alpha.kubernetes.io/defaultProfileName:  'docker/default'
  name: logiq-logiq-flash
  namespace: logiq
  labels:
    app: logiq-flash
spec:
  allowPrivilegeEscalation: false
  fsGroup:
    rule: 'MustRunAs'
    ranges:
      # Forbid adding the root group.
      - min: 1
        max: 65535
  hostIPC: false
  hostNetwork: false
  hostPID: false
  requiredDropCapabilities:
  - NET_RAW
  privileged: false
  readOnlyRootFilesystem: false
  runAsUser:
    rule: 'MustRunAsNonRoot'
  seLinux:
    rule: 'RunAsAny'
  supplementalGroups:
    rule: 'MustRunAs'
    ranges:
      # Forbid adding the root group.
      - min: 1
        max: 65535
  volumes:
  - 'configMap'
  - 'downwardAPI'
  - 'emptyDir'
  - 'persistentVolumeClaim'
  - 'projected'
  - 'secret'
---
# Source: logiq/charts/logiqctl/templates/psp.yaml
apiVersion: policy/v1beta1
kind: PodSecurityPolicy
metadata:
  annotations:
    seccomp.security.alpha.kubernetes.io/allowedProfileNames: 'docker/default'
    seccomp.security.alpha.kubernetes.io/defaultProfileName:  'docker/default'
  name: logiq-logiqctl
  namespace: logiq
  labels:
    app: logiqctl
spec:
  allowPrivilegeEscalation: false
  fsGroup:
    rule: 'MustRunAs'
    ranges:
      # Forbid adding the root group.
      - min: 1
        max: 65535
  hostIPC: false
  hostNetwork: false
  hostPID: false
  requiredDropCapabilities:
  - NET_RAW
  privileged: false
  readOnlyRootFilesystem: false
  runAsUser:
    rule: 'MustRunAsNonRoot'
  seLinux:
    rule: 'RunAsAny'
  supplementalGroups:
    rule: 'MustRunAs'
    ranges:
      # Forbid adding the root group.
      - min: 1
        max: 65535
  volumes:
  - 'configMap'
  - 'downwardAPI'
  - 'emptyDir'
  - 'persistentVolumeClaim'
  - 'projected'
  - 'secret'
---
# Source: logiq/charts/postgres/templates/psp.yaml
apiVersion: policy/v1beta1
kind: PodSecurityPolicy
metadata:
  annotations:
    seccomp.security.alpha.kubernetes.io/allowedProfileNames: 'docker/default'
    seccomp.security.alpha.kubernetes.io/defaultProfileName:  'docker/default'
  name: logiq-postgres
  namespace: logiq
spec:
  allowPrivilegeEscalation: false
  fsGroup:
    rule: 'MustRunAs'
    ranges:
    # Forbid adding the root group.
     - min: 1
       max: 65535
  hostIPC: false
  hostNetwork: false
  hostPID: false
  requiredDropCapabilities:
  - NET_RAW
  privileged: false
  readOnlyRootFilesystem: false
  runAsUser:
    rule: 'MustRunAsNonRoot'
  seLinux:
    rule: 'RunAsAny'
  supplementalGroups:
    rule: 'MustRunAs'
    ranges:
    # Forbid adding the root group.
      - min: 1
        max: 65535
  volumes:
  - 'configMap'
  - 'downwardAPI'
  - 'emptyDir'
  - 'persistentVolumeClaim'
  - 'projected'
  - 'secret'
---
# Source: logiq/charts/prometheus/charts/kube-state-metrics/templates/psp.yaml
apiVersion: policy/v1beta1
kind: PodSecurityPolicy
metadata:
  name: logiq-kube-state-metrics
  labels:
    app.kubernetes.io/name: kube-state-metrics
    helm.sh/chart: kube-state-metrics-2.1.19
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
spec:
  privileged: false
  volumes:
    - 'secret'
  hostNetwork: false
  hostIPC: false
  hostPID: false
  runAsUser:
    rule: 'MustRunAs'
    ranges:
      - min: 1001
        max: 1001
  seLinux:
    rule: 'RunAsAny'
  supplementalGroups:
    rule: 'MustRunAs'
    ranges:
      - min: 1001
        max: 1001
  fsGroup:
    rule: 'MustRunAs'
    ranges:
      - min: 1001
        max: 1001
  readOnlyRootFilesystem: false
---
# Source: logiq/charts/prometheus/charts/node-exporter/templates/psp.yaml
apiVersion: policy/v1beta1
kind: PodSecurityPolicy
metadata:
  name: logiq-node-exporter
  labels:
    app.kubernetes.io/name: node-exporter
    helm.sh/chart: node-exporter-2.3.17
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
spec:
  privileged: false
  allowPrivilegeEscalation: false
  requiredDropCapabilities:
    - ALL
  volumes:
    - 'configMap'
    - 'emptyDir'
    - 'projected'
    - 'secret'
    - 'downwardAPI'
    - 'persistentVolumeClaim'
    - 'hostPath'
  hostNetwork: true
  hostIPC: false
  hostPID: true
  hostPorts:
    - min: 0
      max: 65535
  runAsUser:
    rule: 'MustRunAs'
    ranges:
      - min: 1001
        max: 1001
  seLinux:
    rule: 'RunAsAny'
  supplementalGroups:
    rule: 'MustRunAs'
    ranges:
      - min: 1001
        max: 1001
  fsGroup:
    rule: 'MustRunAs'
    ranges:
      - min: 1001
        max: 1001
  readOnlyRootFilesystem: false
---
# Source: logiq/charts/prometheus/templates/alertmanager/psp.yaml
apiVersion: policy/v1beta1
kind: PodSecurityPolicy
metadata:
  name: logiq-prometheus-alertmanager
  labels:
    app.kubernetes.io/name: prometheus
    helm.sh/chart: prometheus-6.5.3
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
    app.kubernetes.io/component: alertmanager
spec:
  privileged: false
  allowPrivilegeEscalation: false
  requiredDropCapabilities:
    - ALL
  volumes:
    - 'configMap'
    - 'emptyDir'
    - 'projected'
    - 'secret'
    - 'downwardAPI'
    - 'persistentVolumeClaim'
  hostNetwork: false
  hostIPC: false
  hostPID: false
  runAsUser:
    rule: 'MustRunAs'
    ranges:
      - min: 1001
        max: 1001
  seLinux:
    rule: 'RunAsAny'
  supplementalGroups:
    rule: 'MustRunAs'
    ranges:
      - min: 1001
        max: 1001
  fsGroup:
    rule: 'MustRunAs'
    ranges:
      - min: 1001
        max: 1001
---
# Source: logiq/charts/prometheus/templates/prometheus-operator/psp.yaml
apiVersion: policy/v1beta1
kind: PodSecurityPolicy
metadata:
  name: logiq-prometheus-operator
  labels:
    app.kubernetes.io/name: prometheus
    helm.sh/chart: prometheus-6.5.3
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
    app.kubernetes.io/component: operator
spec:
  privileged: false
  allowPrivilegeEscalation: false
  requiredDropCapabilities:
    - ALL
  volumes:
    - 'configMap'
    - 'emptyDir'
    - 'projected'
    - 'secret'
    - 'downwardAPI'
    - 'persistentVolumeClaim'
  hostNetwork: false
  hostIPC: false
  hostPID: false
  runAsUser:
    rule: 'MustRunAs'
    ranges:
      - min: 1001
        max: 1001
  seLinux:
    rule: 'RunAsAny'
  supplementalGroups:
    rule: 'MustRunAs'
    ranges:
      - min: 1001
        max: 1001
  fsGroup:
    rule: 'MustRunAs'
    ranges:
      - min: 1001
        max: 1001
---
# Source: logiq/charts/prometheus/templates/prometheus/psp.yaml
apiVersion: policy/v1beta1
kind: PodSecurityPolicy
metadata:
  name: logiq-prometheus-prometheus
  labels:
    app.kubernetes.io/name: prometheus
    helm.sh/chart: prometheus-6.5.3
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
    app.kubernetes.io/component: prometheus
spec:
  privileged: false
  allowPrivilegeEscalation: false
  requiredDropCapabilities:
    - ALL
  volumes:
    - 'configMap'
    - 'emptyDir'
    - 'projected'
    - 'secret'
    - 'downwardAPI'
    - 'persistentVolumeClaim'
  hostNetwork: false
  hostIPC: false
  hostPID: false
  runAsUser:
    rule: 'MustRunAs'
    ranges:
      - min: 1001
        max: 1001
  seLinux:
    rule: 'RunAsAny'
  supplementalGroups:
    rule: 'MustRunAs'
    ranges:
      - min: 1001
        max: 1001
  fsGroup:
    rule: 'MustRunAs'
    ranges:
      - min: 1001
        max: 1001
---
# Source: logiq/charts/redis/templates/psp.yaml
apiVersion: policy/v1beta1
kind: PodSecurityPolicy
metadata:
  name: logiq-redis
  namespace: logiq
  labels:
    app: redis
    chart: redis-10.6.5
    heritage: Helm
    release: logiq
spec:
  allowPrivilegeEscalation: false
  fsGroup:
    rule: 'MustRunAs'
    ranges:
      - min: 1001
        max: 1001
  hostIPC: false
  hostNetwork: false
  hostPID: false
  privileged: false
  readOnlyRootFilesystem: false
  requiredDropCapabilities:
    - ALL
  runAsUser:
    rule: 'MustRunAs'
    ranges:
      - min: 1001
        max: 1001
  seLinux:
    rule: 'RunAsAny'
  supplementalGroups:
    rule: 'MustRunAs'
    ranges:
      - min: 1001
        max: 1001
  volumes:
    - 'configMap'
    - 'secret'
    - 'emptyDir'
    - 'persistentVolumeClaim'
---
# Source: logiq/charts/s3gateway/templates/psp-job.yaml
apiVersion: policy/v1beta1
kind: PodSecurityPolicy
metadata:
  annotations:
    seccomp.security.alpha.kubernetes.io/allowedProfileNames: 'docker/default'
    seccomp.security.alpha.kubernetes.io/defaultProfileName:  'docker/default'
  name: logiq-s3-gateway-job
  namespace: logiq
  labels:
    app: s3-gateway-job
spec:
  allowPrivilegeEscalation: false
  fsGroup:
    rule: 'MustRunAs'
    ranges:
      # Forbid adding the root group.
      - min: 1
        max: 65535
  hostIPC: false
  hostNetwork: false
  hostPID: false
  requiredDropCapabilities:
  - NET_RAW
  privileged: false
  readOnlyRootFilesystem: false
  runAsUser:
    rule: 'RunAsAny'
  seLinux:
    rule: 'RunAsAny'
  supplementalGroups:
    rule: 'MustRunAs'
    ranges:
      # Forbid adding the root group.
      - min: 1
        max: 65535
  volumes:
  - 'configMap'
  - 'downwardAPI'
  - 'emptyDir'
  - 'persistentVolumeClaim'
  - 'projected'
  - 'secret'
---
# Source: logiq/charts/s3gateway/templates/psp.yaml
apiVersion: policy/v1beta1
kind: PodSecurityPolicy
metadata:
  annotations:
    seccomp.security.alpha.kubernetes.io/allowedProfileNames: 'docker/default'
    seccomp.security.alpha.kubernetes.io/defaultProfileName:  'docker/default'
  name: logiq-s3-gateway
  namespace: logiq
  labels:
    app: s3-gateway
spec:
  allowPrivilegeEscalation: false
  fsGroup:
    rule: 'MustRunAs'
    ranges:
      # Forbid adding the root group.
      - min: 1
        max: 65535
  hostIPC: false
  hostNetwork: false
  hostPID: false
  requiredDropCapabilities:
  - NET_RAW
  privileged: false
  readOnlyRootFilesystem: false
  runAsUser:
    rule: 'MustRunAsNonRoot'
  seLinux:
    rule: 'RunAsAny'
  supplementalGroups:
    rule: 'MustRunAs'
    ranges:
      # Forbid adding the root group.
      - min: 1
        max: 65535
  volumes:
  - 'configMap'
  - 'downwardAPI'
  - 'emptyDir'
  - 'persistentVolumeClaim'
  - 'projected'
  - 'secret'
---
# Source: logiq/charts/flash-coffee/templates/service-account.yaml
apiVersion: v1
kind: ServiceAccount
metadata:
  name: flash-coffee
  namespace: logiq
  labels:
    app: flash-coffee
---
# Source: logiq/charts/flash-discovery/templates/service-account.yaml
apiVersion: v1
kind: ServiceAccount
metadata:
  name: flash-discovery
  namespace: logiq
  labels:
    app: flash-discovery
---
# Source: logiq/charts/kubernetes-ingress/templates/controller-serviceaccount.yaml
apiVersion: v1
kind: ServiceAccount
metadata:
  labels:
    app: kubernetes-ingress
    chart: kubernetes-ingress-1.37.0
    heritage: Helm
    release: logiq
  name: ingress-nginx
---
# Source: logiq/charts/kubernetes-ingress/templates/default-backend-serviceaccount.yaml
apiVersion: v1
kind: ServiceAccount
metadata:
  labels:
    app: kubernetes-ingress
    chart: kubernetes-ingress-1.37.0
    heritage: Helm
    release: logiq
  name: logiq-kubernetes-ingress-backend
---
# Source: logiq/charts/logiq-flash/templates/service-account.yaml
apiVersion: v1
kind: ServiceAccount
metadata:
  name: logiq-flash
  namespace: logiq
  labels:
    app: logiq-flash
---
# Source: logiq/charts/logiqctl/templates/service-account.yaml
apiVersion: v1
kind: ServiceAccount
metadata:
  name: logiqctl
  namespace: logiq
  labels:
    app: logiqctl
---
# Source: logiq/charts/postgres/templates/service-account.yaml
apiVersion: v1
kind: ServiceAccount
metadata:
  labels:
    app: postgres
    chart: postgres-8.7.3
    release: "logiq"
    heritage: "Helm"
  name: postgres
  namespace: logiq
---
# Source: logiq/charts/prometheus/charts/kube-state-metrics/templates/serviceaccount.yaml
apiVersion: v1
kind: ServiceAccount
metadata:
  name: logiq-kube-state-metrics
  namespace: logiq
  labels:
    app.kubernetes.io/name: kube-state-metrics
    helm.sh/chart: kube-state-metrics-2.1.19
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
---
# Source: logiq/charts/prometheus/charts/node-exporter/templates/serviceaccount.yaml
apiVersion: v1
kind: ServiceAccount
metadata:
  name: logiq-node-exporter
  namespace: logiq
  labels:
    app.kubernetes.io/name: node-exporter
    helm.sh/chart: node-exporter-2.3.17
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
---
# Source: logiq/charts/prometheus/templates/alertmanager/serviceaccount.yaml
apiVersion: v1
kind: ServiceAccount
metadata:
  name: logiq-prometheus-alertmanager
  namespace: logiq
  labels:
    app.kubernetes.io/name: prometheus
    helm.sh/chart: prometheus-6.5.3
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
    app.kubernetes.io/component: alertmanager
---
# Source: logiq/charts/prometheus/templates/prometheus-operator/serviceaccount.yaml
apiVersion: v1
kind: ServiceAccount
metadata:
  name: logiq-prometheus-operator
  namespace: logiq
  labels:
    app.kubernetes.io/name: prometheus
    helm.sh/chart: prometheus-6.5.3
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
    app.kubernetes.io/component: operator
---
# Source: logiq/charts/prometheus/templates/prometheus/serviceaccount.yaml
apiVersion: v1
kind: ServiceAccount
metadata:
  name: logiq-prometheus-prometheus
  namespace: logiq
  labels:
    app.kubernetes.io/name: prometheus
    helm.sh/chart: prometheus-6.5.3
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
    app.kubernetes.io/component: prometheus
---
# Source: logiq/charts/redis/templates/redis-serviceaccount.yaml
apiVersion: v1
kind: ServiceAccount
metadata:
  name: redis
  namespace: logiq
  labels:
    app: redis
    chart: redis-10.6.5
    release: logiq
    heritage: Helm
---
# Source: logiq/charts/s3gateway/templates/post-install-prometheus-metrics-serviceaccount.yaml
apiVersion: v1
kind: ServiceAccount
metadata:
  name: s3-gateway-update-prometheus-secret
  namespace: logiq
  labels:
    app: s3gateway-update-prometheus-secret
    chart: s3gateway-5.0.20
    release: logiq
    heritage: Helm
---
# Source: logiq/charts/s3gateway/templates/serviceaccount-job.yaml
apiVersion: v1
kind: ServiceAccount
metadata:
  name: s3-gateway-job
  namespace: "logiq"
---
# Source: logiq/charts/s3gateway/templates/serviceaccount.yaml
apiVersion: v1
kind: ServiceAccount
metadata:
  name: "s3-gateway"
  namespace: "logiq"
---
# Source: logiq/charts/thanos/templates/bucketweb/serviceaccount.yaml
apiVersion: v1
kind: ServiceAccount
metadata:
  name: logiq-thanos-bucketweb
  namespace: "logiq"
  labels:
    app.kubernetes.io/name: thanos
    helm.sh/chart: thanos-8.2.5
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
    app.kubernetes.io/component: bucketweb
  annotations:
automountServiceAccountToken: true
---
# Source: logiq/charts/thanos/templates/compactor/serviceaccount.yaml
apiVersion: v1
kind: ServiceAccount
metadata:
  name: logiq-thanos-compactor
  namespace: "logiq"
  labels:
    app.kubernetes.io/name: thanos
    helm.sh/chart: thanos-8.2.5
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
    app.kubernetes.io/component: compactor
  annotations:
automountServiceAccountToken: true
---
# Source: logiq/charts/thanos/templates/query/serviceaccount.yaml
apiVersion: v1
kind: ServiceAccount
metadata:
  name: logiq-thanos-query
  namespace: "logiq"
  labels:
    app.kubernetes.io/name: thanos
    helm.sh/chart: thanos-8.2.5
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
    app.kubernetes.io/component: query
  annotations:
automountServiceAccountToken: true
---
# Source: logiq/charts/thanos/templates/receive/serviceaccount.yaml
apiVersion: v1
kind: ServiceAccount
metadata:
  name: logiq-thanos-receive
  namespace: "logiq"
  labels:
    app.kubernetes.io/name: thanos
    helm.sh/chart: thanos-8.2.5
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
    app.kubernetes.io/component: receive
  annotations:
automountServiceAccountToken: true
---
# Source: logiq/charts/thanos/templates/ruler/serviceaccount.yaml
apiVersion: v1
kind: ServiceAccount
metadata:
  name: logiq-thanos-ruler
  namespace: "logiq"
  labels:
    app.kubernetes.io/name: thanos
    helm.sh/chart: thanos-8.2.5
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
    app.kubernetes.io/component: ruler
  annotations:
automountServiceAccountToken: true
---
# Source: logiq/charts/thanos/templates/storegateway/serviceaccount.yaml
apiVersion: v1
kind: ServiceAccount
metadata:
  name: logiq-thanos-storegateway
  namespace: "logiq"
  labels:
    app.kubernetes.io/name: thanos
    helm.sh/chart: thanos-8.2.5
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
    app.kubernetes.io/component: storegateway
  annotations:
automountServiceAccountToken: true
---
# Source: logiq/charts/flash-coffee/templates/secrets.yaml
apiVersion: v1
kind: Secret
metadata:
  name: logiq-flash-coffee
  namespace: logiq
  labels:
    app: flash-coffee
    chart: flash-coffee-1.0.0
    release: logiq
    heritage: Helm
type: Opaque
data:
  mail_server: "c210cC1tYWlsLXNlcnZlcg==" 
  mail_port: "NTg3" 
  mail_username: "dXNlcg==" 
  mail_password: "cGFzc3dvcmQ=" 
  mail_default_sender: "Zmxhc2gtYWRtaW5AZm9vLmNvbQ==" 
  postgres_coffee_db: "Y29mZmVl" 
  logiq_flash_host: "bG9naXEtZmxhc2g=" 
  logiq_flash_port: "OTk5OQ==" 
  s3_access: "bG9naXFfYWNjZXNz" 
  s3_secret: "bG9naXFfc2VjcmV0" 
  s3_bucket: "bG9naXE=" 
  s3_url: "aHR0cDovL3MzLWdhdGV3YXk6OTAwMA==" 
  admin_email: "Zmxhc2gtYWRtaW5AZm9vLmNvbQ=="
  admin_password: "Zmxhc2gtcGFzc3dvcmQ="
  admin_name: "Zmxhc2gtYWRtaW5AZm9vLmNvbQ=="
  admin_org: "Zmxhc2gtb3Jn"
  postgres_port: "NTQzMg==" 
  postgres_host: "cG9zdGdyZXM=" 
  postgres_password: "cG9zdGdyZXM=" 
  postgres_db: "cG9zdGdyZXM=" 
  postgres_user: "cG9zdGdyZXM=" 
  redis_host: "cmVkaXMtbWFzdGVy" 
  redis_port: "6379" 
  database_url: "cG9zdGdyZXNxbDovL3Bvc3RncmVzOnBvc3RncmVzQHBvc3RncmVzOjU0MzIvcG9zdGdyZXM="
  coffee_database_url: "cG9zdGdyZXNxbDovL3Bvc3RncmVzOnBvc3RncmVzQHBvc3RncmVzOjU0MzIvY29mZmVl"
---
# Source: logiq/charts/flash-discovery/templates/secrets.yaml
apiVersion: v1
kind: Secret
metadata:
  name: flash-discovery
  namespace: logiq
  labels:
    app: flash-discovery
    chart: flash-discovery-1.0.0
    release: logiq
    heritage: Helm
type: Opaque
data:
  postgres_port: "NTQzMg==" 
  postgres_host: "cG9zdGdyZXM=" 
  postgres_password: "cG9zdGdyZXM=" 
  postgres_db: "cG9zdGdyZXM=" 
  postgres_user: "cG9zdGdyZXM=" 
  database_url: "cG9zdGdyZXNxbDovL3Bvc3RncmVzOnBvc3RncmVzQHBvc3RncmVzOjU0MzIvcG9zdGdyZXM="
---
# Source: logiq/charts/logiq-flash/templates/secrets.yaml
apiVersion: v1
kind: Secret
metadata:
  name: logiq-logiq-flash
  namespace: logiq
  labels:
    app: logiq-flash
    chart: logiq-flash-1.0.0
    release: logiq
    heritage: Helm
type: Opaque
data:
  postgres_port: "NTQzMg==" 
  postgres_host: "cG9zdGdyZXM=" 
  postgres_password: "cG9zdGdyZXM=" 
  postgres_db: "cG9zdGdyZXM=" 
  postgres_user: "cG9zdGdyZXM=" 
  redis_host: "cmVkaXMtbWFzdGVy" 
  redis_port: "NjM3OQ==" 
  admin_email: "Zmxhc2gtYWRtaW5AZm9vLmNvbQ=="
  admin_password: "Zmxhc2gtcGFzc3dvcmQ="
---
# Source: logiq/charts/logiqctl/templates/secrets.yaml
apiVersion: v1
kind: Secret
metadata:
  name: logiq-logiqctl
  namespace: logiq
  labels:
    app: logiqctl
    chart: logiqctl-1.0.0
    release: logiq
    heritage: Helm
type: Opaque
data:
  admin_email: "Zmxhc2gtYWRtaW5AZm9vLmNvbQ=="
  admin_password: "Zmxhc2gtcGFzc3dvcmQ="
  admin_name: "Zmxhc2gtYWRtaW5AZm9vLmNvbQ=="
  admin_org: "Zmxhc2gtb3Jn"
---
# Source: logiq/charts/postgres/templates/secrets.yaml
apiVersion: v1
kind: Secret
metadata:
  name: postgres
  namespace: logiq
  labels:
    app: postgres
    chart: postgres-8.7.3
    release: "logiq"
    heritage: "Helm"
type: Opaque
data:
  postgresql-password: "cG9zdGdyZXM="
---
# Source: logiq/charts/prometheus/templates/alertmanager/secrets.yaml
apiVersion: v1
kind: Secret
metadata:
  name: alertmanager-logiq-prometheus-alertmanager
  namespace: logiq
  labels:
    app.kubernetes.io/name: prometheus
    helm.sh/chart: prometheus-6.5.3
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
    app.kubernetes.io/component: alertmanager
data:
  alertmanager.yaml: "Z2xvYmFsOgogIHJlc29sdmVfdGltZW91dDogNW0KcmVjZWl2ZXJzOgotIG5hbWU6ICJudWxsIgpyb3V0ZToKICBncm91cF9ieToKICAtIGpvYgogIGdyb3VwX2ludGVydmFsOiA1bQogIGdyb3VwX3dhaXQ6IDMwcwogIHJlY2VpdmVyOiAibnVsbCIKICByZXBlYXRfaW50ZXJ2YWw6IDEyaAogIHJvdXRlczoKICAtIG1hdGNoOgogICAgICBhbGVydG5hbWU6IFdhdGNoZG9nCiAgICByZWNlaXZlcjogIm51bGwi"
---
# Source: logiq/charts/s3gateway/templates/secrets.yaml
apiVersion: v1
kind: Secret
metadata:
  name: s3-gateway
  namespace: logiq
  labels:
    app: s3gateway
    chart: s3gateway-5.0.20
    release: logiq
    heritage: Helm
type: Opaque
data:
  accesskey: "bG9naXFfYWNjZXNz"
  secretkey: "bG9naXFfc2VjcmV0"
  
  
  
  mchosttarget: "aHR0cDovL2xvZ2lxX2FjY2Vzczpsb2dpcV9zZWNyZXRAczMtZ2F0ZXdheTo5MDAw"
---
# Source: logiq/charts/thanos/templates/objstore-secret.yaml
apiVersion: v1
kind: Secret
metadata:
  name: logiq-thanos-objstore-secret
  namespace: "logiq"
  labels:
    app.kubernetes.io/name: thanos
    helm.sh/chart: thanos-8.2.5
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
data:
  objstore.yml: |-
    dHlwZTogczMKY29uZmlnOgoKICBhY2Nlc3Nfa2V5OiBsb2dpcV9hY2Nlc3MgCiAgc2VjcmV0X2tleTogbG9naXFfc2VjcmV0IAoKICBidWNrZXQ6IGxvZ2lxIAoKICBlbmRwb2ludDogczMtZ2F0ZXdheTo5MDAwIAogIGluc2VjdXJlOiB0cnVlCgogIHJlZ2lvbjogdXMtZWFzdC0xIA==
---
# Source: logiq/charts/kubernetes-ingress/templates/controller-configmap.yaml
apiVersion: v1
kind: ConfigMap
metadata:
  labels:
    app: kubernetes-ingress
    chart: kubernetes-ingress-1.37.0
    component: ""
    heritage: Helm
    release: logiq
  name: logiq-kubernetes-ingress
data:
  use-gzip: "true" # ENABLE GZIP COMPRESSION
  gzip-types: "*" 
  gzip-level: "9"
  map-hash-bucket-size: "128"
  ssl-protocols: SSLv2 SSLv3 TLSv1 TLSv1.1 TLSv1.2 TLSv1.3
  disable-access-log: "false"
---
# Source: logiq/charts/kubernetes-ingress/templates/tcp-configmap.yaml
apiVersion: v1
kind: ConfigMap
metadata:
  labels:
    app: kubernetes-ingress
    chart: kubernetes-ingress-1.37.0
    component: ""
    heritage: Helm
    release: logiq
  name: logiq-kubernetes-ingress-tcp
data:
  "7514": logiq-flash:7514
  "7515": logiq-flash:7515
  "8081": logiq-flash-ml:8081
  "9998": logiq-flash:9998
  "14250": logiq-flash:14250
  "20514": logiq-flash:20514
---
# Source: logiq/charts/logiq-flash/templates/configMap.yaml
apiVersion: v1
kind: ConfigMap
metadata:
  name: logiq-config
  namespace: logiq
data:
  config.yaml: |
    
        options:
    
            ca: "/flash/certs/ca.crt"
    
            cert: "/flash/certs/syslog.crt"
    
            key: "/flash/certs/syslog.key"
    
            host: 0.0.0.0
    
        partitions:
    
          -
    
            name: p_scheme
    
            fields:
    
              - namespace
    
              - appname
    
              - year
    
              - month
    
              - day
    
        credentials:
    
          -
    
            name: logiq
    
            s3:



              secret_key: logiq_secret
    
              access_key: logiq_access


    
        destinations:
    
          -
    
            name: default_log_store
    
            partition: p_scheme
    
            s3:
    
              bucket: logiq
    


              endpoint: http://s3-gateway:9000


    
              credential: logiq
    
        rules:
    
          -
    
            destination: default_log_store
---
# Source: logiq/charts/logiqctl/templates/configmap.yaml
# Source: logiq/charts/logiqctl/templates/configmap.yaml
apiVersion: v1
kind: ConfigMap
metadata:
  name: logiq-logiqctl
  namespace: logiq
  labels:
    app: logiqctl
    chart: logiqctl-1.0.0
    release: logiq
    heritage: Helm
data:
  export: |-
  logiq.json: |
    {
        "datasources": {
            "1": {
                "name": "LogiqMonitoring",
                "options": {
                    "url": "http://logiq-thanos-query:9090"
                },
                "type": "logiq_prometheus"
                }
            }
    }
---
# Source: logiq/charts/postgres/templates/extended-config-configmap.yaml
apiVersion: v1
kind: ConfigMap
metadata:
  name: postgres-extended-configuration
  namespace: logiq
  labels:
    app: postgres
    chart: postgres-8.7.3
    release: "logiq"
    heritage: "Helm"
data:

  override.conf: |
    max_connections=400
    shared_buffers=1024MB
---
# Source: logiq/charts/prometheus/templates/prometheus-operator/configmap.yaml
apiVersion: v1
kind: ConfigMap
metadata:
  name: logiq-prometheus-operator
  namespace: logiq
  labels:
    app.kubernetes.io/name: prometheus
    helm.sh/chart: prometheus-6.5.3
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
    app.kubernetes.io/component: operator
data:
  prometheus-config-reloader: docker.io/bitnami/prometheus-operator:0.53.1-debian-10-r0
---
# Source: logiq/charts/redis/templates/configmap.yaml
apiVersion: v1
kind: ConfigMap
metadata:
  name: redis
  namespace: logiq
  labels:
    app: redis
    chart: redis-10.6.5
    heritage: Helm
    release: logiq
data:
  redis.conf: |-
    # User-supplied configuration:
    # Enable AOF https://redis.io/topics/persistence#append-only-file
    appendonly no
    # Disable RDB persistence, AOF persistence already enabled.
    save ""
    repl-diskless-sync yes
  master.conf: |-
    dir /data
  replica.conf: |-
    dir /data
    slave-read-only yes
---
# Source: logiq/charts/redis/templates/health-configmap.yaml
apiVersion: v1
kind: ConfigMap
metadata:
  name: redis-health
  namespace: logiq
  labels:
    app: redis
    chart: redis-10.6.5
    heritage: Helm
    release: logiq
data:
  ping_readiness_local.sh: |-
    #!/bin/bash
    response=$(
      timeout -s 9 $1 \
      redis-cli \
        -h localhost \
        -p $REDIS_PORT \
        ping
    )
    if [ "$response" != "PONG" ]; then
      echo "$response"
      exit 1
    fi
  ping_liveness_local.sh: |-
    #!/bin/bash
    response=$(
      timeout -s 9 $1 \
      redis-cli \
        -h localhost \
        -p $REDIS_PORT \
        ping
    )
    if [ "$response" != "PONG" ] && [ "$response" != "LOADING Redis is loading the dataset in memory" ]; then
      echo "$response"
      exit 1
    fi
  ping_readiness_master.sh: |-
    #!/bin/bash
     response=$(
      timeout -s 9 $1 \
      redis-cli \
        -h $REDIS_MASTER_HOST \
        -p $REDIS_MASTER_PORT_NUMBER \
        ping
    )
    if [ "$response" != "PONG" ]; then
      echo "$response"
      exit 1
    fi
  ping_liveness_master.sh: |-
    #!/bin/bash
    response=$(
      timeout -s 9 $1 \
      redis-cli \
        -h $REDIS_MASTER_HOST \
        -p $REDIS_MASTER_PORT_NUMBER \
        ping
    )
    if [ "$response" != "PONG" ] && [ "$response" != "LOADING Redis is loading the dataset in memory" ]; then
      echo "$response"
      exit 1
    fi
  ping_readiness_local_and_master.sh: |-
    script_dir="$(dirname "$0")"
    exit_status=0
    "$script_dir/ping_readiness_local.sh" $1 || exit_status=$?
    "$script_dir/ping_readiness_master.sh" $1 || exit_status=$?
    exit $exit_status
  ping_liveness_local_and_master.sh: |-
    script_dir="$(dirname "$0")"
    exit_status=0
    "$script_dir/ping_liveness_local.sh" $1 || exit_status=$?
    "$script_dir/ping_liveness_master.sh" $1 || exit_status=$?
    exit $exit_status
---
# Source: logiq/charts/s3gateway/templates/configmap.yaml
apiVersion: v1
kind: ConfigMap
metadata:
  name: s3-gateway
  namespace: logiq
  labels:
    app: s3gateway
    chart: s3gateway-5.0.20
    release: logiq
    heritage: Helm
data:
  initialize: |-
    #!/bin/sh
    set -e ; # Have script exit in the event of a failed command.
    MC_CONFIG_DIR="/etc/minio/mc/"
    MC="/usr/bin/mc --config-dir ${MC_CONFIG_DIR}"
    
    # connectToMinio
    # Use a check-sleep-check loop to wait for Minio service to be available
    connectToMinio() {
      SCHEME=$1
      ATTEMPTS=0 ; LIMIT=59 ; # Allow 60 attempts
      set -e ; # fail if we can't read the keys.
      ACCESS=$(cat /config/accesskey) ; SECRET=$(cat /config/secretkey) ;
      set +e ; # The connections to minio are allowed to fail.
      echo "Connecting to Minio server: $SCHEME://$MINIO_ENDPOINT:$MINIO_PORT" ;
      MC_COMMAND="${MC} config host add myminio $SCHEME://$MINIO_ENDPOINT:$MINIO_PORT $ACCESS $SECRET" ;
      $MC_COMMAND ;
      STATUS=$? ;
      until [ $STATUS = 0 ]
      do
        ATTEMPTS=`expr $ATTEMPTS + 1` ;
        echo \"Failed attempts: $ATTEMPTS\" ;
        if [ $ATTEMPTS -gt $LIMIT ]; then
          exit 1 ;
        fi ;
        sleep 2 ; # 1 second intervals between attempts
        $MC_COMMAND ;
        STATUS=$? ;
      done ;
      set -e ; # reset `e` as active
      return 0
    }
    
    # checkBucketExists ($bucket)
    # Check if the bucket exists, by using the exit code of `mc ls`
    checkBucketExists() {
      BUCKET=$1
      CMD=$(${MC} ls myminio/$BUCKET > /dev/null 2>&1)
      return $?
    }
    
    # createBucket ($bucket, $policy, $purge)
    # Ensure bucket exists, purging if asked to
    createBucket() {
      BUCKET=$1
      POLICY=$2
      PURGE=$3
    
      # Purge the bucket, if set & exists
      # Since PURGE is user input, check explicitly for `true`
      if [ $PURGE = true ]; then
        if checkBucketExists $BUCKET ; then
          echo "Purging bucket '$BUCKET'."
          set +e ; # don't exit if this fails
          ${MC} rm -r --force myminio/$BUCKET
          set -e ; # reset `e` as active
        else
          echo "Bucket '$BUCKET' does not exist, skipping purge."
        fi
      fi
    
      # Create the bucket if it does not exist
      if ! checkBucketExists $BUCKET ; then
        echo "Creating bucket '$BUCKET'"
        ${MC} mb myminio/$BUCKET
      else
        echo "Bucket '$BUCKET' already exists."
      fi
    
      # At this point, the bucket should exist, skip checking for existence
      # Set policy on the bucket
      echo "Setting policy of bucket '$BUCKET' to '$POLICY'."
      ${MC} policy set $POLICY myminio/$BUCKET
    }
    
    # Try connecting to Minio instance
    scheme=http
    connectToMinio $scheme
    # Create the bucket
    createBucket logiq none false
---
# Source: logiq/charts/thanos/templates/receive/configmap.yaml
apiVersion: v1
kind: ConfigMap
metadata:
  name: logiq-thanos-receive
  namespace: "logiq"
  labels:
    app.kubernetes.io/name: thanos
    helm.sh/chart: thanos-8.2.5
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
    app.kubernetes.io/component: receive
data:
  hashrings.json: |-
    [
      {
        "endpoints": [
            "127.0.0.1:10901"
        ]
      }
    ]
---
# Source: logiq/charts/thanos/templates/ruler/configmap.yaml
apiVersion: v1
kind: ConfigMap
metadata:
  name: logiq-thanos-ruler-configmap
  namespace: "logiq"
  labels:
    app.kubernetes.io/name: thanos
    helm.sh/chart: thanos-8.2.5
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
    app.kubernetes.io/component: ruler
data:
  ruler.yml: |-
    groups:
      - name: "metamonitoring"
        rules:
          - alert: "PrometheusDown"
            expr: absent(up{prometheus="logiq/logiq-prometheus-prometheus"})
---
# Source: logiq/templates/tcpConfigMap.yaml
apiVersion: v1
kind: ConfigMap
metadata:
  name: ingress-tcp-ports
  namespace: logiq
data:

  9998:
    logiq/logiq-flash:9998
  8081:
    logiq/logiq-flash-ml:8081
  514:
    logiq/logiq-flash:514
  7514:
    logiq/logiq-flash:7514
  517:
    logiq/logiq-flash:517
  25225:
    logiq/logiq-flash:25225
  25224:
    logiq/logiq-flash:25224
  20514:
    logiq/logiq-flash:20514
  2514:
    logiq/logiq-flash:2514
  14250: 
    logiq/logiq-flash:14250
  
  14250: logiq/logiq-flash:14250
  20514: logiq/logiq-flash:20514
  7514: logiq/logiq-flash:7514
  7515: logiq/logiq-flash:7515
  8081: logiq/logiq-flash-ml:8081
  9998: logiq/logiq-flash:9998
---
# Source: logiq/charts/thanos/templates/compactor/pvc.yaml
kind: PersistentVolumeClaim
apiVersion: v1
metadata:
  name: logiq-thanos-compactor
  namespace: "logiq"
  labels:
    app.kubernetes.io/name: thanos
    helm.sh/chart: thanos-8.2.5
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
    app.kubernetes.io/component: compactor
spec:
  accessModes:
    - "ReadWriteOnce"
  resources:
    requests:
      storage: "8Gi"
---
# Source: logiq/charts/kubernetes-ingress/templates/clusterrole.yaml
apiVersion: rbac.authorization.k8s.io/v1
kind: ClusterRole
metadata:
  labels:
    app: kubernetes-ingress
    chart: kubernetes-ingress-1.37.0
    heritage: Helm
    release: logiq
  name: logiq-kubernetes-ingress
rules:
  - apiGroups:
      - ""
    resources:
      - configmaps
      - endpoints
      - nodes
      - pods
      - secrets
    verbs:
      - list
      - watch
      - update
  - apiGroups:
      - ""
    resources:
      - nodes
    verbs:
      - get
  - apiGroups:
      - ""
    resources:
      - services
    verbs:
      - get
      - list
      - update
      - watch
  - apiGroups:
      - extensions
      - "networking.k8s.io" # k8s 1.14+
    resources:
      - ingresses
    verbs:
      - get
      - list
      - watch
  - apiGroups:
      - ""
    resources:
      - events
    verbs:
      - create
      - patch
  - apiGroups:
      - extensions
      - "networking.k8s.io" # k8s 1.14+
    resources:
      - ingresses/status
    verbs:
      - update
---
# Source: logiq/charts/logiq-flash/templates/clusterrole.yaml
apiVersion: rbac.authorization.k8s.io/v1
kind: ClusterRole
metadata:
  labels:
    app: logiq-flash
    chart: logiq-flash-1.0.0
    heritage: Helm
  annotations:
    rbac.authorization.kubernetes.io/autoupdate: "true"
  name: logiq-logiq-flash
rules:
- apiGroups:
  - apiextensions.k8s.io
  resources:
  - customresourcedefinitions
  verbs:
  - create
- apiGroups:
  - apiextensions.k8s.io
  resourceNames:
  - alertmanagers.monitoring.coreos.com
  - podmonitors.monitoring.coreos.com
  - prometheuses.monitoring.coreos.com
  - prometheusrules.monitoring.coreos.com
  - servicemonitors.monitoring.coreos.com
  - thanosrulers.monitoring.coreos.com
  resources:
  - customresourcedefinitions
  verbs:
  - get
  - update
- apiGroups:
  - monitoring.coreos.com
  resources:
  - alertmanagers
  - alertmanagers/finalizers
  - prometheuses
  - prometheuses/finalizers
  - thanosrulers
  - thanosrulers/finalizers
  - servicemonitors
  - podmonitors
  - prometheusrules
  verbs:
  - '*'
- apiGroups:
  - ""
  resources:
  - pods
  - pods/log
  verbs:
  - '*'
- apiGroups:
  - ""
  resources:
  - services
  verbs:
  - get
  - watch
  - create
  - delete
  - update
  - patch
  - list
- apiGroups:
  - apps
  resources:
  - statefulsets
  verbs:
  - get
  - list
  - watch
  - create
  - patch
  - delete
  - update
- apiGroups:
  - ""
  resources:
  - nodes
  - persistentvolumes
  - persistentvolumeclaims
  - namespaces
  - pods
  - deployments
  - configmaps
  - secrets
  verbs:
  - get
  - list
  - watch
  - create
  - delete
  - patch
  - update
- apiGroups:
  - storage.k8s.io
  resources:
  - storageclasses
  verbs:
  - get
  - list
  - watch
  - create
  - delete
  - patch
  - update
---
# Source: logiq/charts/prometheus/charts/kube-state-metrics/templates/clusterrole.yaml
apiVersion: rbac.authorization.k8s.io/v1
kind: ClusterRole
metadata:
  name: logiq-kube-state-metrics
  labels:
    app.kubernetes.io/name: kube-state-metrics
    helm.sh/chart: kube-state-metrics-2.1.19
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
rules:
  - apiGroups: ["certificates.k8s.io"]
    resources:
      - certificatesigningrequests
    verbs: ["list", "watch"]
  - apiGroups: [""]
    resources:
      - configmaps
    verbs: ["list", "watch"]
  - apiGroups: ["batch"]
    resources:
      - cronjobs
    verbs: ["list", "watch"]
  - apiGroups: ["extensions", "apps"]
    resources:
      - daemonsets
    verbs: ["list", "watch"]
  - apiGroups: ["extensions", "apps"]
    resources:
      - deployments
    verbs: ["list", "watch"]
  - apiGroups: [""]
    resources:
      - endpoints
    verbs: ["list", "watch"]
  - apiGroups: ["autoscaling"]
    resources:
      - horizontalpodautoscalers
    verbs: ["list", "watch"]
  - apiGroups: ["extensions", "networking.k8s.io"]
    resources:
      - ingresses
    verbs: ["list", "watch"]
  - apiGroups: ["batch"]
    resources:
      - jobs
    verbs: ["list", "watch"]
  - apiGroups: [""]
    resources:
      - limitranges
    verbs: ["list", "watch"]
  - apiGroups: ["admissionregistration.k8s.io"]
    resources:
      - mutatingwebhookconfigurations
    verbs: ["list", "watch"]
  - apiGroups: [""]
    resources:
      - namespaces
    verbs: ["list", "watch"]
  - apiGroups: ["networking.k8s.io"]
    resources:
      - networkpolicies
    verbs: ["list", "watch"]
  - apiGroups: [""]
    resources:
      - nodes
    verbs: ["list", "watch"]
  - apiGroups: [""]
    resources:
      - persistentvolumeclaims
    verbs: ["list", "watch"]
  - apiGroups: [""]
    resources:
      - persistentvolumes
    verbs: ["list", "watch"]
  - apiGroups: ["policy"]
    resources:
      - poddisruptionbudgets
    verbs: ["list", "watch"]
  - apiGroups: [""]
    resources:
      - pods
    verbs: ["list", "watch"]
  - apiGroups: ["extensions", "apps"]
    resources:
      - replicasets
    verbs: ["list", "watch"]
  - apiGroups: [""]
    resources:
      - replicationcontrollers
    verbs: ["list", "watch"]
  - apiGroups: [""]
    resources:
      - resourcequotas
    verbs: ["list", "watch"]
  - apiGroups: [""]
    resources:
      - secrets
    verbs: ["list", "watch"]
  - apiGroups: [""]
    resources:
      - services
    verbs: ["list", "watch"]
  - apiGroups: ["apps"]
    resources:
      - statefulsets
    verbs: ["list", "watch"]
  - apiGroups: ["storage.k8s.io"]
    resources:
      - storageclasses
    verbs: ["list", "watch"]
  - apiGroups: ["storage.k8s.io"]
    resources:
      - volumeattachments
    verbs: ["list", "watch"]
---
# Source: logiq/charts/prometheus/charts/kube-state-metrics/templates/psp-clusterrole.yaml
kind: ClusterRole
apiVersion: rbac.authorization.k8s.io/v1
metadata:
  name: logiq-kube-state-metrics-psp
  labels:
    app.kubernetes.io/name: kube-state-metrics
    helm.sh/chart: kube-state-metrics-2.1.19
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
rules:
  - apiGroups: ['extensions']
    resources: ['podsecuritypolicies']
    verbs: ['use']
    resourceNames:
      - logiq-kube-state-metrics
---
# Source: logiq/charts/prometheus/charts/node-exporter/templates/psp-clusterrole.yaml
kind: ClusterRole
apiVersion: rbac.authorization.k8s.io/v1
metadata:
  name: logiq-node-exporter-psp
  labels:
    app.kubernetes.io/name: node-exporter
    helm.sh/chart: node-exporter-2.3.17
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
rules:
  - apiGroups: ['extensions']
    resources: ['podsecuritypolicies']
    verbs: ['use']
    resourceNames:
      - logiq-node-exporter
---
# Source: logiq/charts/prometheus/templates/alertmanager/psp-clusterrole.yaml
kind: ClusterRole
apiVersion: rbac.authorization.k8s.io/v1
metadata:
  name: logiq-prometheus-alertmanager-psp
  labels:
    app.kubernetes.io/name: prometheus
    helm.sh/chart: prometheus-6.5.3
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
    app.kubernetes.io/component: alertmanager
rules:
  - apiGroups: ['extensions']
    resources: ['podsecuritypolicies']
    verbs: ['use']
    resourceNames:
      - logiq-prometheus-alertmanager
---
# Source: logiq/charts/prometheus/templates/prometheus-operator/clusterrole.yaml
apiVersion: rbac.authorization.k8s.io/v1
kind: ClusterRole
metadata:
  name: logiq-prometheus-operator
  labels:
    app.kubernetes.io/name: prometheus
    helm.sh/chart: prometheus-6.5.3
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
    app.kubernetes.io/component: operator
rules:
  - apiGroups:
      - apiextensions.k8s.io
    resources:
      - customresourcedefinitions
    verbs:
      - create
  - apiGroups:
      - apiextensions.k8s.io
    resourceNames:
      - alertmanagers.monitoring.coreos.com
      - podmonitors.monitoring.coreos.com
      - prometheuses.monitoring.coreos.com
      - prometheusrules.monitoring.coreos.com
      - servicemonitors.monitoring.coreos.com
      - thanosrulers.monitoring.coreos.com
      - probes.monitoring.coreos.com
    resources:
      - customresourcedefinitions
    verbs:
      - get
      - update
  - apiGroups:
      - monitoring.coreos.com
    resources:
      - alertmanagers
      - alertmanagers/finalizers
      - alertmanagerconfigs
      - prometheuses
      - prometheuses/finalizers
      - thanosrulers
      - thanosrulers/finalizers
      - servicemonitors
      - podmonitors
      - probes
      - prometheusrules
    verbs:
      - '*'
  - apiGroups:
      - apps
    resources:
      - statefulsets
    verbs:
      - '*'
  - apiGroups:
      - ""
    resources:
      - configmaps
      - secrets
    verbs:
      - '*'
  - apiGroups:
      - ""
    resources:
      - pods
    verbs:
      - list
      - delete
  - apiGroups:
      - ""
    resources:
      - services
      - services/finalizers
      - endpoints
    verbs:
      - get
      - create
      - update
      - delete
  - apiGroups:
      - ""
    resources:
      - nodes
    verbs:
      - list
      - watch
  - apiGroups:
      - ""
    resources:
      - namespaces
    verbs:
      - get
      - list
      - watch
  - apiGroups:
      - networking.k8s.io
    resources:
      - ingresses
    verbs:
      - get
      - list
      - watch
---
# Source: logiq/charts/prometheus/templates/prometheus-operator/psp-clusterrole.yaml
kind: ClusterRole
apiVersion: rbac.authorization.k8s.io/v1
metadata:
  name: logiq-prometheus-operator-psp
  labels:
    app.kubernetes.io/name: prometheus
    helm.sh/chart: prometheus-6.5.3
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
    app.kubernetes.io/component: operator
rules:
  - apiGroups: ['extensions']
    resources: ['podsecuritypolicies']
    verbs: ['use']
    resourceNames:
      - logiq-prometheus-operator
---
# Source: logiq/charts/prometheus/templates/prometheus/clusterrole.yaml
apiVersion: rbac.authorization.k8s.io/v1
kind: ClusterRole
metadata:
  name: logiq-prometheus-prometheus
  labels:
    app.kubernetes.io/name: prometheus
    helm.sh/chart: prometheus-6.5.3
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
    app.kubernetes.io/component: prometheus
rules:
  - apiGroups:
      - ""
    resources:
      - nodes/metrics
    verbs:
      - get
      - list
      - watch
  - apiGroups:
      - ""
    resources:
      - nodes
      - nodes/proxy
      - services
      - endpoints
      - pods
    verbs:
      - "get"
      - "list"
      - "watch"
  - apiGroups:
      - extensions
      - "networking.k8s.io"
    resources:
      - ingresses
    verbs:
      - get
      - list
      - watch
  - nonResourceURLs:
      - "/metrics"
    verbs:
      - "get"
---
# Source: logiq/charts/prometheus/templates/prometheus/psp-clusterrole.yaml
kind: ClusterRole
apiVersion: rbac.authorization.k8s.io/v1
metadata:
  name: logiq-prometheus-prometheus-psp
  labels:
    app.kubernetes.io/name: prometheus
    helm.sh/chart: prometheus-6.5.3
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
    app.kubernetes.io/component: prometheus
rules:
  - apiGroups: ['extensions']
    resources: ['podsecuritypolicies']
    verbs: ['use']
    resourceNames:
      - logiq-prometheus-prometheus
---
# Source: logiq/charts/kubernetes-ingress/templates/clusterrolebinding.yaml
apiVersion: rbac.authorization.k8s.io/v1
kind: ClusterRoleBinding
metadata:
  labels:
    app: kubernetes-ingress
    chart: kubernetes-ingress-1.37.0
    heritage: Helm
    release: logiq
  name: logiq-kubernetes-ingress
roleRef:
  apiGroup: rbac.authorization.k8s.io
  kind: ClusterRole
  name: logiq-kubernetes-ingress
subjects:
  - kind: ServiceAccount
    name: ingress-nginx
    namespace: logiq
---
# Source: logiq/charts/logiq-flash/templates/clusterrolebinding.yaml
apiVersion: rbac.authorization.k8s.io/v1
kind: ClusterRoleBinding
metadata:
  labels:
    app: logiq-flash
    chart: logiq-flash-1.0.0
    heritage: Helm
  name: logiq-logiq-flash
roleRef:
  apiGroup: rbac.authorization.k8s.io
  kind: ClusterRole
  name: logiq-logiq-flash
subjects:
- kind: ServiceAccount
  name: logiq-flash
  namespace: logiq
---
# Source: logiq/charts/prometheus/charts/kube-state-metrics/templates/clusterrolebinding.yaml
apiVersion: rbac.authorization.k8s.io/v1
kind: ClusterRoleBinding
metadata:
  name: logiq-kube-state-metrics
  labels:
    app.kubernetes.io/name: kube-state-metrics
    helm.sh/chart: kube-state-metrics-2.1.19
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
roleRef:
  apiGroup: rbac.authorization.k8s.io
  kind: ClusterRole
  name: logiq-kube-state-metrics
subjects:
  - kind: ServiceAccount
    name: logiq-kube-state-metrics
    namespace: logiq
---
# Source: logiq/charts/prometheus/charts/kube-state-metrics/templates/psp-clusterrolebinding.yaml
apiVersion: rbac.authorization.k8s.io/v1
kind: ClusterRoleBinding
metadata:
  name: logiq-kube-state-metrics-psp
  labels:
    app.kubernetes.io/name: kube-state-metrics
    helm.sh/chart: kube-state-metrics-2.1.19
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
roleRef:
  apiGroup: rbac.authorization.k8s.io
  kind: ClusterRole
  name: logiq-kube-state-metrics-psp
subjects:
  - kind: ServiceAccount
    name: logiq-kube-state-metrics
    namespace: logiq
---
# Source: logiq/charts/prometheus/charts/node-exporter/templates/psp-clusterrolebinding.yaml
apiVersion: rbac.authorization.k8s.io/v1
kind: ClusterRoleBinding
metadata:
  name: logiq-node-exporter-psp
  labels:
    app.kubernetes.io/name: node-exporter
    helm.sh/chart: node-exporter-2.3.17
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
roleRef:
  apiGroup: rbac.authorization.k8s.io
  kind: ClusterRole
  name: logiq-node-exporter-psp
subjects:
  - kind: ServiceAccount
    name: logiq-node-exporter
    namespace: logiq
---
# Source: logiq/charts/prometheus/templates/alertmanager/psp-clusterrolebinding.yaml
apiVersion: rbac.authorization.k8s.io/v1
kind: ClusterRoleBinding
metadata:
  name: logiq-prometheus-alertmanager-psp
  labels:
    app.kubernetes.io/name: prometheus
    helm.sh/chart: prometheus-6.5.3
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
    app.kubernetes.io/component: alertmanager
roleRef:
  apiGroup: rbac.authorization.k8s.io
  kind: ClusterRole
  name: logiq-prometheus-alertmanager-psp
subjects:
  - kind: ServiceAccount
    name: logiq-prometheus-alertmanager
    namespace: logiq
---
# Source: logiq/charts/prometheus/templates/prometheus-operator/clusterrolebinding.yaml
apiVersion: rbac.authorization.k8s.io/v1
kind: ClusterRoleBinding
metadata:
  name: logiq-prometheus-operator
  labels:
    app.kubernetes.io/name: prometheus
    helm.sh/chart: prometheus-6.5.3
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
    app.kubernetes.io/component: operator
roleRef:
  apiGroup: rbac.authorization.k8s.io
  kind: ClusterRole
  name: logiq-prometheus-operator
subjects:
  - kind: ServiceAccount
    name: logiq-prometheus-operator
    namespace: logiq
---
# Source: logiq/charts/prometheus/templates/prometheus-operator/psp-clusterrolebinding.yaml
apiVersion: rbac.authorization.k8s.io/v1
kind: ClusterRoleBinding
metadata:
  name: logiq-prometheus-operator-psp
  labels:
    app.kubernetes.io/name: prometheus
    helm.sh/chart: prometheus-6.5.3
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
    app.kubernetes.io/component: operator
roleRef:
  apiGroup: rbac.authorization.k8s.io
  kind: ClusterRole
  name: logiq-prometheus-operator-psp
subjects:
  - kind: ServiceAccount
    name: logiq-prometheus-operator
    namespace: logiq
---
# Source: logiq/charts/prometheus/templates/prometheus/clusterrolebinding.yaml
apiVersion: rbac.authorization.k8s.io/v1
kind: ClusterRoleBinding
metadata:
  name: logiq-prometheus-prometheus
  labels:
    app.kubernetes.io/name: prometheus
    helm.sh/chart: prometheus-6.5.3
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
    app.kubernetes.io/component: prometheus
roleRef:
  apiGroup: rbac.authorization.k8s.io
  kind: ClusterRole
  name: logiq-prometheus-prometheus
subjects:
  - kind: ServiceAccount
    name: logiq-prometheus-prometheus
    namespace: logiq
---
# Source: logiq/charts/prometheus/templates/prometheus/psp-clusterrolebinding.yaml
apiVersion: rbac.authorization.k8s.io/v1
kind: ClusterRoleBinding
metadata:
  name: logiq-prometheus-prometheus-psp
  labels:
    app.kubernetes.io/name: prometheus
    helm.sh/chart: prometheus-6.5.3
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
    app.kubernetes.io/component: prometheus
roleRef:
  apiGroup: rbac.authorization.k8s.io
  kind: ClusterRole
  name: logiq-prometheus-prometheus-psp
subjects:
  - kind: ServiceAccount
    name: logiq-prometheus-prometheus
    namespace: logiq
---
# Source: logiq/charts/flash-coffee/templates/role.yaml
# Cluster role which grants access to the default pod security policy
apiVersion: rbac.authorization.k8s.io/v1
kind: Role
metadata:
  name: flash-coffee
  namespace: logiq
  labels:
    app: flash-coffee
rules:
- apiGroups:
  - policy
  resourceNames:
  - flash-coffee
  resources:
  - podsecuritypolicies
  verbs:
  - use
- apiGroups:
  - extensions
  resourceNames:
  - flash-coffee
  resources:
  - podsecuritypolicies
  verbs:
  - use
---
# Source: logiq/charts/flash-discovery/templates/role.yaml
# Cluster role which grants access to the default pod security policy
apiVersion: rbac.authorization.k8s.io/v1
kind: Role
metadata:
  name: flash-discovery
  namespace: logiq
  labels:
    app: flash-discovery
rules:
- apiGroups:
  - policy
  resourceNames:
  - flash-discovery
  resources:
  - podsecuritypolicies
  verbs:
  - use
- apiGroups:
  - extensions
  resourceNames:
  - flash-discovery
  resources:
  - podsecuritypolicies
  verbs:
  - use
---
# Source: logiq/charts/kubernetes-ingress/templates/controller-role.yaml
apiVersion: rbac.authorization.k8s.io/v1
kind: Role
metadata:
  labels:
    app: kubernetes-ingress
    chart: kubernetes-ingress-1.37.0
    heritage: Helm
    release: logiq
  name: logiq-kubernetes-ingress
rules:
  - apiGroups:
      - ""
    resources:
      - namespaces
    verbs:
      - get
  - apiGroups:
      - ""
    resources:
      - configmaps
      - pods
      - secrets
      - endpoints
    verbs:
      - get
      - list
      - watch
  - apiGroups:
      - ""
    resources:
      - services
    verbs:
      - get
      - list
      - update
      - watch
  - apiGroups:
      - extensions
      - "networking.k8s.io" # k8s 1.14+
    resources:
      - ingresses
    verbs:
      - get
      - list
      - watch
  - apiGroups:
      - extensions
      - "networking.k8s.io" # k8s 1.14+
    resources:
      - ingresses/status
    verbs:
      - update
  - apiGroups:
      - ""
    resources:
      - configmaps
    resourceNames:
      - ingress-controller-leader-logiq-ingress-logiq
    verbs:
      - get
      - update
  - apiGroups:
      - ""
    resources:
      - configmaps
    verbs:
      - create
  - apiGroups:
      - ""
    resources:
      - endpoints
    verbs:
      - create
      - get
      - update
  - apiGroups:
      - ""
    resources:
      - events
    verbs:
      - create
      - patch
  - apiGroups:      ['policy']
    resources:      ['podsecuritypolicies']
    verbs:          ['use']
    resourceNames:  [logiq-kubernetes-ingress]
---
# Source: logiq/charts/kubernetes-ingress/templates/default-backend-role.yaml
apiVersion: rbac.authorization.k8s.io/v1
kind: Role
metadata:
  labels:
    app: kubernetes-ingress
    chart: kubernetes-ingress-1.37.0
    heritage: Helm
    release: logiq
  name: logiq-kubernetes-ingress-backend
rules:
  - apiGroups:      ['policy']
    resources:      ['podsecuritypolicies']
    verbs:          ['use']
    resourceNames:  [logiq-kubernetes-ingress-backend]
---
# Source: logiq/charts/logiq-flash/templates/role.yaml
# Cluster role which grants access to the default pod security policy
apiVersion: rbac.authorization.k8s.io/v1
kind: Role
metadata:
  name: logiq-flash
  namespace: logiq
  labels:
    app: logiq-flash
rules:
- apiGroups:
  - policy
  resourceNames:
  - logiq-flash
  resources:
  - podsecuritypolicies
  verbs:
  - use
- apiGroups:
  - extensions
  resourceNames:
  - logiq-flash
  resources:
  - podsecuritypolicies
  verbs:
  - use
---
# Source: logiq/charts/logiqctl/templates/role.yaml
# Role which grants access to the default pod security policy
apiVersion: rbac.authorization.k8s.io/v1
kind: Role
metadata:
  name: logiqctl
  namespace: logiq
  labels:
    app: logiqctl
rules:
- apiGroups:
  - policy
  resourceNames:
  - logiqctl
  resources:
  - podsecuritypolicies
  verbs:
  - use
- apiGroups:
  - extensions
  resourceNames:
  - logiqctl
  resources:
  - podsecuritypolicies
  verbs:
  - use
---
# Source: logiq/charts/postgres/templates/role.yaml
apiVersion: rbac.authorization.k8s.io/v1
kind: Role
metadata:
  name: postgres
  namespace: logiq
  labels:
    app: popstgres
rules:
- apiGroups:
    - policy
  resourceNames:
    - postgres
  resources:
    - podsecuritypolicies
  verbs:
    - use
---
# Source: logiq/charts/redis/templates/redis-role.yaml
apiVersion: rbac.authorization.k8s.io/v1
kind: Role
metadata:
  name: redis
  namespace: logiq
  labels:
    app: redis
    chart: redis-10.6.5
    release: logiq
    heritage: Helm
rules:
  - apiGroups: ['policy']
    resources: ['podsecuritypolicies']
    verbs: ['use']
    resourceNames: [redis]
---
# Source: logiq/charts/s3gateway/templates/post-install-prometheus-metrics-role.yaml
apiVersion: rbac.authorization.k8s.io/v1
kind: Role
metadata:
  name: s3-gateway-update-prometheus-secret
  namespace: logiq
  labels:
    app: s3gateway-update-prometheus-secret
    chart: s3gateway-5.0.20
    release: logiq
    heritage: Helm
rules:
  - apiGroups:
      - ""
    resources:
      - secrets
    verbs:
      - get
      - create
      - update
      - patch
    resourceNames:
      - s3-gateway-prometheus
  - apiGroups:
      - ""
    resources:
      - secrets
    verbs:
      - create
  - apiGroups:
      - monitoring.coreos.com
    resources:
      - servicemonitors
    verbs:
      - get
    resourceNames:
      - s3-gateway
---
# Source: logiq/charts/s3gateway/templates/role-job.yaml
# Cluster role which grants access to the default pod security policy
apiVersion: rbac.authorization.k8s.io/v1
kind: Role
metadata:
  name: s3-gateway-job
  namespace: logiq
  labels:
    app: s3-gateway-job
rules:
- apiGroups:
  - policy
  resourceNames:
  - s3-gateway-job
  resources:
  - podsecuritypolicies
  verbs:
  - use
- apiGroups:
  - extensions
  resourceNames:
  - s3-gateway-job
  resources:
  - podsecuritypolicies
  verbs:
  - use
---
# Source: logiq/charts/s3gateway/templates/role.yaml
# Cluster role which grants access to the default pod security policy
apiVersion: rbac.authorization.k8s.io/v1
kind: Role
metadata:
  name: s3-gateway
  namespace: logiq
  labels:
    app: s3-gateway
rules:
- apiGroups:
  - policy
  resourceNames:
  - s3-gateway
  resources:
  - podsecuritypolicies
  verbs:
  - use
- apiGroups:
  - extensions
  resourceNames:
  - s3-gateway
  resources:
  - podsecuritypolicies
  verbs:
  - use
---
# Source: logiq/charts/flash-coffee/templates/role-binding.yaml
# Cluster role binding for default pod security policy granting all authenticated users access
apiVersion: rbac.authorization.k8s.io/v1
kind: RoleBinding
metadata:
  name: flash-coffee
  namespace: logiq
  labels:
    app: flash-coffee
roleRef:
  apiGroup: rbac.authorization.k8s.io
  kind: Role
  name: flash-coffee
subjects:
- kind: ServiceAccount
  name: flash-coffee
  namespace: logiq
---
# Source: logiq/charts/flash-discovery/templates/role-binding.yaml
# Cluster role binding for default pod security policy granting all authenticated users access
apiVersion: rbac.authorization.k8s.io/v1
kind: RoleBinding
metadata:
  name: flash-discovery
  namespace: logiq
  labels:
    app: flash-discovery
roleRef:
  apiGroup: rbac.authorization.k8s.io
  kind: Role
  name: flash-discovery
subjects:
- kind: ServiceAccount
  name: flash-discovery
  namespace: logiq
---
# Source: logiq/charts/kubernetes-ingress/templates/controller-rolebinding.yaml
apiVersion: rbac.authorization.k8s.io/v1
kind: RoleBinding
metadata:
  labels:
    app: kubernetes-ingress
    chart: kubernetes-ingress-1.37.0
    heritage: Helm
    release: logiq
  name: logiq-kubernetes-ingress
roleRef:
  apiGroup: rbac.authorization.k8s.io
  kind: Role
  name: logiq-kubernetes-ingress
subjects:
  - kind: ServiceAccount
    name: ingress-nginx
    namespace: logiq
---
# Source: logiq/charts/kubernetes-ingress/templates/default-backend-rolebinding.yaml
apiVersion: rbac.authorization.k8s.io/v1
kind: RoleBinding
metadata:
  labels:
    app: kubernetes-ingress
    chart: kubernetes-ingress-1.37.0
    heritage: Helm
    release: logiq
  name: logiq-kubernetes-ingress-backend
roleRef:
  apiGroup: rbac.authorization.k8s.io
  kind: Role
  name: logiq-kubernetes-ingress-backend
subjects:
  - kind: ServiceAccount
    name: logiq-kubernetes-ingress-backend
    namespace: logiq
---
# Source: logiq/charts/logiq-flash/templates/role-binding.yaml
# Cluster role binding for default pod security policy granting all authenticated users access
apiVersion: rbac.authorization.k8s.io/v1
kind: RoleBinding
metadata:
  name: logiq-flash
  namespace: logiq
  labels:
    app: logiq-flash
roleRef:
  apiGroup: rbac.authorization.k8s.io
  kind: Role
  name: logiq-flash
subjects:
- kind: ServiceAccount
  name: logiq-flash
  namespace: logiq
---
# Source: logiq/charts/logiqctl/templates/role-binding.yaml
# Role binding for default pod security policy granting all authenticated users access
apiVersion: rbac.authorization.k8s.io/v1
kind: RoleBinding
metadata:
  name: logiqctl
  namespace: logiq
  labels:
    app: logiqctl
roleRef:
  apiGroup: rbac.authorization.k8s.io
  kind: Role
  name: logiqctl
subjects:
- kind: ServiceAccount
  name: logiqctl
  namespace: logiq
---
# Source: logiq/charts/postgres/templates/role-binding.yaml
apiVersion: rbac.authorization.k8s.io/v1
kind: RoleBinding
metadata:
  name: postgres
  namespace: logiq
roleRef:
  apiGroup: rbac.authorization.k8s.io
  kind: Role
  name: postgres
subjects:
- kind: ServiceAccount
  name: postgres
---
# Source: logiq/charts/redis/templates/redis-rolebinding.yaml
apiVersion: rbac.authorization.k8s.io/v1
kind: RoleBinding
metadata:
  name: redis
  namespace: logiq
  labels:
    app: redis
    chart: redis-10.6.5
    release: logiq
    heritage: Helm
roleRef:
  apiGroup: rbac.authorization.k8s.io
  kind: Role
  name: redis
subjects:
- kind: ServiceAccount
  name: redis
---
# Source: logiq/charts/s3gateway/templates/post-install-prometheus-metrics-rolebinding.yaml
apiVersion: rbac.authorization.k8s.io/v1
kind: RoleBinding
metadata:
  name: s3-gateway-update-prometheus-secret
  namespace: logiq
  labels:
    app: s3gateway-update-prometheus-secret
    chart: s3gateway-5.0.20
    release: logiq
    heritage: Helm
roleRef:
  apiGroup: rbac.authorization.k8s.io
  kind: Role
  name: s3-gateway-update-prometheus-secret
subjects:
  - kind: ServiceAccount
    name: s3-gateway-update-prometheus-secret
    namespace: logiq
---
# Source: logiq/charts/s3gateway/templates/role-binding-job.yaml
# Cluster role binding for default pod security policy granting all authenticated users access
apiVersion: rbac.authorization.k8s.io/v1
kind: RoleBinding
metadata:
  name: s3-gateway-job
  namespace: logiq
  labels:
    app: s3-gateway-job
roleRef:
  apiGroup: rbac.authorization.k8s.io
  kind: Role
  name: s3-gateway-job
subjects:
- kind: ServiceAccount
  name: s3-gateway-job
  namespace: logiq
---
# Source: logiq/charts/s3gateway/templates/role-binding.yaml
# Cluster role binding for default pod security policy granting all authenticated users access
apiVersion: rbac.authorization.k8s.io/v1
kind: RoleBinding
metadata:
  name: s3-gateway
  namespace: logiq
  labels:
    app: s3-gateway
roleRef:
  apiGroup: rbac.authorization.k8s.io
  kind: Role
  name: s3-gateway
subjects:
- kind: ServiceAccount
  name: "s3-gateway"
  namespace: logiq
---
# Source: logiq/charts/flash-coffee/templates/002-coffee-server-service.yaml
apiVersion: v1
kind: Service
metadata:
  name: coffee
  namespace: logiq
spec:
  type: NodePort
  ports:
  - name: "http"
    port: 80
    targetPort: 5000
  selector:
    app: coffee-server
status:
  loadBalancer: {}
---
# Source: logiq/charts/flash-discovery/templates/discoveryService.yaml
apiVersion: v1
kind: Service
metadata:
  name: flash-discovery
  namespace: logiq
  labels:
    app: flash-discovery
    chart: flash-discovery-1.0.0
    release: logiq
    heritage: Helm
spec:
  type: ClusterIP
  ports:
    - port: 8081
      targetPort: 8081
      protocol: TCP
      name: discovery-health
    - port: 4000
      targetPort: 4000
      protocol: TCP
      name: discovery-api

  selector:
    app: flash-discovery
    release: logiq
---
# Source: logiq/charts/kubernetes-ingress/templates/controller-service.yaml
apiVersion: v1
kind: Service
metadata:
  labels:
    app: kubernetes-ingress
    chart: kubernetes-ingress-1.37.0
    component: ""
    heritage: Helm
    release: logiq
  name: logiq-kubernetes-ingress
spec:
  ports:
    - name: http
      port: 80
      protocol: TCP
      targetPort: http
    - name: "14250-tcp"
      port: 14250
      protocol: TCP
      targetPort: "14250-tcp"
    - name: "20514-tcp"
      port: 20514
      protocol: TCP
      targetPort: "20514-tcp"
    - name: "7514-tcp"
      port: 7514
      protocol: TCP
      targetPort: "7514-tcp"
    - name: "7515-tcp"
      port: 7515
      protocol: TCP
      targetPort: "7515-tcp"
    - name: "8081-tcp"
      port: 8081
      protocol: TCP
      targetPort: "8081-tcp"
    - name: "9998-tcp"
      port: 9998
      protocol: TCP
      targetPort: "9998-tcp"
  selector:
    app: kubernetes-ingress
    release: logiq
    app.kubernetes.io/component: controller
  type: "LoadBalancer"
---
# Source: logiq/charts/kubernetes-ingress/templates/default-backend-service.yaml
apiVersion: v1
kind: Service
metadata:
  labels:
    app: kubernetes-ingress
    chart: kubernetes-ingress-1.37.0
    component: "default-backend"
    heritage: Helm
    release: logiq
  name: logiq-kubernetes-ingress-default-backend
spec:
  ports:
    - name: http
      port: 80
      protocol: TCP
      targetPort: http
  selector:
    app: kubernetes-ingress
    release: logiq
    app.kubernetes.io/component: default-backend
  type: "ClusterIP"
---
# Source: logiq/charts/logiq-flash/templates/service-headless-ml.yaml
apiVersion: v1
kind: Service
metadata:
  name: logiq-flash-ml
  namespace: logiq
  labels:
    app: logiq-flash-ml
    chart: logiq-flash-1.0.0
    release: logiq
    heritage: Helm
    promMonitor: logiq-flash
spec:
  clusterIP: None
  type: ClusterIP
  ports:
    - port: 16686
      targetPort: 16686
      protocol: TCP
      name: tracingui
    - port: 8081
      targetPort: 50054
      protocol: TCP
      name: grpc
    - port: 9998
      targetPort: 9998
      protocol: TCP
      name: webcli
    - port: 9999
      targetPort: 9999
      protocol: TCP
      name: api
    - port: 8080
      targetPort: 8080
      protocol: TCP
      name: liveness-port
  selector:
    app: logiq-flash-ml
    release: logiq
---
# Source: logiq/charts/logiq-flash/templates/service-headless-sync.yaml
apiVersion: v1
kind: Service
metadata:
  name: logiq-flash-sync
  namespace: logiq
  labels:
    app: logiq-flash-sync
    chart: logiq-flash-1.0.0
    release: logiq
    heritage: Helm
    promMonitor: logiq-flash
spec:
  clusterIP: None
  type: ClusterIP
  ports:
    - port: 8081
      targetPort: 50054
      protocol: TCP
      name: grpc
    - port: 9998
      targetPort: 9998
      protocol: TCP
      name: webcli
    - port: 9999
      targetPort: 9999
      protocol: TCP
      name: api
    - port: 8080
      targetPort: 8080
      protocol: TCP
      name: liveness-port
  selector:
    app: logiq-flash-sync
    release: logiq
---
# Source: logiq/charts/logiq-flash/templates/service-headless.yaml
apiVersion: v1
kind: Service
metadata:
  name: logiq-flash-headless
  namespace: logiq
  labels:
    app: logiq-flash-headless
    chart: logiq-flash-1.0.0
    release: logiq
    heritage: Helm
    promMonitor: logiq-flash
spec:
  clusterIP: None
  ports:
    - port: 14250
      targetPort: 14250
      protocol: TCP
      name: tracinggrpc
    - port: 8081
      targetPort: 50054
      protocol: TCP
      name: grpc
    - port: 9999
      targetPort: 9999
      protocol: TCP
      name: api
    - port: 9998
      targetPort: 9998
      protocol: TCP
      name: webcli
    - port: 514
      targetPort: 1514
      protocol: TCP
      name: syslog
    - port: 7514
      targetPort: 7514
      protocol: TCP
      name: syslogtls
    - port: 515
      targetPort: 1515
      protocol: TCP
      name: cefport
    - port: 7515
      targetPort: 7515
      protocol: TCP
      name: cefportls
    - port: 20514
      targetPort: 20514
      protocol: TCP
      name: relp
    - port: 2514
      targetPort: 2514
      protocol: TCP
      name: relptls
    - port: 24225
      targetPort: 24225
      protocol: TCP
      name: fluentfwdtls
    - port: 24224
      targetPort: 24224
      protocol: TCP
      name: fluentforward
    - port: 25224
      targetPort: 25224
      protocol: TCP
      name: filebeat
    - port: 25225
      targetPort: 25225
      protocol: TCP
      name: filebeatls
    - port: 8080
      targetPort: 8080
      protocol: TCP
      name: liveness-port
    - port: 517
      targetPort: 1517
      protocol: TCP
      name: rawtcp
  selector:
    app: logiq-flash
    release: logiq
---
# Source: logiq/charts/logiq-flash/templates/service.yaml
apiVersion: v1
kind: Service
metadata:
  name: logiq-flash
  namespace: logiq
  labels:
    app: logiq-flash
    chart: logiq-flash-1.0.0
    release: logiq
    heritage: Helm
spec:
  type: NodePort
  ports:
    - port: 14250
      targetPort: 14250
      protocol: TCP
      name: tracinggrpc
    - port: 8081
      targetPort: 50054
      protocol: TCP
      name: grpc
    - port: 9998
      targetPort: 9998
      protocol: TCP
      name: webcli
    - port: 9999
      targetPort: 9999
      protocol: TCP
      name: api
    - port: 514
      targetPort: 1514
      protocol: TCP
      name: syslog
    - port: 7514
      targetPort: 7514
      protocol: TCP
      name: syslogtls
    - port: 515
      targetPort: 1515
      protocol: TCP
      name: cefport
    - port: 7515
      targetPort: 7515
      protocol: TCP
      name: cefportls
    - port: 2514
      targetPort: 2514
      protocol: TCP
      name: relptls
    - port: 20514
      targetPort: 20514
      protocol: TCP
      name: relp
    - port: 24225
      targetPort: 24225
      protocol: TCP
      name: fluentfwdtls
    - port: 24224
      targetPort: 24224
      protocol: TCP
      name: fluentforward
    - port: 8080
      targetPort: 8080
      protocol: TCP
      name: liveness-port
    - port: 25224
      targetPort: 25224
      protocol: TCP
      name: filebeat
    - port: 25225
      targetPort: 25225
      protocol: TCP
      name: filebeatls
    - port: 517
      targetPort: 1517
      protocol: TCP
      name: rawtcp
  selector:
    app: logiq-flash
    release: logiq
---
# Source: logiq/charts/postgres/templates/metrics-svc.yaml
apiVersion: v1
kind: Service
metadata:
  name: postgres-metrics
  namespace: logiq
  labels:
    app: postgres
    chart: postgres-8.7.3
    release: "logiq"
    heritage: "Helm"
  annotations:
    prometheus.io/port: "9187"
    prometheus.io/scrape: "true"
spec:
  type: ClusterIP
  ports:
    - name: http-metrics
      port: 9187
      targetPort: http-metrics
  selector:
    app: postgres
    release: logiq
    role: master
---
# Source: logiq/charts/postgres/templates/svc-headless.yaml
apiVersion: v1
kind: Service
metadata:
  name: postgres-headless
  namespace: logiq
  labels:
    app: postgres
    chart: postgres-8.7.3
    release: "logiq"
    heritage: "Helm"
spec:
  type: ClusterIP
  clusterIP: None
  ports:
    - name: tcp-postgresql
      port: 5432
      targetPort: tcp-postgresql
  selector:
    app: postgres
    release: "logiq"
---
# Source: logiq/charts/postgres/templates/svc.yaml
apiVersion: v1
kind: Service
metadata:
  name: postgres
  namespace: logiq
  labels:
    app: postgres
    chart: postgres-8.7.3
    release: "logiq"
    heritage: "Helm"
spec:
  type: ClusterIP
  ports:
    - name: tcp-postgresql
      port: 5432
      targetPort: tcp-postgresql
  selector:
    app: postgres
    release: "logiq"
    role: master
---
# Source: logiq/charts/prometheus/charts/kube-state-metrics/templates/service.yaml
apiVersion: v1
kind: Service
metadata:
  name: logiq-kube-state-metrics
  namespace: logiq
  annotations:
  labels:
    app.kubernetes.io/name: kube-state-metrics
    helm.sh/chart: kube-state-metrics-2.1.19
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
spec:
  type: ClusterIP
  ports:
    - name: http
      port: 8080
      targetPort: http
      nodePort: null
  selector:
    app.kubernetes.io/name: kube-state-metrics
    app.kubernetes.io/instance: logiq
---
# Source: logiq/charts/prometheus/charts/node-exporter/templates/service.yaml
apiVersion: v1
kind: Service
metadata:
  name: logiq-node-exporter
  namespace: logiq
  annotations:
    prometheus.io/scrape: "true"
  labels:
    app.kubernetes.io/name: node-exporter
    helm.sh/chart: node-exporter-2.3.17
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
    jobLabel: node-exporter
spec:
  type: ClusterIP
  ports:
    - name: metrics
      port: 9100
      targetPort: metrics
      nodePort: null
  selector:
    app.kubernetes.io/name: node-exporter
    app.kubernetes.io/instance: logiq
---
# Source: logiq/charts/prometheus/templates/alertmanager/service.yaml
apiVersion: v1
kind: Service
metadata:
  name: logiq-prometheus-alertmanager
  namespace: logiq
  labels:
    app.kubernetes.io/name: prometheus
    helm.sh/chart: prometheus-6.5.3
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
    app.kubernetes.io/component: alertmanager
spec:
  type: ClusterIP
  ports:
    - name: http
      port: 9093
      targetPort: 9093
  selector:
    app.kubernetes.io/name: alertmanager
    alertmanager: logiq-prometheus-alertmanager
---
# Source: logiq/charts/prometheus/templates/prometheus-operator/service.yaml
apiVersion: v1
kind: Service
metadata:
  name: logiq-prometheus-operator
  namespace: logiq
  labels:
    app.kubernetes.io/name: prometheus
    helm.sh/chart: prometheus-6.5.3
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
    app.kubernetes.io/component: operator
spec:
  type: ClusterIP
  ports:
    - name: http
      port: 8080
      targetPort: http
  selector:
    app.kubernetes.io/name: prometheus
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/component: operator
---
# Source: logiq/charts/prometheus/templates/prometheus/service.yaml
apiVersion: v1
kind: Service
metadata:
  name: logiq-prometheus-prometheus
  namespace: logiq
  labels:
    app.kubernetes.io/name: prometheus
    helm.sh/chart: prometheus-6.5.3
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
    app.kubernetes.io/component: prometheus
spec:
  type: ClusterIP
  ports:
    - name: http
      port: 9090
      targetPort: 9090
      protocol: TCP
  selector:
    app.kubernetes.io/name: prometheus
    prometheus: logiq-prometheus-prometheus
---
# Source: logiq/charts/prometheus/templates/prometheus/thanos-service.yaml
apiVersion: v1
kind: Service
metadata:
  name: logiq-prometheus-prometheus-thanos
  namespace: logiq
  labels:
    app.kubernetes.io/name: prometheus
    helm.sh/chart: prometheus-6.5.3
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
    app.kubernetes.io/component: prometheus
    app.kubernetes.io/subcomponent: thanos
spec:
  type: ClusterIP
  clusterIP: None
  ports:
    - name: grpc
      port: 10901
      targetPort: grpc
      protocol: TCP
  selector:
    app.kubernetes.io/name: prometheus
    prometheus: logiq-prometheus-prometheus
---
# Source: logiq/charts/redis/templates/headless-svc.yaml
apiVersion: v1
kind: Service
metadata:
  name: redis-headless
  namespace: logiq
  labels:
    app: redis
    chart: redis-10.6.5
    release: logiq
    heritage: Helm
spec:
  type: ClusterIP
  clusterIP: None
  ports:
  - name: redis
    port: 6379
    targetPort: redis
  selector:
    app: redis
    release: logiq
---
# Source: logiq/charts/redis/templates/metrics-svc.yaml
apiVersion: v1
kind: Service
metadata:
  name: redis-metrics
  namespace: logiq
  labels:
    app: redis
    chart: redis-10.6.5
    release: logiq
    heritage: Helm
spec:
  type: ClusterIP
  ports:
  - name: metrics
    port: 9121
    targetPort: metrics
  selector:
    app: redis
    release: logiq
---
# Source: logiq/charts/redis/templates/redis-master-svc.yaml
apiVersion: v1
kind: Service
metadata:
  name: redis-master
  namespace: logiq
  labels:
    app: redis
    chart: redis-10.6.5
    release: logiq
    heritage: Helm
spec:
  type: ClusterIP
  ports:
  - name: redis
    port: 6379
    targetPort: redis
  selector:
    app: redis
    release: logiq
    role: master
---
# Source: logiq/charts/s3gateway/templates/service.yaml
apiVersion: v1
kind: Service
metadata:
  name: s3-gateway
  namespace: logiq
  labels:
    app: s3gateway
    chart: s3gateway-5.0.20
    release: logiq
    heritage: Helm
spec:
  type: ClusterIP
  ports:
    - name: http
      port: 9000
      protocol: TCP
      targetPort: 9000
  selector:
    app: s3gateway
    release: logiq
---
# Source: logiq/charts/s3gateway/templates/statefulset.yaml
apiVersion: v1
kind: Service
metadata:
  name: s3-gateway-svc
  namespace: logiq
  labels:
    app: s3gateway
    chart: s3gateway-5.0.20
    release: "logiq"
    heritage: "Helm"
spec:
  publishNotReadyAddresses: true
  clusterIP: None
  ports:
    - name: http
      port: 9000
      protocol: TCP
  selector:
    app: s3gateway
    release: logiq
---
# Source: logiq/charts/thanos/templates/bucketweb/service.yaml
apiVersion: v1
kind: Service
metadata:
  name: logiq-thanos-bucketweb
  namespace: "logiq"
  labels:
    app.kubernetes.io/name: thanos
    helm.sh/chart: thanos-8.2.5
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
    app.kubernetes.io/component: bucketweb
  annotations:
spec:
  type: ClusterIP
  ports:
    - port: 8080
      targetPort: http
      protocol: TCP
      name: http
      nodePort: null
  selector:
    app.kubernetes.io/name: thanos
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/component: bucketweb
---
# Source: logiq/charts/thanos/templates/compactor/service.yaml
apiVersion: v1
kind: Service
metadata:
  name: logiq-thanos-compactor
  namespace: "logiq"
  labels:
    app.kubernetes.io/name: thanos
    helm.sh/chart: thanos-8.2.5
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
    app.kubernetes.io/component: compactor
  annotations:
spec:
  type: ClusterIP
  ports:
    - port: 9090
      targetPort: http
      protocol: TCP
      name: http
      nodePort: null
  selector:
    app.kubernetes.io/name: thanos
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/component: compactor
---
# Source: logiq/charts/thanos/templates/query/service.yaml
apiVersion: v1
kind: Service
metadata:
  name: logiq-thanos-query
  namespace: "logiq"
  labels:
    app.kubernetes.io/name: thanos
    helm.sh/chart: thanos-8.2.5
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
    app.kubernetes.io/component: query
  annotations:
spec:
  type: ClusterIP
  ports:
    - port: 9090
      targetPort: http
      protocol: TCP
      name: http
      nodePort: null
    - port: 10901
      targetPort: grpc
      protocol: TCP
      name: grpc
      nodePort: null
  selector:
    app.kubernetes.io/name: thanos
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/component: query
---
# Source: logiq/charts/thanos/templates/receive/service.yaml
apiVersion: v1
kind: Service
metadata:
  name: logiq-thanos-receive
  namespace: "logiq"
  labels:
    app.kubernetes.io/name: thanos
    helm.sh/chart: thanos-8.2.5
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
    app.kubernetes.io/component: receive
  annotations:    
spec:
  type: ClusterIP
  ports:
    - port: 10902
      targetPort: http
      protocol: TCP
      name: http
      nodePort: null
    - port: 10901
      targetPort: grpc
      protocol: TCP
      name: grpc
      nodePort: null
    - port: 19291
      targetPort: remote-write
      protocol: TCP
      name: remote
      nodePort: null
  selector:
    app.kubernetes.io/name: thanos
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/component: receive
---
# Source: logiq/charts/thanos/templates/ruler/service.yaml
apiVersion: v1
kind: Service
metadata:
  name: logiq-thanos-ruler
  namespace: "logiq"
  labels:
    app.kubernetes.io/name: thanos
    helm.sh/chart: thanos-8.2.5
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
    app.kubernetes.io/component: ruler
    prometheus-operator/monitor: 'true'
  annotations:
spec:
  type: ClusterIP
  ports:
    - port: 9090
      targetPort: http
      protocol: TCP
      name: http
      nodePort: null
    - port: 10901
      targetPort: grpc
      protocol: TCP
      name: grpc
      nodePort: null
  selector:
    app.kubernetes.io/name: thanos
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/component: ruler
---
# Source: logiq/charts/thanos/templates/storegateway/service.yaml
apiVersion: v1
kind: Service
metadata:
  name: logiq-thanos-storegateway
  namespace: "logiq"
  labels:
    app.kubernetes.io/name: thanos
    helm.sh/chart: thanos-8.2.5
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
    app.kubernetes.io/component: storegateway
    prometheus-operator/monitor: 'true'
  annotations:
spec:
  type: ClusterIP
  ports:
    - port: 9090
      targetPort: http
      protocol: TCP
      name: http
      nodePort: null
    - port: 10901
      targetPort: grpc
      protocol: TCP
      name: grpc
      nodePort: null
  selector:
    app.kubernetes.io/name: thanos
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/component: storegateway
---
# Source: logiq/charts/prometheus/charts/node-exporter/templates/daemonset.yaml
apiVersion: apps/v1
kind: DaemonSet
metadata:
  name: logiq-node-exporter
  namespace: logiq
  labels:
    app.kubernetes.io/name: node-exporter
    helm.sh/chart: node-exporter-2.3.17
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
spec:
  selector:
    matchLabels:
      app.kubernetes.io/name: node-exporter
      app.kubernetes.io/instance: logiq
  updateStrategy:
    rollingUpdate:
      maxUnavailable: 1
    type: RollingUpdate
  minReadySeconds: 0
  template:
    metadata:
      labels:
        app.kubernetes.io/name: node-exporter
        helm.sh/chart: node-exporter-2.3.17
        app.kubernetes.io/instance: logiq
        app.kubernetes.io/managed-by: Helm
    spec:
      
      serviceAccountName: logiq-node-exporter
      affinity:
        podAffinity:
          
        podAntiAffinity:
          preferredDuringSchedulingIgnoredDuringExecution:
            - podAffinityTerm:
                labelSelector:
                  matchLabels:
                    app.kubernetes.io/name: node-exporter
                    app.kubernetes.io/instance: logiq
                namespaces:
                  - "logiq"
                topologyKey: kubernetes.io/hostname
              weight: 1
        nodeAffinity:
          
      securityContext:
        runAsUser: 1001
        fsGroup: 1001
        runAsNonRoot: 
      containers:
        - name: node-exporter
          image: docker.io/bitnami/node-exporter:1.3.1-debian-10-r0
          imagePullPolicy: IfNotPresent
          args:
            - --path.procfs=/host/proc
            - --path.sysfs=/host/sys
            - --web.listen-address=0.0.0.0:9100
            - --collector.filesystem.ignored-fs-types=^(autofs|binfmt_misc|cgroup|configfs|debugfs|devpts|devtmpfs|fusectl|hugetlbfs|mqueue|overlay|proc|procfs|pstore|rpc_pipefs|securityfs|sysfs|tracefs)$
            - --collector.filesystem.ignored-mount-points=^/(dev|proc|sys|var/lib/docker/.+)($|/)
          ports:
            - name: metrics
              containerPort: 9100
              protocol: TCP
          livenessProbe:
            failureThreshold: 6
            initialDelaySeconds: 120
            periodSeconds: 10
            successThreshold: 1
            timeoutSeconds: 5
            httpGet:
              path: /
              port: metrics
          readinessProbe:
            failureThreshold: 6
            initialDelaySeconds: 30
            periodSeconds: 10
            successThreshold: 1
            timeoutSeconds: 5
            httpGet:
              path: /
              port: metrics
          resources:
            limits: {}
            requests: {}
          volumeMounts:
            - name: proc
              mountPath: /host/proc
              readOnly: true
            - name: sys
              mountPath: /host/sys
              readOnly: true
      hostNetwork: true
      hostPID: true
      volumes:
        - name: proc
          hostPath:
            path: /proc
        - name: sys
          hostPath:
            path: /sys
---
# Source: logiq/charts/kubernetes-ingress/templates/controller-deployment.yaml
apiVersion: apps/v1
kind: Deployment
metadata:
  labels:
    app: kubernetes-ingress
    chart: kubernetes-ingress-1.37.0
    heritage: Helm
    release: logiq
    app.kubernetes.io/component: controller
  name: logiq-kubernetes-ingress
  annotations:
    {}
spec:
  selector:
    matchLabels:
      app: kubernetes-ingress
      release: logiq
  replicas: 1
  revisionHistoryLimit: 10
  strategy:
    {}
  minReadySeconds: 0
  template:
    metadata:
      labels:
        app: kubernetes-ingress
        release: logiq
        component: ""
        app.kubernetes.io/component: controller
    spec:
      dnsPolicy: ClusterFirst
      containers:
        - name: logiq-kubernetes-ingress
          image: "k8s.gcr.io/ingress-nginx/controller:v1.2.0"
          imagePullPolicy: "IfNotPresent"
          args:
            - /nginx-ingress-controller
            - --default-backend-service=logiq/logiq-kubernetes-ingress-default-backend
            - --election-id=ingress-controller-leader
            - --ingress-class=logiq-ingress-logiq
            - --configmap=logiq/logiq-kubernetes-ingress
            - --tcp-services-configmap=logiq/ingress-tcp-ports
          securityContext:
            capabilities:
                drop:
                - ALL
                add:
                - NET_BIND_SERVICE
            runAsUser: 101
            allowPrivilegeEscalation: true
          env:
            - name: POD_NAME
              valueFrom:
                fieldRef:
                  fieldPath: metadata.name
            - name: POD_NAMESPACE
              valueFrom:
                fieldRef:
                  fieldPath: metadata.namespace
          livenessProbe:
            httpGet:
              path: /healthz
              port: 10254
              scheme: HTTP
            initialDelaySeconds: 10
            periodSeconds: 10
            timeoutSeconds: 1
            successThreshold: 1
            failureThreshold: 15
          ports:
            - name: http
              containerPort: 80
              protocol: TCP
            - name: https
              containerPort: 443
              protocol: TCP
            - name: "14250-tcp"
              containerPort: 14250
              protocol: TCP
            - name: "20514-tcp"
              containerPort: 20514
              protocol: TCP
            - name: "7514-tcp"
              containerPort: 7514
              protocol: TCP
            - name: "7515-tcp"
              containerPort: 7515
              protocol: TCP
            - name: "8081-tcp"
              containerPort: 8081
              protocol: TCP
            - name: "9998-tcp"
              containerPort: 9998
              protocol: TCP
          readinessProbe:
            httpGet:
              path: /healthz
              port: 10254
              scheme: HTTP
            initialDelaySeconds: 10
            periodSeconds: 10
            timeoutSeconds: 1
            successThreshold: 1
            failureThreshold: 3
          resources:
            {}
      hostNetwork: false


      serviceAccountName: ingress-nginx
      terminationGracePeriodSeconds: 60
---
# Source: logiq/charts/kubernetes-ingress/templates/default-backend-deployment.yaml
apiVersion: apps/v1
kind: Deployment
metadata:
  labels:
    app: kubernetes-ingress
    chart: kubernetes-ingress-1.37.0
    heritage: Helm
    release: logiq
    app.kubernetes.io/component: default-backend
  name: logiq-kubernetes-ingress-default-backend
spec:
  selector:
    matchLabels:
      app: kubernetes-ingress
      release: logiq
  replicas: 1
  revisionHistoryLimit: 10
  template:
    metadata:
      labels:
        app: kubernetes-ingress
        release: logiq
        app.kubernetes.io/component: default-backend
    spec:
      containers:
        - name: kubernetes-ingress-default-backend
          image: "k8s.gcr.io/defaultbackend-amd64:1.5"
          imagePullPolicy: "IfNotPresent"
          args:
          securityContext:
            runAsUser: 65534
          livenessProbe:
            httpGet:
              path: /healthz
              port: 8080
              scheme: HTTP
            initialDelaySeconds: 30
            periodSeconds: 10
            timeoutSeconds: 5
            successThreshold: 1
            failureThreshold: 15
          readinessProbe:
            httpGet:
              path: /healthz
              port: 8080
              scheme: HTTP
            initialDelaySeconds: 0
            periodSeconds: 5
            timeoutSeconds: 5
            successThreshold: 1
            failureThreshold: 6
          ports:
            - name: http
              containerPort: 8080
              protocol: TCP
          resources:
            {}
      serviceAccountName: logiq-kubernetes-ingress-backend


      terminationGracePeriodSeconds: 60
---
# Source: logiq/charts/prometheus/charts/kube-state-metrics/templates/deployment.yaml
apiVersion: apps/v1
kind: Deployment
metadata:
  name: logiq-kube-state-metrics
  namespace: logiq
  labels:
    app.kubernetes.io/name: kube-state-metrics
    helm.sh/chart: kube-state-metrics-2.1.19
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
spec:
  selector:
    matchLabels:
      app.kubernetes.io/name: kube-state-metrics
      app.kubernetes.io/instance: logiq
  replicas: 1
  strategy:
    {}
  minReadySeconds: 0
  template:
    metadata:
      labels:
        app.kubernetes.io/name: kube-state-metrics
        helm.sh/chart: kube-state-metrics-2.1.19
        app.kubernetes.io/instance: logiq
        app.kubernetes.io/managed-by: Helm
    spec:
      
      securityContext:
        runAsUser: 1001
        fsGroup: 1001
      hostNetwork: false
      serviceAccountName: logiq-kube-state-metrics
      affinity:
        podAffinity:
          
        podAntiAffinity:
          preferredDuringSchedulingIgnoredDuringExecution:
            - podAffinityTerm:
                labelSelector:
                  matchLabels:
                    app.kubernetes.io/name: kube-state-metrics
                    app.kubernetes.io/instance: logiq
                namespaces:
                  - "logiq"
                topologyKey: kubernetes.io/hostname
              weight: 1
        nodeAffinity:
          
      containers:
        - name: kube-state-metrics
          image: docker.io/bitnami/kube-state-metrics:2.3.0-debian-10-r0
          imagePullPolicy: IfNotPresent
          args:
            - --resources=certificatesigningrequests
            - --resources=configmaps
            - --resources=cronjobs
            - --resources=daemonsets
            - --resources=deployments
            - --resources=endpoints
            - --resources=horizontalpodautoscalers
            - --resources=ingresses
            - --resources=jobs
            - --resources=limitranges
            - --resources=mutatingwebhookconfigurations
            - --resources=namespaces
            - --resources=networkpolicies
            - --resources=nodes
            - --resources=persistentvolumeclaims
            - --resources=persistentvolumes
            - --resources=poddisruptionbudgets
            - --resources=pods
            - --resources=replicasets
            - --resources=replicationcontrollers
            - --resources=resourcequotas
            - --resources=secrets
            - --resources=services
            - --resources=statefulsets
            - --resources=storageclasses
            - --resources=volumeattachments
          ports:
            - name: http
              containerPort: 8080
              protocol: TCP
          livenessProbe:
            httpGet:
              path: /healthz
              port: http
            initialDelaySeconds: 120
            periodSeconds: 10
            timeoutSeconds: 5
            successThreshold: 1
            failureThreshold: 6
          readinessProbe:
            httpGet:
              path: /
              port: http
            initialDelaySeconds: 30
            periodSeconds: 10
            timeoutSeconds: 5
            successThreshold: 1
            failureThreshold: 6
          resources:
            limits: {}
            requests: {}
---
# Source: logiq/charts/prometheus/templates/prometheus-operator/deployment.yaml
apiVersion: apps/v1
kind: Deployment
metadata:
  name: logiq-prometheus-operator
  namespace: logiq
  labels:
    app.kubernetes.io/name: prometheus
    helm.sh/chart: prometheus-6.5.3
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
    app.kubernetes.io/component: operator
spec:
  replicas: 1
  selector:
    matchLabels:
      app.kubernetes.io/name: prometheus
      app.kubernetes.io/instance: logiq
      app.kubernetes.io/component: operator
  template:
    metadata:
      labels:
        app.kubernetes.io/name: prometheus
        helm.sh/chart: prometheus-6.5.3
        app.kubernetes.io/instance: logiq
        app.kubernetes.io/managed-by: Helm
        app.kubernetes.io/component: operator
    spec:
      serviceAccountName: logiq-prometheus-operator
      securityContext:
        fsGroup: 1001
        runAsUser: 1001
      affinity:
        podAffinity:
          
        podAntiAffinity:
          preferredDuringSchedulingIgnoredDuringExecution:
            - podAffinityTerm:
                labelSelector:
                  matchLabels:
                    app.kubernetes.io/name: prometheus
                    app.kubernetes.io/instance: logiq
                    app.kubernetes.io/component: operator
                namespaces:
                  - "logiq"
                topologyKey: kubernetes.io/hostname
              weight: 1
  

      containers:
        - name: prometheus-operator
          image: docker.io/bitnami/prometheus-operator:0.53.1-debian-10-r0
          imagePullPolicy: IfNotPresent
          env:
            - name: PROMETHEUS_CONFIG_RELOADER
              valueFrom:
                configMapKeyRef:
                  name: logiq-prometheus-operator
                  key: prometheus-config-reloader
          args:
            - --kubelet-service=kube-system/logiq-prometheus-kubelet
            - --log-format=logfmt
            - --log-level=info
            - --localhost=127.0.0.1
            - --prometheus-config-reloader=$(PROMETHEUS_CONFIG_RELOADER)
            - --namespaces=logiq
          ports:
            - name: http
              containerPort: 8080
              protocol: TCP
          livenessProbe:
            httpGet:
              path: /metrics
              port: http
              scheme: HTTP
            initialDelaySeconds: 120
            periodSeconds: 25
            timeoutSeconds: 25
            failureThreshold: 6
            successThreshold: 1
          readinessProbe:
            httpGet:
              path: /metrics
              port: http
              scheme: HTTP
            initialDelaySeconds: 30
            periodSeconds: 25
            timeoutSeconds: 25
            failureThreshold: 6
            successThreshold: 1
          # yamllint disable rule:indentation
          securityContext:
            allowPrivilegeEscalation: false
            capabilities:
              drop:
              - ALL
            readOnlyRootFilesystem: false
            runAsNonRoot: true
          # yamllint enable rule:indentation
---
# Source: logiq/charts/thanos/templates/bucketweb/deployment.yaml
apiVersion: apps/v1
kind: Deployment
metadata:
  name: logiq-thanos-bucketweb
  namespace: "logiq"
  labels:
    app.kubernetes.io/name: thanos
    helm.sh/chart: thanos-8.2.5
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
    app.kubernetes.io/component: bucketweb
spec:
  replicas: 1
  strategy:
    type: RollingUpdate
  selector:
    matchLabels:
      app.kubernetes.io/name: thanos
      app.kubernetes.io/instance: logiq
      app.kubernetes.io/component: bucketweb
  template:
    metadata:
      labels:
        app.kubernetes.io/name: thanos
        helm.sh/chart: thanos-8.2.5
        app.kubernetes.io/instance: logiq
        app.kubernetes.io/managed-by: Helm
        app.kubernetes.io/component: bucketweb
      annotations:
        checksum/ojbstore-configuration: da75997dd0b9aece1666342dee51b8a13d97cd034e79263b88d83bbc95e5c7f9
    spec:
      
      serviceAccount: logiq-thanos-bucketweb
      affinity:
        podAffinity:
          
        podAntiAffinity:
          preferredDuringSchedulingIgnoredDuringExecution:
            - podAffinityTerm:
                labelSelector:
                  matchLabels:
                    app.kubernetes.io/name: thanos
                    app.kubernetes.io/instance: logiq
                    app.kubernetes.io/component: bucketweb
                namespaces:
                  - "logiq"
                topologyKey: kubernetes.io/hostname
              weight: 1


      securityContext:
        fsGroup: 1001
      containers:
        - name: bucketweb
          image: docker.io/bitnami/thanos:0.24.0-scratch-r0
          imagePullPolicy: "IfNotPresent"
          securityContext:
            allowPrivilegeEscalation: false
            readOnlyRootFilesystem: false
            runAsNonRoot: true
            runAsUser: 1001
          args:
            - tools
            - bucket
            - web
            - --http-address=0.0.0.0:8080
            - --log.level=info
            - --log.format=logfmt
            - --objstore.config-file=/conf/objstore.yml
            - --refresh=30m
            - --timeout=5m
          ports:
            - name: http
              containerPort: 8080
              protocol: TCP
          livenessProbe:
            failureThreshold: 6
            initialDelaySeconds: 30
            periodSeconds: 10
            successThreshold: 1
            timeoutSeconds: 30
            httpGet:
              path: /-/healthy
              port: http
          readinessProbe:
            failureThreshold: 6
            initialDelaySeconds: 30
            periodSeconds: 10
            successThreshold: 1
            timeoutSeconds: 30
            httpGet:
              path: /-/ready
              port: http
          resources:
            limits: {}
            requests: {}
          volumeMounts:
            - name: objstore-config
              mountPath: /conf
      volumes:
        - name: objstore-config
          secret:
            secretName: logiq-thanos-objstore-secret
---
# Source: logiq/charts/thanos/templates/compactor/deployment.yaml
apiVersion: apps/v1
kind: Deployment
metadata:
  name: logiq-thanos-compactor
  namespace: "logiq"
  labels:
    app.kubernetes.io/name: thanos
    helm.sh/chart: thanos-8.2.5
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
    app.kubernetes.io/component: compactor
spec:
  replicas: 1
  strategy:
    type: Recreate
  selector:
    matchLabels:
      app.kubernetes.io/name: thanos
      app.kubernetes.io/instance: logiq
      app.kubernetes.io/component: compactor
  template:
    metadata:
      labels:
        app.kubernetes.io/name: thanos
        helm.sh/chart: thanos-8.2.5
        app.kubernetes.io/instance: logiq
        app.kubernetes.io/managed-by: Helm
        app.kubernetes.io/component: compactor
      annotations:
        checksum/ojbstore-configuration: da75997dd0b9aece1666342dee51b8a13d97cd034e79263b88d83bbc95e5c7f9
    spec:
      
      serviceAccount: logiq-thanos-compactor
      affinity:
        podAffinity:
          
        podAntiAffinity:
          preferredDuringSchedulingIgnoredDuringExecution:
            - podAffinityTerm:
                labelSelector:
                  matchLabels:
                    app.kubernetes.io/name: thanos
                    app.kubernetes.io/instance: logiq
                    app.kubernetes.io/component: compactor
                namespaces:
                  - "logiq"
                topologyKey: kubernetes.io/hostname
              weight: 1


      securityContext:
        fsGroup: 1001
      containers:
        - name: compactor
          image: docker.io/bitnami/thanos:0.24.0-scratch-r0
          imagePullPolicy: "IfNotPresent"
          securityContext:
            allowPrivilegeEscalation: false
            readOnlyRootFilesystem: false
            runAsNonRoot: true
            runAsUser: 1001
          args:
            - compact
            - --log.level=info
            - --log.format=logfmt
            - --http-address=0.0.0.0:10902
            - --data-dir=/data
            - --retention.resolution-raw=30d
            - --retention.resolution-5m=30d
            - --retention.resolution-1h=10y
            - --consistency-delay=30m
            - --objstore.config-file=/conf/objstore.yml
            - --wait
          ports:
            - name: http
              containerPort: 10902
              protocol: TCP
          livenessProbe:
            failureThreshold: 6
            initialDelaySeconds: 30
            periodSeconds: 10
            successThreshold: 1
            timeoutSeconds: 30
            httpGet:
              path: /-/healthy
              port: http
          readinessProbe:
            failureThreshold: 6
            initialDelaySeconds: 30
            periodSeconds: 10
            successThreshold: 1
            timeoutSeconds: 30
            httpGet:
              path: /-/ready
              port: http
          resources:
            limits: {}
            requests: {}
          volumeMounts:
            - name: objstore-config
              mountPath: /conf
            - name: data
              mountPath: /data
      volumes:
        - name: objstore-config
          secret:
            secretName: logiq-thanos-objstore-secret
        - name: data
          persistentVolumeClaim:
            claimName: logiq-thanos-compactor
---
# Source: logiq/charts/thanos/templates/query/deployment.yaml
apiVersion: apps/v1
kind: Deployment
metadata:
  name: logiq-thanos-query
  namespace: "logiq"
  labels:
    app.kubernetes.io/name: thanos
    helm.sh/chart: thanos-8.2.5
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
    app.kubernetes.io/component: query
spec:
  replicas: 1
  strategy:
    type: RollingUpdate
  selector:
    matchLabels:
      app.kubernetes.io/name: thanos
      app.kubernetes.io/instance: logiq
      app.kubernetes.io/component: query
  template:
    metadata:
      labels:
        app.kubernetes.io/name: thanos
        helm.sh/chart: thanos-8.2.5
        app.kubernetes.io/instance: logiq
        app.kubernetes.io/managed-by: Helm
        app.kubernetes.io/component: query
    spec:
      
      serviceAccount: logiq-thanos-query
      affinity:
        podAffinity:
          
        podAntiAffinity:
          preferredDuringSchedulingIgnoredDuringExecution:
            - podAffinityTerm:
                labelSelector:
                  matchLabels:
                    app.kubernetes.io/name: thanos
                    app.kubernetes.io/instance: logiq
                    app.kubernetes.io/component: query
                namespaces:
                  - "logiq"
                topologyKey: kubernetes.io/hostname
              weight: 1


      securityContext:
        fsGroup: 1001
      containers:
        - name: query
          image: docker.io/bitnami/thanos:0.24.0-scratch-r0
          imagePullPolicy: "IfNotPresent"
          securityContext:
            allowPrivilegeEscalation: false
            readOnlyRootFilesystem: false
            runAsNonRoot: true
            runAsUser: 1001
          args:
            - query
            - --log.level=info
            - --log.format=logfmt
            - --grpc-address=0.0.0.0:10901
            - --http-address=0.0.0.0:10902
            - --query.replica-label=replica
            - --store=dnssrv+_grpc._tcp.logiq-prometheus-prometheus-thanos.logiq.svc.cluster.local
            - --store=dnssrv+_grpc._tcp.logiq-thanos-storegateway.logiq.svc.cluster.local
            - --store=dnssrv+_grpc._tcp.logiq-thanos-ruler.logiq.svc.cluster.local
            - --store=dnssrv+_grpc._tcp.logiq-thanos-receive.logiq.svc.cluster.local
          ports:
            - name: http
              containerPort: 10902
              protocol: TCP
            - name: grpc
              containerPort: 10901
              protocol: TCP
          livenessProbe:
            failureThreshold: 6
            initialDelaySeconds: 30
            periodSeconds: 10
            successThreshold: 1
            timeoutSeconds: 30
            httpGet:
              path: /-/healthy
              port: http
          readinessProbe:
            failureThreshold: 6
            initialDelaySeconds: 30
            periodSeconds: 10
            successThreshold: 1
            timeoutSeconds: 30
            httpGet:
              path: /-/ready
              port: http
          resources:
            limits: {}
            requests: {}
          volumeMounts:
      volumes:
---
# Source: logiq/charts/flash-coffee/templates/001-coffee-server-sts.yaml
apiVersion: apps/v1
kind: StatefulSet
metadata:
  labels:
    app: coffee-server-deployment
  name: coffee-server
  namespace: logiq
spec:
  replicas: 1
  serviceName: coffee
  selector:
    matchLabels:
      app: coffee-server
  template:
    metadata:
      labels:
        app: coffee-server
    spec:
      serviceAccountName: flash-coffee

   
      securityContext:
        fsGroup: 1000
        runAsUser: 1000
        runAsGroup: 1000
      
      initContainers:
      - name: check-redis
        image: logiqai/toolbox:2.0.1
        imagePullPolicy: IfNotPresent
        command:
        - sh
        - -c
        - until redis-cli -h redis-master ping; do echo "waiting for redis-master"; sleep 1;
          done;
      - name: check-postgres
        image: logiqai/toolbox:2.0.1
        imagePullPolicy: IfNotPresent
        env:
          - name: POSTGRES_PASSWORD
            valueFrom:
              secretKeyRef:
                name: logiq-flash-coffee
                key: postgres_password
          - name: POSTGRES_HOST
            valueFrom:
              secretKeyRef:
                name: logiq-flash-coffee
                key: postgres_host
          - name: DATABASE_URL
            valueFrom:
              secretKeyRef:
                name: logiq-flash-coffee
                key: database_url
        command: ['sh', '-c',
          'until pg_isready -h $(POSTGRES_HOST) -p 5432 -d $(DATABASE_URL);
          do echo waiting for database; sleep 1; done;']
      volumes:
        
        - name: sharedcert
          secret:
            secretName: logiq-shared-secret
        
      containers:
        - env:
          - name: LOGIQ_UI_GOOGLE_ANALYTICS_CODE
            value: 
          - name: CONFIG_HASH
            value: "7b67a19281a5c06880cf509c4c4ba44c0e242a71897bae579f0fbc97cf8f69d9"
          - name: PYTHONUNBUFFERED
            value: "0"
          - name: COOKIE_SECRET
            value: d84c0edd-ab5e-4664-b0ee-2cd15a9ae5f0 
          - name: LOG_LEVEL
            value: ERROR
          
          - name: MY_APP_NAME
            value: coffee-server
          - name: MY_NODE_NAME
            valueFrom:
              fieldRef:
                fieldPath: spec.nodeName
          - name: MY_POD_NAME
            valueFrom:
              fieldRef:
                fieldPath: metadata.name
          - name: MY_POD_NAMESPACE
            valueFrom:
              fieldRef:
                fieldPath: metadata.namespace
          - name: MY_POD_IP
            valueFrom:
              fieldRef:
                fieldPath: status.podIP                
            
          - name: MY_CLUSTER_ID
            value: LOGIQ
          
          - name: LOGIQ_FLASH_HOST
            valueFrom:
              secretKeyRef:
                name: logiq-flash-coffee
                key: logiq_flash_host
          - name: LOGIQ_FLASH_PORT
            valueFrom:
              secretKeyRef:
                name: logiq-flash-coffee
                key: logiq_flash_port
          - name: REDIS_HOST
            valueFrom:
              secretKeyRef:
                name: logiq-flash-coffee
                key: redis_host
          - name: REDIS_URL
            value: redis://redis-master:6379/0
          - name: POSTGRES_USER
            valueFrom:
              secretKeyRef:
                name: logiq-flash-coffee
                key: postgres_user
          - name: POSTGRES_PASSWORD
            valueFrom:
              secretKeyRef:
                name: logiq-flash-coffee
                key: postgres_password
          - name: POSTGRES_HOST
            valueFrom:
              secretKeyRef:
                name: logiq-flash-coffee
                key: postgres_host
          - name: POSTGRES_PORT
            valueFrom:
              secretKeyRef:
                name: logiq-flash-coffee
                key: postgres_port
          - name: POSTGRES_DB
            valueFrom:
              secretKeyRef:
                name: logiq-flash-coffee
                key: postgres_db
          - name: POSTGRES_COFFEE_DB
            valueFrom:
              secretKeyRef:
                name: logiq-flash-coffee
                key: postgres_coffee_db
          - name: DATABASE_URL
            valueFrom:
              secretKeyRef:
                name: logiq-flash-coffee
                key: coffee_database_url
          - name: S3_URL
            valueFrom:
              secretKeyRef:
                name: logiq-flash-coffee
                key: s3_url
          - name: S3_ACCESS
            valueFrom:
              secretKeyRef:
                name: logiq-shared-secret
                key: s3_access
          - name: S3_SECRET
            valueFrom:
              secretKeyRef:
                name: logiq-shared-secret
                key: s3_secret
          - name: S3_BUCKET
            valueFrom:
              secretKeyRef:
                name: logiq-shared-secret
                key: s3_bucket
          
          - name: ADMIN_NAME
            valueFrom:
              secretKeyRef:
                name: logiq-flash-coffee
                key: admin_name
          
          
          - name: ADMIN_PASSWORD
            valueFrom:
              secretKeyRef:
                name: logiq-flash-coffee
                key: admin_password
          
          
          - name: ADMIN_ORG
            valueFrom:
              secretKeyRef:
                name: logiq-flash-coffee
                key: admin_org
          
          
          - name: ADMIN_EMAIL
            valueFrom:
              secretKeyRef:
                name: logiq-flash-coffee
                key: admin_email
          
          
          - name: MAIL_SERVER
            valueFrom:
              secretKeyRef:
                name: logiq-flash-coffee
                key: mail_server
          
          
          - name: MAIL_PORT
            valueFrom:
              secretKeyRef:
                name: logiq-flash-coffee
                key: mail_port
          
          
          - name: MAIL_USERNAME
            valueFrom:
              secretKeyRef:
                name: logiq-flash-coffee
                key: mail_username
          
          
          - name: MAIL_PASSWORD
            valueFrom:
              secretKeyRef:
                name: logiq-flash-coffee
                key: mail_password
          
          
          - name: MAIL_DEFAULT_SENDER
            valueFrom:
              secretKeyRef:
                name: logiq-flash-coffee
                key: mail_default_sender
          
          - name: WEB_WORKERS
            value: "4"
          - name: CONFIGURE_LOGIQ_DS
            value: "true"
          - name:  COFFEE_UI_SERVER_URL
            value: http://coffee:80
          - name: CONFIGURE_LOGIQEVENTS_DS
            value: "false"
            
          - name: PROM_ALERT_MGR_URL
            value: logiq-prometheus-alertmanager:9093
               
          - name: EVENT_REPORTING_WEBHOOKS
            value: ""
          - name: LOGIQ_AUDIT_EVENT_GROUP
            value: logiq-audit
          volumeMounts:
          
          - mountPath: /app/sharedcerts
            name: sharedcert
          
          image: "logiqai/flash-brew-coffee:brew.2.1.37-rc60"
          imagePullPolicy: IfNotPresent
          name: coffee
          command: ["/app/flash-brew/setup_coffee.sh"]
          ports:
            - containerPort: 5000
          readinessProbe:
            httpGet:
              port:  5000
              path: /static/js/jquery.min.js
            initialDelaySeconds: 10
            periodSeconds: 10
            timeoutSeconds: 4
            successThreshold: 1
            failureThreshold: 5
          resources:
            requests:
              cpu: 100m
              memory: 0.2Gi
      restartPolicy: Always
---
# Source: logiq/charts/flash-coffee/templates/003-coffee-worker-sts.yaml
apiVersion: apps/v1
kind: StatefulSet
metadata:
  labels:
    app: coffee-worker-deployment
  name: coffee-worker
  namespace: logiq
spec:
  replicas: 1
  serviceName: coffee
  selector:
    matchLabels:
      app: coffee-worker
  template:
    metadata:
      labels:
        app: coffee-worker
    spec:
      serviceAccountName: flash-coffee

   
      securityContext:
        fsGroup: 1000
        runAsUser: 1000
        runAsGroup: 1000
      
      initContainers:
      - name: check-redis
        image: logiqai/toolbox:2.0.1
        imagePullPolicy: IfNotPresent
        command:
        - sh
        - -c
        - until redis-cli -h redis-master ping; do echo "waiting for redis-master"; sleep 1;
          done;
      - name: check-postgres
        image: logiqai/toolbox:2.0.1
        imagePullPolicy: IfNotPresent
        env:
          - name: POSTGRES_PASSWORD
            valueFrom:
              secretKeyRef:
                name: logiq-flash-coffee
                key: postgres_password
          - name: POSTGRES_HOST
            valueFrom:
              secretKeyRef:
                name: logiq-flash-coffee
                key: postgres_host
          - name: DATABASE_URL
            valueFrom:
              secretKeyRef:
                name: logiq-flash-coffee
                key: database_url
        command: ['sh', '-c',
          'until pg_isready -h $(POSTGRES_HOST) -p 5432 -d $(DATABASE_URL);
          do echo waiting for database; sleep 1; done;']
      volumes:
        
        - name: sharedcert
          secret:
            secretName: logiq-shared-secret
        
      containers:
        - args:
          - scheduler
          env:
          - name: CONFIG_HASH
            value: "7b67a19281a5c06880cf509c4c4ba44c0e242a71897bae579f0fbc97cf8f69d9"
          - name: PYTHONUNBUFFERED
            value: "0"
          - name: COOKIE_SECRET
            value: d84c0edd-ab5e-4664-b0ee-2cd15a9ae5f0 
          - name: QUEUES
            value: queries,scheduled_queries,celery
          - name: LOG_LEVEL
            value: ERROR
          
          - name: MY_APP_NAME
            value: coffee-worker
          - name: MY_NODE_NAME
            valueFrom:
              fieldRef:
                fieldPath: spec.nodeName
          - name: MY_POD_NAME
            valueFrom:
              fieldRef:
                fieldPath: metadata.name
          - name: MY_POD_NAMESPACE
            valueFrom:
              fieldRef:
                fieldPath: metadata.namespace
          - name: MY_POD_IP
            valueFrom:
              fieldRef:
                fieldPath: status.podIP                
            
          - name: MY_CLUSTER_ID
            value: LOGIQ
           
          - name: LOGIQ_FLASH_HOST
            valueFrom:
              secretKeyRef:
                name: logiq-flash-coffee
                key: logiq_flash_host
          - name: LOGIQ_FLASH_PORT
            valueFrom:
              secretKeyRef:
                name: logiq-flash-coffee
                key: logiq_flash_port
          - name: WORKERS_COUNT
            value: "1"
          - name: REDIS_HOST
            valueFrom:
              secretKeyRef:
                name: logiq-flash-coffee
                key: redis_host
          - name: REDIS_URL
            value: redis://redis-master:6379/0
          - name: POSTGRES_USER
            valueFrom:
              secretKeyRef:
                name: logiq-flash-coffee
                key: postgres_user
          - name: POSTGRES_PASSWORD
            valueFrom:
              secretKeyRef:
                name: logiq-flash-coffee
                key: postgres_password
          - name: POSTGRES_HOST
            valueFrom:
              secretKeyRef:
                name: logiq-flash-coffee
                key: postgres_host
          - name: POSTGRES_PORT
            valueFrom:
              secretKeyRef:
                name: logiq-flash-coffee
                key: postgres_port
          - name: POSTGRES_DB
            valueFrom:
              secretKeyRef:
                name: logiq-flash-coffee
                key: postgres_db
          - name: POSTGRES_COFFEE_DB
            valueFrom:
              secretKeyRef:
                name: logiq-flash-coffee
                key: postgres_coffee_db
          - name: DATABASE_URL
            valueFrom:
              secretKeyRef:
                name: logiq-flash-coffee
                key: coffee_database_url
          - name: S3_URL
            valueFrom:
              secretKeyRef:
                name: logiq-flash-coffee
                key: s3_url
          - name: S3_ACCESS
            valueFrom:
              secretKeyRef:
                name: logiq-shared-secret
                key: s3_access
          - name: S3_SECRET
            valueFrom:
              secretKeyRef:
                name: logiq-shared-secret
                key: s3_secret
          - name: S3_BUCKET
            valueFrom:
              secretKeyRef:
                name: logiq-shared-secret
                key: s3_bucket
          
          - name: ADMIN_NAME
            valueFrom:
              secretKeyRef:
                name: logiq-flash-coffee
                key: admin_name
          
          
          - name: ADMIN_PASSWORD
            valueFrom:
              secretKeyRef:
                name: logiq-flash-coffee
                key: admin_password
          
          
          - name: ADMIN_ORG
            valueFrom:
              secretKeyRef:
                name: logiq-flash-coffee
                key: admin_org
          
          
          - name: ADMIN_EMAIL
            valueFrom:
              secretKeyRef:
                name: logiq-flash-coffee
                key: admin_email
          
          
          - name: MAIL_SERVER
            valueFrom:
              secretKeyRef:
                name: logiq-flash-coffee
                key: mail_server
          
          
          - name: MAIL_PORT
            valueFrom:
              secretKeyRef:
                name: logiq-flash-coffee
                key: mail_port
          
          
          - name: MAIL_USERNAME
            valueFrom:
              secretKeyRef:
                name: logiq-flash-coffee
                key: mail_username
          
          
          - name: MAIL_PASSWORD
            valueFrom:
              secretKeyRef:
                name: logiq-flash-coffee
                key: mail_password
          
          
          - name: MAIL_DEFAULT_SENDER
            valueFrom:
              secretKeyRef:
                name: logiq-flash-coffee
                key: mail_default_sender
          
          
          - name: PROM_ALERT_MGR_URL
            value: logiq-prometheus-alertmanager:9093
           
          - name: EVENT_REPORTING_WEBHOOKS
            value: ""
          - name: LOGIQ_AUDIT_EVENT_GROUP
            value: logiq-audit
          volumeMounts:
          
          - mountPath: /app/sharedcerts
            name: sharedcert
          
          image: "logiqai/flash-brew-coffee:brew.2.1.37-rc60"
          imagePullPolicy: IfNotPresent
          name: coffee-worker
          resources:
            requests:
              cpu: 100m
              memory: 0.2Gi
      restartPolicy: Always
---
# Source: logiq/charts/flash-discovery/templates/discoveryStatefulSet.yaml
apiVersion: apps/v1
kind: StatefulSet
metadata:
  name: flash-discovery
  namespace: logiq
  labels:
    app: flash-discovery
    chart: flash-discovery-1.0.0
    release: logiq
    heritage: Helm
spec:
  serviceName: flash-discovery
  replicas: 1
  selector:
    matchLabels:
      app: flash-discovery
      release: logiq
  volumeClaimTemplates:
  - metadata:
      name: data
    spec:
      accessModes:
        - ReadWriteOnce
      resources:
        requests:
          storage: "0.5Gi"
      storageClassName: microk8s-hostpath
  template:
    metadata:
      labels:
        app: flash-discovery
        release: logiq
    spec:
      serviceAccountName: flash-discovery


      securityContext:
        fsGroup: 1000
        runAsUser: 1000
        runAsGroup: 1000
      initContainers:
      - name: check-postgres
        image: logiqai/toolbox:2.0.1
        imagePullPolicy: IfNotPresent
        env:
          - name: POSTGRES_PASSWORD
            valueFrom:
              secretKeyRef:
                name: flash-discovery
                key: postgres_password
          - name: POSTGRES_HOST
            valueFrom:
              secretKeyRef:
                name: flash-discovery
                key: postgres_host
          - name: DATABASE_URL
            valueFrom:
              secretKeyRef:
                name: flash-discovery
                key: database_url
        command: ['sh', '-c', 
          'until pg_isready -h $(POSTGRES_HOST) -p 5432 -d $(DATABASE_URL);
          do echo waiting for database; sleep 1; done;']
      
      volumes:
        
        
        
        - name: license
          secret:
            secretName: flash-discovery-license
        
        
        - name: sharedcert
          secret:
            secretName: logiq-shared-secret
        
      containers:
        - name: flash-discovery
          image: "logiqai/flash-discovery:2.0.1"
          imagePullPolicy: IfNotPresent
          env:
          - name: CONFIG_HASH
            value: "d02a0870ae064707207c138f940869a81f522b28810da7510ce4aabe98447f63"
          - name: POSTGRES_USER
            valueFrom:
              secretKeyRef:
                name: flash-discovery
                key: postgres_user
          - name: POSTGRES_PASSWORD
            valueFrom:
              secretKeyRef:
                name: flash-discovery
                key: postgres_password
          - name: POSTGRES_HOST
            valueFrom:
              secretKeyRef:
                name: flash-discovery
                key: postgres_host
          - name: POSTGRES_PORT
            valueFrom:
              secretKeyRef:
                name: flash-discovery
                key: postgres_port
          - name: POSTGRES_DB
            valueFrom:
              secretKeyRef:
                name: flash-discovery
                key: postgres_db
          - name: MY_APP_NAME
            value: flash-discovery
          - name: MY_NODE_NAME
            valueFrom:
              fieldRef:
                fieldPath: spec.nodeName
          - name: MY_POD_NAME
            valueFrom:
              fieldRef:
                fieldPath: metadata.name
          - name: MY_POD_NAMESPACE
            valueFrom:
              fieldRef:
                fieldPath: metadata.namespace
          - name: MY_POD_IP
            valueFrom:
              fieldRef:
                fieldPath: status.podIP                
            
          - name: MY_CLUSTER_ID
            value: LOGIQ
                
          volumeMounts:
          - mountPath: /flash/db
            name: data
          
          
          - mountPath: /flash/license
            name: license
          
          
          - mountPath: /flash/sharedcerts
            name: sharedcert
          
          ports:
            - name: healthcheck
              containerPort: 8081
              protocol: TCP
            - name: discovery
              containerPort: 4000
              protocol: TCP
          livenessProbe:
            httpGet:
              path: /live
              port: healthcheck
            initialDelaySeconds: 10
            failureThreshold: 3
            periodSeconds: 10
          readinessProbe:
            httpGet:
              path: /ready
              port: healthcheck
            initialDelaySeconds: 5
            failureThreshold: 3
            periodSeconds: 10             
          resources:
            requests:
              cpu: 100m
              memory: 100Mi
---
# Source: logiq/charts/logiq-flash/templates/statefulSet.yaml
apiVersion: apps/v1
kind: StatefulSet
metadata:
  name: logiq-flash
  namespace: logiq
  labels:
    app: logiq-flash
    chart: logiq-flash-1.0.0
    release: logiq
    heritage: Helm
spec:
  serviceName: logiq-flash-headless
  replicas: 1
  selector:
    matchLabels:
      app: logiq-flash
      release: logiq
  volumeClaimTemplates:
  - metadata:
      name: data
    spec:
      accessModes:
        - ReadWriteOnce
      resources:
        requests:
          storage: "10Gi"
      storageClassName: microk8s-hostpath
  template:
    metadata:
      annotations:
        checksum/config: 5286af0c4df4c5a3793fed5f0625fa4ac645ef619587fd072ecce8a177dcf0db
      labels:
        app: logiq-flash
        release: logiq
    spec:
      serviceAccountName: logiq-flash

      
      securityContext:
        fsGroup: 1000
        runAsUser: 1000
        runAsGroup: 1000
      initContainers:
      - command:
        - sh
        - -c
        - until $(curl --output /dev/null --silent --fail http://flash-discovery:8081/ready); do echo "waiting for discovery"; sleep 1;
          done;
        image: logiqai/toolbox:2.0.1
        imagePullPolicy: IfNotPresent
        name: check-discovery
      - name: check-redis
        image: logiqai/toolbox:2.0.1
        imagePullPolicy: IfNotPresent
        command:
        - sh
        - -c
        - until redis-cli -h redis-master ping; do echo "waiting for redis-master"; sleep 1;
          done;
                
      - command:
          - sh
          - -c
          - until $(curl --output /dev/null --silent --fail http://s3-gateway:9000/minio/health/ready); do echo "waiting for s3-gateway"; sleep 1;
            done;
        image: logiqai/toolbox:2.0.1
        imagePullPolicy: IfNotPresent
        name: check-s3-gateway
            
      volumes:
        
        - name: config
          configMap:
            
            name: logiq-config
            
        
        
        
        - name: sharedcert
          secret:
            secretName: logiq-shared-secret
        
      
      terminationGracePeriodSeconds: 60
      containers:
        - name: logiq-flash
          image: "logiqai/flash:v3.1"
          imagePullPolicy: IfNotPresent
          args:
          - -c
          - /flash/bin/flash -config /flash/config/config.yaml -install_root /flash -runtime_folder /flash/db -discovery_domain $(DISCOVERY_DOMAIN) -discovery_url $(DISCOVERY_URL) -discovery_id flash1 -pg_max_idle_conns 190 -pg_max_open_Conns 195 -batch_timer_duration 10s -postgres_timeout 20s -workers 150 -connection_channel_size 10 --pg_conn_max_lifetime 5m 
          command:
          - /bin/bash
          env:
          - name: CONFIG_HASH
            value: "dd289722ef34988ce24097cd2d8ef1f147a40728fdbd62f6a97c86256d97ab67"
          - name: DISCOVERY_URL
            value: http://flash-discovery:4000
          - name: DISCOVERY_ID
            valueFrom:
              fieldRef:
                fieldPath: metadata.name
          - name: DISCOVERY_DOMAIN
            value: logiq-flash-headless
          
          - name: REDIS_HOST
            valueFrom:
              secretKeyRef:
                name: logiq-logiq-flash
                key: redis_host
          - name: REDIS_PORT
            valueFrom:
              secretKeyRef:
                name: logiq-logiq-flash
                key: redis_port
          
          
          - name: ADMIN_EMAIL
            valueFrom:
              secretKeyRef:
                name: logiq-logiq-flash
                key: admin_email
          
          
          - name: ADMIN_PASSWORD
            valueFrom:
              secretKeyRef:
                name: logiq-logiq-flash
                key: admin_password
          
          - name: POSTGRES_USER
            valueFrom:
              secretKeyRef:
                name: logiq-logiq-flash
                key: postgres_user
          - name: POSTGRES_PASSWORD
            valueFrom:
              secretKeyRef:
                name: logiq-logiq-flash
                key: postgres_password
          - name: POSTGRES_HOST
            valueFrom:
              secretKeyRef:
                name: logiq-logiq-flash
                key: postgres_host
          - name: POSTGRES_PORT
            valueFrom:
              secretKeyRef:
                name: logiq-logiq-flash
                key: postgres_port
          - name: POSTGRES_DB
            valueFrom:
              secretKeyRef:
                name: logiq-logiq-flash
                key: postgres_db
          - name: S3_ACCESS
            valueFrom:
              secretKeyRef:
                name: logiq-shared-secret
                key: s3_access
          - name: S3_SECRET
            valueFrom:
              secretKeyRef:
                name: logiq-shared-secret
                key: s3_secret
          - name: S3_BUCKET
            valueFrom:
              secretKeyRef:
                name: logiq-shared-secret
                key: s3_bucket
            
          - name: MY_CLUSTER_ID
            value: LOGIQ
          
          - name: MY_APP_NAME
            value: logiq-flash
          - name: MY_NODE_NAME
            valueFrom:
              fieldRef:
                fieldPath: spec.nodeName
          - name: MY_POD_NAME
            valueFrom:
              fieldRef:
                fieldPath: metadata.name
          - name: MY_POD_NAMESPACE
            valueFrom:
              fieldRef:
                fieldPath: metadata.namespace
          - name: MY_POD_IP
            valueFrom:
              fieldRef:
                fieldPath: status.podIP
          volumeMounts:
          - mountPath: /flash/config
            name: config
          - mountPath: /flash/db
            name: data
          
          
          - mountPath: /flash/sharedcerts
            name: sharedcert
          
          ports:
            - name: grpc
              containerPort: 50054
              protocol: TCP
            - name: webcli
              containerPort: 9998
              protocol: TCP
            - name: api
              containerPort: 9999
              protocol: TCP
            - name: syslog
              containerPort: 1514
              protocol: TCP
            - name: syslogtls
              containerPort: 7514
              protocol: TCP
            - name: cefport
              containerPort: 1515
              protocol: TCP
            - name: cefportls
              containerPort: 7515
              protocol: TCP
            - name: relp
              containerPort: 20514
              protocol: TCP
            - name: relptls
              containerPort: 2514
              protocol: TCP
            - name: fluentforward
              containerPort: 24224
              protocol: TCP
            - name: fluentfwdtls
              containerPort: 24225
              protocol: TCP
            - name: filebeat
              containerPort: 25224
              protocol: TCP
            - name: filebeatls
              containerPort: 25225
              protocol: TCP
            - name: healthcheck
              containerPort: 8080
              protocol: TCP
            - name: rawtcp
              containerPort: 517
              protocol: TCP
          readinessProbe:
            httpGet:
              path: /ready
              port: 8080
            initialDelaySeconds: 10
            periodSeconds: 10
            successThreshold: 1
            failureThreshold: 25
            timeoutSeconds: 15
          resources:
            limits:
              cpu: 1250m
            requests:
              cpu: 1250m
              memory: 512Mi
        - name: logiq-flash-query
          image: "logiqai/flash:v3.1"
          imagePullPolicy: IfNotPresent
          args:
          - -c
          - /flash/bin/flash -config /flash/config/config.yaml -install_root /flash -runtime_folder /flash/db -discovery_domain $(DISCOVERY_DOMAIN) -discovery_url $(DISCOVERY_URL) -discovery_id $(DISCOVERY_ID) -pg_max_idle_conns 10 -pg_max_open_Conns 10 -batch_timer_duration 10s -postgres_timeout 20s --pg_conn_max_lifetime 5m -grpc_port 51054 -health_check_port 18080 --sidecar-node -api_port 19999 
          command:
          - /bin/bash
          env:
          - name: CONFIG_HASH
            value: "dd289722ef34988ce24097cd2d8ef1f147a40728fdbd62f6a97c86256d97ab67"
          - name: DISCOVERY_URL
            value: http://flash-discovery:4000
          - name: DISCOVERY_ID
            valueFrom:
              fieldRef:
                fieldPath: metadata.name
          - name: DISCOVERY_DOMAIN
            value: logiq-flash-headless
          
          - name: REDIS_HOST
            valueFrom:
              secretKeyRef:
                name: logiq-logiq-flash
                key: redis_host
          - name: REDIS_PORT
            valueFrom:
              secretKeyRef:
                name: logiq-logiq-flash
                key: redis_port
          
          
          - name: ADMIN_EMAIL
            valueFrom:
              secretKeyRef:
                name: logiq-logiq-flash
                key: admin_email
          
          
          - name: ADMIN_PASSWORD
            valueFrom:
              secretKeyRef:
                name: logiq-logiq-flash
                key: admin_password
          
          - name: POSTGRES_USER
            valueFrom:
              secretKeyRef:
                name: logiq-logiq-flash
                key: postgres_user
          - name: POSTGRES_PASSWORD
            valueFrom:
              secretKeyRef:
                name: logiq-logiq-flash
                key: postgres_password
          - name: POSTGRES_HOST
            valueFrom:
              secretKeyRef:
                name: logiq-logiq-flash
                key: postgres_host
          - name: POSTGRES_PORT
            valueFrom:
              secretKeyRef:
                name: logiq-logiq-flash
                key: postgres_port
          - name: POSTGRES_DB
            valueFrom:
              secretKeyRef:
                name: logiq-logiq-flash
                key: postgres_db
          - name: S3_ACCESS
            valueFrom:
              secretKeyRef:
                name: logiq-shared-secret
                key: s3_access
          - name: S3_SECRET
            valueFrom:
              secretKeyRef:
                name: logiq-shared-secret
                key: s3_secret
          - name: S3_BUCKET
            valueFrom:
              secretKeyRef:
                name: logiq-shared-secret
                key: s3_bucket
            
          - name: MY_CLUSTER_ID
            value: LOGIQ
          
          - name: MY_APP_NAME
            value: logiq-flash
          - name: MY_NODE_NAME
            valueFrom:
              fieldRef:
                fieldPath: spec.nodeName
          - name: MY_POD_NAME
            valueFrom:
              fieldRef:
                fieldPath: metadata.name
          - name: MY_POD_NAMESPACE
            valueFrom:
              fieldRef:
                fieldPath: metadata.namespace
          - name: MY_POD_IP
            valueFrom:
              fieldRef:
                fieldPath: status.podIP
          ports:
          - containerPort: 51054
            name: grpc
            protocol: TCP
          - containerPort: 19998
            name: webcli
            protocol: TCP
          - containerPort: 19999
            name: api
            protocol: TCP
          - containerPort: 18080
            name: healthcheck
            protocol: TCP
          readinessProbe:
            failureThreshold: 25
            httpGet:
              path: /ready
              port: 18080
              scheme: HTTP
            initialDelaySeconds: 10
            periodSeconds: 10
            successThreshold: 1
            timeoutSeconds: 15
          volumeMounts:
          - mountPath: /flash/config
            name: config
          - mountPath: /flash/db
            name: data
          
          
          - mountPath: /flash/sharedcerts
            name: sharedcert
          
          resources:
            limits:
              memory: 1Gi
            requests:
              cpu: 500m
              memory: 1Gi
        - name: logiq-flash-tracing
          image: "logiqai/tracing:v1.35.2-lq1"
          imagePullPolicy: 
          args:
          - --grpc-storage.server=localhost:50054
          command:
          - /go/bin/all-in-one-linux
          env:
          - name: SPAN_STORAGE_TYPE
            value: grpc-plugin
          resources:
            limits:
              memory: 1Gi
            requests:
              cpu: 50m
              memory: 1Gi
          ports:
          - containerPort: 14250
            name: tracing-2
            protocol: TCP
---
# Source: logiq/charts/logiq-flash/templates/statefulset-ml.yaml
apiVersion: apps/v1
kind: StatefulSet
metadata:
  name: logiq-flash-ml
  namespace: logiq
  labels:
    app: logiq-flash-ml
    chart: logiq-flash-1.0.0
    release: logiq
    heritage: Helm
spec:
  serviceName: logiq-flash-ml
  replicas: 1
  selector:
    matchLabels:
      app: logiq-flash-ml
      release: logiq
  volumeClaimTemplates:
  - metadata:
      name: data
    spec:
      accessModes:
        - ReadWriteOnce
      resources:
        requests:
          storage: "10Gi"
      storageClassName: microk8s-hostpath
  template:
    metadata:
      annotations:
        checksum/config: 5286af0c4df4c5a3793fed5f0625fa4ac645ef619587fd072ecce8a177dcf0db
      labels:
        app: logiq-flash-ml
        release: logiq
    spec:
      serviceAccountName: logiq-flash
      securityContext:
        fsGroup: 1000
        runAsUser: 1000
        runAsGroup: 1000
      initContainers:
      - name: check-redis
        image: logiqai/toolbox:2.0.1
        imagePullPolicy: IfNotPresent
        command:
        - sh
        - -c
        - until redis-cli -h redis-master ping; do echo "waiting for redis-master"; sleep 1;
          done;
          
      - command:
          - sh
          - -c
          - until $(curl --output /dev/null --silent --fail http://s3-gateway:9000/minio/health/ready); do echo "waiting for s3-gateway"; sleep 1;
            done;
        image: logiqai/toolbox:2.0.1
        imagePullPolicy: IfNotPresent
        name: check-s3-gateway
        
      - command:
        - sh
        - -c
        - until $(curl --output /dev/null --silent --fail http://logiq-flash:8080/ready); do echo "waiting for flash"; sleep 1;
          done;
        image: logiqai/toolbox:2.0.1
        imagePullPolicy: IfNotPresent
        name: check-flash
      volumes:
        
        - name: config
          configMap:
            
            name: logiq-config
            
        
        
        
        - name: sharedcert
          secret:
            secretName: logiq-shared-secret
        
      
      containers:
        - name: logiq-flash-ml
          image: "logiqai/flash:v3.1"
          imagePullPolicy: IfNotPresent
          args:
          - -c
          - /flash/bin/flash -config /flash/config/config.yaml -install_root /flash -runtime_folder /flash/db -is-kube=true -discovery_domain=$(DISCOVERY_DOMAIN) -pg_max_idle_conns 50 -pg_max_open_Conns 50 -metadata-db-ttl 11m -postgres_timeout 20s -api-node  -redis_max_connections 3000 --pg_conn_max_lifetime 5m -ml-use-sidecar 
          command:
          - /bin/bash
          env:
          - name: CONFIG_HASH
            value: "dd289722ef34988ce24097cd2d8ef1f147a40728fdbd62f6a97c86256d97ab67"
          - name: DISCOVERY_DOMAIN
            value: logiq-flash-ml
          
          - name: REDIS_HOST
            valueFrom:
              secretKeyRef:
                name: logiq-logiq-flash
                key: redis_host
          - name: REDIS_PORT
            valueFrom:
              secretKeyRef:
                name: logiq-logiq-flash
                key: redis_port
          
          
          - name: ADMIN_EMAIL
            valueFrom:
              secretKeyRef:
                name: logiq-logiq-flash
                key: admin_email
          
          
          - name: ADMIN_PASSWORD
            valueFrom:
              secretKeyRef:
                name: logiq-logiq-flash
                key: admin_password
          
          - name: POSTGRES_USER
            valueFrom:
              secretKeyRef:
                name: logiq-logiq-flash
                key: postgres_user
          - name: POSTGRES_PASSWORD
            valueFrom:
              secretKeyRef:
                name: logiq-logiq-flash
                key: postgres_password
          - name: POSTGRES_HOST
            valueFrom:
              secretKeyRef:
                name: logiq-logiq-flash
                key: postgres_host
          - name: POSTGRES_PORT
            valueFrom:
              secretKeyRef:
                name: logiq-logiq-flash
                key: postgres_port
          - name: POSTGRES_DB
            valueFrom:
              secretKeyRef:
                name: logiq-logiq-flash
                key: postgres_db
          - name: S3_ACCESS
            valueFrom:
              secretKeyRef:
                name: logiq-shared-secret
                key: s3_access
          - name: S3_SECRET
            valueFrom:
              secretKeyRef:
                name: logiq-shared-secret
                key: s3_secret
          - name: S3_BUCKET
            valueFrom:
              secretKeyRef:
                name: logiq-shared-secret
                key: s3_bucket
            
          - name: MY_CLUSTER_ID
            value: LOGIQ
          
          - name: MY_APP_NAME
            value: logiq-flash-ml
          - name: MY_NODE_NAME
            valueFrom:
              fieldRef:
                fieldPath: spec.nodeName
          - name: MY_POD_NAME
            valueFrom:
              fieldRef:
                fieldPath: metadata.name
          - name: MY_POD_NAMESPACE
            valueFrom:
              fieldRef:
                fieldPath: metadata.namespace
          - name: MY_POD_IP
            valueFrom:
              fieldRef:
                fieldPath: status.podIP
          volumeMounts:
          - mountPath: /flash/config
            name: config
          - mountPath: /flash/db
            name: data
          
          
          - mountPath: /flash/sharedcerts
            name: sharedcert
          
          ports:
            - name: grpc
              containerPort: 50054
              protocol: TCP
            - name: webcli
              containerPort: 9998
              protocol: TCP
            - name: api
              containerPort: 9999
              protocol: TCP
            - name: healthcheck
              containerPort: 8080
              protocol: TCP
          readinessProbe:
            httpGet:
              path: /ready
              port: 8080
            initialDelaySeconds: 10
            periodSeconds: 25
            successThreshold: 1
            failureThreshold: 3
            timeoutSeconds: 25
          resources:
            limits:
              memory: 1Gi
            requests:
              cpu: 500m
              memory: 1Gi
        - name: logiq-flash-tracing
          image: "logiqai/tracing:v1.35.2-lq1-q"
          imagePullPolicy: 
          args:
          - --grpc-storage.server=localhost:50054
          - --query.bearer-token-propagation=true
          - --query.base-path=/dtracing
          command:
          - /go/bin/query-linux
          env:          
          - name: SPAN_STORAGE_TYPE
            value: grpc-plugin
          ports:
          - containerPort: 16686
            name: tracing
            protocol: TCP
          resources:
            limits:
              memory: 1Gi
            requests:
              cpu: 50m
              memory: 1Gi
---
# Source: logiq/charts/logiq-flash/templates/statefulset-sync.yaml
apiVersion: apps/v1
kind: StatefulSet
metadata:
  name: logiq-flash-sync
  namespace: logiq
  labels:
    app: logiq-flash-sync
    chart: logiq-flash-1.0.0
    release: logiq
    heritage: Helm
spec:
  serviceName: logiq-flash-sync
  replicas: 1
  selector:
    matchLabels:
      app: logiq-flash-sync
      release: logiq
  template:
    metadata:
      annotations:
        checksum/config: 5286af0c4df4c5a3793fed5f0625fa4ac645ef619587fd072ecce8a177dcf0db
      labels:
        app: logiq-flash-sync
        release: logiq
    spec:
      serviceAccountName: logiq-flash
      securityContext:
        fsGroup: 1000
        runAsUser: 1000
        runAsGroup: 1000
      initContainers:
      - command:
        - sh
        - -c
        - until $(curl --output /dev/null --silent --fail http://logiq-flash:8080/ready); do echo "waiting for flash"; sleep 1;
          done;
        image: logiqai/toolbox:2.0.1
        imagePullPolicy: IfNotPresent
        name: check-flash
      - name: check-redis
        image: logiqai/toolbox:2.0.1
        imagePullPolicy: IfNotPresent
        command:
        - sh
        - -c
        - until redis-cli -h redis-master ping; do echo "waiting for redis-master"; sleep 1;
          done;
                 
      - command:
          - sh
          - -c
          - until $(curl --output /dev/null --silent --fail http://s3-gateway:9000/minio/health/ready); do echo "waiting for s3-gateway"; sleep 1;
            done;
        image: logiqai/toolbox:2.0.1
        imagePullPolicy: IfNotPresent
        name: check-s3-gateway
            
      volumes:
        
        - name: config
          configMap:
            
            name: logiq-config
            
        
        
        
        - name: sharedcert
          secret:
            secretName: logiq-shared-secret
        
        - name: data
          emptyDir: {}
      
      containers:
        - name: logiq-flash-sync
          image: "logiqai/flash:v3.1"
          imagePullPolicy: IfNotPresent
          args:
          - -c
          - /flash/bin/flash -config /flash/config/config.yaml -install_root /flash -runtime_folder /flash/db -is-kube=true -discovery_domain=$(DISCOVERY_DOMAIN) -pg_max_idle_conns 100 -pg_max_open_Conns 100 -postgres_timeout 40s -metadata-db-ttl 11m -metadata-text-upload-jobs 50 -sync-node
          command:
          - /bin/bash
          env:
          - name: CONFIG_HASH
            value: "dd289722ef34988ce24097cd2d8ef1f147a40728fdbd62f6a97c86256d97ab67"
          - name: DISCOVERY_DOMAIN
            value: logiq-flash-sync
          
          - name: REDIS_HOST
            valueFrom:
              secretKeyRef:
                name: logiq-logiq-flash
                key: redis_host
          - name: REDIS_PORT
            valueFrom:
              secretKeyRef:
                name: logiq-logiq-flash
                key: redis_port
          
          
          - name: ADMIN_EMAIL
            valueFrom:
              secretKeyRef:
                name: logiq-logiq-flash
                key: admin_email
          
          
          - name: ADMIN_PASSWORD
            valueFrom:
              secretKeyRef:
                name: logiq-logiq-flash
                key: admin_password
          
          - name: POSTGRES_USER
            valueFrom:
              secretKeyRef:
                name: logiq-logiq-flash
                key: postgres_user
          - name: POSTGRES_PASSWORD
            valueFrom:
              secretKeyRef:
                name: logiq-logiq-flash
                key: postgres_password
          - name: POSTGRES_HOST
            valueFrom:
              secretKeyRef:
                name: logiq-logiq-flash
                key: postgres_host
          - name: POSTGRES_PORT
            valueFrom:
              secretKeyRef:
                name: logiq-logiq-flash
                key: postgres_port
          - name: POSTGRES_DB
            valueFrom:
              secretKeyRef:
                name: logiq-logiq-flash
                key: postgres_db
          - name: S3_ACCESS
            valueFrom:
              secretKeyRef:
                name: logiq-shared-secret
                key: s3_access
          - name: S3_SECRET
            valueFrom:
              secretKeyRef:
                name: logiq-shared-secret
                key: s3_secret
          - name: S3_BUCKET
            valueFrom:
              secretKeyRef:
                name: logiq-shared-secret
                key: s3_bucket
            
          - name: MY_CLUSTER_ID
            value: LOGIQ
          
          - name: MY_APP_NAME
            value: logiq-flash-sync
          - name: MY_NODE_NAME
            valueFrom:
              fieldRef:
                fieldPath: spec.nodeName
          - name: MY_POD_NAME
            valueFrom:
              fieldRef:
                fieldPath: metadata.name
          - name: MY_POD_NAMESPACE
            valueFrom:
              fieldRef:
                fieldPath: metadata.namespace
          - name: MY_POD_IP
            valueFrom:
              fieldRef:
                fieldPath: status.podIP
          volumeMounts:
          - mountPath: /flash/config
            name: config
          - mountPath: /flash/db
            name: data
          
          
          - mountPath: /flash/sharedcerts
            name: sharedcert
          
          ports:
            - name: grpc
              containerPort: 50054
              protocol: TCP
            - name: webcli
              containerPort: 9998
              protocol: TCP
            - name: api
              containerPort: 9999
              protocol: TCP
            - name: healthcheck
              containerPort: 8080
              protocol: TCP
          readinessProbe:
            httpGet:
              path: /ready
              port: 8080
            initialDelaySeconds: 10
            periodSeconds: 25
            successThreshold: 1
            failureThreshold: 3
            timeoutSeconds: 25
          resources:
            requests:
              cpu: 100m
---
# Source: logiq/charts/postgres/templates/statefulset.yaml
apiVersion: apps/v1
kind: StatefulSet
metadata:
  name: postgres
  namespace: logiq
  labels:
    app: postgres
    chart: postgres-8.7.3
    release: "logiq"
    heritage: "Helm"
spec:
  serviceName: postgres-headless
  replicas: 1
  updateStrategy:
    type: RollingUpdate
  selector:
    matchLabels:
      app: postgres
      release: "logiq"
      role: master
  template:
    metadata:
      name: postgres
      labels:
        app: postgres
        chart: postgres-8.7.3
        release: "logiq"
        heritage: "Helm"
        role: master
    spec:      


      securityContext:
        fsGroup: 1001
      serviceAccountName: postgres
      containers:
        - name: postgres
          image: docker.io/bitnami/postgresql:12.3.0-debian-10-r18
          imagePullPolicy: "IfNotPresent"
          resources:
            requests:
              cpu: 100m
              memory: 0.5Gi
          securityContext:
            runAsUser: 1001
          env:
            - name: BITNAMI_DEBUG
              value: "false"
            - name: POSTGRESQL_PORT_NUMBER
              value: "5432"
            - name: POSTGRESQL_VOLUME_DIR
              value: "/bitnami/postgresql"
            - name: PGDATA
              value: "/bitnami/postgresql/data"
            - name: POSTGRES_USER
              value: "postgres"
            - name: POSTGRES_PASSWORD
              valueFrom:
                secretKeyRef:
                  name: postgres
                  key: postgresql-password
            - name: POSTGRES_DB
              value: "postgres"
            - name: POSTGRESQL_ENABLE_LDAP
              value: "no"
          ports:
            - name: tcp-postgresql
              containerPort: 5432
          livenessProbe:
            exec:
              command:
                - /bin/sh
                - -c
                - exec pg_isready -U "postgres" -d "postgres" -h 127.0.0.1 -p 5432
            initialDelaySeconds: 30
            periodSeconds: 10
            timeoutSeconds: 5
            successThreshold: 1
            failureThreshold: 6
          readinessProbe:
            exec:
              command:
                - /bin/sh
                - -c
                - -e
                - |
                  exec pg_isready -U "postgres" -d "postgres" -h 127.0.0.1 -p 5432
                  [ -f /opt/bitnami/postgresql/tmp/.initialized ] || [ -f /bitnami/postgresql/.initialized ]
            initialDelaySeconds: 5
            periodSeconds: 10
            timeoutSeconds: 5
            successThreshold: 1
            failureThreshold: 6
          volumeMounts:
            - name: postgresql-extended-config
              mountPath: /bitnami/postgresql/conf/conf.d/
            - name: dshm
              mountPath: /dev/shm
            - name: data
              mountPath: /bitnami/postgresql
              subPath: 
        - name: metrics
          image: docker.io/bitnami/postgres-exporter:0.8.0-debian-10-r72
          imagePullPolicy: "IfNotPresent"
          securityContext:
            runAsUser: 1001
          env:
            - name: DATA_SOURCE_URI
              value: "127.0.0.1:5432/postgres?sslmode=disable"
            - name: DATA_SOURCE_PASS
              valueFrom:
                secretKeyRef:
                  name: postgres
                  key: postgresql-password
            - name: DATA_SOURCE_USER
              value: postgres
          livenessProbe:
            httpGet:
              path: /
              port: http-metrics
            initialDelaySeconds: 5
            periodSeconds: 10
            timeoutSeconds: 5
            successThreshold: 1
            failureThreshold: 6
          readinessProbe:
            httpGet:
              path: /
              port: http-metrics
            initialDelaySeconds: 5
            periodSeconds: 10
            timeoutSeconds: 5
            successThreshold: 1
            failureThreshold: 6
          volumeMounts:
          ports:
            - name: http-metrics
              containerPort: 9187
      volumes:
        - name: postgresql-extended-config
          configMap:
            name: postgres-extended-configuration
        - name: dshm
          emptyDir:
            medium: Memory
            sizeLimit: 1Gi
  volumeClaimTemplates:
    - metadata:
        name: data
      spec:
        accessModes:
          - "ReadWriteOnce"
        resources:
          requests:
            storage: "1Gi"
        storageClassName: microk8s-hostpath
---
# Source: logiq/charts/redis/templates/redis-master-statefulset.yaml
apiVersion: apps/v1
kind: StatefulSet
metadata:
  name: redis-master
  namespace: logiq
  labels:
    app: redis
    chart: redis-10.6.5
    release: logiq
    heritage: Helm
spec:
  selector:
    matchLabels:
      app: redis
      release: logiq
      role: master
  serviceName: redis-headless
  template:
    metadata:
      labels:
        app: redis
        chart: redis-10.6.5
        release: logiq
        role: master
      annotations:
        checksum/health: e8e99923b8eed0e2c97e84461c2924f5a5841f39626d08f86d5b949b40404c20
        checksum/configmap: 94ff7fc339c155eb08eb6bd5f7d6e5d22db9734b82d562fdf7608c416a994530
        checksum/secret: e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855
        prometheus.io/port: "9121"
        prometheus.io/scrape: "true"
    spec:      
      securityContext:
        fsGroup: 1001
      serviceAccountName: "redis"
      affinity:
        podAntiAffinity:
          requiredDuringSchedulingIgnoredDuringExecution:
          - labelSelector:
              matchExpressions:
              - key: app
                operator: In
                values:
                - redis
            topologyKey: kubernetes.io/hostname


      containers:
      - name: redis
        image: "docker.io/bitnami/redis:6.0.4-debian-10-r6"
        imagePullPolicy: "IfNotPresent"
        securityContext:
          runAsUser: 1001
        command:
        - /bin/bash
        - -c
        - |
          if [[ -n $REDIS_PASSWORD_FILE ]]; then
            password_aux=`cat ${REDIS_PASSWORD_FILE}`
            export REDIS_PASSWORD=$password_aux
          fi
          if [[ ! -f /opt/bitnami/redis/etc/master.conf ]];then
            cp /opt/bitnami/redis/mounted-etc/master.conf /opt/bitnami/redis/etc/master.conf
          fi
          if [[ ! -f /opt/bitnami/redis/etc/redis.conf ]];then
            cp /opt/bitnami/redis/mounted-etc/redis.conf /opt/bitnami/redis/etc/redis.conf
          fi
          ARGS=("--port" "${REDIS_PORT}")
          ARGS+=("--protected-mode" "no")
          ARGS+=("--include" "/opt/bitnami/redis/etc/redis.conf")
          ARGS+=("--include" "/opt/bitnami/redis/etc/master.conf")
          /run.sh ${ARGS[@]}
        env:
        - name: REDIS_REPLICATION_MODE
          value: master
        - name: ALLOW_EMPTY_PASSWORD
          value: "yes"
        - name: REDIS_PORT
          value: "6379"
        ports:
        - name: redis
          containerPort: 6379
        livenessProbe:
          initialDelaySeconds: 5
          periodSeconds: 5
          timeoutSeconds: 5
          successThreshold: 1
          failureThreshold: 5
          exec:
            command:
            - sh
            - -c
            - /health/ping_liveness_local.sh 5
        readinessProbe:
          initialDelaySeconds: 5
          periodSeconds: 5
          timeoutSeconds: 1
          successThreshold: 1
          failureThreshold: 5
          exec:
            command:
            - sh
            - -c
            - /health/ping_readiness_local.sh 5
        resources:
          null
        volumeMounts:
        - name: health
          mountPath: /health
        - name: redis-data
          mountPath: /data
          subPath: 
        - name: config
          mountPath: /opt/bitnami/redis/mounted-etc
        - name: redis-tmp-conf
          mountPath: /opt/bitnami/redis/etc/
      - name: metrics
        image: docker.io/bitnami/redis-exporter:1.5.2-debian-10-r24
        imagePullPolicy: "IfNotPresent"
        command:
        - /bin/bash
        - -c
        - |
          if [[ -f '/secrets/redis-password' ]]; then
           export REDIS_PASSWORD=$(cat /secrets/redis-password)
          fi
          redis_exporter
        env:
        - name: REDIS_ALIAS
          value: redis
        volumeMounts:
        ports:
        - name: metrics
          containerPort: 9121
        resources:
          null
      volumes:
      - name: health
        configMap:
          name: redis-health
          defaultMode: 0755
      - name: config
        configMap:
          name: redis
      - name: "redis-data"
        emptyDir: {}
      - name: redis-tmp-conf
        emptyDir: {}
  updateStrategy:
    type: RollingUpdate
---
# Source: logiq/charts/s3gateway/templates/statefulset.yaml
apiVersion: apps/v1
kind: StatefulSet
metadata:
  name: s3-gateway
  labels:
    app: s3gateway
    chart: s3gateway-5.0.20
    release: logiq
    heritage: Helm
spec:
  updateStrategy:
    type: RollingUpdate
  podManagementPolicy: "Parallel"
  serviceName: s3-gateway-svc
  replicas: 4
  selector:
    matchLabels:
      app: s3gateway
      release: logiq
  template:
    metadata:
      name: s3-gateway
      labels:
        app: s3gateway
        release: logiq
      annotations:
        checksum/secrets: 05fa62bcb5eef9595053ce5a8640327ffb33b6fdad21127d690fbe28468fdb09
        checksum/config: 2ac2efadc3d5fb6d1195cd2646fbb6de8212de42c62c56d3c55500dcd9a967df
    spec:
      serviceAccountName: "s3-gateway"
      securityContext:
        runAsUser: 1000
        runAsGroup: 1000
        fsGroup: 1000
      containers:
        - name: s3gateway
          image: minio/minio:RELEASE.2020-09-17T04-49-20Z
          imagePullPolicy: IfNotPresent
          command: [ "/bin/sh",
            "-ce",
            "/usr/bin/docker-entrypoint.sh minio -S /etc/minio/certs/ server  http://s3-gateway-{0...3}.s3-gateway-svc.logiq.svc.cluster.local/export" ]
          volumeMounts:
            - name: export
              mountPath: /export
            
          ports:
            - name: http
              containerPort: 9000
          env:
            - name: MINIO_PROMETHEUS_AUTH_TYPE 
              value: "public"
            - name: MINIO_ACCESS_KEY
              valueFrom:
                secretKeyRef:
                  name: s3-gateway
                  key: accesskey
            - name: MINIO_SECRET_KEY
              valueFrom:
                secretKeyRef:
                  name: s3-gateway
                  key: secretkey
          livenessProbe:
            httpGet:
              path: /minio/health/live
              port: http
              scheme: HTTP
            initialDelaySeconds: 5
            periodSeconds: 30
            timeoutSeconds: 1
            successThreshold: 1
            failureThreshold: 3
          readinessProbe:
            httpGet:
              path: /minio/health/ready
              port: http
              scheme: HTTP
            initialDelaySeconds: 60
            periodSeconds: 15
            timeoutSeconds: 1
            successThreshold: 1
            failureThreshold: 3
          resources:
            {}


      volumes:
        - name: minio-user
          secret:
            secretName: s3-gateway
  volumeClaimTemplates:
    - metadata:
        name: export
      spec:
        accessModes: [ "ReadWriteOnce" ]
        storageClassName: microk8s-hostpath
        resources:
          requests:
            storage: 25Gi
---
# Source: logiq/charts/thanos/templates/receive/statefulset.yaml
apiVersion: apps/v1
kind: StatefulSet
metadata:
  name: logiq-thanos-receive
  namespace: "logiq"
  labels:
    app.kubernetes.io/name: thanos
    helm.sh/chart: thanos-8.2.5
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
    app.kubernetes.io/component: receive
spec:
  replicas: 1
  podManagementPolicy: OrderedReady
  serviceName: logiq-thanos-receive-headless
  updateStrategy:
    type: RollingUpdate
  selector:
    matchLabels:
      app.kubernetes.io/name: thanos
      app.kubernetes.io/instance: logiq
      app.kubernetes.io/component: receive
  template:
    metadata:
      labels:
        app.kubernetes.io/name: thanos
        helm.sh/chart: thanos-8.2.5
        app.kubernetes.io/instance: logiq
        app.kubernetes.io/managed-by: Helm
        app.kubernetes.io/component: receive
      annotations:
        checksum/ojbstore-configuration: da75997dd0b9aece1666342dee51b8a13d97cd034e79263b88d83bbc95e5c7f9
        checksum/receive-configuration: 78dde4c5f74f79f295481b7c04003b301212f3f4a0b054ff46d7ca1a22704d4a
    spec:
      
      serviceAccount: logiq-thanos-receive
      affinity:
        podAffinity:
          
        podAntiAffinity:
          preferredDuringSchedulingIgnoredDuringExecution:
            - podAffinityTerm:
                labelSelector:
                  matchLabels:
                    app.kubernetes.io/name: thanos
                    app.kubernetes.io/instance: logiq
                    app.kubernetes.io/component: receive
                namespaces:
                  - "logiq"
                topologyKey: kubernetes.io/hostname
              weight: 1


      securityContext:
        fsGroup: 1001
      containers:
        - name: receive
          image: docker.io/bitnami/thanos:0.24.0-scratch-r0
          imagePullPolicy: "IfNotPresent"
          securityContext:
            allowPrivilegeEscalation: false
            readOnlyRootFilesystem: false
            runAsNonRoot: true
            runAsUser: 1001
          args:
            - receive
            - --log.level=debug
            - --log.format=logfmt
            - --grpc-address=0.0.0.0:10901
            - --http-address=0.0.0.0:10902
            - --remote-write.address=0.0.0.0:19291
            - --receive.replication-factor=1
            - --objstore.config=$(OBJSTORE_CONFIG)
            - --tsdb.path=/var/thanos/receive
            - --label=replica="$(NAME)"
            - --label=receive="true"
            - --tsdb.retention=30d
            - --receive.local-endpoint=127.0.0.1:10901
            - --receive.hashrings-file=/var/lib/thanos-receive/hashrings.json
          env:
            - name: NAME
              valueFrom:
                fieldRef:
                  fieldPath: metadata.name
            - name: NAMESPACE
              valueFrom:
                fieldRef:
                  fieldPath: metadata.namespace
            - name: OBJSTORE_CONFIG
              valueFrom:
                secretKeyRef:
                  key: objstore.yml
                  name: logiq-thanos-objstore-secret
          ports:
            - containerPort: 10901
              name: grpc
              protocol: TCP
            - containerPort: 10902
              name: http
              protocol: TCP
            - containerPort: 19291
              name: remote-write
              protocol: TCP
          livenessProbe:
            failureThreshold: 6
            initialDelaySeconds: 30
            periodSeconds: 10
            successThreshold: 1
            timeoutSeconds: 30
            httpGet:
              path: /-/healthy
              port: http
          readinessProbe:
            failureThreshold: 6
            initialDelaySeconds: 30
            periodSeconds: 10
            successThreshold: 1
            timeoutSeconds: 30
            httpGet:
              path: /-/ready
              port: http
          resources:
            limits: {}
            requests: {}
          volumeMounts:
            - name: hashring-config
              mountPath: /var/lib/thanos-receive
            - name: data
              mountPath: /var/thanos/receive
      volumes:
        - name: hashring-config
          configMap:
            name: logiq-thanos-receive
  volumeClaimTemplates:
    - metadata:
        name: data
      spec:
        accessModes:
          - "ReadWriteOnce"
        resources:
          requests:
            storage: "8Gi"
---
# Source: logiq/charts/thanos/templates/ruler/statefulset.yaml
apiVersion: apps/v1
kind: StatefulSet
metadata:
  name: logiq-thanos-ruler
  namespace: "logiq"
  labels:
    app.kubernetes.io/name: thanos
    helm.sh/chart: thanos-8.2.5
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
    app.kubernetes.io/component: ruler
spec:
  replicas: 1
  podManagementPolicy: OrderedReady
  serviceName: logiq-thanos-ruler-headless
  updateStrategy:
    type: RollingUpdate
  selector:
    matchLabels:
      app.kubernetes.io/name: thanos
      app.kubernetes.io/instance: logiq
      app.kubernetes.io/component: ruler
  template:
    metadata:
      labels:
        app.kubernetes.io/name: thanos
        helm.sh/chart: thanos-8.2.5
        app.kubernetes.io/instance: logiq
        app.kubernetes.io/managed-by: Helm
        app.kubernetes.io/component: ruler
      annotations:
        checksum/ojbstore-configuration: da75997dd0b9aece1666342dee51b8a13d97cd034e79263b88d83bbc95e5c7f9
        checksum/ruler-configuration: f6d4bce844313c4dcc3ccefd82c0fc538eaf1cf38ecca93963360861c4a0c7f8
    spec:
      
      serviceAccount: logiq-thanos-ruler
      affinity:
        podAffinity:
          
        podAntiAffinity:
          preferredDuringSchedulingIgnoredDuringExecution:
            - podAffinityTerm:
                labelSelector:
                  matchLabels:
                    app.kubernetes.io/name: thanos
                    app.kubernetes.io/instance: logiq
                    app.kubernetes.io/component: ruler
                namespaces:
                  - "logiq"
                topologyKey: kubernetes.io/hostname
              weight: 1


      securityContext:
        fsGroup: 1001
      containers:
        - name: ruler
          image: docker.io/bitnami/thanos:0.24.0-scratch-r0
          imagePullPolicy: "IfNotPresent"
          securityContext:
            allowPrivilegeEscalation: false
            readOnlyRootFilesystem: false
            runAsNonRoot: true
            runAsUser: 1001
          args:
            - rule
            - --log.level=info
            - --log.format=logfmt
            - --grpc-address=0.0.0.0:10901
            - --http-address=0.0.0.0:10902
            - --data-dir=/data
            - --eval-interval=1m
            - --alertmanagers.url=http://logiq-prometheus-alertmanager.logiq.svc.cluster.local:9093
            - --query=dnssrv+_http._tcp.logiq-thanos-query.logiq.svc.cluster.local
            - --label=replica="$(POD_NAME)"
            - --label=ruler_cluster=""
            - --alert.label-drop=replica
            - --objstore.config-file=/conf/objstore/objstore.yml
            - --rule-file=/conf/rules/*.yml
          env:
            - name: POD_NAME
              valueFrom:
                fieldRef:
                  fieldPath: metadata.name
          ports:
            - name: http
              containerPort: 10902
              protocol: TCP
            - name: grpc
              containerPort: 10901
              protocol: TCP
          livenessProbe:
            failureThreshold: 6
            initialDelaySeconds: 30
            periodSeconds: 10
            successThreshold: 1
            timeoutSeconds: 30
            httpGet:
              path: /-/healthy
              port: http
          readinessProbe:
            failureThreshold: 6
            initialDelaySeconds: 30
            periodSeconds: 10
            successThreshold: 1
            timeoutSeconds: 30
            httpGet:
              path: /-/ready
              port: http
          resources:
            limits: {}
            requests: {}
          volumeMounts:
            - name: ruler-config
              mountPath: /conf/rules
            - name: objstore-config
              mountPath: /conf/objstore
            - name: data
              mountPath: /data
      volumes:
        - name: ruler-config
          configMap:
            name: logiq-thanos-ruler-configmap
        - name: objstore-config
          secret:
            secretName: logiq-thanos-objstore-secret
  volumeClaimTemplates:
    - metadata:
        name: data
      spec:
        accessModes:
          - "ReadWriteOnce"
        resources:
          requests:
            storage: "8Gi"
---
# Source: logiq/charts/thanos/templates/storegateway/statefulset.yaml
apiVersion: apps/v1
kind: StatefulSet
metadata:
  name: logiq-thanos-storegateway
  namespace: "logiq"
  labels:
    app.kubernetes.io/name: thanos
    helm.sh/chart: thanos-8.2.5
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
    app.kubernetes.io/component: storegateway
spec:
  replicas: 1
  podManagementPolicy: OrderedReady
  serviceName: logiq-thanos-storegateway-headless
  updateStrategy:
    type: RollingUpdate
  selector:
    matchLabels:
      app.kubernetes.io/name: thanos
      app.kubernetes.io/instance: logiq
      app.kubernetes.io/component: storegateway
  template:
    metadata:
      labels:
        app.kubernetes.io/name: thanos
        helm.sh/chart: thanos-8.2.5
        app.kubernetes.io/instance: logiq
        app.kubernetes.io/managed-by: Helm
        app.kubernetes.io/component: storegateway
      annotations:
        checksum/ojbstore-configuration: da75997dd0b9aece1666342dee51b8a13d97cd034e79263b88d83bbc95e5c7f9
    spec:
      
      serviceAccount: logiq-thanos-storegateway
      affinity:
        podAffinity:
          
        podAntiAffinity:
          preferredDuringSchedulingIgnoredDuringExecution:
            - podAffinityTerm:
                labelSelector:
                  matchLabels:
                    app.kubernetes.io/name: thanos
                    app.kubernetes.io/instance: logiq
                    app.kubernetes.io/component: storegateway
                namespaces:
                  - "logiq"
                topologyKey: kubernetes.io/hostname
              weight: 1


      securityContext:
        fsGroup: 1001
      containers:
        - name: storegateway
          image: docker.io/bitnami/thanos:0.24.0-scratch-r0
          imagePullPolicy: "IfNotPresent"
          securityContext:
            allowPrivilegeEscalation: false
            readOnlyRootFilesystem: false
            runAsNonRoot: true
            runAsUser: 1001
          args:
            - store
            - --log.level=info
            - --log.format=logfmt
            - --grpc-address=0.0.0.0:10901
            - --http-address=0.0.0.0:10902
            - --data-dir=/data
            - --objstore.config-file=/conf/objstore.yml
          ports:
            - name: http
              containerPort: 10902
              protocol: TCP
            - name: grpc
              containerPort: 10901
              protocol: TCP
          livenessProbe:
            failureThreshold: 6
            initialDelaySeconds: 30
            periodSeconds: 10
            successThreshold: 1
            timeoutSeconds: 30
            httpGet:
              path: /-/healthy
              port: http
          readinessProbe:
            failureThreshold: 6
            initialDelaySeconds: 30
            periodSeconds: 10
            successThreshold: 1
            timeoutSeconds: 30
            httpGet:
              path: /-/ready
              port: http
          resources:
            limits: {}
            requests: {}
          volumeMounts:
            - name: objstore-config
              mountPath: /conf
            - name: data
              mountPath: /data
      volumes:
        - name: objstore-config
          secret:
            secretName: logiq-thanos-objstore-secret
  volumeClaimTemplates:
    - metadata:
        name: data
      spec:
        accessModes:
          - "ReadWriteOnce"
        resources:
          requests:
            storage: "8Gi"
---
# Source: logiq/templates/ingress.yaml
apiVersion: networking.k8s.io/v1
kind: Ingress
metadata:
  name: logiq-ingress
  namespace: logiq
  labels:
    helm.sh/chart: logiq-v3.0.5
    app.kubernetes.io/name: logiq
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/version: "v3.0.5"
    app.kubernetes.io/managed-by: Helm
  annotations:
    kubernetes.io/ingress.class: logiq-ingress-logiq
    ingress.kubernetes.io/proxy-body-size: 100M
    ingress.kubernetes.io/app-root: "/"
    nginx.ingress.kubernetes.io/connection-proxy-header: keep-alive
    nginx.ingress.kubernetes.io/load-balance: round_robin
    nginx.ingress.kubernetes.io/proxy-send-timeout: "300"
    nginx.ingress.kubernetes.io/session-cookie-expires: "300"
    nginx.ingress.kubernetes.io/session-cookie-max-age: "300"
    nginx.ingress.kubernetes.io/client-body-buffer-size: 1M
    nginx.org/proxy-connect-timeout: 30s
    nginx.org/proxy-read-timeout: 175s
    nginx.ingress.kubernetes.io/configuration-snippet: |
      if ($request_uri ~* \.(js|css|gif|jpe?g|png)) {
        expires 1M;
        add_header Cache-Control "public";
      }
spec:
  rules:
    
    - http:
        paths:
        - path: /
          pathType: Prefix
          backend:
            service:
              name: coffee
              port: 
                 number: 80
        - path: /v1/json_batch
          pathType: Prefix
          backend:
            service:
                name: logiq-flash
                port: 
                   number: 9999
        - path: /v1/json
          pathType: Prefix
          backend:
            service:
               name: logiq-flash
               port: 
                  number: 9999
        - path: /v1
          pathType: Prefix
          backend:
            service:
               name: logiq-flash-ml
               port: 
                 number: 9999
        - path: /v2
          pathType: Prefix
          backend:
            service:
               name: logiq-flash-ml
               port: 
                   number: 9999
        - path: /dtracing
          pathType: Prefix
          backend:
            service:
               name: logiq-flash-ml
               port: 
                   number: 16686          
         
        - path: /api/v1/receive
          pathType: Prefix
          backend:
            service:
               name: logiq-thanos-receive
               port:
                  number: 19291
---
# Source: logiq/charts/prometheus/templates/alertmanager/alertmanager.yaml
apiVersion: monitoring.coreos.com/v1
kind: Alertmanager
metadata:
  name: logiq-prometheus-alertmanager
  namespace: logiq
  labels:
    app.kubernetes.io/name: prometheus
    helm.sh/chart: prometheus-6.5.3
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
    app.kubernetes.io/component: alertmanager
spec:
  replicas: 1
  serviceAccountName: logiq-prometheus-alertmanager
  image: docker.io/bitnami/alertmanager:0.23.0-debian-10-r113
  listenLocal: false
  externalUrl: http://logiq-prometheus-alertmanager.logiq:9093/
  portName: "web"
  paused: false
  logFormat: logfmt
  logLevel: info
  retention: 120h
  resources:
    {}
  routePrefix: "/"
  securityContext:
    fsGroup: 1001
    runAsUser: 1001
  storage:
    volumeClaimTemplate:
      spec:
        accessModes:
          - "ReadWriteOnce"
        resources:
          requests:
            storage: "20Gi"
        
  podMetadata:
    labels:
      app.kubernetes.io/name: prometheus
      app.kubernetes.io/instance: logiq
      app.kubernetes.io/component: alertmanager
  affinity:
    podAntiAffinity:
      preferredDuringSchedulingIgnoredDuringExecution:
        - podAffinityTerm:
            labelSelector:
              matchLabels:
                app.kubernetes.io/name: prometheus
                app.kubernetes.io/instance: logiq
                app.kubernetes.io/component: alertmanager
            namespaces:
              - "logiq"
            topologyKey: kubernetes.io/hostname
          weight: 1
  
  containers:
    ## This monkey patching is needed until the securityContexts are
    ## directly patchable via the CRD.
    ## ref: https://github.com/prometheus-operator/prometheus-operator/issues/3947
    ## currently implemented with strategic merge
    ## ref: https://github.com/prometheus-operator/prometheus-operator/blob/master/Documentation/user-guides/strategic-merge-patch.md
    - name: alertmanager
      securityContext:
        allowPrivilegeEscalation: false
        capabilities:
          drop:
          - ALL
        readOnlyRootFilesystem: false
        runAsNonRoot: true
      livenessProbe:
        httpGet:
          path: /-/healthy
          port: web
          scheme: HTTP
        initialDelaySeconds: 0
        periodSeconds: 25
        timeoutSeconds: 25
        failureThreshold: 120
        successThreshold: 1
      readinessProbe:
        httpGet:
          path: /-/ready
          port: web
          scheme: HTTP
        initialDelaySeconds: 0
        periodSeconds: 25
        timeoutSeconds: 25
        failureThreshold: 120
        successThreshold: 1
    ## This monkey patching is needed until the securityContexts are
    ## directly patchable via the CRD.
    ## ref: https://github.com/prometheus-operator/prometheus-operator/issues/3947
    ## currently implemented with strategic merge
    ## ref: https://github.com/prometheus-operator/prometheus-operator/blob/master/Documentation/user-guides/strategic-merge-patch.md
    - name: config-reloader
      securityContext:
        allowPrivilegeEscalation: false
        capabilities:
          drop:
          - ALL
        readOnlyRootFilesystem: false
        runAsNonRoot: true
      livenessProbe:
        tcpSocket:
          port: reloader-web
        initialDelaySeconds: 10
        periodSeconds: 10
        timeoutSeconds: 5
        failureThreshold: 6
        successThreshold: 1
      readinessProbe:
        tcpSocket:
          port: reloader-web
        initialDelaySeconds: 15
        periodSeconds: 20
        timeoutSeconds: 5
        failureThreshold: 6
        successThreshold: 1
---
# Source: logiq/charts/prometheus/templates/prometheus/prometheus.yaml
apiVersion: monitoring.coreos.com/v1
kind: Prometheus
metadata:
  name: logiq-prometheus-prometheus
  namespace: logiq
  labels:
    app.kubernetes.io/name: prometheus
    helm.sh/chart: prometheus-6.5.3
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
    app.kubernetes.io/component: prometheus
spec:
  replicas: 1
  serviceAccountName: logiq-prometheus-prometheus
  serviceMonitorSelector: {}
  podMonitorSelector: {}
  probeSelector: {}
  alerting:
    alertmanagers:
      - namespace: logiq
        name: logiq-prometheus-alertmanager
        port: http
        pathPrefix: "/"
  image: docker.io/bitnami/prometheus:2.32.1-debian-10-r2
  externalUrl: http://logiq-prometheus-prometheus.logiq:9090/
  paused: false
  logLevel: info
  logFormat: logfmt
  listenLocal: false
  enableAdminAPI: false
  retention: 30d
  portName: "web"
  routePrefix: "/"
  serviceMonitorNamespaceSelector: {}
  podMonitorNamespaceSelector: {}
  probeNamespaceSelector: {}
  securityContext:
    fsGroup: 1001
    runAsUser: 1001
  ruleNamespaceSelector: {}
  ruleSelector: {}
  storage:
    volumeClaimTemplate:
      spec:
        accessModes:
          - "ReadWriteOnce"
        resources:
          requests:
            storage: "20Gi"
        
  podMetadata:
    labels:
      app.kubernetes.io/name: prometheus
      app.kubernetes.io/instance: logiq
      app.kubernetes.io/component: prometheus
  affinity:
    podAntiAffinity:
      preferredDuringSchedulingIgnoredDuringExecution:
        - podAffinityTerm:
            labelSelector:
              matchLabels:
                app.kubernetes.io/name: prometheus
                app.kubernetes.io/instance: logiq
                app.kubernetes.io/component: prometheus
            namespaces:
              - "logiq"
            topologyKey: kubernetes.io/hostname
          weight: 1

  
  containers:
    - name: thanos-sidecar
      image: docker.io/bitnami/thanos:0.23.1-scratch-r4
      imagePullPolicy: IfNotPresent
      args:
        - sidecar
        - --prometheus.url=http://localhost:9090
        - --grpc-address=0.0.0.0:10901
        - --http-address=0.0.0.0:10902
        - --tsdb.path=/prometheus/
        - --objstore.config=$(OBJSTORE_CONFIG)
      env:
        - name: OBJSTORE_CONFIG
          valueFrom:
            secretKeyRef:
              name: thanos-objectstorage-config
              key: thanos.yaml
      resources:
        limits: {}
        requests: {}
      ports:
        - name: grpc
          containerPort: 10901
          protocol: TCP
        - name: http
          containerPort: 10902
          protocol: TCP
      volumeMounts:
        - mountPath: /prometheus
          name: prometheus-logiq-prometheus-prometheus-db
          subPath: prometheus-db
      # yamllint disable rule:indentation
      securityContext:
        allowPrivilegeEscalation: false
        capabilities:
          drop:
          - ALL
        readOnlyRootFilesystem: false
        runAsNonRoot: true
      # yamllint enable rule:indentation
      livenessProbe:
        httpGet:
          path: /-/healthy
          port: http
          scheme: HTTP
        initialDelaySeconds: 0
        periodSeconds: 25
        timeoutSeconds: 25
        failureThreshold: 120
        successThreshold: 1
      readinessProbe:
        httpGet:
          path: /-/ready
          port: http
          scheme: HTTP
        initialDelaySeconds: 0
        periodSeconds: 25
        timeoutSeconds: 25
        failureThreshold: 120
        successThreshold: 1
    ## This monkey patching is needed until the securityContexts are
    ## directly patchable via the CRD.
    ## ref: https://github.com/prometheus-operator/prometheus-operator/issues/3947
    ## currently implemented with strategic merge
    ## ref: https://github.com/prometheus-operator/prometheus-operator/blob/master/Documentation/user-guides/strategic-merge-patch.md
    - name: prometheus
      args:
      - --web.console.templates=/etc/prometheus/consoles
      - --web.console.libraries=/etc/prometheus/console_libraries
      - --config.file=/etc/prometheus/config_out/prometheus.env.yaml
      - --storage.tsdb.path=/prometheus
      - --storage.tsdb.retention.time=30d
      - --web.enable-lifecycle
      - --web.external-url=http://prometheus-prometheus.logiq:9090/
      - --web.route-prefix=/
      - --web.config.file=/etc/prometheus/web_config/web-config.yaml
      - --storage.tsdb.min-block-duration=2h
      - --storage.tsdb.max-block-duration=2h
      securityContext:
        allowPrivilegeEscalation: false
        capabilities:
          drop:
          - ALL
        readOnlyRootFilesystem: false
        runAsNonRoot: true
      livenessProbe:
        httpGet:
          path: /-/healthy
          port: web
          scheme: HTTP
        initialDelaySeconds: 0
        periodSeconds: 10
        timeoutSeconds: 3
        failureThreshold: 10
        successThreshold: 1
      readinessProbe:
        httpGet:
          path: /-/ready
          port: web
          scheme: HTTP
        initialDelaySeconds: 0
        periodSeconds: 10
        timeoutSeconds: 3
        failureThreshold: 10
        successThreshold: 1
    ## This monkey patching is needed until the securityContexts are
    ## directly patchable via the CRD.
    ## ref: https://github.com/prometheus-operator/prometheus-operator/issues/3947
    ## currently implemented with strategic merge
    ## ref: https://github.com/prometheus-operator/prometheus-operator/blob/master/Documentation/user-guides/strategic-merge-patch.md
    - name: config-reloader
      securityContext:
        allowPrivilegeEscalation: false
        capabilities:
          drop:
          - ALL
        readOnlyRootFilesystem: false
        runAsNonRoot: true
      livenessProbe:
        tcpSocket:
          port: reloader-web
        initialDelaySeconds: 10
        periodSeconds: 10
        timeoutSeconds: 5
        failureThreshold: 6
        successThreshold: 1
      readinessProbe:
        tcpSocket:
          port: reloader-web
        initialDelaySeconds: 15
        periodSeconds: 20
        timeoutSeconds: 5
        failureThreshold: 6
        successThreshold: 1
---
# Source: logiq/charts/prometheus/templates/alertmanager/logiq-alert-rules.yaml
# Generated from 'kubernetes-storage' group from https://raw.githubusercontent.com/coreos/kube-prometheus/master/manifests/prometheus-rules.yaml
# Do not change in-place! In order to change this file first read following link:
# https://github.com/helm/charts/tree/master/stable/prometheus-operator/hack
apiVersion: monitoring.coreos.com/v1
kind: PrometheusRule
metadata:
  name: logiq-prometheus-alertmanager
  labels:
    prometheus: k8s
    role: alert-rules
spec:
  groups:
  - name: logiq-exporter.rules
    rules:
    - expr: |
        (round(sum(rate(logiq_message_count[5m])),1))
      record: logiq:messages_per_second:rate
    - expr: |
        (round(sum(increase(logiq_data_received_bytes[30d]))/1000000000000,0.01))
      record: logiq:data_ingested_monthly:sum
    - expr: |
        (round(sum(increase(logiq_message_count[24h]))/1000000,1))
      record: logiq:messages_ingested_daily:sum
    - expr: |
        (round(avg(increase(logiq_data_received_bytes[5m])*12/1000000000)/1,0.01)*100)
      record: logiq:ingest_capacity_utilization:percent
    - expr: |
        (sum by (exported_namespace,app) (increase(logiq_namespace_app_received_bytes[1h])))
      record: logiq:namespace_app_bytes_hourly:increase
    - expr: |
        (sum by (exported_namespace,app) (increase(logiq_namespace_app_message_count[1h])))
      record: logiq:namespace_app_count_hourly:increase
    - expr: |
        (sum by (exported_namespace,app) (increase(logiq_namespace_app_received_bytes[24h])))
      record: logiq:namespace_app_bytes_daily:increase
    - expr: |
        (sum by (exported_namespace,app) (increase(logiq_namespace_app_message_count[24h])))
      record: logiq:namespace_app_count_daily:increase
    - expr: |
        (sum by (exported_namespace,app) (increase(logiq_namespace_app_received_bytes[7d])))
      record: logiq:namespace_app_bytes_weekly:increase
    - expr: |
        (sum by (exported_namespace,app) (increase(logiq_namespace_app_message_count[7d])))
      record: logiq:namespace_app_count_weekly:increase
    - expr: |
        (sum by (exported_namespace,app) (increase(logiq_namespace_app_received_bytes[30d])))
      record: logiq:namespace_app_bytes_monthly:increase
    - expr: |
        (sum by (exported_namespace,app) (increase(logiq_namespace_app_message_count[30d])))
      record: logiq:namespace_app_count_monthly:increase
  
  - name: node-exporter.rules
    rules:
    - expr: |
        count without (cpu) (
          count without (mode) (
            node_cpu_seconds_total{job="node-exporter"}
          )
        )
      record: instance:node_num_cpu:sum
    - expr: |
        1 - avg without (cpu, mode) (
          rate(node_cpu_seconds_total{job="node-exporter", mode="idle"}[1m])
        )
      record: instance:node_cpu_utilisation:rate1m
    - expr: |
        (
          node_load1{job="node-exporter"}
        /
          instance:node_num_cpu:sum{job="node-exporter"}
        )
      record: instance:node_load1_per_cpu:ratio
    - expr: |
        1 - (
          node_memory_MemAvailable_bytes{job="node-exporter"}
        /
          node_memory_MemTotal_bytes{job="node-exporter"}
        )
      record: instance:node_memory_utilisation:ratio
    - expr: |
        rate(node_vmstat_pgmajfault{job="node-exporter"}[1m])
      record: instance:node_vmstat_pgmajfault:rate1m
    - expr: |
        rate(node_disk_io_time_seconds_total{job="node-exporter", device=~"nvme.+|rbd.+|sd.+|vd.+|xvd.+|dm-.+|dasd.+"}[1m])
      record: instance_device:node_disk_io_time_seconds:rate1m
    - expr: |
        rate(node_disk_io_time_weighted_seconds_total{job="node-exporter", device=~"nvme.+|rbd.+|sd.+|vd.+|xvd.+|dm-.+|dasd.+"}[1m])
      record: instance_device:node_disk_io_time_weighted_seconds:rate1m
    - expr: |
        sum without (device) (
          rate(node_network_receive_bytes_total{job="node-exporter", device!="lo"}[1m])
        )
      record: instance:node_network_receive_bytes_excluding_lo:rate1m
    - expr: |
        sum without (device) (
          rate(node_network_transmit_bytes_total{job="node-exporter", device!="lo"}[1m])
        )
      record: instance:node_network_transmit_bytes_excluding_lo:rate1m
    - expr: |
        sum without (device) (
          rate(node_network_receive_drop_total{job="node-exporter", device!="lo"}[1m])
        )
      record: instance:node_network_receive_drop_excluding_lo:rate1m
    - expr: |
        sum without (device) (
          rate(node_network_transmit_drop_total{job="node-exporter", device!="lo"}[1m])
        )
      record: instance:node_network_transmit_drop_excluding_lo:rate1m
  - name: kube-scheduler.rules
    rules:
    - expr: |
        histogram_quantile(0.99, sum(rate(scheduler_e2e_scheduling_duration_seconds_bucket{job="kube-scheduler"}[5m])) without(instance, pod))
      labels:
        quantile: "0.99"
      record: cluster_quantile:scheduler_e2e_scheduling_duration_seconds:histogram_quantile
    - expr: |
        histogram_quantile(0.99, sum(rate(scheduler_scheduling_algorithm_duration_seconds_bucket{job="kube-scheduler"}[5m])) without(instance, pod))
      labels:
        quantile: "0.99"
      record: cluster_quantile:scheduler_scheduling_algorithm_duration_seconds:histogram_quantile
    - expr: |
        histogram_quantile(0.99, sum(rate(scheduler_binding_duration_seconds_bucket{job="kube-scheduler"}[5m])) without(instance, pod))
      labels:
        quantile: "0.99"
      record: cluster_quantile:scheduler_binding_duration_seconds:histogram_quantile
    - expr: |
        histogram_quantile(0.9, sum(rate(scheduler_e2e_scheduling_duration_seconds_bucket{job="kube-scheduler"}[5m])) without(instance, pod))
      labels:
        quantile: "0.9"
      record: cluster_quantile:scheduler_e2e_scheduling_duration_seconds:histogram_quantile
    - expr: |
        histogram_quantile(0.9, sum(rate(scheduler_scheduling_algorithm_duration_seconds_bucket{job="kube-scheduler"}[5m])) without(instance, pod))
      labels:
        quantile: "0.9"
      record: cluster_quantile:scheduler_scheduling_algorithm_duration_seconds:histogram_quantile
    - expr: |
        histogram_quantile(0.9, sum(rate(scheduler_binding_duration_seconds_bucket{job="kube-scheduler"}[5m])) without(instance, pod))
      labels:
        quantile: "0.9"
      record: cluster_quantile:scheduler_binding_duration_seconds:histogram_quantile
    - expr: |
        histogram_quantile(0.5, sum(rate(scheduler_e2e_scheduling_duration_seconds_bucket{job="kube-scheduler"}[5m])) without(instance, pod))
      labels:
        quantile: "0.5"
      record: cluster_quantile:scheduler_e2e_scheduling_duration_seconds:histogram_quantile
    - expr: |
        histogram_quantile(0.5, sum(rate(scheduler_scheduling_algorithm_duration_seconds_bucket{job="kube-scheduler"}[5m])) without(instance, pod))
      labels:
        quantile: "0.5"
      record: cluster_quantile:scheduler_scheduling_algorithm_duration_seconds:histogram_quantile
    - expr: |
        histogram_quantile(0.5, sum(rate(scheduler_binding_duration_seconds_bucket{job="kube-scheduler"}[5m])) without(instance, pod))
      labels:
        quantile: "0.5"
      record: cluster_quantile:scheduler_binding_duration_seconds:histogram_quantile
  - name: node.rules
    rules:
    - expr: |
        sum(min(kube_pod_info{node!=""}) by (cluster, node))
      record: ':kube_pod_info_node_count:'
    - expr: |
        topk by(namespace, pod) (1,
          max by (node, namespace, pod) (
            label_replace(kube_pod_info{job="kube-state-metrics",node!=""}, "pod", "$1", "pod", "(.*)")
        ))
      record: 'node_namespace_pod:kube_pod_info:'
    - expr: |
        count by (cluster, node) (sum by (node, cpu) (
          node_cpu_seconds_total{job="node-exporter"}
        * on (namespace, pod) group_left(node)
          node_namespace_pod:kube_pod_info:
        ))
      record: node:node_num_cpu:sum
    - expr: |
        sum(
          node_memory_MemAvailable_bytes{job="node-exporter"} or
          (
            node_memory_Buffers_bytes{job="node-exporter"} +
            node_memory_Cached_bytes{job="node-exporter"} +
            node_memory_MemFree_bytes{job="node-exporter"} +
            node_memory_Slab_bytes{job="node-exporter"}
          )
        ) by (cluster)
      record: :node_memory_MemAvailable_bytes:sum
  - name: kube-prometheus-node-recording.rules
    rules:
    - expr: sum(rate(node_cpu_seconds_total{mode!="idle",mode!="iowait"}[3m])) BY
        (instance)
      record: instance:node_cpu:rate:sum
    - expr: sum(rate(node_network_receive_bytes_total[3m])) BY (instance)
      record: instance:node_network_receive_bytes:rate:sum
    - expr: sum(rate(node_network_transmit_bytes_total[3m])) BY (instance)
      record: instance:node_network_transmit_bytes:rate:sum
    - expr: sum(rate(node_cpu_seconds_total{mode!="idle",mode!="iowait"}[5m])) WITHOUT
        (cpu, mode) / ON(instance) GROUP_LEFT() count(sum(node_cpu_seconds_total)
        BY (instance, cpu)) BY (instance)
      record: instance:node_cpu:ratio
    - expr: sum(rate(node_cpu_seconds_total{mode!="idle",mode!="iowait"}[5m]))
      record: cluster:node_cpu:sum_rate5m
    - expr: cluster:node_cpu_seconds_total:rate5m / count(sum(node_cpu_seconds_total)
        BY (instance, cpu))
      record: cluster:node_cpu:ratio
  - name: kube-prometheus-general.rules
    rules:
    - expr: count without(instance, pod, node) (up == 1)
      record: count:up1
    - expr: count without(instance, pod, node) (up == 0)
      record: count:up0
  - name: kube-state-metrics
    rules:
    - alert: KubeStateMetricsListErrors
      annotations:
        message: kube-state-metrics is experiencing errors at an elevated rate in
          list operations. This is likely causing it to not be able to expose metrics
          about Kubernetes objects correctly or at all.
        runbook_url: https://github.com/kubernetes-monitoring/kubernetes-mixin/tree/master/runbook.md#alert-name-kubestatemetricslisterrors
      expr: |
        (sum(rate(kube_state_metrics_list_total{job="kube-state-metrics",result="error"}[5m]))
          /
        sum(rate(kube_state_metrics_list_total{job="kube-state-metrics"}[5m])))
        > 0.01
      for: 15m
      labels:
        severity: critical
    - alert: KubeStateMetricsWatchErrors
      annotations:
        message: kube-state-metrics is experiencing errors at an elevated rate in
          watch operations. This is likely causing it to not be able to expose metrics
          about Kubernetes objects correctly or at all.
        runbook_url: https://github.com/kubernetes-monitoring/kubernetes-mixin/tree/master/runbook.md#alert-name-kubestatemetricswatcherrors
      expr: |
        (sum(rate(kube_state_metrics_watch_total{job="kube-state-metrics",result="error"}[5m]))
          /
        sum(rate(kube_state_metrics_watch_total{job="kube-state-metrics"}[5m])))
        > 0.01
      for: 15m
      labels:
        severity: critical
  - name: node-exporter
    rules:
    - alert: NodeFilesystemSpaceFillingUp
      annotations:
        description: Filesystem on {{ $labels.device }} at {{ $labels.instance }}
          has only {{ printf "%.2f" $value }}% available space left and is filling
          up.
        runbook_url: https://github.com/kubernetes-monitoring/kubernetes-mixin/tree/master/runbook.md#alert-name-nodefilesystemspacefillingup
        summary: Filesystem is predicted to run out of space within the next 24 hours.
      expr: |
        (
          node_filesystem_avail_bytes{job="node-exporter",fstype!=""} / node_filesystem_size_bytes{job="node-exporter",fstype!=""} * 100 < 40
        and
          predict_linear(node_filesystem_avail_bytes{job="node-exporter",fstype!=""}[6h], 24*60*60) < 0
        and
          node_filesystem_readonly{job="node-exporter",fstype!=""} == 0
        )
      for: 1h
      labels:
        severity: warning
    - alert: NodeFilesystemSpaceFillingUp
      annotations:
        description: Filesystem on {{ $labels.device }} at {{ $labels.instance }}
          has only {{ printf "%.2f" $value }}% available space left and is filling
          up fast.
        runbook_url: https://github.com/kubernetes-monitoring/kubernetes-mixin/tree/master/runbook.md#alert-name-nodefilesystemspacefillingup
        summary: Filesystem is predicted to run out of space within the next 4 hours.
      expr: |
        (
          node_filesystem_avail_bytes{job="node-exporter",fstype!=""} / node_filesystem_size_bytes{job="node-exporter",fstype!=""} * 100 < 15
        and
          predict_linear(node_filesystem_avail_bytes{job="node-exporter",fstype!=""}[6h], 4*60*60) < 0
        and
          node_filesystem_readonly{job="node-exporter",fstype!=""} == 0
        )
      for: 1h
      labels:
        severity: critical
    - alert: NodeFilesystemAlmostOutOfSpace
      annotations:
        description: Filesystem on {{ $labels.device }} at {{ $labels.instance }}
          has only {{ printf "%.2f" $value }}% available space left.
        runbook_url: https://github.com/kubernetes-monitoring/kubernetes-mixin/tree/master/runbook.md#alert-name-nodefilesystemalmostoutofspace
        summary: Filesystem has less than 5% space left.
      expr: |
        (
          node_filesystem_avail_bytes{job="node-exporter",fstype!=""} / node_filesystem_size_bytes{job="node-exporter",fstype!=""} * 100 < 5
        and
          node_filesystem_readonly{job="node-exporter",fstype!=""} == 0
        )
      for: 1h
      labels:
        severity: warning
    - alert: NodeFilesystemAlmostOutOfSpace
      annotations:
        description: Filesystem on {{ $labels.device }} at {{ $labels.instance }}
          has only {{ printf "%.2f" $value }}% available space left.
        runbook_url: https://github.com/kubernetes-monitoring/kubernetes-mixin/tree/master/runbook.md#alert-name-nodefilesystemalmostoutofspace
        summary: Filesystem has less than 3% space left.
      expr: |
        (
          node_filesystem_avail_bytes{job="node-exporter",fstype!=""} / node_filesystem_size_bytes{job="node-exporter",fstype!=""} * 100 < 3
        and
          node_filesystem_readonly{job="node-exporter",fstype!=""} == 0
        )
      for: 1h
      labels:
        severity: critical
    - alert: NodeFilesystemFilesFillingUp
      annotations:
        description: Filesystem on {{ $labels.device }} at {{ $labels.instance }}
          has only {{ printf "%.2f" $value }}% available inodes left and is filling
          up.
        runbook_url: https://github.com/kubernetes-monitoring/kubernetes-mixin/tree/master/runbook.md#alert-name-nodefilesystemfilesfillingup
        summary: Filesystem is predicted to run out of inodes within the next 24 hours.
      expr: |
        (
          node_filesystem_files_free{job="node-exporter",fstype!=""} / node_filesystem_files{job="node-exporter",fstype!=""} * 100 < 40
        and
          predict_linear(node_filesystem_files_free{job="node-exporter",fstype!=""}[6h], 24*60*60) < 0
        and
          node_filesystem_readonly{job="node-exporter",fstype!=""} == 0
        )
      for: 1h
      labels:
        severity: warning
    - alert: NodeFilesystemFilesFillingUp
      annotations:
        description: Filesystem on {{ $labels.device }} at {{ $labels.instance }}
          has only {{ printf "%.2f" $value }}% available inodes left and is filling
          up fast.
        runbook_url: https://github.com/kubernetes-monitoring/kubernetes-mixin/tree/master/runbook.md#alert-name-nodefilesystemfilesfillingup
        summary: Filesystem is predicted to run out of inodes within the next 4 hours.
      expr: |
        (
          node_filesystem_files_free{job="node-exporter",fstype!=""} / node_filesystem_files{job="node-exporter",fstype!=""} * 100 < 20
        and
          predict_linear(node_filesystem_files_free{job="node-exporter",fstype!=""}[6h], 4*60*60) < 0
        and
          node_filesystem_readonly{job="node-exporter",fstype!=""} == 0
        )
      for: 1h
      labels:
        severity: critical
    - alert: NodeFilesystemAlmostOutOfFiles
      annotations:
        description: Filesystem on {{ $labels.device }} at {{ $labels.instance }}
          has only {{ printf "%.2f" $value }}% available inodes left.
        runbook_url: https://github.com/kubernetes-monitoring/kubernetes-mixin/tree/master/runbook.md#alert-name-nodefilesystemalmostoutoffiles
        summary: Filesystem has less than 5% inodes left.
      expr: |
        (
          node_filesystem_files_free{job="node-exporter",fstype!=""} / node_filesystem_files{job="node-exporter",fstype!=""} * 100 < 5
        and
          node_filesystem_readonly{job="node-exporter",fstype!=""} == 0
        )
      for: 1h
      labels:
        severity: warning
    - alert: NodeFilesystemAlmostOutOfFiles
      annotations:
        description: Filesystem on {{ $labels.device }} at {{ $labels.instance }}
          has only {{ printf "%.2f" $value }}% available inodes left.
        runbook_url: https://github.com/kubernetes-monitoring/kubernetes-mixin/tree/master/runbook.md#alert-name-nodefilesystemalmostoutoffiles
        summary: Filesystem has less than 3% inodes left.
      expr: |
        (
          node_filesystem_files_free{job="node-exporter",fstype!=""} / node_filesystem_files{job="node-exporter",fstype!=""} * 100 < 3
        and
          node_filesystem_readonly{job="node-exporter",fstype!=""} == 0
        )
      for: 1h
      labels:
        severity: critical
    - alert: NodeNetworkReceiveErrs
      annotations:
        description: '{{$labels.instance }} interface {{ $labels.device }} has encountered
          {{ printf "%.0f" $value }} receive errors in the last two minutes.'
        runbook_url: https://github.com/kubernetes-monitoring/kubernetes-mixin/tree/master/runbook.md#alert-name-nodenetworkreceiveerrs
        summary: Network interface is reporting many receive errors.
      expr: |
        increase(node_network_receive_errs_total[2m]) > 10
      for: 1h
      labels:
        severity: warning
    - alert: NodeNetworkTransmitErrs
      annotations:
        description: '{{$labels.instance }} interface {{ $labels.device }} has encountered
          {{ printf "%.0f" $value }} transmit errors in the last two minutes.'
        runbook_url: https://github.com/kubernetes-monitoring/kubernetes-mixin/tree/master/runbook.md#alert-name-nodenetworktransmiterrs
        summary: Network interface is reporting many transmit errors.
      expr: |
        increase(node_network_transmit_errs_total[2m]) > 10
      for: 1h
      labels:
        severity: warning
    - alert: NodeHighNumberConntrackEntriesUsed
      annotations:
        description: '{{ $value | humanizePercentage }} of conntrack entries are used.'
        runbook_url: https://github.com/kubernetes-monitoring/kubernetes-mixin/tree/master/runbook.md#alert-name-nodehighnumberconntrackentriesused
        summary: Number of conntrack are getting close to the limit.
      expr: |
        (node_nf_conntrack_entries / node_nf_conntrack_entries_limit) > 0.75
      labels:
        severity: warning
    - alert: NodeTextFileCollectorScrapeError
      annotations:
        description: Node Exporter text file collector failed to scrape.
        runbook_url: https://github.com/kubernetes-monitoring/kubernetes-mixin/tree/master/runbook.md#alert-name-nodetextfilecollectorscrapeerror
        summary: Node Exporter text file collector failed to scrape.
      expr: |
        node_textfile_scrape_error{job="node-exporter"} == 1
      labels:
        severity: warning
    - alert: NodeClockSkewDetected
      annotations:
        message: Clock on {{ $labels.instance }} is out of sync by more than 300s.
          Ensure NTP is configured correctly on this host.
        runbook_url: https://github.com/kubernetes-monitoring/kubernetes-mixin/tree/master/runbook.md#alert-name-nodeclockskewdetected
        summary: Clock skew detected.
      expr: |
        (
          node_timex_offset_seconds > 0.05
        and
          deriv(node_timex_offset_seconds[5m]) >= 0
        )
        or
        (
          node_timex_offset_seconds < -0.05
        and
          deriv(node_timex_offset_seconds[5m]) <= 0
        )
      for: 10m
      labels:
        severity: warning
    - alert: NodeClockNotSynchronising
      annotations:
        message: Clock on {{ $labels.instance }} is not synchronising. Ensure NTP
          is configured on this host.
        runbook_url: https://github.com/kubernetes-monitoring/kubernetes-mixin/tree/master/runbook.md#alert-name-nodeclocknotsynchronising
        summary: Clock not synchronising.
      expr: |
        min_over_time(node_timex_sync_status[5m]) == 0
      for: 10m
      labels:
        severity: warning
  - name: kubernetes-apps
    rules:
    - alert: KubePodCrashLooping
      annotations:
        message: Pod {{ $labels.namespace }}/{{ $labels.pod }} {{ $labels.container }} is restarting {{ printf "%.2f" $value }} times / 5 minutes.
        runbook_url: https://github.com/kubernetes-monitoring/kubernetes-mixin/tree/master/runbook.md#alert-name-kubepodcrashlooping
      expr: |
        rate(kube_pod_container_status_restarts_total{job="kube-state-metrics"}[5m]) * 60 * 5 > 0
      for: 15m
      labels:
        severity: warning
    - alert: KubePodNotReady
      annotations:
        message: Pod {{ $labels.namespace }}/{{ $labels.pod }} has been in a non-ready
          state for longer than 15 minutes.
        runbook_url: https://github.com/kubernetes-monitoring/kubernetes-mixin/tree/master/runbook.md#alert-name-kubepodnotready
      expr: |
        sum by (namespace, pod) (
          max by(namespace, pod) (
            kube_pod_status_phase{job="kube-state-metrics", phase=~"Pending|Unknown"}
          ) * on(namespace, pod) group_left(owner_kind) topk by(namespace, pod) (
            1, max by(namespace, pod, owner_kind) (kube_pod_owner{owner_kind!="Job"})
          )
        ) > 0
      for: 15m
      labels:
        severity: warning
    - alert: KubeDeploymentGenerationMismatch
      annotations:
        message: Deployment generation for {{ $labels.namespace }}/{{$labels.deployment}} does not match,
         this indicates that the Deployment has failed but has not been rolled back.
        runbook_url: https://github.com/kubernetes-monitoring/kubernetes-mixin/tree/master/runbook.md#alert-name-kubedeploymentgenerationmismatch
      expr: |
        kube_deployment_status_observed_generation{job="kube-state-metrics"}
          !=
        kube_deployment_metadata_generation{job="kube-state-metrics"}
      for: 15m
      labels:
        severity: warning
    - alert: KubeDeploymentReplicasMismatch
      annotations:
        message: Deployment {{$labels.namespace}}/{{ $labels.deployment }} has not matched the expected number of replicas for longer than 15 minutes.
        runbook_url: https://github.com/kubernetes-monitoring/kubernetes-mixin/tree/master/runbook.md#alert-name-kubedeploymentreplicasmismatch
      expr: |
        (
          kube_deployment_spec_replicas{job="kube-state-metrics"}
            !=
          kube_deployment_status_replicas_available{job="kube-state-metrics"}
        ) and (
          changes(kube_deployment_status_replicas_updated{job="kube-state-metrics"}[5m])
            ==
          0
        )
      for: 15m
      labels:
        severity: warning
    - alert: KubeStatefulSetReplicasMismatch
      annotations:
        message: StatefulSet {{ $labels.namespace }}/{{ $labels.statefulset }} has
          not matched the expected number of replicas for longer than 15 minutes.
        runbook_url: https://github.com/kubernetes-monitoring/kubernetes-mixin/tree/master/runbook.md#alert-name-kubestatefulsetreplicasmismatch
      expr: |
        (
          kube_statefulset_status_replicas_ready{job="kube-state-metrics"}
            !=
          kube_statefulset_status_replicas{job="kube-state-metrics"}
        ) and (
          changes(kube_statefulset_status_replicas_updated{job="kube-state-metrics"}[5m])
            ==
          0
        )
      for: 15m
      labels:
        severity: warning
    - alert: KubeStatefulSetGenerationMismatch
      annotations:
        message: StatefulSet generation for {{ $labels.namespace }}/{{ $labels.statefulset }} does not match, this indicates that the StatefulSet has failed but has
          not been rolled back.
        runbook_url: https://github.com/kubernetes-monitoring/kubernetes-mixin/tree/master/runbook.md#alert-name-kubestatefulsetgenerationmismatch
      expr: |
        kube_statefulset_status_observed_generation{job="kube-state-metrics"}
          !=
        kube_statefulset_metadata_generation{job="kube-state-metrics"}
      for: 15m
      labels:
        severity: warning
    - alert: KubeStatefulSetUpdateNotRolledOut
      annotations:
        message: StatefulSet {{ $labels.namespace }}/{{ $labels.statefulset }} update
          has not been rolled out.
        runbook_url: https://github.com/kubernetes-monitoring/kubernetes-mixin/tree/master/runbook.md#alert-name-kubestatefulsetupdatenotrolledout
      expr: |
        (
          max without (revision) (
            kube_statefulset_status_current_revision{job="kube-state-metrics"}
              unless
            kube_statefulset_status_update_revision{job="kube-state-metrics"}
          )
            *
          (
            kube_statefulset_replicas{job="kube-state-metrics"}
              !=
            kube_statefulset_status_replicas_updated{job="kube-state-metrics"}
          )
        )  and (
          changes(kube_statefulset_status_replicas_updated{job="kube-state-metrics"}[5m])
            ==
          0
        )
      for: 15m
      labels:
        severity: warning
    - alert: KubeDaemonSetRolloutStuck
      annotations:
        message: Only {{ $value }} of the desired Pods of DaemonSet
          {{ $labels.namespace }}/{{ $labels.daemonset }} are scheduled and ready.
        runbook_url: https://github.com/kubernetes-monitoring/kubernetes-mixin/tree/master/runbook.md#alert-name-kubedaemonsetrolloutstuck
      expr: |
        kube_daemonset_status_number_ready{job="kube-state-metrics"}
          /
        kube_daemonset_status_desired_number_scheduled{job="kube-state-metrics"} < 1.00
      for: 15m
      labels:
        severity: warning
    - alert: KubeContainerWaiting
      annotations:
        message: Pod {{ $labels.namespace }}/{{ $labels.pod }} container {{ $labels.container }}
          has been in waiting state for longer than 1 hour.
        runbook_url: https://github.com/kubernetes-monitoring/kubernetes-mixin/tree/master/runbook.md#alert-name-kubecontainerwaiting
      expr: |
        sum by (namespace, pod, container) (kube_pod_container_status_waiting_reason{job="kube-state-metrics"}) > 0
      for: 1h
      labels:
        severity: warning
    - alert: KubeDaemonSetNotScheduled
      annotations:
        message: '{{ $value }} Pods of DaemonSet {{ $labels.namespace }}/{{ $labels.daemonset }} are not scheduled.'
        runbook_url: https://github.com/kubernetes-monitoring/kubernetes-mixin/tree/master/runbook.md#alert-name-kubedaemonsetnotscheduled
      expr: |
        kube_daemonset_status_desired_number_scheduled{job="kube-state-metrics"}
          -
        kube_daemonset_status_current_number_scheduled{job="kube-state-metrics"} > 0
      for: 10m
      labels:
        severity: warning
    - alert: KubeDaemonSetMisScheduled
      annotations:
        message: '{{ $value }} Pods of DaemonSet {{ $labels.namespace }}/{{ $labels.daemonset }} are running where they are not supposed to run.'
        runbook_url: https://github.com/kubernetes-monitoring/kubernetes-mixin/tree/master/runbook.md#alert-name-kubedaemonsetmisscheduled
      expr: |
        kube_daemonset_status_number_misscheduled{job="kube-state-metrics"} > 0
      for: 15m
      labels:
        severity: warning
    - alert: KubeJobCompletion
      annotations:
        message: Job {{ $labels.namespace }}/{{ $labels.job_name }} is taking more
          than 12 hours to complete.
        runbook_url: https://github.com/kubernetes-monitoring/kubernetes-mixin/tree/master/runbook.md#alert-name-kubejobcompletion
      expr: |
        kube_job_spec_completions{job="kube-state-metrics"} - kube_job_status_succeeded{job="kube-state-metrics"}  > 0
      for: 12h
      labels:
        severity: warning
    - alert: KubeJobFailed
      annotations:
        message: Job {{ $labels.namespace }}/{{ $labels.job_name }} failed to complete.
        runbook_url: https://github.com/kubernetes-monitoring/kubernetes-mixin/tree/master/runbook.md#alert-name-kubejobfailed
      expr: |
        kube_job_failed{job="kube-state-metrics"}  > 0
      for: 15m
      labels:
        severity: warning
    - alert: KubeHpaReplicasMismatch
      annotations:
        message: HPA {{ $labels.namespace }}/{{ $labels.hpa }} has not matched the
          desired number of replicas for longer than 15 minutes.
        runbook_url: https://github.com/kubernetes-monitoring/kubernetes-mixin/tree/master/runbook.md#alert-name-kubehpareplicasmismatch
      expr: |
        (kube_hpa_status_desired_replicas{job="kube-state-metrics"}
          !=
        kube_hpa_status_current_replicas{job="kube-state-metrics"})
          and
        changes(kube_hpa_status_current_replicas[15m]) == 0
      for: 15m
      labels:
        severity: warning
    - alert: KubeHpaMaxedOut
      annotations:
        message: HPA {{ $labels.namespace }}/{{ $labels.hpa }} has been running at
          max replicas for longer than 15 minutes.
        runbook_url: https://github.com/kubernetes-monitoring/kubernetes-mixin/tree/master/runbook.md#alert-name-kubehpamaxedout
      expr: |
        kube_hpa_status_current_replicas{job="kube-state-metrics"}
          ==
        kube_hpa_spec_max_replicas{job="kube-state-metrics"}
      for: 15m
      labels:
        severity: warning
  - name: kubernetes-resources
    rules:
    - alert: KubeCPUOvercommit
      annotations:
        message: Cluster has overcommitted CPU resource requests for Pods and cannot
          tolerate node failure.
        runbook_url: https://github.com/kubernetes-monitoring/kubernetes-mixin/tree/master/runbook.md#alert-name-kubecpuovercommit
      expr: |
        sum(namespace:kube_pod_container_resource_requests_cpu_cores:sum{})
          /
        sum(kube_node_status_allocatable_cpu_cores)
          >
        (count(kube_node_status_allocatable_cpu_cores)-1) / count(kube_node_status_allocatable_cpu_cores)
      for: 5m
      labels:
        severity: warning
    - alert: KubeMemoryOvercommit
      annotations:
        message: Cluster has overcommitted memory resource requests for Pods and cannot
          tolerate node failure.
        runbook_url: https://github.com/kubernetes-monitoring/kubernetes-mixin/tree/master/runbook.md#alert-name-kubememoryovercommit
      expr: |
        sum(namespace:kube_pod_container_resource_requests_memory_bytes:sum{})
          /
        sum(kube_node_status_allocatable_memory_bytes)
          >
        (count(kube_node_status_allocatable_memory_bytes)-1)
          /
        count(kube_node_status_allocatable_memory_bytes)
      for: 5m
      labels:
        severity: warning
    - alert: KubeCPUQuotaOvercommit
      annotations:
        message: Cluster has overcommitted CPU resource requests for Namespaces.
        runbook_url: https://github.com/kubernetes-monitoring/kubernetes-mixin/tree/master/runbook.md#alert-name-kubecpuquotaovercommit
      expr: |
        sum(kube_resourcequota{job="kube-state-metrics", type="hard", resource="cpu"})
          /
        sum(kube_node_status_allocatable_cpu_cores)
          > 1.5
      for: 5m
      labels:
        severity: warning
    - alert: KubeMemoryQuotaOvercommit
      annotations:
        message: Cluster has overcommitted memory resource requests for Namespaces.
        runbook_url: https://github.com/kubernetes-monitoring/kubernetes-mixin/tree/master/runbook.md#alert-name-kubememoryquotaovercommit
      expr: |
        sum(kube_resourcequota{job="kube-state-metrics", type="hard", resource="memory"})
          /
        sum(kube_node_status_allocatable_memory_bytes{job="node-exporter"})
          > 1.5
      for: 5m
      labels:
        severity: warning
    - alert: KubeQuotaFullyUsed
      annotations:
        message: Namespace {{ $labels.namespace }} is using {{ $value | humanizePercentage }} of its {{ $labels.resource }} quota.
        runbook_url: https://github.com/kubernetes-monitoring/kubernetes-mixin/tree/master/runbook.md#alert-name-kubequotafullyused
      expr: |
        kube_resourcequota{job="kube-state-metrics", type="used"}
          / ignoring(instance, job, type)
        (kube_resourcequota{job="kube-state-metrics", type="hard"} > 0)
          >= 1
      for: 15m
      labels:
        severity: info
    - alert: CPUThrottlingHigh
      annotations:
        message: '{{ $value | humanizePercentage }} throttling of CPU in namespace
          {{ $labels.namespace }} for container {{ $labels.container }} in pod {{ $labels.pod }}.'
        runbook_url: https://github.com/kubernetes-monitoring/kubernetes-mixin/tree/master/runbook.md#alert-name-cputhrottlinghigh
      expr: |
        sum(increase(container_cpu_cfs_throttled_periods_total{container!="", }[5m])) by (container, pod, namespace)
          /
        sum(increase(container_cpu_cfs_periods_total{}[5m])) by (container, pod, namespace)
          > ( 50 / 100 )
      for: 15m
      labels:
        severity: info
    - alert: KubePersistentVolumeErrors
      annotations:
        message: The persistent volume {{ $labels.persistentvolume }} has status {{ $labels.phase }}.
        runbook_url: https://github.com/kubernetes-monitoring/kubernetes-mixin/tree/master/runbook.md#alert-name-kubepersistentvolumeerrors
      expr: |
        kube_persistentvolume_status_phase{phase=~"Failed|Pending",job="kube-state-metrics"} > 0
      for: 5m
      labels:
        severity: critical
  - name: kubernetes-system
    rules:
    - alert: KubeVersionMismatch
      annotations:
        message: There are {{ $value }} different semantic versions of Kubernetes
          components running.
        runbook_url: https://github.com/kubernetes-monitoring/kubernetes-mixin/tree/master/runbook.md#alert-name-kubeversionmismatch
      expr: |
        count(count by (gitVersion) (label_replace(kubernetes_build_info{job!~"kube-dns|coredns"},"gitVersion","$1","gitVersion","(v[0-9]*.[0-9]*).*"))) > 1
      for: 15m
      labels:
        severity: warning
    - alert: KubeClientErrors
      annotations:
        message: Kubernetes API server client {{ $labels.job }}/{{ $labels.instance }} is experiencing {{ $value | humanizePercentage }} errors.'
        runbook_url: https://github.com/kubernetes-monitoring/kubernetes-mixin/tree/master/runbook.md#alert-name-kubeclienterrors
      expr: |
        (sum(rate(rest_client_requests_total{code=~"5.."}[5m])) by (instance, job)
          /
        sum(rate(rest_client_requests_total[5m])) by (instance, job))
        > 0.01
      for: 15m
      labels:
        severity: warning
    - alert: AggregatedAPIErrors
      annotations:
        message: An aggregated API {{ $labels.name }}/{{ $labels.namespace }} has
          reported errors. The number of errors have increased for it in the past
          five minutes. High values indicate that the availability of the service
          changes too often.
        runbook_url: https://github.com/kubernetes-monitoring/kubernetes-mixin/tree/master/runbook.md#alert-name-aggregatedapierrors
      expr: |
        sum by(name, namespace)(increase(aggregator_unavailable_apiservice_count[5m])) > 2
      labels:
        severity: warning
    - alert: AggregatedAPIDown
      annotations:
        message: An aggregated API {{ $labels.name }}/{{ $labels.namespace }} has
          been only {{ $value }}% available over the last 5m.
        runbook_url: https://github.com/kubernetes-monitoring/kubernetes-mixin/tree/master/runbook.md#alert-name-aggregatedapidown
      expr: |
        (1 - max by(name, namespace)(avg_over_time(aggregator_unavailable_apiservice[5m]))) * 100 < 90
      for: 5m
      labels:
        severity: warning
    - alert: KubeNodeUnreachable
      annotations:
        message: '{{ $labels.node }} is unreachable and some workloads may be rescheduled.'
        runbook_url: https://github.com/kubernetes-monitoring/kubernetes-mixin/tree/master/runbook.md#alert-name-kubenodeunreachable
      expr: |
        (kube_node_spec_taint{job="kube-state-metrics",key="node.kubernetes.io/unreachable",effect="NoSchedule"} unless ignoring(key,value) kube_node_spec_taint{job="kube-state-metrics",key=~"ToBeDeletedByClusterAutoscaler|cloud.google.com/impending-node-termination|aws-node-termination-handler/spot-itn"}) == 1
      labels:
        severity: warning
    - alert: KubeNodeReadinessFlapping
      annotations:
        message: The readiness status of node {{ $labels.node }} has changed {{ $value }} times in the last 15 minutes.
        runbook_url: https://github.com/kubernetes-monitoring/kubernetes-mixin/tree/master/runbook.md#alert-name-kubenodereadinessflapping
      expr: |
        sum(changes(kube_node_status_condition{status="true",condition="Ready"}[15m])) by (node) > 2
      for: 15m
      labels:
        severity: warning
  - name: prometheus
    rules:
    - alert: PrometheusBadConfig
      annotations:
        description: Prometheus {{ $labels.namespace }}/{{ $labels.pod }} has failed to
          reload its configuration.
        summary: Failed Prometheus configuration reload.
      expr: |
        # Without max_over_time, failed scrapes could create false negatives, see
        # https://www.robustperception.io/alerting-on-gauges-in-prometheus-2-0 for details.
        max_over_time(prometheus_config_last_reload_successful{job="prometheus-k8s",namespace="monitoring"}[5m]) == 0
      for: 10m
      labels:
        severity: critical
    - alert: PrometheusNotificationQueueRunningFull
      annotations:
        description: Alert notification queue of Prometheus {{ $labels.namespace }}/{{ $labels.pod }}
          is running full.
        summary: Prometheus alert notification queue predicted to run full in less
          than 30m.
      expr: |
        # Without min_over_time, failed scrapes could create false negatives, see
        # https://www.robustperception.io/alerting-on-gauges-in-prometheus-2-0 for details.
        (
          predict_linear(prometheus_notifications_queue_length{job="prometheus-k8s",namespace="monitoring"}[5m], 60 * 30)
        >
          min_over_time(prometheus_notifications_queue_capacity{job="prometheus-k8s",namespace="monitoring"}[5m])
        )
      for: 15m
      labels:
        severity: warning
    - alert: PrometheusErrorSendingAlertsToSomeAlertmanagers
      annotations:
        description: '{{ printf "%.1f"  $value }}% errors while sending alerts from
          Prometheus {{ $labels.namespace }}/{{ $labels.pod }} to Alertmanager {{$labels.alertmanager}}.'
        summary: Prometheus has encountered more than 1% errors sending alerts to
          a specific Alertmanager.
      expr: |
        (
          rate(prometheus_notifications_errors_total{job="prometheus-k8s",namespace="monitoring"}[5m])
        /
          rate(prometheus_notifications_sent_total{job="prometheus-k8s",namespace="monitoring"}[5m])
        )
        * 100
        > 1
      for: 15m
      labels:
        severity: warning
    - alert: PrometheusErrorSendingAlertsToAnyAlertmanager
      annotations:
        description: '{{ printf "%.1f" $value }}% minimum errors while sending alerts
          from Prometheus {{ $labels.namespace }}/{{ $labels.pod }} to any Alertmanager.'
        summary: Prometheus encounters more than 3% errors sending alerts to any Alertmanager.
      expr: |
        min without(alertmanager) (
          rate(prometheus_notifications_errors_total{job="prometheus-k8s",namespace="monitoring"}[5m])
        /
          rate(prometheus_notifications_sent_total{job="prometheus-k8s",namespace="monitoring"}[5m])
        )
        * 100
        > 3
      for: 15m
      labels:
        severity: critical
    - alert: PrometheusNotConnectedToAlertmanagers
      annotations:
        description: Prometheus {{ $labels.namespace }}/{{ $labels.pod }} is not connected
          to any Alertmanagers.
        summary: Prometheus is not connected to any Alertmanagers.
      expr: |
        # Without max_over_time, failed scrapes could create false negatives, see
        # https://www.robustperception.io/alerting-on-gauges-in-prometheus-2-0 for details.
        max_over_time(prometheus_notifications_alertmanagers_discovered{job="prometheus-k8s",namespace="monitoring"}[5m]) < 1
      for: 10m
      labels:
        severity: warning
    - alert: PrometheusTSDBReloadsFailing
      annotations:
        description: Prometheus {{ $labels.namespace }}/{{ $labels.pod }} has detected
          {{ $value }} reload failures over the last 3h.
        summary: Prometheus has issues reloading blocks from disk.
      expr: |
        increase(prometheus_tsdb_reloads_failures_total{job="prometheus-k8s",namespace="monitoring"}[3h]) > 0
      for: 4h
      labels:
        severity: warning
    - alert: PrometheusTSDBCompactionsFailing
      annotations:
        description: Prometheus {{ $labels.namespace }}/{{ $labels.pod }} has detected
          {{ $value }} compaction failures over the last 3h.
        summary: Prometheus has issues compacting blocks.
      expr: |
        increase(prometheus_tsdb_compactions_failed_total{job="prometheus-k8s",namespace="monitoring"}[3h]) > 0
      for: 4h
      labels:
        severity: warning
    - alert: PrometheusNotIngestingSamples
      annotations:
        description: Prometheus {{ $labels.namespace }}/{{ $labels.pod }} is not ingesting
          samples.
        summary: Prometheus is not ingesting samples.
      expr: |
        rate(prometheus_tsdb_head_samples_appended_total{job="prometheus-k8s",namespace="monitoring"}[5m]) <= 0
      for: 10m
      labels:
        severity: warning
    - alert: PrometheusDuplicateTimestamps
      annotations:
        description: Prometheus {{ $labels.namespace }}/{{ $labels.pod }} is dropping
          {{ printf "%.4g"  $value }} samples/s with different values but duplicated
          timestamp.
        summary: Prometheus is dropping samples with duplicate timestamps.
      expr: |
        rate(prometheus_target_scrapes_sample_duplicate_timestamp_total{job="prometheus-k8s",namespace="monitoring"}[5m]) > 0
      for: 10m
      labels:
        severity: warning
    - alert: PrometheusOutOfOrderTimestamps
      annotations:
        description: Prometheus {{ $labels.namespace }}/{{ $labels.pod }} is dropping
          {{ printf "%.4g"  $value }} samples/s with timestamps arriving out of order.
        summary: Prometheus drops samples with out-of-order timestamps.
      expr: |
        rate(prometheus_target_scrapes_sample_out_of_order_total{job="prometheus-k8s",namespace="monitoring"}[5m]) > 0
      for: 10m
      labels:
        severity: warning
    - alert: PrometheusRemoteStorageFailures
      annotations:
        description: Prometheus {{ $labels.namespace }}/{{ $labels.pod }} failed to send
          {{ printf "%.1f" $value }}% of the samples to {{$labels.remote_name}}:{{$labels.url}}
        summary: Prometheus fails to send samples to remote storage.
      expr: |
        (
          rate(prometheus_remote_storage_failed_samples_total{job="prometheus-k8s",namespace="monitoring"}[5m])
        /
          (
            rate(prometheus_remote_storage_failed_samples_total{job="prometheus-k8s",namespace="monitoring"}[5m])
          +
            rate(prometheus_remote_storage_succeeded_samples_total{job="prometheus-k8s",namespace="monitoring"}[5m])
          )
        )
        * 100
        > 1
      for: 15m
      labels:
        severity: critical
    - alert: PrometheusRemoteWriteBehind
      annotations:
        description: Prometheus {{ $labels.namespace }}/{{ $labels.pod }} remote write
          is {{ printf "%.1f" $value }}s behind for {{$labels.remote_name}}:{{$labels.url}}.
        summary: Prometheus remote write is behind.
      expr: |
        # Without max_over_time, failed scrapes could create false negatives, see
        # https://www.robustperception.io/alerting-on-gauges-in-prometheus-2-0 for details.
        (
          max_over_time(prometheus_remote_storage_highest_timestamp_in_seconds{job="prometheus-k8s",namespace="monitoring"}[5m])
        - on(job, instance) group_right
          max_over_time(prometheus_remote_storage_queue_highest_sent_timestamp_seconds{job="prometheus-k8s",namespace="monitoring"}[5m])
        )
        > 120
      for: 15m
      labels:
        severity: critical
    - alert: PrometheusRemoteWriteDesiredShards
      annotations:
        description: Prometheus {{ $labels.namespace }}/{{ $labels.pod }} remote write {{$labels.remote_name}}:{{$labels.url}}, which is more than the max of prometheus_remote_storage_shards_max{instance="{{ $labels.instance }}",job="prometheus-k8s",namespace="monitoring"}.
        summary: Prometheus remote write desired shards calculation wants to run more
          than configured max shards.
      expr: |
        # Without max_over_time, failed scrapes could create false negatives, see
        # https://www.robustperception.io/alerting-on-gauges-in-prometheus-2-0 for details.
        (
          max_over_time(prometheus_remote_storage_shards_desired{job="prometheus-k8s",namespace="monitoring"}[5m])
        >
          max_over_time(prometheus_remote_storage_shards_max{job="prometheus-k8s",namespace="monitoring"}[5m])
        )
      for: 15m
      labels:
        severity: warning
    - alert: PrometheusRuleFailures
      annotations:
        description: Prometheus {{ $labels.namespace }}/{{ $labels.pod }} has failed to
          evaluate {{ printf "%.0f" $value }} rules in the last 5m.
        summary: Prometheus is failing rule evaluations.
      expr: |
        increase(prometheus_rule_evaluation_failures_total{job="prometheus-k8s",namespace="monitoring"}[5m]) > 0
      for: 15m
      labels:
        severity: critical
    - alert: PrometheusMissingRuleEvaluations
      annotations:
        description: Prometheus {{ $labels.namespace }}/{{ $labels.pod }} has missed {{ printf "%.0f" $value }} rule group evaluations in the last 5m.
        summary: Prometheus is missing rule evaluations due to slow rule group evaluation.
      expr: |
        increase(prometheus_rule_group_iterations_missed_total{job="prometheus-k8s",namespace="monitoring"}[5m]) > 0
      for: 15m
      labels:
        severity: warning
  - name: alertmanager.rules
    rules:
    - alert: AlertmanagerFailedReload
      annotations:
        message: Reloading Alertmanager's configuration has failed for {{$labels.namespace}}/{{ $labels.pod }}.
      expr: |
        alertmanager_config_last_reload_successful{job="alertmanager-main",namespace="monitoring"} == 0
      for: 10m
      labels:
        severity: warning
    - alert: AlertmanagerMembersInconsistent
      annotations:
        message: Alertmanager has not found all other members of the cluster.
      expr: |
        alertmanager_cluster_members{job="alertmanager-main",namespace="monitoring"}
          != on (service) GROUP_LEFT()
        count by (service) (alertmanager_cluster_members{job="alertmanager-main",namespace="monitoring"})
      for: 5m
      labels:
        severity: critical
  - name: node-network
    rules:
    - alert: NodeNetworkInterfaceFlapping
      annotations:
        message: Network interface "{{$labels.device}}" changing it's up status
          often on node-exporter {{ $labels.namespace }}/{{ $labels.pod }}"
      expr: |
        changes(node_network_up{job="node-exporter",device!~"veth.+"}[2m]) > 2
      for: 2m
      labels:
        severity: warning
  - name: prometheus-operator
    rules:
    - alert: PrometheusOperatorListErrors
      annotations:
        message: Errors while performing List operations in controller {{$labels.controller}}
          in {{ $labels.namespace }} namespace.
      expr: |
        (sum by (controller,namespace) (rate(prometheus_operator_list_operations_failed_total{job="prometheus-operator",namespace="monitoring"}[1h])) / sum by (controller,namespace) (rate(prometheus_operator_list_operations_total{job="prometheus-operator",namespace="monitoring"}[1h]))) > 0.4
      for: 15m
      labels:
        severity: warning
    - alert: PrometheusOperatorWatchErrors
      annotations:
        message: Errors while performing Watch operations in controller {{$labels.controller}}
          in {{ $labels.namespace }} namespace.
      expr: |
        (sum by (controller,namespace) (rate(prometheus_operator_watch_operations_failed_total{job="prometheus-operator",namespace="monitoring"}[1h])) / sum by (controller,namespace) (rate(prometheus_operator_watch_operations_total{job="prometheus-operator",namespace="monitoring"}[1h]))) > 0.4
      for: 15m
      labels:
        severity: warning
    - alert: PrometheusOperatorReconcileErrors
      annotations:
        message: Errors while reconciling {{$labels.controller}} in {{ $labels.namespace }} Namespace.
      expr: |
        rate(prometheus_operator_reconcile_errors_total{job="prometheus-operator",namespace="monitoring"}[5m]) > 0.1
      for: 10m
      labels:
        severity: warning
    - alert: PrometheusOperatorNodeLookupErrors
      annotations:
        message: Errors while reconciling Prometheus in {{ $labels.namespace }} Namespace.
      expr: |
        rate(prometheus_operator_node_address_lookup_errors_total{job="prometheus-operator",namespace="monitoring"}[5m]) > 0.1
      for: 10m
      labels:
        severity: warning
---
# Source: logiq/charts/logiq-flash/templates/serviceMonitor.yaml
apiVersion: monitoring.coreos.com/v1
kind: ServiceMonitor
metadata:
  labels:
    app: logiq-flash
    release: "prometheus"
  name: prometheus-logiq-logiq-flash
  namespace: logiq
spec:
  endpoints:
  - interval: 2m
    path: /metrics
    scheme: https
    targetPort: 9998
    tlsConfig:
      insecureSkipVerify: true
  namespaceSelector:
    matchNames:
    - logiq
  selector:
    matchLabels:
      promMonitor: logiq-flash
---
# Source: logiq/charts/postgres/templates/servicemonitor.yaml
apiVersion: monitoring.coreos.com/v1
kind: ServiceMonitor
metadata:
  name: postgres
  namespace: logiq
  labels:
    app: postgres
    chart: postgres-8.7.3
    release: "logiq"
    heritage: "Helm"
spec:
  endpoints:
    - port: http-metrics
      interval: 1m
      scrapeTimeout: 10s
  namespaceSelector:
    matchNames:
      - logiq
  selector:
    matchLabels:
      app: postgres
      release: logiq
---
# Source: logiq/charts/prometheus/charts/kube-state-metrics/templates/servicemonitor.yaml
apiVersion: monitoring.coreos.com/v1
kind: ServiceMonitor
metadata:
  name: logiq-kube-state-metrics
  namespace: logiq
  labels:
    app.kubernetes.io/name: kube-state-metrics
    helm.sh/chart: kube-state-metrics-2.1.19
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
spec:
  selector:
    matchLabels:
      app.kubernetes.io/name: kube-state-metrics
      app.kubernetes.io/instance: logiq
  endpoints:
    - port: http
      honorLabels: true
  namespaceSelector:
    matchNames:
    - logiq
---
# Source: logiq/charts/prometheus/charts/node-exporter/templates/servicemonitor.yaml
apiVersion: monitoring.coreos.com/v1
kind: ServiceMonitor
metadata:
  name: logiq-node-exporter
  namespace: logiq
  labels:
    app.kubernetes.io/name: node-exporter
    helm.sh/chart: node-exporter-2.3.17
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
spec:
  jobLabel: jobLabel
  selector:
    matchLabels:
      app.kubernetes.io/name: node-exporter
      app.kubernetes.io/instance: logiq
  endpoints:
    - port: metrics
  namespaceSelector:
    matchNames:
    - logiq
---
# Source: logiq/charts/prometheus/templates/alertmanager/servicemonitor.yaml
apiVersion: monitoring.coreos.com/v1
kind: ServiceMonitor
metadata:
  name: logiq-prometheus-alertmanager
  namespace: logiq
  labels:
    app.kubernetes.io/name: prometheus
    helm.sh/chart: prometheus-6.5.3
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
    app.kubernetes.io/component: alertmanager
spec:
  selector:
    matchLabels:
      app.kubernetes.io/name: prometheus
      app.kubernetes.io/instance: logiq
      app.kubernetes.io/component: alertmanager
  namespaceSelector:
    matchNames:
      - logiq
  endpoints:
    - port: http
      path: /metrics
---
# Source: logiq/charts/prometheus/templates/exporters/kubelet/servicemonitor.yaml
apiVersion: monitoring.coreos.com/v1
kind: ServiceMonitor
metadata:
  name: logiq-prometheus-kubelet
  namespace: logiq
  labels:
    app.kubernetes.io/name: prometheus
    helm.sh/chart: prometheus-6.5.3
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
    app.kubernetes.io/component: kubelet
spec:
  jobLabel: k8s-app
  selector:
    matchLabels:
      k8s-app: kubelet
  namespaceSelector:
    matchNames:
      - kube-system
  endpoints:
    - port: https-metrics
      scheme: https
      tlsConfig:
        caFile: /var/run/secrets/kubernetes.io/serviceaccount/ca.crt
        serverName: kubernetes
        insecureSkipVerify: true
      bearerTokenFile: /var/run/secrets/kubernetes.io/serviceaccount/token
      honorLabels: true
    - port: https-metrics
      path: /metrics/cadvisor
      scheme: https
      tlsConfig:
        caFile: /var/run/secrets/kubernetes.io/serviceaccount/ca.crt
        serverName: kubernetes
        insecureSkipVerify: true
      bearerTokenFile: /var/run/secrets/kubernetes.io/serviceaccount/token
      honorLabels: true
---
# Source: logiq/charts/prometheus/templates/prometheus-operator/servicemonitor.yaml
apiVersion: monitoring.coreos.com/v1
kind: ServiceMonitor
metadata:
  name: logiq-prometheus-operator
  namespace: logiq
  labels:
    app.kubernetes.io/name: prometheus
    helm.sh/chart: prometheus-6.5.3
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
    app.kubernetes.io/component: operator
spec:
  endpoints:
    - port: http
      honorLabels: true
  selector:
    matchLabels:
      app.kubernetes.io/name: prometheus
      app.kubernetes.io/instance: logiq
      app.kubernetes.io/component: operator
  namespaceSelector:
    matchNames:
      - logiq
---
# Source: logiq/charts/prometheus/templates/prometheus/servicemonitor.yaml
apiVersion: monitoring.coreos.com/v1
kind: ServiceMonitor
metadata:
  name: logiq-prometheus-prometheus
  namespace: logiq
  labels:
    app.kubernetes.io/name: prometheus
    helm.sh/chart: prometheus-6.5.3
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
    app.kubernetes.io/component: prometheus
spec:
  selector:
    matchLabels:
      app.kubernetes.io/name: prometheus
      app.kubernetes.io/instance: logiq
      app.kubernetes.io/component: prometheus
  namespaceSelector:
    matchNames:
      - logiq
  endpoints:
    - port: http
      path: /metrics
---
# Source: logiq/charts/redis/templates/metrics-prometheus.yaml
apiVersion: monitoring.coreos.com/v1
kind: ServiceMonitor
metadata:
  name: redis
  namespace: logiq
  labels:
    app: redis
    chart: redis-10.6.5
    release: logiq
    heritage: Helm
    prometheus: "kube-prometheus"
    release: "prometheus"
spec:
  endpoints:
  - port: metrics
    interval: 1m
  selector:
    matchLabels:
      app: redis
      release: logiq
  namespaceSelector:
    matchNames:
    - logiq
---
# Source: logiq/charts/thanos/templates/bucketweb/servicemonitor.yaml
apiVersion: monitoring.coreos.com/v1
kind: ServiceMonitor
metadata:
  name: logiq-thanos-bucketweb
  namespace: "logiq"
  labels:
    app.kubernetes.io/name: thanos
    helm.sh/chart: thanos-8.2.5
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
    app.kubernetes.io/component: bucketweb
spec:
  endpoints:
    - port: http
  namespaceSelector:
    matchNames:
      - logiq
  selector:
    matchLabels:
      app.kubernetes.io/name: thanos
      app.kubernetes.io/instance: logiq
      app.kubernetes.io/component: bucketweb
---
# Source: logiq/charts/thanos/templates/compactor/servicemonitor.yaml
apiVersion: monitoring.coreos.com/v1
kind: ServiceMonitor
metadata:
  name: logiq-thanos-compactor
  namespace: "logiq"
  labels:
    app.kubernetes.io/name: thanos
    helm.sh/chart: thanos-8.2.5
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
    app.kubernetes.io/component: compactor
spec:
  endpoints:
    - port: http
  namespaceSelector:
    matchNames:
      - logiq
  selector:
    matchLabels:
      app.kubernetes.io/name: thanos
      app.kubernetes.io/instance: logiq
      app.kubernetes.io/component: compactor
---
# Source: logiq/charts/thanos/templates/query/servicemonitor.yaml
apiVersion: monitoring.coreos.com/v1
kind: ServiceMonitor
metadata:
  name: logiq-thanos-query
  namespace: "logiq"
  labels:
    app.kubernetes.io/name: thanos
    helm.sh/chart: thanos-8.2.5
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
    app.kubernetes.io/component: query
spec:
  endpoints:
    - port: http
  namespaceSelector:
    matchNames:
      - logiq
  selector:
    matchLabels:
      app.kubernetes.io/name: thanos
      app.kubernetes.io/instance: logiq
      app.kubernetes.io/component: query
---
# Source: logiq/charts/thanos/templates/receive/servicemonitor.yaml
apiVersion: monitoring.coreos.com/v1
kind: ServiceMonitor
metadata:
  name: logiq-thanos-receive
  namespace: "logiq"
  labels:
    app.kubernetes.io/name: thanos
    helm.sh/chart: thanos-8.2.5
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
    app.kubernetes.io/component: receive
spec:
  endpoints:
    - port: http
  namespaceSelector:
    matchNames:
      - logiq
  selector:
    matchLabels:
      app.kubernetes.io/name: thanos
      app.kubernetes.io/instance: logiq
      app.kubernetes.io/component: receive
---
# Source: logiq/charts/thanos/templates/ruler/servicemonitor.yaml
apiVersion: monitoring.coreos.com/v1
kind: ServiceMonitor
metadata:
  name: logiq-thanos-ruler
  namespace: "logiq"
  labels:
    app.kubernetes.io/name: thanos
    helm.sh/chart: thanos-8.2.5
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
    app.kubernetes.io/component: ruler
spec:
  endpoints:
    - port: http
  namespaceSelector:
    matchNames:
      - logiq
  selector:
    matchLabels:
      app.kubernetes.io/name: thanos
      app.kubernetes.io/instance: logiq
      app.kubernetes.io/component: ruler
---
# Source: logiq/charts/thanos/templates/storegateway/servicemonitor.yaml
apiVersion: monitoring.coreos.com/v1
kind: ServiceMonitor
metadata:
  name: logiq-thanos-storegateway
  namespace: "logiq"
  labels:
    app.kubernetes.io/name: thanos
    helm.sh/chart: thanos-8.2.5
    app.kubernetes.io/instance: logiq
    app.kubernetes.io/managed-by: Helm
    app.kubernetes.io/component: storegateway
spec:
  endpoints:
    - port: http
  namespaceSelector:
    matchNames:
      - logiq
  selector:
    matchLabels:
      app.kubernetes.io/name: thanos
      app.kubernetes.io/instance: logiq
      app.kubernetes.io/component: storegateway


~/.kube 4m 53s
❯ microk8s kubectl get service             
NAME         TYPE        CLUSTER-IP     EXTERNAL-IP   PORT(S)   AGE
kubernetes   ClusterIP   10.152.183.1   <none>        443/TCP   10d

~/.kube
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

~/.kube
❯ 

