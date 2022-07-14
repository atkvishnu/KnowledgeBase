// 1. Create a npm project and install Express.js and nodemon
// 2. create an Express.js app which funnels the request through 2 middleware functions that log something to the console and return one response.
// 3. Handle request to "/" and "/users" such that each request only has one handler/ middleware that does something with it. (eg. send dummy response)

const express = require('express');

const app = express();

app.use('/', (req,res,next) => {
    console.log('This will always run');
    next();
})

app.use('/users', (req,res,next) => {
    console.log('In first middleware!');
    res.send('<h1>In the "Users" page!</h1>');
    return;
})

app.use('/', (req,res,next) => {
    console.log('In second middleware!');
    res.send("<h1>Hello from '/' page</h1>");
    return;
})


app.listen(3000);