

#include <stdlib.h>

#ifndef MSTRING_H
#define MSTRING_H

char** split(const char* cstr, const char* delim);

char* join(const char** parts, const char* delim);


#endif

