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




// // module.exports = router;
// exports.routes = router;
// exports.products = products;
module.exports = router;