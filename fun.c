#include <stdio.h>
#include <stdlib.h>
#include "1.h"
void del_matrix(int **a, int n)
{
  for(int i=0; i<n;i++)  free(a[i]);
   free(a);
}
int** get_matrix(FILE *in, int *n, int *m, int *err)
{
  int i=0,j=0,x;
  int** a;
  *err= -1;
  if(!in)//нет файла
  {
    *err=0;
    return 0;
  }
  if(fscanf(in,"%d%d",n,m)!=2||*n<=0||*m<=0)
  {
    *err=1;
    return 0;
  }
  a=(int**)malloc((*n)*sizeof(int**));
  
  if(!a){*err=2;return 0;}
  while(fscanf(in,"%d",&x)==1)
{
  if(i==*n) {del_matrix(a,i); *err=3;return 0;}//!!!
  if(j==0)
{
   a[i]=(int*)malloc(sizeof(int)*(*m));
  if(a[i]==0) {del_matrix(a,i); *err=2; return 0;}// почему a[i]==0 это значение или кол-во памяти
}
  a[i][j]=x;
  j++;
if(j==*m){j=0; i++;}
  
}
if(!feof(in)) {*err=4; del_matrix(a,i); return 0;}
if(j || i<*n) {*err=3; del_matrix(a,i); return 0;}//слишком мало?? j?

return a;
}
int task(int **a, int n, int m)
{ int max=0,ki=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)
    {
      if(sravn_stok(a, i, j, m)==i && sravn_stok(a, i, max, m)==i){if(max==i)ki++; max=i; }
    }
        if(ki==n) return max;
	ki=0;
  }
    return -1;
}

void out_matrix(int **a,int n, int m)
{
    for(int i=0; i<n; i++)
    {
        printf("\n");
        for(int j=0; j<m; j++) printf("%d ",a[i][j]);
    }
    printf("\n");
}
int del_string(int **a,int n,int max)
{
  int k;
  free(a[max]);
  for (k=max;k<n-1;k++) a[k]=a[k+1];
  return n--;
  
}
int sravn_stok(int **a, int p, int f,int m)
{int k=0;
   for(int j=0;j<m;j++)
    if(a[p][j]>a[f][j]) k++;
   if(k==m) return p;
   else if(k==0) return f;
   else return -1;
}














