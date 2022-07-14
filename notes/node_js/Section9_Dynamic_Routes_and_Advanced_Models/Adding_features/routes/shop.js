const path = require("path");
const express = require("express");

const router = express.Router();

const shopController = require("../controllers/shop");

// We need to get access to the products array in shop.js

router.get("/", shopController.getIndex);

router.get("/products", shopController.getProducts);

// router.get("/products/delete", shopController.deleteProduct);    // this will work

router.get("/products/:productId", shopController.getProduct);      // :productId is a dynamic route. This feature is called as Dynamic Routes which is provided by express router. We are using this feature to get the productId from the URL.
// later we will use this productId to get the product from the products array.
// :productId can be anything. It is just a placeholder.

// router.get("/products/delete", shopController.deleteProduct);   // this will not work, we need to place this above the dynamic route
// if we have a extra path which is same as /products/... (like /products/delete) then we need to put that above the dynamic route (i.e. /products/:productId) because we are not using next() in the `controller/shop.js` file.

router.get("/cart", shopController.getCart);

router.post("/cart", shopController.postCart);

router.get("/orders", shopController.getOrders);

router.get("/checkout", shopController.getCheckout);


module.exports = router;
