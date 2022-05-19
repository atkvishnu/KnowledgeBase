// 1. Create a npm project and install Express and ejs + Nodemon

// 2. Add 2 routes:
//    a. "/" => Holds a <form> that allows users to input their name
//    b. "/users" => Outputs an <ul> with the user names (or some error text)

const express = require("express");
const path = require("path");
const bodyParser = require("body-parser");


const app = express();

app.set("view engine", "ejs");
app.set("views", "views");

const rootDir = require('./utils/path');


app.use(bodyParser.urlencoded({ extended: true }));
app.use(express.static(path.join(rootDir, "public")));


const users = [];


app.get("/", (req, res, next) => {
    res.render('index.ejs', {
        pageTitle: 'Add User',
        path: '/',
    });
});


app.get("/users", (req, res, next) => {
    res.render("users.ejs", {
        pageTitle: "Users",
        path: "/users",
        users: users
    });
});

app.post("/add-users", (req, res, next) => {
    users.push({ name: req.body.username });
    res.redirect("/users");
});

app.use((req, res, next) => {
    res.status(404).render("404.ejs", {
        pageTitle: "Page Not Found!",
        path: null
    });
});


app.listen(3001);