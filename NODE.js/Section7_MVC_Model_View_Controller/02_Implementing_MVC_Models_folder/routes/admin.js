const path = require("path");
const express = require("express");

const productsController = require("../controllers/products");      // from controllers folder


const router = express.Router();


// /admin/add-product => GET
router.get("/add-product", productsController.getAddProduct);       // don't execute the getAddProduct fn.

// /admin/add-product => POST
router.post("/add-product", productsController.postAddProduct);     // don't execute the postAddProduct fn.

// // module.exports = router;
// exports.routes = router;
// exports.products = products;
module.exports = router;