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

console.log(person.name);
console.log(person.sayHello);

person.sayHello();  // this returns "hello undefined", because the this keyword is not defined inside the function.
// We have to use the bind method to define the this keyword OR use the old way of defining the function using function keyword.

person.greet(); // this will work, because we are using the old way of defining the function.

person.greet2();