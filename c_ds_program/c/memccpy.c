void* mem_ccpy(char* s1, char* s2,int c,int n)
{
	int i=0;
	for(i=0;i<n||s2[i]!=c;i++)
	{
		s1[i]=s2[i];
		
	}
	return s1;	
}
