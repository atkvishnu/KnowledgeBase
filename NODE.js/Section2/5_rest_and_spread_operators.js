// In modern JS, we can use rest and spread operators to create functions that accept a variable number of arguments.

// Spread operator
// When we add a new hobbie we don't add it to the old array, we add it to a new array.
// Immutability

const hobbies = ["Sports", "Cooking"];

const copiedArray = hobbies.slice();    // slice simply copies the array, with no arguments, it copies the entire array
// we can add arguments to slice() to copy only a part of the array
console.log(copiedArray);   // ["Sports", "Cooking"]

// const copiedArray2 = hobbies.slice(0, 1); // slice(start, end)

const arrayInArray = [hobbies];     // this is not a copy, it's a new array with the old array as an element (exact same array)
console.log(arrayInArray); // [['Sports', 'Cooking']]

// spread operator
// spread operator copies all the elements of an array into a new array
const copiedArray3 = [...hobbies]; // spread operator

console.log(copiedArray3); // ["Sports", "Cooking"]

// in object
const person = {
    name: "John",
    age: 30,
    hobbies: ["Sports", "Cooking"]
};

const copiedPerson = {...person};   // spread operator
// pulls all the elements of the object into a new object
console.log(copiedPerson); // {name: "John", age: 30, hobbies: Array(2)}


// Rest operator

const toArray = (arg1, arg2, arg3) => {     // this is not flexible, what if we want to add 4 elements? for this we use the rest operator
    return [arg1, arg2, arg3];
};
console.log(toArray(1, 2, 3)); // [1, 2, 3]
console.log(toArray(1, 2, 3, 4, 5)); // [1, 2, 3]   // this is allowed in JS syntax, but it won't print the 4th and 5th element

// rest operator
const toArray2 = (...args) => {     // this is flexible, it accepts any number of arguments
    return args;
};
console.log(toArray2(1, 2, 3)); // [1, 2, 3]
console.log(toArray2(1, 2, 3, 4, 5)); // [1, 2, 3, 4, 5]

// KIM:
// Rest operator looks just like spread operator, it's the place where we have used this operator determines which operator it is! 
// If it's used to pull elements from an array/object then it's a spread operator.
// If we use it to merge multiple arguments into an array, and we use it in argument list of a function, then it's a rest operator.
