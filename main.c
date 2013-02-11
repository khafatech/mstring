#include <stdio.h>

#include "mstring.h"


int main(void) {
	
	char* cstr = "a\tb\tword two\tsdd sdf fsdfs";
	char* cstr2 = "t he quick   brown fox    jumped";
	char** parts;
	char** parts_orig;

	char* str;

	printf("String: %s\n", cstr);

	// Test split
	// TODO free prats
	parts = split(cstr2, " ");
	parts_orig = parts;
	
	printf("Split: ");
	char* delim = ",";


    // print
	while (*parts != NULL) {
		printf("%s%s", *parts, *(parts+1)==NULL?"":delim);
		parts++;
	}
	putchar('\n');

	parts = parts_orig;

	// join
	str = join((const char **) parts, ":");
	printf("Join: %s\n", str);


    free_parts(parts);
    free(str);

	return 0;
}


