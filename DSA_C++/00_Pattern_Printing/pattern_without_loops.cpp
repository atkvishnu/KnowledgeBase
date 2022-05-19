#include<stdio.h> 

int i=1,j=1;

int main () 
{ 
   one:	if(i<=10) 
	{ 
		 
		if(j<=i) 
		{ 
			printf("*"); 
			j++; 
			goto one; 
		} 
		j=1; 
		printf("\n"); 
		i++; 
		main(); 
	} 
} 