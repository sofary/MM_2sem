#define Nmax 10
#define LMax 2/////???зачем это надо??
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "3.h"

int Lineget();
int Intget();
void del_matrix(int **matrix, int n, int *m);



int main(void)
{
FILE*in=fopen("1.txt","r");
int **matrix,n,*m,err=-1;
matrix=get_matrix(in,&n,&m,&err);

if(err==0) {printf("No file"); return -1;}
if(err==1) printf("File is bad");
if(err==2) printf("File is empty");
fclose(in);
if(err>=0) return -1;

pr(matrix,n,m);
del_matrix(matrix,n,m);
puts("");
return 0;
}
