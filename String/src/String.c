#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct {
	char* string;
	int size;
} string;

void scan_string(string* s);
string reverse(string* s);

int main(void) {

	string s1;
	printf("Inserisci nome -> ");
	scan_string(&s1);
	printf("\n%s\n%d", s1.string, s1.size);
	system("pause");
	
	return EXIT_SUCCESS;
}

void scan_string(string* s){

	char c;
	s->string = malloc(sizeof(char));
	int siz = 0;
	
	do {

		c = getch();
		
		if ( siz > 0 && c == 8 ){

			// delete previous letter
			putchar(8);
			putchar(0);
			putchar(8);
			
			siz--;
			s->string = realloc(s->string, sizeof(char)*(siz));
		} else if ( siz >= 0 && c != 8 ){
			putchar(c);
			s->string = realloc(s->string, sizeof(char)*(siz+1));
			s->string[siz] = c;
			siz++;
		}

	} while ( c != 13 );

	putchar(10);
	putchar(13);

	s->string[siz-1] = '\0';
	s->size = siz;
}

string reverse(string* s)
   {
       int i, j;

       string rev;
       rev.size = s->size;
       rev.string = malloc(sizeof(char)*(s->size));

       for (i = 0, j = rev.size-2; i < rev.size; i++, j--) {
    	   rev.string[i] = s->string[j];
       }

       rev.string[rev.size-1] = '\0';
       return rev;
   }

string int_to_string(int n)
  {
      int i;

      string s;
      s.string = malloc(sizeof(char));

      i = 0;
      do {
    	  s.string = realloc(s.string, sizeof(char)* (i+1));
    	  s.string[i++] = n % 10 + '0';
      } while ((n /= 10) > 0);

      s.string = realloc(s.string, sizeof(char) * (i+1));
      s.string[i] = '\0';
      s.size = i+1;

      return reverse(&s);
  }
