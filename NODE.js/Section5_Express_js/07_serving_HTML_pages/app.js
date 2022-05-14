const express = require('express');
const bodyParser = require('body-parser');
const path = require('path');

const app = express();

const adminRoutes = require('./routes/admin');
const shopRoutes = require('./routes/shop');


app.use(bodyParser.urlencoded({extended: true}));
app.use(express.static(path.join(__dirname, 'public')));        // this is the way we will be able to serve the static files (CSS, JS, Images from public folder, otherwise the server will not be able to serve them)


// app.use(shopRoutes);
// app.use(adminRoutes);
// we can place these 2 in any order because we have used router.get()/router.post() instead of router.use()

// adding path filters
// here we are adding path filters to the router, so that any admin page starts with /admin/
app.use('/admin', adminRoutes);     // redirects to /admin/add-product
app.use(shopRoutes);


app.use((req,res,next) => {
    res.status(404).sendFile(path.join(__dirname, "views", "404.html"));
})



app.listen(3000);