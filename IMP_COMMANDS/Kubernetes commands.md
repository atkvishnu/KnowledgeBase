
[kubectl CheatSheet](https://kubernetes.io/docs/reference/kubectl/cheatsheet/)

- `kubectl get ns` -> 
- `kubectl config` -> Modify kubeconfig files (in ~/.kube/config) using subcommands like `kubectl config set current-context <my-context>` 
- `kubectl config view` -> View the config file.

> OCI logic -> ociops (tenancy name) -> Single sign on (SSO) -> oracleidentitycloudservice -> kumarvishnu -> pwd -> Search (Kubernetes clusters (OKE)) -> logiq-dev -> Access Cluster -> Local access -> run the command from this panel locally.
> `export KUBEONFIG = $HOME/.kube/config`
> Flatten all config files in the main file (`$HOME/.kube/config`)
> `KUBECONFIG = ~/.kube/config:~/.kube/config-dev kubectl config view --flatten > /tmp/config`

> kubectl config <commands\> 

#### Available Commands:

| SUBCOMMAND |  Details  |
| :-----------: | :----------------: |
| current-context | Display the current-context |
| delete-cluster | Delete the specified cluster from the kubeconfig |               
| delete-context | Delete the specified context from the kubeconfig |          
| delete-user | Delete the specified user from the kubeconfig |   
| get-clusters | Display clusters defined in the kubeconfig |    
| get-contexts | Describe one or many contexts |      
| get-users | Display users defined in the kubeconfig   |      
| rename-context | Rename a context from the kubeconfig file   |      
| set | Set an individual value in a kubeconfig file  |   
| set-cluster | Set a cluster entry in kubeconfig |    
| set-context | Set a context entry in kubeconfig |   
| set-credentials | Set a user entry in kubeconfig |   
| unset | Unset an individual value in a kubeconfig file |      
| use-context | Set the current-context in a kubeconfig file  |    
| view | Display merged kubeconfig settings or a specified kubeconfig file |     

Usage:
  `kubectl config <SUBCOMMAND>`

- `kubectl config get-clusters`
- `kubectl config get-contexts`
- `kubectl config rename-context <old-context-name> <new-context-name>`
- `kubectl config get-context logiq-dev`
- `kubectl get ns`
- `kubectl config set-context <context-name> --namespace <namespace-name>`
- `kubectl get ingress`
- `kubectl get pods`
- `kubectl -n <namespace> get pods` (when context is not set, will have to set context)
- `kubectl logs <pod-name>` -> logs
- `kubectl edit sts <sts-name>` -> edit sts
- `kubectl port-forward -n <namespace> <pod-name> <host-port-no.>:<pod-port-no.>` -> port-forward
- `stern -n <namespace> -l app=<app-name> --since=1s` -> stern
- `kubectl exec -it <pod-name> /bin/sh` -> exec into pod

#### `top` command
- `kubectl top pods --containers` -> to get pods memory consumption (to see container level memory/cpu utilizations vs pod level)
- `kubectl top pods --all-namespaces` -> to get pods from all the namespaces in this context
> `--all-namespaces` shorthand is `-A`
- `kubectl top pod --namespace <namespace>` -> to get info. about pods from a particular namespace
- `kubectl top node` -> lists metrics of the current node(CPU(cores), CPU%, memory, and memory%)

---

# PostgreSQL

```bash
> kubectl exec -it postgres-0 /bin/sh

$ psql -u postgres
Password: postgres
postgres=# \l               # this lists all the tables

postgres=# \c flash         # connect to database flash as user "postgres"

postgres=# \d               # List all relations and tables

postgres=# \d eventrules          # List all columns in eventrules

postgres=# select * from eventrules;

postgres=# select * from eventrules where namespace is null;

postgres=# delete from eventrules where namespace is null;
```



