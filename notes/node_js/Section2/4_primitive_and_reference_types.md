# Reference types
Objects and Arrays are reference types.
Objects and arrays store primitive values(inside them) in memory.

We can edit the values of the arrays without violating the immutability of the array.

```js
// object - reference type
const obj = {
  name: 'John',
  age: 30
};
```


```js
// array
const hobbies = ['Sports', 'Cooking'];
hobbies.push('Programming');
console.log(hobbies);   // ['Sports', 'Cooking', 'Programming']
// Array.push() adds an element to the end of the array.
// The reason why we can edit the array without violating the immutability of the array is because the array is a reference type. Reference types only store the address of the object pointing to the place in memory where the object of the array is stored. The address doesn't change when we edit the array.
```

Numbers, Strings, Booleans, undefined and null are primitive types.



---

JS has 2 types of memory: Stack and Heap.

`Stack`: Stack is a easy-to-access memory that manages it's items in a LIFO(Last In First Out) manner.

`Heap`: The heap is a memory for items of which you can't pre-determine the exact size and structure. Since objects and arrays can be mutated and change at runtime, they have to go into the heap.
For each heap item, the exact address is stored in a pointer which points at the item in the heap.
This pointer is stored on the stack.

---

# Strange Behavior of "Reference Types"

What's actually stored in the person variable in the following snippet?
```js
var person = { name: 'Max' }
```
Is it: 
a) The object ({ name: 'Max' })
b) The pointer to the object
c) A pointer to the name property?

It's b). A pointer to the person object is stored in the variable. The same would be the case for the hobbies array.

What does the following code spit out then?
```js
var person = { name: 'Max' }
var newPerson = person
newPerson.name = 'Anna'
console.log(person.name) // What does this line print?
```
You'll see 'Anna' in the console!

Why?

Because you never copied the person object itself to newPerson. You only copied the pointer! It still points at the same address in memory though. Hence changing newPerson.name also changes person.name because newPerson points at the exactly same object!

It's the same for arrays.
```js
var hobbies = ['Sports', 'Cooking']
var copiedHobbies = hobbies
copiedHobbies.push('Music')
console.log(hobbies[2]) // What does this line print?
```
You'll see 'Music' in the console!

# How can you copy the actual Value?
We only copy the pointer - how can we actually copy the value behind the pointer? The actual object or array?

You basically need to construct a new object or array and immediately fill it with the properties or elements of the old object or array.

You got multiple ways of doing this - also depending on which kind of JavaScript version you're using (during development).

# Here are the two most popular approaches for arrays:

# 1) Use the slice() method
`slice()` is a standard array method provided by JavaScript. You can check out its full documentation here.
```js
var hobbies = ['Sports', 'Cooking']
var copiedHobbies = hobbies.slice()
```
It basically returns a new array which contains all elements of the old element, starting at the starting index you passed (and then up to the max number of elements you defined). If you just call slice(), without arguments, you get a new array with all elements of the old array.

# 2) Use the spread operator
If you're using ES6+, you can use the spread operator.
```js
var hobbies = ['Sports', 'Cooking']
var copiedHobbies = [...hobbies]
```
Here, you also create a new array (manually, by using []) and you then use the spread operator (...) to "pull all elements of the old array out" and add them to the new array.

# For objects
# 1) Object.assign()
You can use the `Object.assign()`.
```js
var person = { name: 'Max' }
var copiedPerson = Object.assign({}, person)
```
This syntax creates a new object (the {} part) and assigns all properties of the old object (the second argument) to that newly created one. This creates a copy.

# 2) Spread operator
Just as with arrays, you can also use the spread operator on objects.
```js
var person = { name: 'Max' }
var copiedPerson = { ...person }
```
This will also create a new object (because you used { }) and will then pull all properties of person out of it, into the brand-new objects.






