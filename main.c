#include <stdio.h>

#include "mstring.h"



int main(void) {
	
	char* cstr = "a\tb\tword two\tsdd sdf fsdfs";
	char** parts;
	char** parts_orig;

	char* str;

	printf("String: %s\n", cstr);

	// Test split
	// TODO free prats
	parts = split(cstr, "\t");
	parts_orig = parts;
	
	printf("Split: ");
	char* delim = ",";


	while (*parts != NULL) {
		printf("%s%s", *parts, *(parts+1)==NULL?"":delim);
		parts++;
	}
	putchar('\n');

	parts = parts_orig;

	// join
	printf("%p\n", *parts);
	str = join((const char **) parts, ":");
	printf("Join: %s\n", str);

	return 0;
}


