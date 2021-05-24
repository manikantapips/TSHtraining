char *strcat(char *des, const char *src)
{

	while(*des!='\0')
	des++;
	while(*src!='\0')
	*des++=*src++; 

    	return des;


}

