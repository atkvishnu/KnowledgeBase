import java.util.*;

class Array {

	public static void fn(int[] arr) {		// arr is passed as address, because it's made in heap
		arr[2] = 30;
		arr[3] = 40;
		// for(int i = 0; i < arr.length; i++) {			// 1st way of parsing
		// 	System.out.println(arr[i]);
		// }
	}

	public static void main(String[] args) {
		int[] arr = new int[5];		// created in heap
		arr[0] = 10;
		arr[1] = 20;
		arr[4] = 50;

		// System.out.println(arr[0]);
		System.out.println(arr.length);

		fn(arr);	// arr is passed to a fn. like this!

		for(int t: arr) {			// 2nd way of parsing
			System.out.println(t);
		}

	}
}