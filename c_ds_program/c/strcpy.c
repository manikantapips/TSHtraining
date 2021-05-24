char *strcpy(char *des,const char *src){
	int i=0,j;
	while(src[i]!='\0')
	{
		i++;
	}
	
	for(j=0;j<i && src[j]!='\0';j++)
	{
		des[j]=src[j];
	}
	for ( ;j<i; j++)
                des[j] = '\0';

	return des;
}

/* enter string1
bhavana
destination string is bhavana*/


