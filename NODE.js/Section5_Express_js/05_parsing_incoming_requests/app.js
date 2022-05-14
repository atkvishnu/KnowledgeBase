const express = require('express');
const bodyParser = require('body-parser');

const app = express();

app.use(bodyParser.urlencoded({extended: true}));      // bodyParser.urlencoded() is used to parse the data coming from the form
// We get an object whose key is the name of the form field and the value is the value of the form field


app.use('/add-product', (req, res, next) => {
    res.send('<form action="/product" method="POST"><input type="text" name="title"><button type="submit">Add Product</button></form>');
});

// This middleware always executes, not just for POST requests but for GET requests as well
// we can use app.get()/ app.post() instead of app.use() to handle GET/ POST requests only
// app.use('/product', (req, res, next) => {
//     // redirect and log to console
//     console.log(req.body);
//     res.redirect('/');      // redirect() can be directly used instead of setting header. This makes our code more DRY. 
//     // this redirects to the root of the app when we submit the form on /add-product page
// })

// ⬇⬇⬇ app.post() is used to handle GET requests only
// now this middleware will only trigger for incoming POST requests
app.post('/product', (req, res, next) => {
    // redirect and log to console
    console.log(req.body);
    res.redirect('/');      // redirect() can be directly used instead of setting header. This makes our code more DRY. 
    // this redirects to the root of the app when we submit the form on /add-product page
})


app.use('/', (req, res, next) => {
    res.send("<h1>Hello from / page <br><br> <a href='http://localhost:3000/add-product'>/add-product page</a></h1>");
});



app.listen(3000);