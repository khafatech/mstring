
/* realloc example: rememb-o-matic */
#include <stdio.h>
#include <stdlib.h>

int main ()
{
  int input,n;
  int count=0;
  int * numbers = NULL;

  do {
     printf ("Enter an integer value (0 to end): ");
     scanf ("%d", &input);
     count++;
     numbers = (int*) realloc (numbers, count * sizeof(int));
     if (numbers==NULL)
       { puts ("Error (re)allocating memory"); exit (1); }
     numbers[count-1]=input;
  } while (input!=0);

  printf ("Numbers entered: ");
  for (n=0;n<count;n++) printf ("%d ",numbers[n]);
  free (numbers);

  return 0;
}


