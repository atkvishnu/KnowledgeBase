const fs = require("fs");
const path = require("path");
// defines a single product
const Cart = require("./cart");

// const products = [];         // now storing the data in a file instead of an array.

const p = path.join(
	// global helper fn.
	path.dirname(require.main.filename),
	"data",
	"products.json"
);

// helper fn.
const getProductsFromFile = (cb) => {
	const p = path.join(
		path.dirname(require.main.filename),
		"data",
		"products.json"
	);
	fs.readFile(p, (err, fileContent) => {
		if (err) {
			return cb([]);
		}
		cb(JSON.parse(fileContent));
	});
};

module.exports = class Product {
	constructor(id, title, imageUrl, description, price) {
		this.id = id; // we will pass `null` as id if we are creating a new product.
		this.title = title;
		this.imageUrl = imageUrl;
		this.description = description;
		this.price = price;
	}

	save() {
		// products.push(this);
		getProductsFromFile((products) => {
			// ATTENTION: Ep 103.   // Refactored.
			if (this.id) {
				// if id is already existing in data/product.json, then we are updating an existing product.
				const existingProductIndex = products.findIndex(
					(prod) => prod.id === this.id
				);
				const updatedProducts = [...products]; // creating a new array with the old array's values.
				updatedProducts[existingProductIndex] = this; // this is the updated product. this is the product we are trying to save.
				fs.writeFile(p, JSON.stringify(updatedProducts), (err) => {
					console.log(err);
				});
			} else {
				this.id = Math.random().toString(); // random text unique id.
				products.push(this);
				fs.writeFile(p, JSON.stringify(products), (err) => {
					console.log(err);
				});
			}
		});
	}

	static fetchAll(cb) {
		// ATTENTION: Episode 102. Resolving the cb error. WATCH AGAIN.
		// `static` lets us call the method without instantiating the class, otherwise we will have to first instantiate the class using new keyword
		getProductsFromFile(cb);
		// return products;
	}

	static findById(id, cb) {
		getProductsFromFile((products) => {
			const product = products.find((p) => p.id === id);
			cb(product); // executing a callback with product as an argument.
		});
	}

    static deleteById(id) {
        getProductsFromFile(products => {
            const product = products.find(prod => prod.id === id);
			// const productIndex = products.findIndex(prod => prod.id === id);
            // shortcut to the above code (finding index and deleting that index)
			const updatedProducts = products.filter(prod => prod.id !== id);    // prod.id !== id means that only if the id doen't matches we keep that product in the array. (returns true if the id is not equal)
			fs.writeFile(p, JSON.stringify(updatedProducts), err => {
                if(!err) {
                    Cart.deleteProduct(id, product.price);
                }
            })
            // cb(product); // executing a callback with product as an argument.
		});
    }
};
