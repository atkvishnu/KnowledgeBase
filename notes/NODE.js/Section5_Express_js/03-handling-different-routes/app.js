const express = require('express');

const app = express();

app.use('/', (req,res,next) => {
    console.log('This will always run');
    next();
});

app.use('/add-product', (req,res,next) => {
    console.log('In another middleware!');
    console.log('Request URL: ' + req.url);
    res.send('<h1>In the "Add Product" page!</h1>');
    return;
});

app.use('/', (req,res,next) => {
    console.log('In another middleware');
    console.log('Request URL: ' + req.url);
    res.send('<h1>Hello from Express.js!</h1>');
    return;
});




app.listen(3000);
