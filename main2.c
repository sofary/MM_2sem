#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "2.h"

//int search(  const char *name, char *cool);

int main(void)
{

char *cool;
//const char *s="1.txt";
cool = malloc( sizeof(char)*512 ); // выделение памяти




if(search("1.txt", cool)==-1) printf("cannot open!\n");
else printf("%s",cool);
free(cool);
return 0;
}
