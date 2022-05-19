const path = require("path");
const express = require("express");

const router = express.Router();

const productsController = require("../controllers/products");

// We need to get access to the products array in shop.js

router.get("/", productsController.getProducts);

module.exports = router;
