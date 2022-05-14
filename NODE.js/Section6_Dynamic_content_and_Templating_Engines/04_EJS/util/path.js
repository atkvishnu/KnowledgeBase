const path = require('path');

module.exports = path.dirname(require.main.filename);   // dirname() returns the directory name of the current module.