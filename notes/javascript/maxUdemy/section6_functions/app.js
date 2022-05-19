const startGameBtn = document.getElementById("start-game-btn");
const endGameBtn = document.getElementById("end-game-btn");

const ROCK = "ROCK";
const PAPER = "PAPER";
const SCISSORS = "SCISSORS";
const DEFAULT_USER_CHOICE = ROCK;
const RESULT_DRAW = "DRAW";
const RESULT_PLAYER_WINS = "PLAYER";
const RESULT_COMPUTER_WINS = "COMPUTER";

let gameIsRunning = false;

const getPlayerChoice = () => {
  const selection = prompt(
    `${ROCK}, ${PAPER}, or ${SCISSORS}?`,
    ""
  ).toUpperCase();
  if (selection != ROCK && selection != PAPER && selection != SCISSORS) {
    alert("Please enter a valid selection.");
    return getPlayerChoice();
    //alert("Invalid choice! We chose ${DEFAULT_USER_CHOICE} for you.");
    //return DEFAULT_USER_CHOICE;
  }
  return selection;
};

const getComputerChoice = () => {
  const randomValue = Math.random();
  if (randomValue < 0.34) {
    return ROCK;
  } else if (randomValue < 0.67) {
    return PAPER;
  } else {
    return SCISSORS;
  }
};

const getWinner = (cChoice, pChoice) => {
  if (cChoice == pChoice) {
    return RESULT_DRAW;
  } else if (
    (cChoice == ROCK && pChoice == SCISSORS) ||
    (cChoice == PAPER && pChoice == ROCK) ||
    (cChoice == SCISSORS && pChoice == PAPER)
  ) {
    return RESULT_COMPUTER_WINS;
  } else {
    return RESULT_PLAYER_WINS;
  }
};

const start = () => {
  if (gameIsRunning) {
    return;
  }
  gameIsRunning = true;
  console.log("Game is starting....");
  const playerSelection = getPlayerChoice();
  const computerSelection = getComputerChoice();
  const winner = getWinner(computerSelection, playerSelection);
  console.log(
    `You chose ${playerSelection} and the computer chose ${computerSelection}.`
  );
  console.log(`The winner is ${winner}!`);
};

const end = () => {
  console.log("Game is ending....");
  gameIsRunning = false;
};

startGameBtn.addEventListener("click", start);
endGameBtn.addEventListener("click", end);
