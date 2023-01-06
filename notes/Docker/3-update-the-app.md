# Next we will make a modification in our app and learn how to update our running application with a new image.

made a change in src/static/js/app.js

- built the image again

> `docker build -t getting-started .`

- Start a new container using the updated code.

> `docker run -dp 3000:3000 getting-started`

- If the old docker container was running on host's port 3000, we will get an error, and only one process on the machine(containers included) can listen to a specific port.
- To fix this, remove the old container.

# Replacing the old container

## Remove container using the CLI

- Get the ID of the container using: 
`docker ps`

- Stopping the container
`docker stop <container-id>`

- Removing container
`docker rm <container-id>`

- Start the updated app container using
`docker run -dp 3000:3000 getting-started`

# Things to NOTE:
- All of the existing items in our todo list are gone.
- There were a lot of steps involved for such a small change. In an upcoming section, we’ll talk about how to see code updates without needing to rebuild and start a new container every time we make a change.



