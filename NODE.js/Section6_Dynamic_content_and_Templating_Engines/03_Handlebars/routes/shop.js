const path = require("path");
const express = require("express");

const router = express.Router();

const rootDir = require("../util/path");
const adminData = require("./admin");

// We need to get access to the products array in shop.js

router.get("/", (req, res, next) => {
	// console.log('shop.js' + adminData.products);            // This is a bad way to do it. This data is inherently shared across requests and users.i.e., it is not private to a single user, if we open a firefox instance of localhost:3000, we can see the data in the console again.
	// // We may never want to implement this kind of data sharing. We will want to fetch a data for a specific request and user. We may want to use a database to store the data.
	// res.sendFile(path.join(rootDir, "views", "shop.html"));   // same as above. NEATER
	const products = adminData.products;
	// res.render('shop', {prods: products, docTitle: 'Shop'});
	res.render("shop-with-layout.handlebars", {
		prods: products,
		pageTitle: "Shop",
		path: "/",
		hasProducts: products.length > 0,
        activeShop: true,
        productCSS: true
	});
});

module.exports = router;
