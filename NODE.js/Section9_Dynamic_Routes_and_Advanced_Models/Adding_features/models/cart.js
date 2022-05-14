const fs = require("fs");
const path = require("path");

const p = path.join(
    path.dirname(require.main.filename),
    "data",
    "cart.json"
);


module.exports = class Cart {
    // constructor() {
    //     this.products = [];
    //     this.totalPrice = 0;
    // }
    // instead of using a constructor we will use a static addProduct method

    // arguments id and productPrice are passed from the controller.
    static addProduct(id, productPrice) {
        // LOGIC: Fetch the previous cart
        fs.readFile(p, (err, fileContent) => {
            let cart = {products: [], totalPrice: 0};
            if(!err) {
                cart = JSON.parse(fileContent);
            }
            // LOGIC: Analyze the cart => Find existing product
            // const existingProduct = cart.products.find(prod => prod.id === id);  // instead of doing this we are using the findIndex method and then dealing with the index
            const existingProductIndex = cart.products.findIndex(prod => prod.id === id);   // we are getting the index of the product in the cart.
            const existingProduct = cart.products[existingProductIndex];    // accessing the product at that index
            let updatedProduct;
            // LOGIC: Add new product/ increase quantity
            // 
            if (existingProduct) {// either updated product is updated
                updatedProduct = {...existingProduct};      // spread operator to add all the existing properties of the existingProduct to the updatedProduct.
                updatedProduct.qty++;       // and increment the qty by 1.
                cart.products = [...cart.products];     // copying the old array
                cart.products[existingProductIndex] = updatedProduct;   // replacing the old product at existingProductIndex(that index) with the updated product.
            } else {// or a new product is added
                updatedProduct = {id: id, qty: 1};
                cart.products = [...cart.products, updatedProduct];
            }
            cart.totalPrice = cart.totalPrice + +productPrice;
            fs.writeFile(p, JSON.stringify(cart), err => {
                console.log(err);
            })
        });
    }

    static deleteProduct(id, productPrice) {
        fs.readFile(p, (err, fileContent) => {
            if(err) {
                return;
            }
            // const updatedCart = {...cart};
            const updatedCart = {...JSON.parse(fileContent)};
            const product = updatedCart.products.find(prod => prod.id === id);
            if(!product) {      // if the product is not found in the cart.
                return;
            }
            updatedCart.products = updatedCart.products.filter(prod => prod.id !== id);
            updatedCart.totalPrice = updatedCart.totalPrice - productPrice * product.qty;
            fs.writeFile(p, JSON.stringify(updatedCart), err => {
                console.log(err);
            })
        });
    }


    static getCart(cb) {
        fs.readFile(p, (err, fileContent) => {
            const cart = JSON.parse(fileContent);
            if(err) {
                cb(null);
            }
            cb(cart);
        })
            
    }

};

// in our cart we need a method to add/remove products
// we don't want to create a new cart object everytime we add a product to the cart.
// There will always be a cart in our application. We will just manage the products in that cart.
