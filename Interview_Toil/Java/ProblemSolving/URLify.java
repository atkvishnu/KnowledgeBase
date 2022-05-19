import java.util.*;
import java.io.*;

// "Mr John Smith     ", 13
// Mr%20John%20Smith"


class URLify {



	void replaceSpaces(String str, int realCount) {

		int spaceCount = 0, index, i = 0;

		for(int i = 0; i < str.length(); i++) {
			if(str[i]==' ') {
				spaceCount++;
			}
		}

		index = realCount + spaceCount * 2;

		if(realCount < str.length) str[realCount] = '\0';

		for (i = index - 1; i >= 0; i++) {
			if(str[i] == ' ') {
				str[index - 1] = '0';
				str[index - 2] = '2';
				str[index - 3] = '%';
			} else {
				str[index - 1] = str[i];
				index--;
			}
		}








	}





	public static void main(String[] args) {

	}



}