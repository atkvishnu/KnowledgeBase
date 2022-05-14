// Destructuring is a way to extract data from a data structure.
// We can destructure an array or an object.

const person = {
    name: "Vishnu",
    age: 25,
    hobbies: ["Sports", "Cooking"]
};

const printName = (personData) => {     // we have made this fn. flexible, it can accept any arguments
    console.log(personData.name);
}

printName(person);

// curly braces are used to destructure an object
const printNameDestructuring = ({ name, age }) => {  // property name will be pulled from the object, and other properties will be ignored
    console.log(name);   // destructuring
    console.log(age);
}
printNameDestructuring(person);

// this syntax is not seen in JS much, but this can be used for destructuring arrays
const { name, age } = person;
console.log(name, age); // ["Vishnu", 25]   // these values are obtained via destructuring

// we can also destructure arrays
const hobbies = ["Sports", "Cooking"];
let [hobby1, hobby2] = hobbies; // elements are pulled according to their position in the array. i.e, hobby1 points to 1st element, hobby2 points to 2nd element of the array
console.log(hobby1, hobby2); // Sports Cooking  // we are not logging an array, we are logging the elements of the array



