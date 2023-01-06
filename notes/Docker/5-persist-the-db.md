# Persist the DB

In case you didn’t notice, our todo list is being wiped clean every single time we launch the container. Why is this? Let’s dive into how the container is working.

## The Container's Filesystem

When a container runs, it uses the various layers from an image for its filesystem.
Each container gets it's own "scratch space" to create/update/remove files.
Any changes won't be seen in another container, even if they are using the same image.




To see this in action, we’re going to start two containers and create a file in each. What you’ll see is that the files created in one container aren’t available in another.

Start an ubuntu container that will create a file named /data.txt with a random number between 1 and 10000.
> `docker run -d ubuntu bash -c "shuf -i 1-10000 -n 1 -o /data.txt && tail -f /dev/null"`

> We are starting a bash shell and invoking 2 commands (why we have &&).    
> The first portion picks a single random number and writes it to `/data.txt`    
> The second command is simply watching a file to keep the container running.    


- Next, either go to docker hub, open terminal for ubuntu container, and run `cat /data.txt`
OR
- From terminal directly do: `docker exec <container-id> cat /data.txt`. We will see a rand. number.

Now let's add another `ubuntu` container (the same image) and we don't have the same file
DO `docker run -it ubuntu ls /` : No data.txt file will be present for this container, because it was written to the scratch space for only the first container.

- Remove the first container using `docker rm -f <container-id>`

# Container Volumes

With the prev. experiment we saw that each container starts from the image definition each time it starts.
While containers can create, update, and delete files, those changes are lost when the container is removed and all changes are isolated to that container. With volumes, we can change all of this.

Volumes provide the ability to connect specific filesystem paths of the container back to the host machine. If a directory in the container is mounted, changes in that directory are also seen on the host machine. If we mount that same directory across container restarts, we’d see the same files.

There are two main types of volumes. We will eventually use both, but we will start with named volumes.


# Persists the todo data

By default, the todo app stores it's data in a `SQLite DB` at `/etc/todos/todo.db` in the container's filesystem.

With the database being a single file, if we can persist that file on the host and make it available to the next container, it should be able to pick up where the last one left off. 
By creating a volume and attaching (often called “mounting”) it to the directory the data is stored in, we can persist the data. As our container writes to the todo.db file, it will be persisted to the host in the volume.

As mentioned, we are going to use a named volume. 
Think of a named volume as simply a bucket of data. 
Docker maintains the physical location on the disk and you only need to remember the name of the volume. 
Every time you use the volume, Docker will make sure the correct data is provided.

- Create a volume by using the `docker volume create` command.
> `docker volume create todo-db`

- Stop and remove the todo app container once again in the Dashboard (or with docker rm -f <id>), as it is still running without using the persistant volume.

- Start the todo app container, but add the `-v` flag to specify a volume mount. We will use the named volume and mount it to 
`/etc/todos`, which will capture all files created at the path.
> `docker run -dp 3000:3000 -v todo-db:/etc/todos getting-started`

- Once the container starts up, open the app and add a few items to your todo list.

- Stop and remove the container for the todo app. Use the Dashboard or `docker ps` to get the ID and then `docker rm -f <id>` to remove it.

- Start a new container using the same command from above.

- Open the app. We should get the data changes which we made earlier.

> NOTE:    
> While named volumes and bind mounts are the 2 main types of volume supported by a default docker engine installation, there are many volume driver plugins available to support NFS, SFTP, NetApp, etc... 
> This will be especially important once you start running containers on multiple hosts in a clustered environment with Swarm, Kubernetes, etc.


# Dive into a volume

> `docker volume inspect todo-db`

```
[
    {
        "CreatedAt": "2022-08-29T12:18:55Z",
        "Driver": "local",
        "Labels": {},
        "Mountpoint": "/var/lib/docker/volumes/todo-db/_data",
        "Name": "todo-db",
        "Options": {},
        "Scope": "local"
    }
]
```

The `Mountpoint` is the actual location on the disk where the data is stored. Note that on most machines, you will need to have root access to access this directory from the host. But, that’s where it is!























