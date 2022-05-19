import java.util.*;
import java.io.*;




class Unique_characters {


	static boolean unique_chars(String str) {	// O(N) & O(1)
		int len = str.length(); 
		if(len > 128) return false;

		boolean[] hashmap = new boolean[128];

		for (int i = 0; i < len; i++) {
			int val = str.charAt(i);
			if(hashmap[val]) {
				return false;
			}
			hashmap[val] = true;
		}
		return true;
	}

	static boolean unique_chars_1(String str) {		// O(n^2) & O(1)
		int len = str.length(); 
		if(len > 128) return false;

		for (int i = 0; i < len; i++) {
			for(int j = i+1; j < len; j++) {
				int val1 = str.charAt(i);
				int val2 = str.charAt(j);
				if(val1 == val2) {
					return false;
				} else {
					continue;
				}
			}
		}
		return true;
	}




	public static void main(String[] args) {

		System.out.println(unique_chars_1("Hello"));

	}



}