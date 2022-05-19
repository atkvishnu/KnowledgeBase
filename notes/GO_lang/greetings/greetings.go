package main

import "fmt"

// Hello returns a greeting for the named person
// func <Function name>(name <Parameter type>) <Return type>
func Hello(name string) string {
	// Return a greeting that embeds the name in a message
	// %v -> format verb
	// := -> operator is a shortcut for declaring and initializing a variable in one line
	message := fmt.Sprintf("Hi, %v. Welcome!", name)
	return message
}
