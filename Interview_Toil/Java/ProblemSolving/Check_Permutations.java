import java.util.*;
import java.io.*;

class Check_Permutations {


	static String Sort(String str) {
		char[] char_arr = new char[str.length()];
		char_arr = str.toCharArray();
		java.util.Arrays.sort(char_arr);
		return new String(char_arr);
	}

	static boolean permutation(String str1, String str2) {
		if(str1.length() != str2.length()) {
			return false;
		} else {
			return Sort(str1).equals(Sort(str2));
		}
	}

	// hashmap insert all chars from str1
	// remove all chars from str2
	// if all is 0, return true;
	// else false;
	static boolean check_perm(String str1, String str2) {

		int len1 = str1.length();
		int len2 = str2.length();

		if(len1 != len2) return false;

		int[] hashmap = new int[128];

		for (int i = 0; i < len1; i++) {
			int val = str1.charAt(i);
			hashmap[val]++;
		}

		for (int i = 0; i < len2; i++) {
			int val2 = str2.charAt(i);
			hashmap[val2]--;
		}

		for (int i = 0; i < 128; i++) {
			if(hashmap[i]!=0) {
				return false;
			}
		}
		
		return true;
	}




	public static void main(String[] str) {

		String str1 = "God";
		String str2 = "dog";

		System.out.println(check_perm(str1, str2));



	}





}