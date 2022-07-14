import java.io.*;
import java.util.*;

class ArrayExample {

	public static void main(String[] args) throws IOException {
		int i;
		Scanner sc = new Scanner(System.in);

		int arr[] = {1,2,3,4,6};

		int arr1[] = new int[5];

		System.out.println("Enter the numbers (size = 5) : ");

		for (i = 0; i < 5; i++) {
			arr1[i] = sc.nextInt();
		}

		System.out.println("arr is : ");
		for (i = 0; i < 5; i++) {
			System.out.print(arr[i] + " ");
		}
		System.out.println();


		System.out.println("arr1 is : ");
		for (i = 0; i < 5; i++) {
			System.out.print(arr1[i] + " ");
		}
		System.out.println();

	} 

}