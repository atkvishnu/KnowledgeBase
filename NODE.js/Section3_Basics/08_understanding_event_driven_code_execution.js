// Internally Node.js manages a registry of event listeners.
// All the event listeners are stored in the registry.
// When an event is triggered, Node.js iterates through the registry and executes all the event listeners.
// The event listeners are executed in the order in which they are registered.



const http = require("http");
const fs = require("fs");

const server = http.createServer(function (req, res) {   // this is a eventListener
	const url = req.url;
	const method = req.method;
	if (url === "/") {
		// if the user visits "https://localhost:3000" button will be displayed which will send a response back to the server (whatever is present in the input field)
		res.write("<html>");
		res.write("<head><title>Enter message</title></head>");
		res.write(
			'<body><form action="/message" method="POST"><input type="text" name="message"><button type="submit">Send</button></form></body>'
		); // this form will send a POST request to the /message
		// the form will also look into the form, it will detect any inputs that are named message and will send the message to the /message route
		res.write("</html>");
		return res.end(); // return is used here because we want the server to end the response, otherwise the following code will also be sent to the user!
		// after we submit the form, the page is redirected to localhost:3000/ and the code below is shown
	}
	// if return was not used, the following code will also be executed
	if (url === "/message" && method === "POST") {
        const body = [];
        // on() allows us to listen to the incoming data
        req.on('data', (chunk) => {   // this is a eventListener
            console.log(chunk);
            body.push(chunk);   // this will push the data to the body array
        });  // this will pull all the data from the request and store it in the body array
        return req.on('end', () => {   // this is a eventListener
            const parsedBody = Buffer.concat(body).toString(); // Buffer object is available globally, this will create a new buffer object and concatenate all the data from the body array
            console.log('parsedBody : ' + parsedBody);
            const message = parsedBody.split('=')[1]; // this will split the data into an array and take the second element of the array
            fs.writeFileSync('message.txt', message);
            // moving these 3 line inside the eventListener
            res.statusCode = 302;
            res.setHeader('Location', '/');
            return res.end();
        });
	}
	res.setHeader("Content-Type", "text/html");
	res.write("<html>");
	res.write("<head><title>My First Page</title></head>");
	res.write("<body><h1>Hello from my Node.js Server!</h1></body>");
	res.write("</html>");
	res.end();
});

server.listen(3000);