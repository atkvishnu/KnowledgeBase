// parsing the message which was sent by the user!
// the incoming data is sent as a stream of data, so we need to parse it
// --------------------------------------------------------------------------------------------------------------------
// STREAMS AND BUFFERS (https://www.udemy.com/course/nodejs-the-complete-guide/learn/lecture/11561900#questions)
// Let's take an Incoming request as an example
// 
// Streams is an ongoing data flow (data is sent in chunks(multiple parts)), it is a sequence of data that is sent to the server and then received by the server and then sent back to the client
// Stream -> Request Body Part 1 -> Request Body Part 2 -> Request Body Part 3 -> ...... -> Fully Parsed 
// How do we work with flow data?
// To organize these incoming chunks we need to use a BUFFER!
// Buffer is a construct which allows us to hold multiple chunks and work with them as a single unit. We work with these buffers in our code!
// --------------------------------------------------------------------------------------------------------------------


const http = require("http");
const fs = require("fs");

const server = http.createServer(function (req, res) {
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
        req.on('data', (chunk) => {
            console.log(chunk);
            body.push(chunk);   // this will push the data to the body array
        });  // this will pull all the data from the request and store it in the body array
        req.on('end', () => {
            const parsedBody = Buffer.concat(body).toString(); // Buffer object is available globally, this will create a new buffer object and concatenate all the data from the body array
            console.log('parsedBody : ' + parsedBody);
            const message = parsedBody.split('=')[1]; // this will split the data into an array and take the second element of the array
            fs.writeFileSync('message.txt', message);
        });
        // if this is the case we want to redirect the user to the / route, and we want to create a new file and store the message the suer entered in it
		// we will use the fs module to create a new file and write the message to it
        // fs.writeFileSync('message.txt', 'DUMMT TEXT');
        // res.writeHead(302, {'Location': '/'});
        // OR we can do it separately
        res.statusCode = 302;
        res.setHeader('Location', '/');
        return res.end();
	}
	res.setHeader("Content-Type", "text/html");
	res.write("<html>");
	res.write("<head><title>My First Page</title></head>");
	res.write("<body><h1>Hello from my Node.js Server!</h1></body>");
	res.write("</html>");
	res.end();
});

server.listen(3000);
