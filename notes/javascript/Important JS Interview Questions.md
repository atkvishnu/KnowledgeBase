-----

### Event Delegation
#JS-EventDelegation
JS `event listeners` fire not only on a single DOM element but on all its descendants.

Event Delegation is a methodology in Javascript where instead of coding an event listener for every similar child elements in a parent element, this method will only let you create one event listener to trigger all child elements. Each child element will be differentiated or targeted by a unique ID.




-----
### Event Bubbling
#JS-EventBubbling
Inverse of event delegation. Also knows as **propogation**, events on an element will "bubble up" and also fire on all parents.


Example: tracking live editing a form

```js
function handleChange(event) {
	//track your change
	console.log(event.currentTarget.value);
}

var formEle = document.getElementByTagName('input');

for(var i = 0; i<formEle.length;i++){
	formEle[i].addEventListener('change',handleChange, false);
}
```

OR

```js
function handleChange(event) {
	//track your change
	// this time on e.target
	console.log(event.target);
}

var el = document.getElementById('form');	//attaching to the parent

el.addEventListener('change', handleChange);
```

-----
### What's the difference between "target" and "currentTarget"?
#JS-target
#JS-currentTarget

>`currentTarget` is the element with the listener attached, 
>> `target` is the actual element that triggered it.


-----
### Explain why the following doesn't work as an IIFE:
#JS-IIFE
```
function foo(){
	//
}();
```

We will get an error if we run this:
>SyntaxError: expected expression, got ')'

JS reads this function like this:
```
function foo(){
	
}

();
// JS reads this in a seperate line!
```

An IIFE (pronouced as ‘iffy’) is an abbreviation for Immediately Invoked Function Expression. It is a common Javascript design pattern used by popular JS libraries such as jQuery, Backbone.js. Purpose of using an IIFE is to maintain code inside of a local scope. This means, to be able to use global object inside of IIFE, you will need to pass it as arguments.

As for an explanation, the following code doesn’t work as an IIFE because it is a _function declaration,_ it does invoked immediately due to its parenthesis at the end, but there are downsides to using this approach.

```js
function foo() {}();
```

For the above code to be considered an IIFE, it needs to be an _anonymous function_, a function without a name, this is because IIFE needs to be Invoked Immediately without invoking it a function name. We also need to wrap the anonymous function with parenthesis, so the Javascript parser treats our anonymous function as a _function expression_.
```js
(function() {}());
```
A function expression is when you assign a function to a variable or property of an object. Anything that is a Javascript expression, including function expression, returns a value.

-----
### What needs to be changed to properly make it an IIFE?
#JS-IIFE 
```js
( function foo(){ } )();
```
Where do we use IIFE?
When we use a framework we will never need this, but when we are building a web page we will need this!
We use IIFE to `Control the variable scope`.
Example:
```js
(function foo(){ })();

console.log(foo);
```
We will get an error: ReferenceError: foo is not defined

Here foo is not gonna be printed. Because foo is not available in this scope.

-----
### Explain the difference on the usage of
```js
function foo(){
	// This is known as a definition or statement
}

var foo = function(){
	// This is an expression.
	// It resolves to a value, eve if it's just "undefined".
};
```

Function as expressions vs. definitions.

1st function is a definition
This fn. acts like a reference

2nd function is a expression
Concept of an expression: Expression is any valid unit of code that resolves to a value.

----

### Why is it, in general, a good idea to leave the global scope of a website as-is and never touch it?
#JS-global_scope

because you can't predict the future.

* Reduce collision
* Maintain independence
* Easier to write your own code


----

### Explain hoisting
#JS-hoisting

It means all variables (var) are declared at the top of any given function scope whether you like it or not(includes function declarations)
This function is an hoisted example!
```js
function foo(){
	// This is known as a definition or statement
}
```

This is not a hoisted function. We canno
```js
function hoist(track) {
	if(track === 'Down with disease') {
		var action = 'dance';
	}
	else {
		var action = 'skip';
	}
	return action;
}
```
We will get an error on line 6: 'action' is already defined

The above function 
```js
function hoist(track) {
	var action;
	if(track === 'Down with disease') {
		action = 'dance';
	}
	else {
		var action = 'skip';
	}
	return action;
}
```
var declaration "hoisted" to top. Linters don't like this but browsers don't mind.


The above function will work like this:

```js
function hoist(track) {
	if(track === 'Down with disease') {
		action = 'dance';
	}
	else {
		action = 'skip';
	}
	
	var action;	// This is fine with javascript.
	
	return action;
}
```

This is why people generally hate Javascript!

This is where ES6 comes in with `const` and `let`.
* Not hoisted.
* Scoped within the block they are in
* Gives you more control

Extra reading: `Dr. Axel Rauschmayer: "Variables and scoping in ECMAScript 6"`

----

### What's the difference between a variable that is: null, undefined or undeclared?
#JS-null
#JS-undefined
#JS-undeclared

in Javascript, **undefined** and **null** are somewhat related on what value a variable contains. The case for **undeclared** differs. It tackles on how a variable is defined and how javascript treats these variables.
Undefined basically means something has gone wrong.

