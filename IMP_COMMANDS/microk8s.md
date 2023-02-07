- Tag branch: `git tag -a -m <cluster-id-name> <branch-name>`
- Then push branch to remote: `git push origin <branch-name> --no-verify`
- `cd ~/.kube`
- `vi values.small.yaml`
	- Chnage old image <oldTAG> -> tag to new tag -> <newTAG>
	- Change coffee tag to new `brew-<newTag>` at two places: @:140 and :149

- `helm install logiq -n logiq --set global.persistance.storageClass=microk8s-hostpath <REPONAME> -f ~/.kube/values.microk8s.yaml --debug timout 10m`
- `helm upgrade logiq -n logiq --set global.persistance.storageClass=microk8s-hostpath <REPONAME> -f ~/.kube/values.microk8s.yaml --debug timout 20m`

> `alias kl="microk8s kubectl -n logiq"`

- `microk8s kubectl get service -n logiq`
- `microk8s kubectl logs coffee`
- `microk8s kubectl describe pods`
- `microk8s kubectl describe pods -n logiq`
- `microk8s kubectl get service -n logiq`
- `microk8s kubectl get pods`
- `microk8s kubectl get pods -n logiq`
