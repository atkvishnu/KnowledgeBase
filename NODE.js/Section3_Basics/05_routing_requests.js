// connecting request and response

// when user visits "https://localhost:3000", we want the user to enter some data which we will send back as a response.
//

const http = require("http");

const server = http.createServer(function (req, res) {
  const url = req.url;
  if (url === "/") {    // if the user visits "https://localhost:3000" button will be displayed which will send a response back to the server (whatever is present in the input field)
    res.write("<html>");
    res.write("<head><title>Enter message</title></head>");
    res.write(
      '<body><form action="/message" method="POST"><input type="text" name="message"><button type="submit">Send</button></form></body>'
    ); // this form will send a POST request to the /message
    // the form will also look into the form, it will detect any inputs that are named message and will send the message to the /message route
    res.write("</html>");
    return res.end();       // return is used here because we want the server to end the response, otherwise the following code will also be sent to the user! 
    // after we submit the form, the page is redirected to localhost:3000/ and the code below is shown      
  }
  // if return was not used, the following code will also be executed
  res.setHeader("Content-Type", "text/html");
  res.write("<html>");
  res.write("<head><title>My First Page</title></head>");
  res.write("<body><h1>Hello from my Node.js Server!</h1></body>");
  res.write("</html>");
  res.end();
});

server.listen(3000);
