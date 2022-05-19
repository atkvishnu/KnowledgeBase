const path = require("path");
const express = require("express");

const adminController = require("../controllers/admin");      // from controllers folder


const router = express.Router();


// /admin/add-product => GET
router.get("/add-product", adminController.getAddProduct);       // don't execute the getAddProduct fn.

// /admin/products => GET
router.get("/products", adminController.getProducts); 

// /admin/add-product => POST
router.post("/add-product", adminController.postAddProduct);     // don't execute the postAddProduct fn.

// we will prepopulate the form with the data of the product we want to edit
router.get('/edit-product/:productId', adminController.getEditProduct);

router.post('/edit-product', adminController.postEditProduct);

router.post('/delete-product', adminController.postDeleteProduct);

// // module.exports = router;
// exports.routes = router;
// exports.products = products;
module.exports = router;