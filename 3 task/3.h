#define Nmax 10
#define LMax 2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void del_matrix(int**matrix,int n,int*m);
int intget(char*s, int *k);
int ** get_matrix(FILE*in, int*n, int**m, int*err);
char *lineget(FILE *inp);
void pr(int**matrix,int n,int*m);