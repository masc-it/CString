/*
 ============================================================================
 Name        : String.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

char* scan_string();

int main(void) {
	printf("Inserisci nome -> ");
	char* string = scan_string();
	printf("\n%s\n", string);
	free(string);
	system("pause");
	return EXIT_SUCCESS;
}


char* scan_string(){

	char c;
	char* string = malloc(sizeof(char));

	int siz = 0;
	do {

		c = getch();
		if ( siz > 0 && c == 8 ){

			putchar(8);
			putchar(0);
			putchar(8);
			siz--;
			string = realloc(string, sizeof(char)*(siz));
		} else if ( siz >= 0 && c != 8 ){
			putchar(c);
			string = realloc(string, sizeof(char)*(siz+1));
			string[siz] = c;
			siz++;
		}

	} while ( c != 13 );

	string[siz-1] = '\0';
	return string;
}
