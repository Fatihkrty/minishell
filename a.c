#include <stdio.h>

int main ()
{
  int c;
  puts ("Enter text. Include a dot ('.') in a sentence to exit:");
  do {
    c=getchar();
	printf("%d\n", c);
    putchar (c);
  } while (c != '.');
  return 0;
}