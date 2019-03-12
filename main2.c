#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int search(const char *name, char *cool);

int main(void)
{

char *cool;
cool = malloc( sizeof(char)*512 ); // выделение памяти
int k;
const char *s="1.txt";

k=search(s, cool);
if(k==-1) printf("cannot open!");
else printf("%s",cool);
free(cool);
}