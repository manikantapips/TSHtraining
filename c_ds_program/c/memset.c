void *mem_set(char *s,int c,int n)
{
	int i=0;
	for(i=0;i<n;i++)
	{
		s[i]=c;
		
	}
	return s;	
}
