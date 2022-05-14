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

// arrow function
// we can omit the function keyword
const summarizeUser1 = (userName, userAge, userHasHobby) => {
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
console.log(summarizeUser1(Name, age, hasHobbies));

// if we have only one statement in the function body, we can also omit the curly braces
const add = (a, b) => a + b;
console.log(add(1, 2));


// if we have only one parameter, we can also omit the parenthesis
const addOne = a => a + 1;
console.log(addOne(1));


// if we have no parameters, we need the parenthesis
const sayHello = () => "Hello";
const addRandom = () => 1 + 9;
console.log(sayHello());
console.log(addRandom());