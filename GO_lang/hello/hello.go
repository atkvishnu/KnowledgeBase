package main

import(
	"fmt"

	"example.com/greetings"
)

//import "rsc.io/quote"



func main() {
	// fmt.Println("Hello, World!")
	// fmt.Println(quote.Go())
	// fmt.Println(quote.Glass())
	// fmt.Println(quote.Hello())
	// fmt.Println(quote.Opt())	
	message := greetings.Hello("Vishnu")
	fmt.Println(message);
}
