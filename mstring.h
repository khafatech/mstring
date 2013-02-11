/* mstring.h

   Lisenced under GPL V.2 or later 

   Implements the split() and join() functions, like the ones in modern programming
   languages.

   Author: github.com/quakehead

 */

#ifndef MSTRING_H
#define MSTRING_H

#include <stdlib.h>


char** split(const char* cstr, const char* delim);

char* join(const char** parts, const char* delim);

void free_parts(char** parts);

#endif

