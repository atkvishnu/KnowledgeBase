import java.util.*;

class JaggedArray{

	/*Normal Matrix*/
	/*
	public static void main(String[] args) {
		int[][] arr = new int[2][3];	// matrix 2x3 size
		arr[0][0] = 10;
		arr[0][1] = 11;
		arr[0][2] = 12;
		arr[1][0] = 21;
		arr[1][1] = 22;
		arr[1][2] = 23;

		for (int i = 0; i < arr.length; i++) {
			for (int j = 0; j <arr[i].length; j++) {
				System.out.print(arr[i][j] + " ");
			}
			System.out.println();
		}
	}
	*/

	public static void fun(int[][] arr) {		// passed by value, but we can change the values from this fn. also 
		arr[1][3] = 555;
		for (int i = 0; i < arr.length; i++) {
			for (int j = 0; j < arr[i].length; j++) {
				System.out.print(arr[i][j] + " ");
			}
			System.out.println();
		}
	}


	/*Jagged Array*/
	public static void main(String[] args) {
		int[][] arr = new int[2][];
		arr[0] = new int[3];
		arr[1] = new int[4];

		arr[0][0] = 10;
		arr[0][1] = 11;
		arr[0][2] = 12;
		arr[1][0] = 21;
		arr[1][1] = 22;
		arr[1][2] = 23;
		arr[1][3] = 24;

		fun(arr);
	}


}