// Async code and Promises

// Async code is a way to run code asynchronously.
// It is a way to run code in a non-blocking way.

/*
// setTimeout() is a function that runs a function after a certain time. It's an inbuilt nodeJS function.
setTimeout(() => {      // this is a callback function(()=>{}) - this is the oldest way of writing async code in JS
    console.log("Timer is done!")
}, 2000); // this will run after 2 seconds i.e., after 2000 milliseconds
// this is asynchronous code, it will not wait for the function to finish before it continues.

// these 2 are synchronous code!
console.log("Hello");   // this will run before the timer is done 
console.log("Hi");
// Hello and Hi will be printed in the console before the timer is done.


// using callback fns. is ok, but we will face problem if we have multiple depending async callbacks.
*/

/*
const fetchData = callback => {    // new function which gets a callback
    setTimeout(() => {
        callback('Done!');
    }, 1500);
};


setTimeout(() => {
    console.log("Timer is done!");
    // nested async call
    fetchData(text => {         // this fn. will be executed after the inner timer of fetchData is done (1500ms)
        console.log(text);
    });
}, 2000);

console.log("Hello");
console.log("Hi");
*/
// PROMISES
// to avoid this problem of nested callbacks, we can use `promises`.
// we use the new keyword to create a promise which creates a new object (constructor). 

const fetchData = () => {   // callback is removed 
    const promise = new Promise((resolve, reject) => {  // this is a promise constructor which is defined in JS
        // resolve is a function which is called when the promise is resolved.
        // reject is a function which is called when the promise is rejected.
        setTimeout(() => {
            resolve('Done!');   // in place of callback resolve is called
        }, 1500);
    });
    return promise;
};


// setTimeout(() => {
//     console.log("Timer is done!");
//     fetchData().then(text => {
//         console.log(text);
//     });
// }, 2000);

// nested async call
setTimeout(() => {
    console.log("Timer is done!");
    // nested async call
    fetchData()                     // this one gets called in the first promise
        .then(text => {
            console.log(text);
            return fetchData();     // in first then clock we returns a new promise. This may not give us a new promise, but returning it will convert it into a promise which instantly resolves! 
        })
        .then(text2 => {            // this second then block is referring to the new promise(return fetchData();) which is returned in the first then block.
            console.log(text2);
        });
}, 2000);


// there is another way of managing async code in JS i.e., async await. Used in modern JS!