# Section 2: JavaScript Basics Refresher

## JS in a nutshell

- Weakly typed Language:
    + No explicit type assignment (JS knows the basic types we don't need to declare the types explicitly).
    + Data types can be switched dynamically.
- Object-Oriented Language:
    + Data can be organized in logical objects
    + Primitive and reference types
- Versatile Language: 
    + Runs in browser and directly on a PC/server
    + Can perform a broad variety of tasks

## Core Syntax

```js
var Name = "Vishnu";  // global variables
var age = 25;
var hasHobbies = true;

// console.log("Hello " + userName);
// console.log(age);

function summarizeUser(userName, userAge, userHasHobby) {
  // this is a normal function declaration
  return (
    "Name is " +
    userName +
    ", age is " +
    userAge +
    " and the user has hobbies: " +
    userHasHobby
  );
}

x = summarizeUser(Name, age, hasHobbies);
console.log(x);
```

--- 

## let and const

var - creates a new cariable
let - also creates a new variable
const - creates constant which never changes

---

## Arrow functions

- Arrow functions are a shorter way to write functions. They use anonymous functions. 

- Arrow functions let us utilize the `this` keyword.

- If there is only one parameter, we can omit the parentheses.

- If there is only one line of code, we can omit the curly braces and the return keyword.


```js
const summarizeUser = function (userName, userAge, userHasHobby) => {
  // this is a normal function declaration
  return (
    "Name is " +
    userName +
    ", age is " +
    userAge +
    " and the user has hobbies: " +
    userHasHobby
  );
}
summarizeUser(Name, age, hasHobbies);
```

```js
// If there is only one line of code, we can omit the curly braces and the return keyword.
const add = (a, b) => a + b;
add(1, 2);
```

```js
// If there is only one parameter, we can omit the parentheses, curly braces and the return keyword.
const returnA = a => a;
returnA();
```

```js
// If there is only no parameter, then we need the parantheses.
const returnOne = () => 1;
returnOne();
```

## `this` keyword

> `this` is required to access class methods or properties from anywhere inside of that class/ object.
> `this` refers to "whoever called the code in which it's being used".

```js
button.addEventListener('click', this.addItem.bind(this));
```
What's this bind(this) thing here? And why are the function parentheses missing?
Why does the line not look like this?
```js
button.addEventListener('click', this.addItem());
```

### Calling functions and using function references

Calling a function in JS:

```js
function someFunction() {
  // do something
}
```

Inside a object/ class, you call a method in a similar way:

```js
class MyClass {
    constructor() { // code will execute the methods immediately when the code is run for the first time. 
        this.myMethod();
    }
    // In the class, the method myMethod is being executed when the constructor is called - i.e. when the class is instantiated.
    myMethod() {
        // do something
    }
}

class MyClass {
    constructor() {
        this.myMethod = function() {
            // do something
        }
    }
}

new MyClass(); // this will trigger the constructor and hence call myMethod()
```

Sometimes, we don't want to execute a function/ method immediately. We want to execute it later.
Consider a event listener on a button.

```js
function someFunction() { ... }

const button = document.querySelector('button');

button.addEventListener('click', someFunction); // `someFunction` would not wait for the click to occur but instead also execute right when the code is first parsed/ executed.
```

- We don't want to execute the function right away. We want to execute it later.
- We just want to "tell JavaScript/ the Browser" that it should execute someFunction for us when the button is clicked. This will also ensure that the function can run multiple times - one time for every button click.

- We can "give JavaScript/ the Browser" the address of something (=> a function) instead of executing it manually right away.

- This is done by passing a "reference".

For the event listener, the following code passes a reference to the "to-be-executed" function to the event listener (i.e. to the button in this case).

```js
function someFunction() { ... };

const button = ...;

button.addEventListener('click', someFunction); // NOTE: the parentheses are missing after someFunction.
```
- Therefore, we don't call the function - instead we just pass a pointer to the function (a so called reference) to the event listener (and hence to the button object).

- code looks pretty much the same as before.
```js
class MyClass {
    constructor() {
        const button = ...;
        button.addEventListener('click', this.myMethod);    // The `this` keyword is important here.
    }

    myMethod() { ... }
}
```

- `this` keyword basically points at the object that is created based on the class. And since `myMethod` is a method of the class/ object, it can only be accessed via `this`.

> That's how we pass a reference to a function instead of calling it immediately. 
> And that's why we would use this syntax without the parentheses.

### `this` behaves differently/strangely in different contexts

`this` is required to access class methods or properties from anywhere inside of that class/ object.


[link](../Section2/js-this-and-function-references/app.js)
- In this example `this` will lead to a strange keyword.
```js
class NameGenerator {
    constructor() {
        const btn = document.querySelector('button');
        this.names = ['D', 'C', 'B', 'A', '0'];
        this.currentName = 0;
        btn.addEventListener('click', this.addName);
    }

    addName() {
        const name = new NameField(this.names[this.currentName]);   // `new NameField()` renders a new <li> with the name as text into the DOM. // this line will cause an error.
        this.currentName++;
        if (this.currentName >= this.names.length) {
            this.currentName = 0;
        }
    }
}
```

This line will cause the error:
```js
const name = new NameField(this.names[this.currentName]);   // accessing this.names and this.currentName fails here.
```

Somehow, accessing `this.names` and `this.currentName` fails here.
But why? Doesn't `this` refer to the object/ class?
It actually doesn't. 
* `this` is not defined to refer to the object that encloses it when you write your code.
Instead, `this` refers to `"whoever called the code in which it's being used"`.
And in this case, the button is responsible for executing addName.
We can see that, if we log the value of this inside of addName:

```js
addName() {
  console.log(this);
  ...
}
```
This will print:
```html
<button> Add Name </button>
```

So this is now referring to the `button` element to which we attached the click event listener.
That is actually the default JavaScript behavior.

> `this` refers to whoever called a method that uses `this`.

Obviously, this is not the behavior we want here - and thankfully, we can change it.
You can bind this inside of addName to something else than the button. we can bind it to the surrounding class/ object:

```js
btn.addEventListener('click', this.addName.bind(this));
```

`bind()`
> The `bind()` method creates a new function that, when called, has its `this` keyword set to the provided value, with a given sequence of arguments preceding any provided when the new function is called.
`bind()` is a default JS method which we can call on functions/methods. It allows us to bind `this` inside of the "to-be-executed function/method" to any value of your choice.

Syntax: 
```js
myFunction.bind(thisArg)
myFunction.bind(thisArg, arg1)
myFunction.bind(thisArg, arg1, arg2)
myFunction.bind(thisArg, arg1, ... , argN)
```

In the above snippet, we bind `this` inside of `addName` to the same value `this` refers to in the constructor.

In that constructor, `this` will refer to the class/object because we execute that code on our own. The constructor essentially is always executes by the object itself. 
Hence, `this` inside of the constructor will refer to the object/ class.

`bind` will also allow you to pass arguments to the function you'll eventually call.

> Summary: If we don't have to execute a function immediately then we don't add paranthese(IIFE), We may also have to use bind(this) to make `this` works correctly in that function/method.

---

# Objects, Properties and Methods

Important Data structure in JS are Objects.
Objects are defined by `curly braces`. They have `key-value` pairs a.k.a. `properties`/`field` of the object.
- Objects are also known as "Dictionaries"/"Classes" in other languages.
- Objects can have properties of different types like strings, numbers, booleans, arrays, functions, objects, etc.
```js
const person = {
    name: 'Vishnu',
    age: 25,
    hobbies: ['Sports', 'Cooking'],
    // methods
    sayHello: () => {        // arrow functions are also methods.
        console.log('Hello ' + this.name);
    },
    greet: function() {      // methods are functions inside of objects.
        console.log('Hello ' + this.name);
    },
    // another way is to define the function directly without the key
    greet2() {  // this will also work!
        console.log('Hello ' + this.name + ' again');
    }
};

console.log(person.sayHello);

person.sayHello();  // this returns "hello undefined", because the this keyword is not defined inside the function.
// We have to use the bind method to define the this keyword OR use the old way of defining the function using function keyword.

person.greet(); // this will work, because we are using the old way of defining the function.

person.greet2();
```

---

# Arrays and Array Methods

Arrays are another main type of data structure in JS.
Arrays are a special type of object.
They are defined by square brackets.
Inside we can store multiple values of different types like strings, numbers, booleans, arrays, functions, objects, etc.

```js
const hobbies = ['Sports', 'Cooking', function() {console.log(1 + 1);}];
for (let hobby of hobbies) {        // for of loop
    console.log(hobby);
}
hobbies[2]();
```

We have a lot of built-in methods for arrays.

Methods:
- `push()`
- `pop()`
- `shift()`
- `unshift()`
- `splice()`
- `sort()`
- `reverse()`
- `concat()`
- `join()`
- `slice()`
- `indexOf()`
- `lastIndexOf()`
- `forEach()`
- `map()`
- `filter()`
- `reduce()`
- `reduceRight()`
- `every()`
- `some()`
- `find()`
- `findIndex()`
- `fill()`
- `copyWithin()`
- `entries()`
- `keys()`
- `values()`
- `includes()`