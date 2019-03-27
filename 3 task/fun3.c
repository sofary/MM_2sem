
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "3.h"


void del_matrix(int**matrix,int n,int*m)
{
for (int i=0; i<n; i++)
free (matrix[i]);
free(matrix);
free(m);
}

int ** get_matrix(FILE*in, int*n, int**m, int*err)
{

int **matrix=0,i=0,j,x,pos;
char *buf,*buf1;
*m=0;
if(in==0) 
	{
		*err=0;
		 return 0;
	}

while(1)
{
	buf=lineget(in);
	if(!buf) break;
	if(i%Nmax==0)
	{

		matrix=(int**)realloc(matrix,(i+Nmax)*sizeof(int*));
		*m=(int*)realloc(*m,(i+Nmax)*sizeof(int*));
	}
	j=0;
	buf1=buf;
	matrix[i]=0;
	while(1)
	{
		pos=intget(buf,&x);
		if(pos==-1)
		{
			*err=1;
			del_matrix(matrix,i+!!j,*m);
			free(buf1);
			return 0;
		}
		if(pos==0) break;
		if(j%Nmax==0)//
		matrix[i]=(int*)realloc(matrix[i],(j+Nmax)*sizeof(int));////
		
		matrix[i][j]=x;
		buf+=pos;
		j++;
	}
	free(buf1);
	(*m)[i]=j;
	i++;
}
	if(i==0)
	{
		*err=2;
		return 0;
	}
	*n=i;

	
		return matrix;
}

int intget(char*s, int *k)
{
int pos = 0;
if (sscanf(s, "%d%n", k, &pos)) return pos;
if (sscanf(s, "%s", s) == 1) return -1;
return 0;
}

char *lineget(FILE *inp)
{
char *s = 0, buf[LMax], *d = 0;
int l = LMax;
while (fgets(buf, LMax, inp)!=0)
{
d = (char*)realloc(s, l);
if (!d) return 0;
else s = d;
if (l == LMax)
s[0] = 0;
strcat(s, buf);
l += LMax - 1;

if (strchr(s, '\n')) break;
}
return s;
}

void pr(int**matrix,int n,int*m)
{
for(int i=0; i<n;i++)
{
for(int j=0; j<m[i];j++) printf("%d ", matrix[i][j]);

	printf("\n");
}

}


int task(int **a, int n, int m)
{ int max=0,ki=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)
    {
      if(sravn_stok(a, i, j, m)==i && sravn_stok(a, i, max, m)==i){if(max==i)ki++; max=i; }
    }
        if(ki==n) return max;
	ki=1;
  }
    return -1;
}



int sravn_stok(int **a, int p, int f,int m)
{int k=0;
   for(int j=0;j<m;j++)
    if(a[p][j]>=a[f][j]) k++;//одинаково большие строки удаляем??
   if(k==m) {return p;}
   else if(k==0) {return f;}
   else {return -1; }

}

/*void out_matrix(int **a,int n, int m)
{
    for(int i=0; i<n; i++)
    {
        printf("\n");
        for(int j=0; j<m; j++) printf("%d ",a[i][j]);
    }
    printf("\n");
}*/
int del_string(int **a,int *m, int n,int max)

{
  int k;
  //t=m[max];
  for (k=max;k<n-1;k++) m[k]=m[k+1]; 
      free(a[max]);
  for (k=max;k<n-1;k++) a[k]=a[k+1];
    
  return n--;
}