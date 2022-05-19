const fs = require("fs");
const path = require("path");
// defines a single product

// const products = [];         // now storing the data in a file instead of an array.

const p = path.join(        // global fn.
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
	constructor(t) {
		this.title = t;
	}

	save() {
		// products.push(this);
        getProductsFromFile(products => {           // ATTENTION: Ep 103.   // Refactored.
            products.push(this);
			fs.writeFile(p, JSON.stringify(products), (err) => {
				console.log(err);
			});
        });
		// const p = path.join(         // not needed anymore refactored using helper fn. getProductsFromFile()
		// 	path.dirname(require.main.filename),
		// 	"data",
		// 	"products.json"
		// ); // stores JSON file in data folder
		fs.readFile(p, (err, fileContent) => {
			let products = [];
			
		});
	}

	static fetchAll(cb) {
		// Episode 102. Resolving the cb error. WATCH AGAIN. ATTENTION:
		// `static` lets us call the method without instantiating the class, otherwise we will have to first instantiate the class using new keyword
		getProductsFromFile(cb);
        // return products;
	}
};
