import java.util.*;


class Class_and_Object {
	int a = 10;
	int b = 20;
	int c;

	public void add() {
		int c = a + b;
		System.out.println("Addition of numbers is: " + c);
	}

	public void sub() {
		int c = a - b;
		System.out.println("Subtraction of number is: " + c);
	}
	

	public static void main(String[] args) {
		Class_and_Object obj = new Class_and_Object();
		obj.add();
		obj.sub();
	}
}