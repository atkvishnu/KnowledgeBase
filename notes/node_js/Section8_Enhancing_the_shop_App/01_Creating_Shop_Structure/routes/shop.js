const path = require("path");
const express = require("express");

const router = express.Router();

const shopController = require("../controllers/shop");

// We need to get access to the products array in shop.js

router.get("/", shopController.getIndex);

router.get("/products", shopController.getProducts);

router.get("/cart", shopController.getCart);

router.get("/orders", shopController.getOrders);

router.get("/checkout", shopController.getCheckout);


module.exports = router;
