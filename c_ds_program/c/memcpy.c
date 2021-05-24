void* mem_cpy(char* s1, char* s2,int n)
{
	int i=0;
	for(i=0;i<n;i++)
	{
		s1[i]=s2[i];
		
	}
	return s1;	
}
