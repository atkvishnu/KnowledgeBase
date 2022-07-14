const Product = require('../models/product');

exports.getAddProduct = (req, res, next) => {
	res.render("add-product-with-includes.ejs", {  // EJS
		pageTitle: "Add Product",
		path: "/admin/add-product"
	});
}


exports.postAddProduct = (req, res, next) => {
    // const title = req.body.title;
    const product = new Product(req.body.title);
    product.save();
	res.redirect("/");
}

exports.getProducts = (req, res, next) => {
    const products = Product.fetchAll((products) => {               // fetchAll error resolved by adding a callback fn. Episode 102. Revisit. ATTENTION:
        res.render("shop-with-includes.ejs", {     // EJS
            prods: products,
            pageTitle: "Shop",
            path: "/"
        });
    });
}

