# NodeJS - A "Javascript Runtime on the Server"

JS is used to manipulate the DOM in the browser.
NodeJS is a different version of JS/runtime which we can use outside the browser i.e, on server or any bare-metal machine. That's why it's a good option to run an application on a server.

NodeJS uses V8 engine that was created by google for chrome browser.
Engine takes JS code, and compiles it to machine code.

> Node -> uses -> V8 engine ( which complies JS code to machine code ) -> Machine Code ( runs on the computer )

V8 is written in C++.

- NodeJS added some extra features to V8 such as Local machine File Handling ( rwx ops. on local files, which we can not do in browser using JS because of security reasons ).

- NodeJS doesn't run on the browser. Browser uses vanilla V8 engine. NodeJS can be used to execute JavaScript scripts/code on our system.

- Some features are also taken away like in browser we can use JS to interact with the DOM, which we cannot do with node.


---

# Getting started

- Install [NodeJS](https://nodejs.org/en/).

- Check NodeJS version `node -v` || `node --version`

- NodeJS offers us a interactive mode (REPL) -> just type `node` in the terminal. Though this is not used to write nodeJS programs (we write nodeJS programs in files and later we execute the files).

```js
console.log("Hello from Node.js");
```

- File System functionality

```js
const fs = require('fs');

fs.writeFileSync('<Path to the file>', '<Content of the file>');
```

---

### Role and Usage of Node.js

- We use node to write server side code.

> User -> Browser(client(runs HTML,CSS,JS)) -> Request to a URL -> Server (https://my-page.com)

- Server send back response to the client

#### On the server we can do many different things ( because of node.js ):
- Database
- Authentication
- Input Validation
- Business Logic ( which may take too much time to run on the client)


Client cannot directly access the Server.



> NOTE: NodeJS is not limited to the server.
It's a JS Runtime which can be used mostly anywhere!
> - We can use it for more than server-side code like `Utility Scripts`, `Build Tools`, etc.


## Basic Node.js Role (in Web Development ):

1. `Run Server`: Create server & Listen to incoming Requests.

In PHP we have other tools like Apache and Nginx which listens to the incoming requests and executes the PHP code. Here, NodeJS does both. 

2. `Business Logic`: Handle Requests, Validate Input, Connect to Database.

3. `Responses`: Return Response (Rendwred HTML, JSON, XML, files, etc.)


### Alternative of Node.js:

- Python with Django/Flask
- PHP with Laravel/ Vanilla PHP
- Ruby
- ASP.NET

---

### Content:

- JS Refresher
- Node.js Basics & Basic Core Modules
- Parsing Requests & Sending Responses
- Rendering HTML Dynamically (on the Server)
- Using Express.js
- Templating Engine - Working with Files and generating PDFs on the Server (on-the-fly)
- Using the Model-View-Controller (MVC) Pattern
- Using Node.js with SQL (MySQL) and Sequelize
- Using Node.js with NoSQL (MongoDB) and Mongoose
- Working with Sessions & Cookies
- User Authentication and Authorization
- Sending E-Mails
- Validating User Input
- Error Handling
- File Upload and Download
- Data Pagination
- Async Request
- Handling Payments with Stripe.js
- Building REST APIs using Node.js
- Advanced REST API Features
- Authentication in REST APIs
- File Upload in REST APIs
- Using async-await
- Websockets and Socket.io
- Building GraphQL APIs
- Authentication in GraphQL APIs
- File Upload in GraphQL APIs
- Building a Realtime Node.js App with Websockets
- Automated Testing (Unit Tests)
- Deploying a Node.js Application
- SSL
- Using TypeScript with Node.js
- Exploring Deno.js

---

## The REPL

There are 2 ways to execute node.js code:
1. using `node` command in terminal to "execute a `js` file".
2. using "the `REPL`" by typing `node` into the terminal.

- R : Read - Read User Input
- E : Eval - Evaluate User Input
- P : Print - Print Output (Result)
- L : Loop - Wait or a new Input

In REPL we don't store the code in files but instead we write it line by line on the terminal.

- REPL is a good playground env., because the files are not stored anywhere! It executes code as we write it.











