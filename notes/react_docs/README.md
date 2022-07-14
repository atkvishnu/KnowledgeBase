What Is React?
React is a declarative, efficient, and flexible JavaScript library for building user interfaces. It lets you compose complex UIs from small and isolated pieces of code called “components”.
We’ll start with React.Component subclasses:

class ShoppingList extends React.Component {
  render() {
    return (
      <div className="shopping-list">
        <h1>Shopping List for {this.props.name}</h1>
        <ul>
          <li>Instagram</li>
          <li>WhatsApp</li>
          <li>Oculus</li>
        </ul>
      </div>
    );
  }
}
// Example usage: <ShoppingList name="Mark" />


Here, ShoppingList is a React component class, or React component type. A component takes in parameters, called props (short for “properties”), and returns a hierarchy of views to display via the render method.
The render method returns a description of what you want to see on the screen. React takes the description and displays the result. In particular, render returns a React element, which is a lightweight description of what to render. 
Most React developers use a special syntax called “JSX” which makes these structures easier to write.
The <div /> syntax is transformed at build time to React.createElement('div'). The example above is equivalent to:
return React.createElement('div', {className: 'shopping-list'},
  React.createElement('h1', /* ... h1 children ... */),
  React.createElement('ul', /* ... ul children ... */)
);

JSX comes with the full power of JavaScript. You can put any JavaScript expressions within braces inside JSX. Each React element is a JavaScript object that you can store in a variable or pass around in your program.

The ShoppingList component above only renders built-in DOM components like <div />and <li />. But you can compose and render custom React components too. For example, we can now refer to the whole shopping list by writing <ShoppingList />. Each React component is encapsulated and can operate independently; this allows you to build complex UIs from simple components.


This Starter Code is the base of what we’re building. We’ve provided the CSS styling so that you only need to focus on learning React and programming the tic-tac-toe game.
By inspecting the code, you’ll notice that we have three React components:
⦁	Square
⦁	Board
⦁	Game

The Square component renders a single <button> and the Board renders 9 squares. The Game component renders a board with placeholder values which we’ll modify later. There are currently no interactive components.

Passing Data Through Props
passing some data from our Board component to our Square component.
In Board’s renderSquare method, change the code to pass a prop called value to the Square:
class Board extends React.Component {
  renderSquare(i) {
    return <Square value={i} />;
  }


Change Square’s render method to show that value by replacing {/* TODO */} with {this.props.value}:
class Square extends React.Component {
  render() {
    return (
      <button className="square">
        {this.props.value}
      </button>
    );
  }
}
Before:
 
After: You should see a number in each square in the rendered output.
 
You’ve just “passed a prop” from a parent Board component to a child Square component. 
Passing props is how information flows in React apps, from parents to children.

Making an Interactive Component
Let’s fill the Square component with an “X” when we click it. First, change the button tag that is returned from the Square component’s render() function to this:
class Square extends React.Component {
  render() {
    return (
      <button className="square" onClick={function() { alert('click'); }}>
        {this.props.value}
      </button>
    );
  }
}
If you click on a Square now, you should see an alert in your browser.
Note
To save typing and avoid the confusing behavior of this, we will use the arrow function syntax for event handlers here and further below:
class Square extends React.Component {
 render() {
   return (
     <button className="square" onClick={() => alert('click')}>
       {this.props.value}
     </button>
   );
 }
}
Notice how with onClick={() => alert('click')}, we’re passing a function as the onClickprop. React will only call this function after a click. Forgetting () => and writing onClick={alert('click')} is a common mistake, and would fire the alert every time the component re-renders.

As a next step, we want the Square component to “remember” that it got clicked, and fill it with an “X” mark. 
To “remember” things, components use state.

React components can have state by setting this.state in their constructors. this.state should be considered as private to a React component that it’s defined in. Let’s store the current value of the Square in this.state, and change it when the Square is clicked.




First, we’ll add a constructor to the class to initialize the state:
class Square extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      value: null,
    };
  }

  render() {
    return (
      <button className="square" onClick={() => alert('click')}>
        {this.props.value}
      </button>
    );
  }
}
Note

