const http = require('http');

const server = http.createServer(function(req, res) {
    console.log(req.url, req.method, req.headers);  // /(url) GET(method) {...}(headers)
    // console.log(req.headers['user-agent']);
    // process.exit();
})

server.listen(3000);