const express = require('express');
const bodyParser = require('body-parser');

const app = express();

const adminRoutes = require('./routes/admin');
const shopRoutes = require('./routes/shop');


app.use(bodyParser.urlencoded({extended: true}));


// app.use(shopRoutes);
// app.use(adminRoutes);
// we can place these 2 in any order because we have used router.get()/router.post() instead of router.use()

// adding path filters
// here we are adding path filters to the router, so that any admin page starts with /admin/
app.use('/admin', adminRoutes);     // redirects to /admin/add-product
app.use(shopRoutes);


app.use((req,res,next) => {
    res.status(404).send('<h1>Page not found</h1>');
})



app.listen(3000);