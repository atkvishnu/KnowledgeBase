/**
 * 
 * Stacks - LIFO - using arrays
 * 
 * functions: push, pop, peek, length
 * 
 */



// arrays have all the functions of a stack
var letters = [];   // stack

var word0 = "hello";
var word1 = "saras";
var word2 = "gmail";

var rword = "";

let x = word2;      // x placeholder

// push letters onto stack
for(var i = 0; i < x.length; i++) {
    letters.push(x[i]);
}

// pop letters off stack
for(var i = 0; i < x.length; i++) {
    rword += letters.pop();
}

if (rword == x) {
    console.log("The word, " + x + ", is a palindrome.");
} else {
    console.log("The word, " + x + ", is not a palindrome.");
}






