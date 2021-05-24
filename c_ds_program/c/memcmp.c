int mem_cmp(const char *s, const char *s1, int n)
{
	int i=0,ret;

while (s[i] == s1[i] && s[i] != '\0')
      i++;
	if(s[i]>s1[i])
	{
     	 ret=1;
	}
    else if(s[i]<s1[i]) 
	{
      ret=-1;
   	} 
	else {
      ret=0;
   	}
		

	return ret;	
}
