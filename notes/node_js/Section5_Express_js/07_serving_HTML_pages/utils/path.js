const path = require('path');

// module.export = path.dirname(process.mainModule.filename);   // deprecated
module.exports = path.dirname(require.main.filename);   // this gives the path of the file which is responsible to run our application
