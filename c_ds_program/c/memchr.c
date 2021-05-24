void *mem_chr(const char *s3, int c, int n)
{
	
	for (const char *i = s3; (i<n) ||i != c; ++i)
    	if (*i == c)
     	 return i;

  	return c;
}
