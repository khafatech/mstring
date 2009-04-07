/*

Lisenced under GPL V.2 or later (Haha. Is this too tiny to be useful?)

Implements the split() function, like the one in modern programming
languages.

There is already a strtok function in string.h that splits the string, but it
modifies its argument and requires repeated calls.

TODO:
 - Maybe it could be done by simply calling strtok till it's done, then
 transforming the pieces in the original string to a dynamically allocated string array.


 ChangeLog:

 * 4/4/09	initial version
	- uses realloc for each new token. (allocates a char pointer)

*/ 




#include <string.h>
#include <stdlib.h>


// This function returns an array of tokens.
// The input string is unmodified.

char ** split(const char * cstr, const char * delim) {

	/* returns { "1", "2", "3", NULL }
	 *
	 * reallocate 1 new pointer at a time.
	*/

	char * str;
	
	char **pieces = NULL;
	char * piece;
	int count = 0;

	// make a copy of the string
	str = malloc(strlen(cstr));
	if (str != NULL) {
		strcpy(str, cstr);
	}

	piece = strtok(str, delim);
	
	while (piece != NULL) {
		count++;
		
		// change size - idea from cplusplus.com
		pieces = (char**) realloc(pieces, count * sizeof(char*));
		if (pieces == NULL) {
			puts("Error allocating memory");
			return NULL;
		}

		// allocate space for str
		pieces[count-1] = malloc(strlen(piece) + 1);
		strcpy(pieces[count-1], piece);

		piece = strtok(NULL, delim);
	}

	// pices = {"one", "two", NULL} 
	
	pieces = (char**) realloc(pieces, (count+1) * sizeof(char*));
	if (pieces == NULL) {
		puts("Error allocating memory");
		return NULL;
	}

	// last element
	pieces[count] = NULL;
	
	free(str);

	return pieces;
}



