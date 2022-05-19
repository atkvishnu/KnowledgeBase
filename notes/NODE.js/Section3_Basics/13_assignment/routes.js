const fs = require('fs');

const routes = (req, res) => {
    const url = req.url;
    const method = req.method;
    if (url === "/") {
        res.write("<html>");
        res.write('<head><title>Welcome message!</title></head>');
        res.write('<body>');
        res.write('<h1>Hello from my Node.js Server!</h1>');
        res.write('<form action="/create-user" method="POST"><input type="text" placeholder="Enter the username" name="username"><button type="submit">Send</button></form>');
        res.write('</body>');
        res.write("</html>");
        return res.end();
    } else if (url === "/users") {
        res.write('<html>');
        res.write('<head><title>Users</title></head>');
        res.write('<body><ul><li>Dummy User 1</li><li>Dummy User 2</li></ul></body>');
        res.write('</html>');
        return res.end();
    } else if (url === "/create-user" && method === "POST") {
        const body = [];
        req.on('data', (chunk) => { 
            // console.log(chunk);
            body.push(chunk);  
        });
        req.on('end', () => { 
            const parsedBody = Buffer.concat(body).toString(); 
            const user = parsedBody.split('=')[1]; 
            console.log('username : ' + user);
        });
        res.statusCode = 302;
        res.setHeader('Location', '/');
        res.end();
    } 
    // else if (url === "/create-user") {
    //     console.log(user);
    //     res.write('<html>');
    //     res.write('<head><title>Create User</title></head>');
    //     res.write('<body>')
    //     res.write('<body><ul><li>'+user+'</li></ul></body>');
    //     res.write('</html>');
    //     return res.end();
    // }
}


module.exports = routes;