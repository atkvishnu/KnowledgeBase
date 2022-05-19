const startGameBtn = document.getElementById('start-game-btn');
// kim: `document.` is a global object which gives us access to the DOM

//---------------------------------------------------------------
// objects - key: value pairs  // kim: functions defined inside a object is called as a method
// greet is a key for a method. the value of greet is a function which is called as a method
// const person = {
//     name: "Vishnu",
//     names: "Vishnu1",
//     greet: function() {
//         console.log("Hello " + this.name + "!");
//     },
// };
// person.greet();
//-------------------------------------------------------------------
// Function Declaration
// this is a normal named function declaration // this function can be called later

// startGame();        // this will work ( as the function is hoisted to the top of the file on first scan )

// function startGame() {
//     console.log("Game is starting....");
//     console.log({startGameBtn});
// }


// console.log(startGame)

// startGame();     // this will also work // direct execution

// console.dir(startGame);

// startGameBtn.addEventListener('click', startGame);  // indirect execution   //addEventListener is a method of the DOM element attached to the button object

//--------------------------------------------------------------------
// Function Expression
// when a function is stored in a variable, it is called a function expression

// start();   // doesn't works // Error: Cannot access 'start' before initialization

// const start = function startGame() { 
//     // function startGame() will not be stored in the global scope
//     // to access this function, we need to call it using the variable name
//     // startGame can also be omitted, as shown below
//     console.log("Game is starting....");
//     // console.log({startGameBtn});
// }

// start();    // works

// anonymous function
// const start = function() {   // this is now an anonymous function   
//     // this is same as the above function, because startGame is not stored in the global scope, and it's not needed to be called using the variable name
//     console.log("Game is starting....");
// };
// at the end of anonymous function, we should add a semi-colon (this is the standard)

// startGameBtn.addEventListener('click', start);  // indirect execution // we cannot call startGame() directly because it is a function expression i.e., it's inside a variable

//--------------------------------------------------------------------
// 130. Anonymous function
// We can also use anonymous fns. where we don't store them in variables like this!

// this is a prominent use case of anonymous functions, it can be used directly in the event listener
// here we are passing a reference of the anonymous function as an argument to the addEventListener function
// we are passing one function(function(){}) as an argument to another function(addEventListener)
startGameBtn.addEventListener('click', function startGame(){  // this creates the anonymous function on the fly which is attached to the event listener
    console.log("Game is starting....");
});   // this will not immediately execute the function, because it is not an IIFE. Although we can make it one by using the IIFE pattern

// startGameBtn.addEventListener('click', function() {
//     console.log("Game is starting....");
// }());  // this will immediately execute the function, because it is an IIFE. // we don't need IIFE though, we will be using the above pattern
// this will execute the fn. before we even click the button

// the anonymous function can be named for a better error catching strategy, because if any error occurs then the error will be caught by the JS engine and it will show us that the error is happening at the anonymous function.



