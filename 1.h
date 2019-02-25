#include <stdio.h>
#include<stdlib.h>
int** get_matrix(FILE *in, int *n, int *m,int *err);
void del_matrix(int **a, int n);
void out_matrix(int **a,int n, int m);
int task(int **a, int n, int m);
int del_string(int **a,int n,int max);
int sravn_stok(int **a, int p, int f,int m);