const Product = require('../models/product');



exports.getProducts = (req, res, next) => {
    Product.fetchAll((products) => {               // fetchAll error resolved by adding a callback fn. Episode 102. Revisit. ATTENTION:
        res.render("shop/product-list.ejs", {     // EJS
            prods: products,
            pageTitle: "All Products",
            path: "/products"
        });
    });
}


exports.getIndex = (req, res, next) => {
    Product.fetchAll((products) => { 
        res.render("shop/index.ejs", {     // EJS
            prods: products,
            pageTitle: "Shop",
            path: "/"
        });
    });
}

exports.getCart = (req, res, next) => {
    res.render("shop/cart.ejs", {     // EJS
        pageTitle: "Your Cart",
        path: "/cart"
    });
}


exports.getOrders = (req, res, next) => {
    res.render("shop/orders.ejs", {     // EJS
        pageTitle: "Your Orders",
        path: "/orders"
    });
}


exports.getCheckout = (req, res, next) => {
    res.render("shop/checkout.ejs", {     // EJS
        pageTitle: "Checkout",
        path: "/checkout"
    });
}