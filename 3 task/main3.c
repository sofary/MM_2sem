
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "3.h"

int *Lineget(FILE *inp);
int Intget(char*s, int *k);
void del_matrix(int **matrix, int n, int *m);
int task(int **a, int n, int m);
int sravn_stok(int **a, int p, int f,int m);
//void out_matrix(int **a,int n, int m);
int del_string(int **a,int *m,int n,int max);


int main(void)
{
FILE*in=fopen("1.txt","r");
int **matrix,n,*m,err=-1,l;
matrix=get_matrix(in,&n,&m,&err);

if(err==0) {printf("No file"); return -1;}
else if(err==1) printf("File is bad");
else if(err==2) 
{
printf("File is empty");
fclose(in);
}

else if(err>=0) return -1;
else if(err==-1)
{
	pr(matrix,n,m);//просто печать
	puts("");

	l=task( matrix,n, *m);//razmer
	
	  if(l==-1 ) 
	  {pr(matrix, n,  m);

	  }
	  else 	  
	  {
	  	
	   del_string(matrix,m, n, l);
	    n=n-1;
	    pr(matrix, n,  m);

	   }

	del_matrix(matrix,n,m);

}




return 0;
}