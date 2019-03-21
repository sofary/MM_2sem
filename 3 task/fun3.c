#define Nmax 10
#define LMax 2
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
	if(i%Nmax==0)//?где инициаллизируем Nmax %i?? тут же ничего не происходит i=0 тоже
	{
		//matrix=(int**)realloc(matrix,(i+Nmax)int*);
		//*m=(int*)realloc(*m,(i+Nmax)int*);
		matrix=(int**)realloc(matrix,(i+Nmax));
		*m=(int*)realloc(*m,(i+Nmax));
	
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
		if(j%Nmax==0)//??j%
		{
			//matrix[i]=(int*)realloc(matrix[i],(j+Nmax)int);
			matrix[i]=(int*)realloc(matrix[i],(j+Nmax));
		}
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