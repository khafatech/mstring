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
#include <stdio.h>


// This function returns an array of tokens.
// The input string is unmodified.

char** split(const char* cstr, const char* delim) {

	/* returns { "1", "2", "3", NULL }
	 *
	 * reallocate 1 new pointer at a time.
	*/

	char* str;
	
	char** pieces = NULL;
	char* piece;
	int count = 0;

	// make a copy of the string
	str = malloc(strlen(cstr));
	if (str != NULL) {
		strcpy(str, cstr);
	}

	piece = strtok(str, delim);
	
	while (piece != NULL) {
		count++;
		
		// change size of pointer array - idea from cplusplus.com
		pieces = (char**) realloc(pieces, count * sizeof(char*));
		if (pieces == NULL) {
			fprintf(stderr, "split(): Error allocating memory");
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



// TODO
char* join(const char** parts, const char* delim) {
	
	const char** part;
	char* result = NULL;
	
	int delim_len;
	
	
	if ((NULL == parts) || (NULL == *parts)) {
		return NULL;
	}

	
	if (NULL == delim) {
		delim_len = 0;
	}
	else {
		delim_len = strlen(delim);
	}
	

	//		0x1		0x2  0x3
	// pices = {"one", "two", NULL}; delim = " "
	// result = "one two"
	
	for (part = parts; NULL != *part; part++) {
		
		// if last part, don't append delim
		if (*(part+1) != NULL) {
			result = (char*) realloc(result, (strlen(*part) + delim_len + 1) * sizeof(char));
			strcat(result, *part);
			strcat(result, (delim != NULL)? delim : "");
		}
		else {
			printf("last size = %d, result: %s\n", (strlen(*part) + 1), result);
				
			// FIXME realloc() says invalid next size
			result = (char*) realloc(result, (strlen(*part) + 1) * sizeof(char));
			strcat(result, *part);
		}

	}
	
	return result;
}




