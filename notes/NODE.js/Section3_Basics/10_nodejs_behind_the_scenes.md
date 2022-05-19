# Single thread, Event Loop, & Blocking Code

Node.js uses a single thread to run the event loop.

Q. How is it able to handle multiple requests at the same time?
A. It uses the event loop to handle multiple requests at the same time. Node.js starts the `event loop` at the start of the program. The event loop `Handles Event Callbacks`. 
Long running code (like big files) is not run in the main thread. They are sent to the `Worker Pool`. Worker Pool is also spun up when the program starts. Worker Pool is `responsible for all the heavy lifting`!
`Worker Pool` `internally uses multiple threads` to handle the requests.
Worker pool is a pool of threads. 

Once the heavy lifting task assigned to the worker pool is done, the worker pool gives the task back to the event loop (by `triggering a Callback` to the Event loop). 

This all happens behind the scenes.

# Event Loop
- Event loop is a `callback queue` that is used to handle the callbacks. 
- It is started at the start of the program. 
- It handles all the callbacks. 
- It keeps the process running.
- It has a certain order through which it handles the callbacks.

- `Timers` phase - At the beggining of each new iteration, it checks if there are any `Timers` `callbacks` that needs to be executed! [Executes `setTimeout` and `setInterval` `callbacks`]. (In Node.js we can set timers just like JS, it requires a function which is executed once the timer expires).

- `Pending Callbacks` phase - As the next step, it checks for any other pending callbacks that needs to be executed. [Execute `I/O-related callbacks` that were deferred]. (I/O related callbacks are `readFile`, `writeFile`, `readdir`, `readlink`, `readdir`, `readFileSync`, `writeFileSync`) (I/O means all the Disk and Network Operations (~Blocking Operations (which take a long time))).

- `Poll` phase - `After finishing all the callbacks`, it `enters` the `Poll phase`. In this phase, it checks if there are any NEW `I/O events` that needs to be executed. If it's not the case (if there are any pending callbacks), it will defer the execution and register it as a pending callback. If there are any Timer callbacks, it will jump to Timer Execution and execute them right away!

- `Check` phase - Executes `setImmediate()` callbacks. It's just like setTimeout and setInterval, but it's executed right away, but always after any open callbacks have been executed. It's typically faster than setTimeout but it's executed after ~1ms of delay after all the callbacks are done.

- `Close Callbacks` phase - Executes all close event callbacks! (`close`, `end`, `error`, `exit`, `SIGINT`, `SIGTERM`, `SIGUSR1`, `SIGUSR2`). Close events are handles seperately.

- Next we may exit the Node.js program only if there are no remaining eventHandlers which are registered (refs == 0). Internally Node.js keeps track of all the eventListeners, it has a counter(refs) for each eventListener. If the counter reaches 0, it means that there are no more eventListeners registered for that event. 
If (eventListener-- -> refs--) || If (eventListener++ -> refs++).

- `Exit` phase - When the event loop is empty, it exits the program. (If `process.exit()`).

---

All the `phases of event loop`:
- Timers
- Pending Callbacks
- Poll
- Check
- Close Callbacks
- Exit

---

Bigger Picture: 
Incoming Requests -> Our code (single JS thread) -> Starts Event Loop(Handles Event Callbacks) -> Starts Worker Pool(Does the heavy lifting) -> Worker Pool uses different threads (when heavy lifting work is done it informs the event loop about it by sending a trigger callback).

---




