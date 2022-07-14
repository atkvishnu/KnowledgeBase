const express = require('express');

const router = express.Router();

router.get('/', (req, res, next) => {
    res.send("<h1>Hello from / page <br><br> <a href='http://localhost:3000/admin/add-product'>/add-product page</a></h1>");
});


module.exports = router;