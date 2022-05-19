/**
 * 
 * Stacks - LIFO - using arrays
 * 
 * functions: push, pop, peek, clear, length
 * 
 * Stack functional components
 */

//=========================================================================================
// Creates a stack using an array
var Stack = function() {
    this.dataStore = [];
    this.top = 0;
    this.push = push;
    this.pop = pop;
    this.peek = peek;
    this.clear = clear;
    this.length = length;

    function push(element) {
        // push element onto stack
        this.dataStore[this.top++] = element;
        this.length++;
    }

    function pop() {
        // remove element from stack
        return this.dataStore[--this.top];
    }

    function peek() {
        // return top element
        return this.dataStore[this.top - 1];
    }

    function clear() {
        // remove all elements from stack
        this.top = 0;
        this.length = 0;
    }

    function length() {
        // return number of elements in stack
        return dataStore.length();
    }

};

let x = new Stack();
x.push("hello");
x.push("saras");
x.push("gmail");
console.log(x.peek());
// console.log(x.length());
console.log(x.pop());
console.log({x});
console.log(x.dataStore);
console.log(x.pop());
console.log(x.dataStore);
//=========================================================================================

// stack using object
// var Stack = function () {
//   this.count = 0; // keeps count of `number of elements in stack`
//   this.storage = {}; // object literal

//   // Adds a value to the end of the stack
//   this.push = function (value) {
//     this.storage[this.count] = value;
//     this.count++;
//   };

//   // Removes and returns the value at the end of the stack
//   this.pop = function() {
//     if (this.count == 0) {
//       return undefined;
//     }

//     this.count--; // decrement count
//     var result = this.storage[this.count]; // store the value of the last element
//     delete this.storage[this.count]; // delete the last element
//     return result;
//   };

//   this.length = function () {
//     return this.count;
//   };

//    this.clear = function() {
//        this.storage = {};
//        this.count = 0;
//    }

//   this.peek = function () {
//     return this.storage[this.count - 1];
//   };
// };

// var myStack = new Stack();

// myStack.push(1);
// myStack.push(2);
// console.log(myStack.peek());
// // console.log(myStack.pop());
// myStack.push("Hello World");
// // console.log(myStack.peek());
// console.log(myStack);

//=========================================================================================

// // exp
// var x = {'float': 'right'};
// var x = new Object();
// x.float = 'right';
// console.log(x);
// console.log(x['float']);