* **undeclared** variables is a variable that has been declared without ‘var’ keyword.
```js
testVar = ‘hello world’;
// as opposed to  
var testVar = ‘hello world’;
```
When former code is executed, undeclared variables are created as global variable and they are configurable (ex. can be deleted).

* **undefined** is a variable that has been declared but no value exists and is a type of itself ‘undefined’.
	- Variable declared but no defined value (not initialized)
	- object/array exists but nothing at that key/index
	- function exists but doesn't return anything
	- falsy

```js
let foo;
let bar = {};
let baz = ['jonny', 'phil', 'ed'];
const qux = function() {
	//don't return anything
};

console.log(foo, bar.name, baz[4], qux());
// all of them print undefined

const quux;
// "Missing initializer in const declaration"
```

* **null** is a value of a variable and is a type of object.
	+ null has a value. It's value is null.
	+ null is a "nothing" value.
	+ It's not zero, not an expty string/object/array
	+ falsy
	+ It's just a placeholder assignment!
	+ We use ‘console.log();’ and ‘type of’ to check if a variable is undefined or null.


#### How would you go about checking for any of these states? 
#JS-typeof
> Undeclared will fiind you. LUL LUL. Except when assigning a value.
> Undefined: use `console.log(typeof foo)`

```js
let foo;

console.log(typeof foo);	// "undefined" as a string
console.log(typeof bar);	// undeclared, but also returns "undefined"

//prefereed way
console.log(foo == undefined);	// true boolean

const baz = 'undefined';
console.log(baz === undefined);	// false boolean
```

> check for null
```js
const foo = null;

console.log(typeof foo);	// object	(LUL LUL)- let that sink in for a minute. null is defined as an object. This is a bug in JS which will be rectified in future.

// preferred way
console.log(foo === null);	// true boolean
```

___


## What do you think of AMD vs CommonJS?
#JS-moduleLoader
AMD and CommonJS are both Javascript module loader. They accomplish the same task but works different.

AMD is better for browser, hence, the name ‘Asynchronous’, as it loads each distinct module in async manner instead of loading in one large file. No extra steps are required to use AMD, it works out-of-the-box. In my opinion, as it is its in Asynchronous nature, it makes alot of async http requests and may not be as performant as described by other devs.

While, CommonJS, is a standard, mostly used in servers and it loads modules synchronously, though extra step is required if you want your JS file size to be minified and compressed.

**_Why do we need to use Javascript module loader?_**

Usually, JS files are loaded in order via script tag in HTML templates, but files and code gets complicated once an application becomes large. Javascript module loaders lets us separate our code into modules and include a specific module in another module. This lets us import what module is required and load only the necessary. Better Javascript file size load and better code compartmentalization, means, JS module loader mitigates away the danger of global-namespace issue.

----

## Explain how prototypal inheritance works
#JS-PrototypalInheritance
Everything in Javascript is an object. Even when creating a Class is an Object via an _Object Literal_ or _Constructor Function_. This is how Javascript does class-based programming as to other traditional Object-Oriented Programming languages where they use the keyword ‘class’ and ‘inheritance’.

Javascript’s version of class-based programming and other traditional class-based programming languages work with the same concept but does not work exactly similar. There are differences in its keyword, syntax, and how it works. There are also debates regarding pros and cons of Javascript’s version of class-based programming, but for simplicity’s sake and learning purposes, I do not want to go over those issues.

So, the core idea of Prototypal Inheritance is that an object can point to another object and inherit all its properties. The main purpose is to allow multiple instances of an object to share common properties, hence, the Singleton Pattern.
Below is a sample code with comments and caption to better see how it works:

After going through the code, its best to read further about Prototypal Inheritance from mozilla doc. Code example below is just one of many ways of implementing Prototypal Inheritance.

```html
<h1>Learn Prototypal Inheritance with ME!</h1>
<h3>Open your console please</h3>
```

```js
// Say we created an object that we are going to consider as a class
var classObject = function() {
  console.log("i am at the very top coz i am a class object");
};
// and we’ve also added a function to our classObject
classObject.classMethod = function() {
 console.log("I do as I am told");
}
// Note: classObject is an object, not an instance

// Now we are going to create an instance of classObject via new keyword.
var otherObject = new classObject();
otherObject.classMethod = function() {
  console.log("I do bare minimum as required.");
}

console.log('call 1');
otherObject.classMethod(); // calls the Instance object method

/*
  Question is, Does this inherit the classMethod from classObject?
  Answer is, No
  What this does is it creates a Static Method
  this can also be created even without first instantiating the object
  wth is Static Method? Don’t fret
  this just means, the method will only exist in Class and not on its child objects
  This is the same as, when we add a function to an instance, it will only apply to that particular instance
*/

console.log('call 2');
classObject.classMethod(); // calls the Static object method

/*
  Now we are getting to the good part
  When we declare prototype, all created instances from here on will now have the static method
*/
classObject.prototype.classMethod = classObject.classMethod;

console.log('call 3');
otherObject.classMethod(); // still calls the Instance object method

/*
  We created another object and instantiated a new classObject
  this should now inherited the static method
*/
var anotherObject = new classObject();

console.log('call 4');
anotherObject.classMethod(); // now, we inherited classObject's method, classMethod
```

