# Using NPM

- npm init - put default texts/ anything you want
- package.json is added

- In package.json in scripts
ATTENTION: 
"scripts": {
    "start": "node app.js",
    "start-server": "node app.js",
}

---------------------------------

# Installing 3rd party packages - Express, body-parser, ....

Available via. npm repository

- 3rd party app to restart server after changes - nodemon

- ATTENTION: npm install nodemon --save-dev

- npm install express --save
- npm install body-parser --save




# HEADING: Global Features vs Core Modules vs Third-Party Modules

- Global Features: (npm install -g nodemon) Global features are always available, you don't need to import them into the files where you want to use them.

- Core Modules: Core Node.js Modules don't need to be installed (NO npm install is required) but you need to import them when you want to use features exposed by them.
Example: Examples would be the file-system module ("fs"), the path module ("path") or the Http module ("http")
const fs = require('fs');
You can now use the fs object exported by the "fs" module.

- Third-party Modules: Installed via npm install - you can add any kind of feature to your app via this way. Third-party Modules need to be installed (via npm install in the project folder) AND imported.
Example:
In terminal/ command prompt: ```npm install --save express-session```
In code file (e.g. app.js): ```const sessions = require('express-session');```

# 

- production dependencies (--save)
- development dependencies (--save-dev)
- global dependencies (-g)







# HEADING: Using Nodemon for Autorestarting Server
- Change the scripts in package.json
```js
"scripts": {
    "start": "nodemon app.js",
    "start-server": "node app.js",
}
```





# HEADING: Global and Local NPM Packages

- The good thing about local dependencies is that you can share projects without the node_modules folder (where they are stored) and you can run npm install in a project to then re-create that node_modules folder. 

- This allows you to share only your source code, hence reducing the size of the shared project vastly.
You could install nodemon globally if you wanted (this is NOT required though - because we can just run it locally): npm install -g nodemon would do the trick. 

- Specifically the -g flag ensures that the package gets added as a global package which you now can use anywhere on your machine, directly from inside the terminal or command prompt.



# HEADING: Different Error types
- Syntax Error: Error thrown when there is a syntax error in the code.
- Runtime Error: Error thrown when there is a runtime error in the code.
- Logical Error: Error thrown when there is a logical error in the code.
- Reference Error: Error thrown when there is a reference error in the code.


# Useful resources:

- More on debugging Node.js: https://nodejs.org/en/docs/guides/debugging-getting-started/
- Debugging Node in Visual Studio Code: https://code.visualstudio.com/docs/nodejs/nodejs-debugging