const products = [];

exports.getAddProduct = (req, res, next) => {
	res.render("add-product-with-includes.ejs", {  // EJS
		pageTitle: "Add Product",
		path: "/admin/add-product"
	});
}


exports.postAddProduct = (req, res, next) => {
	products.push({ title: req.body.title });
	res.redirect("/");
}

exports.getProducts = (req, res, next) => {
	// const products = adminData.products;     // products array is now available in this file, therefore no need to pass it as a parameter
	res.render("shop-with-includes.ejs", {     // EJS
		prods: products,
		pageTitle: "Shop",
		path: "/"
	});
}