In JavaScript classes, you need to always call super when defining the constructor of a subclass. All React component classes that have a constructor should start it with a super(props) call.
Now we’ll change the Square’s render method to display the current state’s value when clicked:
⦁	Replace this.props.value with this.state.value inside the <button> tag.
⦁	Replace the onClick={...} event handler with onClick={() => this.setState({value: 'X'})}.
⦁	Put the className and onClick props on separate lines for better readability.
After these changes, the <button> tag that is returned by the Square’s render method looks like this:
class Square extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      value: null,
    };
  }

  render() {
    return (
      <button
        className="square"
        onClick={() => this.setState({value: 'X'})}
      >
        {this.state.value}
      </button>
    );
  }
}
By calling this.setState from an onClick handler in the Square’s render method, we tell React to re-render that Square whenever its <button> is clicked.

. After the update, the Square’s this.state.value will be 'X', so we’ll see the X on the game board. If you click on any Square, an X should show up.
When you call setState in a component, React automatically updates the child components inside of it too.
Developer Tools
The React Devtools extension for Chrome and Firefox lets you inspect a React component tree with your browser’s developer tools.
s.
 
The React DevTools let you check the props and the state of your React components.
After installing React DevTools, you can right-click on any element on the page, click “Inspect” to open the developer tools, and the React tab will appear as the last tab to the right.
Completing the Game
We now have the basic building blocks for our tic-tac-toe game. To have a complete game, we now need to alternate placing “X”s and “O”s on the board, and we need a way to determine a winner.

Lifting State Up
Currently, each Square component maintains the game’s state. To check for a winner, we’ll maintain the value of each of the 9 squares in one location.
the best approach is to store the game’s state in the parent Board component instead of in each Square
The Board component can tell each Square what to display by passing a prop, just like we did when we passed a number to each Square.
To collect data from multiple children, or to have two child components communicate with each other, you need to declare the shared state in their parent component instead. The parent component can pass the state back down to the children by using props; this keeps the child components in sync with each other and with the parent component.
Lifting state into a parent component is common when React components are refactored
Add a constructor to the Board and set the Board’s initial state to contain an array of 9 nulls corresponding to the 9 squares:
class Board extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      squares: Array(9).fill(null),
    };
  }

  renderSquare(i) {
    return <Square value={i} />;
  }




When we fill the board in later, the this.state.squares array will look something like this:
[
  'O', null, 'X',
  'X', 'X', 'O',
  'O', null, null,
]


The Board’s renderSquare method currently looks like this:
  renderSquare(i) {
    return <Square value={i} />;
  }
In the beginning, we passed the value prop down from the Board to show numbers from 0 to 8 in every Square. In a different previous step, we replaced the numbers with an “X” mark determined by Square’s own state. This is why Square currently ignores the value prop passed to it by the Board.
We will now use the prop passing mechanism again. We will modify the Board to instruct each individual Square about its current value ('X', 'O', or null). We have already defined the squares array in the Board’s constructor, and we will modify the Board’s renderSquaremethod to read from it:
  renderSquare(i) {
    return <Square value={this.state.squares[i]} />;
  }
Each Square will now receive a value prop that will either be 'X', 'O', or null for empty squares.

Next, we need to change what happens when a Square is clicked. The Board component now maintains which squares are filled. We need to create a way for the Square to update the Board’s state. Since state is considered to be private to a component that defines it, we cannot update the Board’s state directly from Square.
Instead, we’ll pass down a function from the Board to the Square, and we’ll have Square call that function when a square is clicked. We’ll change the renderSquare method in Board to:
  renderSquare(i) {
    return (
      <Square
        value={this.state.squares[i]}
        onClick={() => this.handleClick(i)}
      />
    );
  }
Note
We split the returned element into multiple lines for readability, and added parentheses so that JavaScript doesn’t insert a semicolon after return and break our code.
Now we’re passing down two props from Board to Square: value and onClick. The onClick prop is a function that Square can call when clicked.

CDN Links
Both React and ReactDOM are available over a CDN.
<script crossorigin src="https://unpkg.com/react@16/umd/react.development.js"></script>
<script crossorigin src="https://unpkg.com/react-dom@16/umd/react-dom.development.js"></script>
The versions above are only meant for development, and are not suitable for production. 
Minified and optimized production versions of React are available at:
<script crossorigin src="https://unpkg.com/react@16/umd/react.production.min.js"></script>
<script crossorigin src="https://unpkg.com/react-dom@16/umd/react-dom.production.min.js"></script>

To load a specific version of react and react-dom, replace 16 with the version number
Why the crossorigin Attribute?
If you serve React from a CDN, we recommend to keep the crossorigin attribute set:
<script crossorigin src="..."></script>
We also recommend to verify that the CDN you are using sets the Access-Control-Allow-Origin: * HTTP header:

 
This enables a better error handling experience in React 16 and later.


