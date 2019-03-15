#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "2.h"
int search(const char *s, char *cool)
{
FILE *in=fopen(s,"r");
int k=0,nd,cd,flag=0;
char *str1;//считываемая строка
char *str2;//настоящий элемент

char *p;
str1 = malloc( sizeof(char)*512 );

memset(cool,0,512);


if (in==NULL) return -1;
 while(fgets (str1, 512, in)!=0)
 {	

 	str2 = strtok(str1," \t\n");
 		while(str2!=NULL)

 		{   
		  for(int g=0;g<(int)strlen(str2);g++) 
 				if (str2[g]>'9' ||  str2[g]<'0') {flag=1;}//знак не является циврой, +,-
 				
		 if(flag==0)
 			{
			 
			  printf("\n");
 			if(k==0) {strcpy(cool,str2);k=1;}//присваиваем значение первой комбинации цифр в первой строке

 			nd=(int)strlen(str2);//длина текущего слова
 			cd=(int)strlen(cool);//длина cool
//printf("%s  %s",str2,cool);
 			if(nd>cd)
 			{ 
 				p = malloc( sizeof(char)*512 );
 				memset(p,0,512);
				for(int k=0;k<nd-cd;k++)
 					p[k]='0';
 				//str3=
 				strcat(p,cool);
				//printf("kek11");
 				if(strcmp(p,str2)>0) {strcpy(cool,str2);}
 				free(p);

 			}
 			else if(nd==cd && strcmp(cool,str2)>0) {strcpy(cool,str2);}
 					else if(nd<cd)
 					{ 
 						p = malloc( sizeof(char)*512 );
						memset(p,0,512);
 					for(int k=0;k<cd-nd;k++)
 							p[k]='0';
					
					
 						strcat(p,str2);
				
 						if( strcmp(p,cool)<0) {strcpy(cool,str2);/*printf("kek33\n");printf("%s",p);*/}
 						free(p);
 						 
 					}

 					
 		}
 		 
 			str2=strtok(NULL, " \t\n");
 			flag=0;
 			
 	} 
 } 

	
//free(str2);
free(str1);
//free(str3);

return 0;
}
