// 1. Spin up a Node.js driven server (on port 3000)                ✔

// 2. Handle 2 routes: "/" and "/users"                             ✔
//    - Return some gretting text on "/" (Some <h1> tag)            ✔
//    - Return a list of dummy users on "/users" (ex. <ul><li>User1</li><li>User2</li></ul>))   ✔

// 3. Add a form with a "username" <input> to the "/" page and submit a POST requets to "/create-user" upon a button click. ✔

// 4. Add the "/create-user" route and parse the incoming data (i.e., the username) and simply log it to the console.   ✔?

const http = require('http');
const routes = require('./routes');

const server = http.createServer(routes);

server.listen(3000);