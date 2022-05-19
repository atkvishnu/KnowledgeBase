# What's Express?

- Server Logic is complex and hard to maintain! Express is a framework for server-side logic.
- We want to focus on the business logic and not on the nitty-gritty details.
- We use a framework for the heavy lifting.
- Framework: Helper functions, tools & rules that help us build our application.

Alternatives to Express.js:
- Vanilla Node.js
- Adonis.js (laravel inspired framework)
- Koa
- Hapi
- Sails.js

- Express is highly flexible and most popular!

# Install Nodemon

- npm init - put default texts/ anything you want
- package.json is added

- In package.json in scripts

- 3rd party app to restart server after changes - nodemon

- ATTENTION: npm install nodemon --save-dev


# HEADING: Using Nodemon for Autorestarting Server
- Change the scripts in package.json
```js
"scripts": {
    "start": "nodemon app.js",
    "start-server": "node app.js",
}
```



- production dependencies (--save)
- development dependencies (--save-dev)
- global dependencies (-g)


# Install Express.js

- npm install --save express

```js
const http = require('http');

const express = require('express');
const app = express();  // create an instance of express

// The argument next() is a function which we are passing as a parameter to the middleware function.
app.use((req, res, next) => {       // this fn. ((req,res,next)=>{}) will execute for every request
    console.log('Hello from the middleware!');
    next();     // next() is a function that tells Express to continue to the next middleware function.
});  
      
app.use((req, res, next) => {  
    console.log('Hello from another middleware fn.!');
    next();
});

const server = http.createServer(app); // create an instance of http server

server.listen(3000);
```



# Express.js is a middleware

        Request
            ⬇
    Middleware  ((req,res,next) => { ... })
            ⬇
    -> (next()) -> 
            ⬇
    Middleware  ((req,res,next) => { ... }) 
    ->(res.send())-> 
            ⬇
        Response


Middleware means a incoming request is funneled through a series of functions by express.js.
Instead of having one request handler, we can hook up multiple middleware functions, through which the request will go through untill we send the response!
This allows us to keep multiple blocks of code instead of having a huge function!
This is the pluggable nature of express.js.

# How middleware works!

```js
const http = require('http');

const express = require('express');
const app = express(); 

app.use((req, res, next) => { 
    console.log('Hello from the middleware!');
    next();
});  
      
app.use((req, res, next) => {  
    console.log('Hello from another middleware fn.!');
    res.send('<h1>Hello from the server!</h1>'); // send() allows us to send a response to the client. just like res.write() but with any type. We can send HTML code, JSON, etc.
    res.send('Hello from the server 2!');
    res.end();
    // content-type: text/html is set by default.   // we can still set header to something else using res.setHeader()
});

const server = http.createServer(app); // create an instance of http server

server.listen(3000);
```



# Express.js behind the scenes

### We can replace `const server = http.createServer(app);` and `server.listen(3000);` with `app.listen(3000);` and remove `const http = require('http');`

```js
const express = require('express');
const app = express(); 

app.use((req, res, next) => { 
    console.log('Hello from the middleware!');
    next();
});  
      
app.use((req, res, next) => {  
    console.log('Hello from another middleware fn.!');
    res.send('<h1>Hello from the server!</h1>');
    res.send('Hello from the server 2!');
    res.end();
});

app.listen(3000);
```


