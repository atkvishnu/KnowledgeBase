# How the web works.

Client => Request => Server => Response => Client

---

# Program Lifecycle and Event Loop

- Node.js runs non-blocking JS code and uses an event-driven code ("Event Loop") for running our logic!
- A Node program exits as soon as there is no more work to do.
- NOTE: The createServer() event never finishes by default!

---

# Asynchronous Code
- JS code is non-blocking.
Use callback and events => order changes!

---

# Request and Responses
- We have to parse request data in chunks (Stream and Buffers).
- Avoid "double responses"!

---

# Node.js and Code Modules
- Node.js ships with multiple core modules (http, fs, path, ......)
- Core modules can be imported into any file to be used there
- Import via require('module')

---

# The Node Module System
- Import via require('./path-to-file') for custom files or require('module') for core modules and third-party modules.
- Export via. module.exports or just exports (for multiple exports)

---

Useful resources:

- Official Node.js Docs: https://nodejs.org/en/docs/guides/
- Full Node.js Reference (for all core modules): https://nodejs.org/dist/latest/docs/api/
- More about the Node.js Event Loop: https://nodejs.org/en/docs/guides/event-loop-timers-and-nexttick/
- Blocking and Non-Blocking Code: https://nodejs.org/en/docs/guides/dont-block-the-event-loop/