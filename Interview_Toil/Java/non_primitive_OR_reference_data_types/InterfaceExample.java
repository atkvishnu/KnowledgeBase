import java.io.*;
import java.util.*;


interface CalcInterface {
	void multiply();
	void divide();
}


public class InterfaceExample implements CalcInterface {

	int a = 10;
	int b = 20;
	int c;

	public void multiply() {
		int c = a * b;
		System.out.println("Multiplication is : " + c);
	}

	public void divide() {
		int c = a/b;
		System.out.println("Division is: " + c);
	}

	// main method
	public static void main(String[] args) throws IOException {
		InterfaceExample obj = new InterfaceExample();
		obj.multiply();
		obj.divide();
	}

}