----

### Explain how this works in JavaScript
#JS-this_Keyword
**_‘this’_** refers to itself, to its own object or global object.

Using **_‘this’_** are partitioned in 3 locations of code. These are **in functions**, **outside of functions** (global scope, ex: window object), and **in Javascript’s eval() function**.

Common pitfalls when using **_‘this’_** are usually relevant to scope issues in **real functions**, **methods**, and **constructors**. Though there are ways to fix these common issues by using ES5, bind() or ES6 arrow functions, =>

----

### [Difference between == and === in JavaScript ](https://stackoverflow.com/questions/523643/difference-between-and-in-javascript)
#JS-equalsSignDifference

The 3 equal signs mean "equality without type coercion". Using the triple equals, the values must be equal in type as well.

```javascript
0 == false   // true
0 === false  // false, because they are of a different type
1 == "1"     // true, automatic type conversion for value only
1 === "1"    // false, because they are of a different type
null == undefined // true
null === undefined // false
'0' == false // true
'0' === false // false
```

```js
let foo;	// undefined
const bar = null;	// null

//compare the two
console.log(foo == bar);	// true boolean	-> double equals(==) checks for equality
```

> double equals( == ) checks for equality
> triple equals ( === ) checks for equality and type

------
### Javascript is single threaded

JavaScript is a single-threaded synchronous programming language.
It means that the main thread where JavaScript code is run, runs in one line at a time manner and there is no possibility of running code in parallel.

![[https://media.geeksforgeeks.org/wp-content/uploads/20201130202346/singlethreadedjavascript.png]]

```javascript
console.log("Before delay");

function delayBySeconds(sec) {
	let start = now = Date.now()
	while(now-start < (sec*1000)) {
		now = Date.now();
	}
}

delayBySeconds(5);

//Executes after delay of 5 seconds
console.log("After delay");
```

Output:
Before delay
(... waits for 5 seconds)
After delay

----------
# Memory allocation in JavaScript:
#JS-heapMemory
#JS-stackMemory
**1) Heap memory:** Data stored randomly and memory allocated.

![[https://media.geeksforgeeks.org/wp-content/uploads/20201130212753/Heapmemory.png]]

**2) Stack memory:** Memory allocated in the form of stacks. Mainly used for functions.

![[https://media.geeksforgeeks.org/wp-content/uploads/20201130212825/stackmem.png]]



-----
### Function Call Stack
#JS-callStack 
**Function call stack:** The function stack is a function which keeps track of all other functions executed in run time. Ever seen a stack trace being printed when you ran into an error in JavaScript. That is nothing but a snapshot of the function stack at that point when the error occurred.
Example:

```javascript
function LevelTwo() {
	console.log("Inside Level Two!")
}

function LevelOne() {
	LevelTwo()
}

function main() {
	LevelOne()
}

main()
```

![[https://media.geeksforgeeks.org/wp-content/uploads/20201130214516/functionStack.png]]

Order at which functions get executed i.e get popped out of the stack after a function’s purpose gets over as shown below:

![[https://media.geeksforgeeks.org/wp-content/uploads/20201130215236/functionStack.png]]




----

### What is the event loop?
#JS-EventLoop 
An event loop is something that pulls stuff out of the queue and places it onto the function execution stack whenever the function stack becomes empty.

![[https://media.geeksforgeeks.org/wp-content/uploads/20201130232637/EventLoop.png]]

The event loop is the secret by which JavaScript gives us an illusion of being multithreaded even though it is single-threaded. The below illusion demonstrates the functioning of event loop well:
![[https://media.geeksforgeeks.org/wp-content/uploads/20201130234341/eventQueue1.png]]

Here the callback function in the event queue has not yet run and is waiting for its time into the stack when the setTimeOut() is being executed and the Web API is making the mentioned wait. When the function stack becomes empty, the function gets loaded onto the stack as shown below:

![[https://media.geeksforgeeks.org/wp-content/uploads/20201130231618/eventQueue1.png]]

That is where the event loop comes into picture, it takes the first event from the Event Queue and places it onto the stack i.e in this case the callback function. From here, this function executes calling other functions inside it, if any.

![[https://media.geeksforgeeks.org/wp-content/uploads/20201130232227/eventQueue1.png]]

This cycle is called the **event loop** and this how JavaScript manages its events.







----

### What is the difference between call stack and task queue?
#JS-callStack
#JS-taskQueue

in JavaScript there is function called timeout. when you call the function timeout on the "call stack" it would register in "job queue". It won't fire immediately, but will be triggered once the time is reached.
[https://en.wikipedia.org/wiki/Job_queue](https://en.wikipedia.org/wiki/Job_queue)

```javascript
timeout(function(){
    console.log("one");
}, 100);

console.log("two");
```

in call stack, `console.log("one")` is triggered first, but in job queue, the result will display after `two`.
[https://en.wikipedia.org/wiki/Call_stack](https://en.wikipedia.org/wiki/Call_stack)