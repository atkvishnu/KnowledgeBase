const express = require('express');
const bodyParser = require('body-parser');
const path = require('path');

const app = express();

// after importing express add templating engine as a global middleware
// app.set() allows you to set a value for a specific configuration option.
// view engine - sets the templating engine to use
app.set('view engine', 'pug');
// default setting for views is process.cwd() + '/views' - which we have already set. If we were not storing the HTML files in the views folder then we wil;l have to add this next line
app.set('views', 'views');
// app.set('views', path.join(__dirname, '<PATH>'));


const adminData = require('./routes/admin');
const shopRoutes = require('./routes/shop');


app.use(bodyParser.urlencoded({extended: true}));
app.use(express.static(path.join(__dirname, 'public'))); 


app.use('/admin', adminData.routes);     // redirects to /admin/add-product
app.use(shopRoutes);


app.use((req,res,next) => {
    // res.status(404).sendFile(path.join(__dirname, "views", "404.html"));
    // res.status(404).render('404.pug');
    res.status(404).render('404-extends.pug', {pageTitle: "Page Not Found!"});  // using dynamic layout
})



app.listen(3000);