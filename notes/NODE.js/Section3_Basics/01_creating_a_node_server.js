// Core Modules in Node.js - http://nodejs.org/api/
// http - http://nodejs.org/api/http.html - Launch a server, send and receive HTTP requests.
// https - Launch a secure SSL encrypted server, send and receive HTTPS requests.
// fs - This module provides an API for interacting with the file system.
// path - This module provides utilities for working with file and directory paths.
// os - This module provides a portable way of using operating system-level functionality.

//----------------------------------------------------------------------------------------------------------------------
/*
// code to create a server. explained in detail below
const https = require('http');
const server = http.createServer(function(req,res) {
    console.log(req.url);
})
server.listen(3000);
*/
//----------------------------------------------------------------------------------------------------------------------
// using the http module - we will have to import the http module
const http = require('http');

function rqListener(req, res) {     // this function will run for every request that comes to our server
    console.log(req.url);
    // console.log(req.url);
    // res.writeHead(200, { 'Content-Type': 'text/html' });
    // res.write('<h1>Hello World</h1>');
    // res.end();
}

// function createServer(requestListener?: (request: IncomingMessage, response: ServerResponse) => void): Server
// returns a void Server object
const server = http.createServer(rqListener);

server.listen(3000);    // nodejs will keep a server running on the port we specify

//----------------------------------------------------------------------------------------------------------------------
// We can also define the function inside the createServer() function
// const http = require('http');

// http.createServer(function(req, res) {
//     console.log(req.url);
//     res.writeHead(200, { 'Content-Type': 'text/html' });
//     res.write('<h1>Hello World</h1>');
//     res.end();
// });

// next gen syntax
// http.createServer((req,res) => {

// })
//----------------------------------------------------------------------------------------------------------------------
/*
// creating a server at specified port and hostname
const http = require('http');

const hostname = '127.0.0.1';
const port = 3000;

const server = http.createServer((req, res) => {
  res.statusCode = 200;
  res.setHeader('Content-Type', 'text/plain');
  res.end('Hello World');
});

server.listen(port, hostname, () => {
  console.log(`Server running at http://${hostname}:${port}/`);
});
*/