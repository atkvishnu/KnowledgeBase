/* 20 string operations/methods in javascript */

var stringOne = "Hello World!";
var stringTwo = "Namaste World!";

/** 
 * note: charAt() - returns the character at the specified index
 * Syntax: string.charAt(index);
 * Parameters: index - the index of the character to be returned
 * Return: the character at the specified index
 */

// var x = stringOne.charAt(0); // returns H
// console.log(x);
// console.log("\n");



/** 
 * note: charCodeAt()
 * Syntax: string.charCodeAt(index);
 * Parameters: index - the index of the character to be returned
 * Return: the character code at the specified index
 */

// var x = stringOne.charCodeAt(0); // returns 72
// console.log(x);
// console.log("\n");




/** 
 * note: endsWith()
 * Syntax: string.endsWith(searchString, position);
 * Parameters: searchString - the string to search for
 *             position - the index at which to start the search
 * Return: true if the string ends with the specified string
 */

// x = stringOne.endsWith("!"); // returns true
// console.log(x);
// console.log("\n");

/** 
 * note: fromCharCode()
 * Syntax: String.fromCharCode(charCode);
 * Parameters: charCode - the character code to be converted to a string
 * Return: the string corresponding to the character code
 */

// let x = String.fromCharCode(48); // returns H
// console.log(x);

// for (var i = 48; i < 123; i++) {
//     let x = String.fromCharCode(i); // returns H
//     console.log(x + "\n");
// }
// console.log("\n");


/**
 *  note: includes()
 * Syntax: string.includes(searchString, position);
 * Parameters: searchString - the string to search for
 *             position - the index at which to start the search
 * Return: true if the string contains the specified string
 */


console.log(stringOne.includes("Hello", 0)); // returns true
console.log(stringOne.includes("Hello", 1)); // returns false

console.log(stringOne.includes("World", 6)); // returns true
console.log("\n");


/**
 * note: indexOf()
 * Syntax: string.indexOf(searchString, position);
 * Parameters: searchString - the string to search for
 *             position - the index at which to start the search
 * Return: the index of the first occurrence of the specified string
 */

console.log(stringOne.indexOf("ello"));     // returns 1
console.log(stringOne.indexOf("ello", 2));  // returns -1
console.log("\n");



/** 
 * note: lastIndexOf()
 * Syntax: string.lastIndexOf(searchString, position);
 * Parameters: searchString - the string to search for
 *             position - the index at which to start the search
 * Return: the index of the last occurrence of the specified string
 */

console.log(stringTwo.lastIndexOf("aste"));     // returns 2
console.log("\n");


/** 
 * note: match()
 * Syntax: string.match(regexp);
 * Parameters: regexp - the regular expression to match
 * Return: the array of matches
 */

console.log("match() method:");
console.log(stringOne.match(/ello/));
console.log("\n");

/** 
 * note: repeat()
 * Syntax: string.repeat(count);
 * Parameters: count - the number of times to repeat the string
 * Return: the repeated string
 */

console.log("repeat() method: ");
console.log(stringOne.repeat(3));
console.log("\n");


/**
 * note: replace()
 * Syntax: string.replace(searchValue, replaceValue);
 * Parameters: searchValue - the string to search for
 *             replaceValue - the string to replace the search value
 * Return: the string with the specified replacements
 */

console.log(stringOne.replace("Hello", "Namaste"));
console.log("\n");

/**
 * note: search()
 * Syntax: string.search(regexp);
 * Parameters: regexp - the regular expression to search for
 * Return: the index of the first match
 */

console.log(stringOne.search(/World!/));    // returns 6
console.log("\n");

/**
 * note: slice()
 * Syntax: string.slice(start, end);
 * Parameters: start - the index at which to start the slice
 *             end - the index at which to end the slice
 * Return: the new string
 */

console.log(stringOne.slice(0, 5));
console.log("\n");

/**
 * note: split()
 * Syntax: string.split(separator, limit);
 * Parameters: separator - the string to split on
 *             limit - the maximum number of items to return
 * Return: the array of strings
 */

console.log(stringOne.split("ello"));
console.log(stringOne.split(" "));
console.log("\n");

/**
 * note: startsWith()
 * Syntax: string.startsWith(searchString, position);
 * Parameters: searchString - the string to search for
 *             position - the index at which to start the search
 * Return: true if the string starts with the specified string
 */

console.log(stringOne.startsWith("Hello", 0));  // returns true
console.log("\n");

/**
 * note: substr()
 * Syntax: string.substr(start, length);
 * Parameters: start - the index at which to start the substring
 *             length - the length of the substring
 * Return: the new string
 */

console.log(stringOne.substr(0, 5));
console.log("\n");

/**
 * substring()
 * Syntax: string.substring(start, end);
 * Parameters: start - the index at which to start the substring
 *             end - the index at which to end the substring
 * Return: the new string
 */

console.log(stringOne.substring(0, 5));
console.log("\n");

/**
 * note: toLowerCase()
 * Syntax: string.toLowerCase();
 * Parameters: none
 * Return: the string in lowercase
 */

console.log(stringOne.toLowerCase());
console.log("\n");

/**
 * note: toUpperCase()
 * Syntax: string.toUpperCase();
 * Parameters: none
 * Return: the string in uppercase
 */

console.log(stringOne.toUpperCase());
console.log("\n");


/**
 * note: trim()
 * Syntax: string.trim();
 * Parameters: none
 * Return: the string with whitespace removed from both ends
 */

let stringThree = "   Hello World!   ";
console.log("<" + stringThree + ">");
console.log(stringThree.trim());