# Share the application using Docker hub

> `docker push docker/getting-started:<tagname>` - won't work because we are trying to push something in dockers repo


- Login to docker hub from terminal
> `docker login -u atkvishnu`

- Change the name of the tag
> `docker tag getting-started atkvishnu/getting-started`

- Now push to docker hub again
> `docker push atkvishnu/getting-started`
If tags are not added to the image name, then Docker will use a tag called latest


# Run the image on a new instance

- Login to [Play with Docker](labs.play-with-docker.com)
- Login to docker
- Connect to Docker Hub
- Add new ionstance
- `docker run -dp 3000:3000 atkvishnu/getting-started`
- Click on the 3000 port icon. 


# Summary

In this section, we learned how to share our images by pushing them to a registry. 
We then went to a brand new instance and were able to run the freshly pushed image. 
This is quite common in CI pipelines, where the pipeline will create the image and push it to a registry and then the production environment can use the latest version of the image.
Now that we have that figured out, let’s circle back around to what we noticed at the end of the last section. 
As a reminder, we noticed that when we restarted the app, we lost all of our todo list items. 
That’s obviously not a great user experience, so let’s learn how we can persist the data across restarts!




