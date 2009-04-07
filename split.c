#include <stdio.h>

#include "split.h"



int main(void) {
	
	char * cstr = "a\tb\tword two\tsdd sdf fsdfs\tThe end!";
	char **parts;

	puts(cstr);

	parts = split(cstr, "\t");

	while (*parts != NULL) {
		printf("%s, ", *parts);
		parts++;
	}

	putchar('\n');

	return 0;
}




