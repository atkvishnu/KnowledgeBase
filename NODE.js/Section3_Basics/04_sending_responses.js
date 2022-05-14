const http = require('http');

const server = http.createServer(function(req, res) {
    console.log(req.url, req.method, req.headers);  // /(url) GET(method) {...}(headers)
    // console.log(req.headers['user-agent']);
    // process.exit();
    res.setHeader('Content-Type', 'text/html'); // this attaches a header to the response, suggesting that the response is HTML
    res.write('<html>'); // this works in multiple lines
    res.write('<head><title>My First Page</title></head>');
    res.write('<body><h1>Hello from my Node.js Server!</h1></body>');
    res.write('</html>');
    res.end();  // this ends the response, after this we cannot do anymore res.write()
})

server.listen(3000);


// On both request and responses, HTTP headers are added to transport metadata from A to B.
