const express = require("express");
const bodyParser = require("body-parser");
const path = require("path");


const app = express();

// after importing express add templating engine as a global middleware
// app.set() allows you to set a value for a specific configuration option.
// view engine - sets the templating engine to use

app.set("view engine", "ejs");
// app.set('view engine', 'pug');
// default setting for views is process.cwd() + '/views' - which we have already set. If we were not storing the HTML files in the views folder then we wil;l have to add this next line
app.set("views", "views");
// app.set('views', path.join(__dirname, '<PATH>'));

const errorController = require("./controllers/error");
const adminRoutes = require("./routes/admin");
const shopRoutes = require("./routes/shop");


app.use(bodyParser.urlencoded({ extended: true }));
app.use(express.static(path.join(__dirname, "public")));

app.use("/admin", adminRoutes); // redirects to /admin/add-product
app.use(shopRoutes);

app.use(errorController.get404);

app.listen(3000);
