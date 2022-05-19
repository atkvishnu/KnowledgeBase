// As we are building a online shopping cart, we need to create a admin page.
// This should be the path of creation of products which the admin can do
const path = require('path');
const express = require('express');

const rootDir = require('../utils/path');

const router = express.Router();


// /admin/add-product => GET
router.get('/add-product', (req, res, next) => {
    // res.sendFile(path.join(__dirname, "..", "views", "add-product.html"));   // works on both linux and windows
    res.sendFile(path.join(rootDir, "views", "add-product.html"));   // same as above. NEATER
});

// /admin/add-product => POST
router.post('/add-product', (req, res, next) => {
    console.log(req.body);
    res.redirect('/');
})

module.exports = router;
