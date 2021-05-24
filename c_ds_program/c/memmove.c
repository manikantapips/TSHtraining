 void *mem_move(char *s1, const char *s2, int n)

{
	int i;
	char temp[100];
	for (i=0; i<n; i++) 
       temp[i] = s2[i]; 

	for (i=0; i<n; i++) 
       s1[i] = temp[i]; 

	return s1;	
}
