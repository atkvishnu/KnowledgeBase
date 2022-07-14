// Node.js Program Lifecycle

// We made a server using the http module in the last file, we executed it using `node <filename>.js`. 
// This in turn started the script. Parsed the code, Registered the variables and functions. 
// But we never closed the server because of listen command.
// Server did not close because of event loop. 
// Event loop is a loop that runs in the background and keeps the server running until there are eventListeners registered.
// We had a eventListener which we never unregistered. The function which was passed to http.createServer(<eventListener>) was the eventListener! 
// We shouldn't unregister it because we need to keep the server running.

// NodeJS uses event loop for many things. The event loop is a single threaded loop that runs in the background.
// All the process in Node.js uses a single thread.

// Behind the scenes Node.js uses multiple threads using the OS capabilities.

// If we were to eventually unregister the eventListener, the event loop would stop running. We can do this using `process.exit()` command.

const http = require('http');

const server = http.createServer(function(req, res) {
    console.log(req);
    process.exit(); // This will hard exit (stop) the event loop.
})

server.listen(3000);