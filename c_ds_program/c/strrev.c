#include<string.h>
void *strrev(char *str){
	int i,j;
	char ch;
	int l = strlen(str);
	for(i=0,j=l-1;i<j;++i,--j){
		ch=str[i];
		str[i]=str[j];
		str[j]=ch;
	}
str[l-1]='\0';
}
