
# Part 1


> docker run -d -p 80:80 docker/getting-started     
> docker run -dp 80:80 docker/getting-started {we can combine single character flags to shorten the full command.}


Info:

> -d -> Run the container in detached mode (in the background)    
> -p 80:80 -> Map port 80 of the host to port 80 in the container. To access the tutorial, open a web browser and navigate to `https://localhost:80`. If some other service is listening on port 80 then we can use another port. Ex.: -p 3000:80 and then access the tut. via a web browser at `http://localhost:3000`.    
> `docker/getting-started` -> Specify the image to use.



# Container?

A container is a sandboxed process on your machine i.e. isolated from all other process on the host machine.
The solution leverages `kernal namespaces` and `cgroups`.


To summarize, a container:

- is a runnable instance of an image. You can create, start, stop, move, or delete a container using the DockerAPI or CLI.
- can be run on local machines, virtual machines or deployed to the cloud.
- is portable (can be run on any OS).
- is isolated from other containers and runs its own software, binaries, and configurations.


# Container Image?

- When running a container, it uses a isolated filesystem.
- The custom filesystem is provided by a `container image`.
- Since the image contains the container's filesystem, it must contain everything needed to run an application - all dependencies, configs., scripts, binaries, etc.
- Image also contains other config. for the container, such as, env. vars., a default command to run, and other metadata.


