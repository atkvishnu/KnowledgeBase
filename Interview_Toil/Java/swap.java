// We can not use pointers in java
// This means that we can not reference the address of variables.
// 
// 
// This example is of swappiung numbers
/*
In c++ we would do something like this:
fn(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}
int main() {
	fn(10,20);
}
*/


// In Java, we will have to use global variables
import java.util.*;
/*
class swap {
	public static void fn(int a, int b) {
		int temp = a;
		a = b;
		b = temp;
	}

	public static void main(String[] args) {
		int a = 10;
		int b = 20;
		fn(a,b);
		System.out.println(a + ", " + b);		// this returns 10, 20 because we cannot reference variables via. their address
	}
}
*/

class swap {
	public static void fn() {
		int temp = a;
		a = b;
		b = temp;
	}

	static int a = 10;
	static int b = 20;

	public static void main(String[] args) {
		// int a = 10;
		// int b = 20;
		fn();
		System.out.println(a + ", " + b);		// this returns 20, 10
	}
}

