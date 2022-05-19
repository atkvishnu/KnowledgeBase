// till now we have seen function declaration and function expression.
// arrow function is a function expression that is written in the form of =>.
// arrow function is a syntactic sugar for function expression.

// converting this function to arraw fn. below
const getWinner = function (cChoice, pChoice) {
  if (cChoice == pChoice) {
    return RESULT_DRAW;
  } else if (
    (cChoice == ROCK && pChoice == SCISSORS) ||
    (cChoice == PAPER && pChoice == ROCK) ||
    (cChoice == SCISSORS && pChoice == PAPER)
  ) {
    return RESULT_COMPUTER_WINS;
  } else {
    return RESULT_PLAYER_WINS;
  }
};

// arrow function
// this is the same as the above function
const getWinner = (cChoice, pChoice) => {
  if (cChoice == pChoice) {
    return RESULT_DRAW;
  } else if (
    (cChoice == ROCK && pChoice == SCISSORS) ||
    (cChoice == PAPER && pChoice == ROCK) ||
    (cChoice == SCISSORS && pChoice == PAPER)
  ) {
    return RESULT_COMPUTER_WINS;
  } else {
    return RESULT_PLAYER_WINS;
  }
};

() => {}; // this is also an arrow function, but we cannot use it because we need to store the value of the return statement in a variable.

const x = () => {}; // this can be used

// note: arrow function is an anonymous function where we cannot assign a name in any way!

// USAGE:
// arrow function can be used as a callback function.
// arrow function can be used in map, filter, reduce, forEach, every, some, find, findIndex, includes, sort, etc.
// arrow function can be used in event handlers. (event handlers are functions that are called when an event occurs.)
// arrow function can be used in setTimeout, setInterval, requestAnimationFrame, etc.
// arrow function can be used in promise.
// arrow function can be used in class methods.
// arrow function can be used in object destructuring.
// arrow function can be used in array destructuring.
// arrow function can be used in template strings.
// arrow function can be used in rest and spread operators.
// arrow function can be used in async functions.
// arrow function can be used in generator functions.(generator.next(), generator.throw(), generator.return(), generator.next().value, generator.next().done)
// arrow function can be used in generator.

// arrow functions are shorter than function expressions, but they have some extra features.

// arrow functions are not hoisted.

// arrow functions are not bound to the (this, arguments, new, super, function, class, extends, implements, static, let, const, yield, await, static) keyword.

// ------------------------------------------
// writing this code as a ternary operation
const getWinner = function (cChoice, pChoice) {
  if (cChoice == pChoice) {
    return RESULT_DRAW;
  } else if (
    (cChoice == ROCK && pChoice == SCISSORS) ||
    (cChoice == PAPER && pChoice == ROCK) ||
    (cChoice == SCISSORS && pChoice == PAPER)
  ) {
    return RESULT_COMPUTER_WINS;
  } else {
    return RESULT_PLAYER_WINS;
  }
};

const getWinner = (cChoice, pChoice) => {
  return cChoice === pChoice
    ? RESULT_DRAW
    : (cChoice == ROCK && pChoice == SCISSORS) ||
      (cChoice == PAPER && pChoice == ROCK) ||
      (cChoice == SCISSORS && pChoice == PAPER)
    ? RESULT_PLAYER_WINS
    : RESULT_COMPUTER_WINS;
};

// since this is an arrow function, we can omit the return keyword and curly braces.
// kim: this arrow function is returning a single statement that's why we can omit the curly braces, if we had multiple statements then we would have to have curly braces.
const getWinner = (cChoice, pChoice) =>                 // curly braces and return keyword are optional and ommited here.
  cChoice === pChoice
    ? RESULT_DRAW
    : (cChoice == ROCK && pChoice == SCISSORS) ||
      (cChoice == PAPER && pChoice == ROCK) ||
      (cChoice == SCISSORS && pChoice == PAPER)
    ? RESULT_PLAYER_WINS
    : RESULT_COMPUTER_WINS;

// ------------------------------------------







// ------------------------------------------



const add = (a, b) => a + b;

const add = function (a, b) {
    return a + b;
}


// ------------------------------------------

// attention: 
// SUMMARY:

// General Syntax:     
// note: (arg1, arg2) => { ... };

// note: 4 cicumstances:

// 1. No Arguments/ Parameters:
// review: Syntax:    () => { ... };
// Empty pair of paranthesis is required.

// 2. Exactly one(1) argument/ parameter:
// review: Syntax:    arg => { ... };
// Paranthesis can be ommited.

// 3. Exactly one expression in function body:
// review: Syntax:   (a, b) => a + b;
// Curly braces can be ommited. Result of the expression is returned.
// If curly braces are removed then we have to remove the return keyword as well
// There is always a invisible return keyword in front of the function body.

// 4. More than one expression in function body:
// review: Syntax:   (a, b) => { a *= 2; return a + b; };
// Curly braces and return statement required.

// kim: Curly braces are required if there are multiple lines of code in the function body.
// kim: Curly braces are not required if there is only one line of code in the function body.


// ------------------------------------------

// Different Arrow Function Syntaxes

// 1. Default syntax:
const add = (a,b) => {
    const result = a + b;
    return result;                  // like in "normal" functions, parameters and return statement are OPTIONAL!
}
// Noteworthy: Semi-colon at end, no function keyword, parentheses around parameters/ arguments.



// 2. Shorter parameter syntax, if exactly one parameter is received:
const log = message => {
    console.log(message);       // could also return something of course - this example just doesn't return anything.
}
// Noteworthy: Parentheses around parameter list can be omitted (for exactly one argument).



// 3. Empty parameter parentheses if NO arguments are received:
const greet = ()  => {
    console.log("Hi, there!");
}
// Noteworthy: Parentheses have to be added (can't be omitted)



// 4. Shorter function body, if exactly one expression is used:
const add = (a, b) => a + b;
// Noteworthy: Curly braces and return statement can be omitted, expression result is always returned automatically


// 5. Function returns an object (with shortened syntax as shown in 4)):
const loadPerson = pName => ({name: pName});
// Noteworthy: Extra parentheses are required around the object, since the curly braces would otherwise be interpreted as the function body delimiters (and hence a syntax error would be thrown here).


// That last case can be confusing: Normally, in JavaScript, curly braces always can have exactly one meaning.
// const person = { name: 'Max' }; // Clearly creates an object
// if (something) { ... } // Clearly used to mark the if statement block



// But when using arrow functions, curly braces can have two meanings:
// 
// 1) Mark the function body (in default form)
// 
// 2) Create an object which you want to return (in shorter function body form)
// 
// To "tell" JavaScript what you want to do, wrap the expression (e.g. object creation) in parentheses like shown above.



