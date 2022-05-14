// 1. Create a npm project and install Express.js + Nodemon
// 2. Create an Express.js app which serves two html files (of your choice with some content) for "/" and "/users".
// 3. Add some static files (.js or .css) to your project that should be required by at least one of the HTML files.

const path = require('path');
const express = require('express');

const app = express();

app.use(express.static(path.join(__dirname, "public")));

app.get("/users", (req, res, next) => {
    res.sendFile(path.join(__dirname, "views", "users.html"));
    console.log("users.html served");
})

app.get("/", (req,res,next) => {
    res.sendFile(path.join(__dirname, "views", "shop.html"));
    console.log("shop.html served");
})



app.listen(3000);