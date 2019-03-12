#include <stdio.h>
#include <stdlib.h>
#include "1.h"

int main(void)
{
  int n,m, err, **a,l; 

  FILE *in=fopen("data.dat","r");
  a=get_matrix(in,&n,&m,&err);
  if(err==-1)
  {
    out_matrix(a,n,m); 
	  printf("\n");
	  l=task( a,n, m);
	  if(l==-1 ) 
	  {out_matrix(a, n,  m);
	  }
	  else 	  {
	    del_string(a, n, l);
	    n=n-1;
	    out_matrix(a, n,  m);}

	    
	  del_matrix(a,n); }
  else
  {
     if(err==0)
  {printf("no file");}
     if(err==1)
  {printf("wrong sizes of matrix");}    
     if( err==3)
  {printf("too many or less elements");}//когда такое возможно??       
     if(err==2 )
  {printf("no memory for string");}//когда такое возможно??  
     if(err==4 )
  {printf("file is bad");}      
      // if(err==5 )
//  {printf("les elements");}   
  }

  return 0;
}
