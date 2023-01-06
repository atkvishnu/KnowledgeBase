# Sample App

- Get the app on local: 

`git clone https://github.com/docker/getting-started.git`

- Go to src/ where package.json is stored
- Add `Dockerfile` to that base folder

```Dockerfile
# syntax=docker/dockerfile:1
FROM node:12-alpine
RUN apk add --no-cache python2 g++ make
WORKDIR /app
COPY . .
RUN yarn install --production
CMD ["node", "src/index.js"]
EXPOSE 3000
```


- To build:

> `docker build -t getting-started .`

- This command used the Dockerfile to build a new container image. 
- You might have noticed that a lot of “layers” were downloaded. 
This is because we instructed the builder that we wanted to start from the node:12-alpine image. 
But, since we didn’t have that on our machine, that image needed to be downloaded.

After the image was downloaded, we copied in our application and used yarn to install our application’s dependencies. The CMD directive specifies the default command to run when starting a container from this image.

Finally, the -t flag tags our image. Think of this simply as a human-readable name for the final image. Since we named the image getting-started, we can refer to that image when we run a container.

The . at the end of the docker build command tells Docker that it should look for the Dockerfile in the current directory.

- Start the app contrainer after building it

> `docker run -dp 3000:3000 getting-started`

- Application will be running on port 3000. The frontend will be storing the data in the backend.

- Now do `docker ps` to list all the docker instances running.

#### Next we will make a modification in our app and learn how to update our running application with a new image.


