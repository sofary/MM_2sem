#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int search(const char *s, char *cool)
{
FILE *in=fopen(s,"r");
int i=1,k=0,nd,cd;
char *str1;//считываемая строка
char *str2;//настоящий элемент
char *str3;//элемент cool с приписанными 0
char *p;
str1 = malloc( sizeof(char)*512 );
str2 = malloc( sizeof(char)*512 );
str3 = malloc( sizeof(char)*1024 );


if (in==NULL) return -1;
 while(fgets (str1, 512, in)!=0)
 {	
 	str2 = strtok(str1," \t");
 		while(str2!=NULL)
 		{//printf("jj  ");
 			if(k==0) cool=str2;//присваиваем значение первой комбинации цифр в первой строке

 			nd=strlen(str2);//длина текущего слова
 			cd=strlen(cool);//длина cool

 			if(nd>cd)
 			{p = malloc( sizeof(char)*512 );
 				for(int k=0;k<nd-cd;k++)
 					p[k]='0';
 				str3=strcat(p,cool);
 				if(nd==strlen(str3) && strcmp(str3,str2)>0) cool=str2;
 				free(p);
 			}


 			else if(nd==cd && strcmp(cool,str2)>0) cool=str2;
 			else if(nd<cd)
 			{p = malloc( sizeof(char)*512 );
 			for(int k=0;k<nd-cd;k++)
 					p[k]='0';
 				str3=strcat(p,str2);
 				if(cd==strlen(str3) && strcmp(str3,str2)<0) cool=str2;
 				free(p);
 			}

 			k=1;
 			str2=strtok(NULL, " \t");
 		} 
 } 

	printf("%s",cool);
free(str2);
free(str1);

return 0;
}
