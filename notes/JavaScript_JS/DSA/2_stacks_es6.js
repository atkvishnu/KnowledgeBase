/**
 * 
 * Stack class using an array
 * Language: Javascript (ES6)
 * Author: Kumar Vishnu
 * 
 */

class Stack {

    constructor() {
        this.stack = []
        this.top = 0
    }

    push(data) {
        this.stack.push(data);
        this.top++;
    }

    pop() {
        if(this.top != 0) {
            this.top--;
            return this.stack.pop();
        }
        throw new Error("Stack is empty! \n")
    }

    get length() {
        return this.top;
    }

    get isEmpty() {
        return this.top === 0;
    }

    get last() {
        if(this.top!=0) {
            return this.stack[this.stack.length-1];
        }
        throw new Error("Stack is empty! \n")
    }

    static isStack(el) {
        return el instanceof Stack;
    }
}

export { Stack }