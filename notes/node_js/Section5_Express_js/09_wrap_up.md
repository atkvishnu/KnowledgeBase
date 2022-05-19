# [Express.js Official Docs](https://expressjs.com/en/starter/installing.html)

# Express.js
- Express.js is Node.js framework - a package that adds a bunch of utility functions and tools and a clear set of rules and how the app should be built (middleware, routing, etc.)
- It's highly extensible and other packages can be plugged into it (middleware)!

# Middleware, next() and res()
- Express.js relies heavily on middleware functions - we can easily add them by calling use()
- Middleware functions handle a request and should call next() to forward the request to the next function in line or send a response!
- If you are sending a response DO NOT call next()
- If you are not sending a response, call next()

# Routing
- We can filter requests by path and method
- app.get() - GET requests
- app.post() - POST requests
- app.put() - PUT requests
- app.delete() - DELETE requests
- app.all() - all requests
- app.route() - a route group
- app.use() - a route group
- If we filter by method, paths are matched exactly, otherwise, the first segment of a URL is matched.
- We can use the express.Router() to split the routes across multiple files elegantly!

# Serve files
- We are not limited to serving dummy text as response.
- We can sendFile() to serve files from the file system to the users e.g., images, css, etc.
- If a request is directly made for a file (e.g., a .css file is requested), you can enable static serving for such files via. app.use(express.static())


