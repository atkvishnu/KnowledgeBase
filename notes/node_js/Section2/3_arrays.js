// array
const hobbies = [
  "Sports",
  "Cooking",
  function() {
    console.log(1 + 1);
  },
];
for (let hobby of hobbies) {
  // for of loop
  console.log(hobby);
}

hobbies[2](); // function call -> prints 2

// map() allows us to transform the elements of an array. map() returns a new array.
// map() always takes a function which tells how we want to edit our array.
console.log(hobbies.map((hobby) => "Hobby: " + hobby)); // map will return a new array, it will not change the original array
console.log(hobbies);
