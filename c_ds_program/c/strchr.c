char *str_chr(const char *s, int c)
{
	while(*s != c && *s != '\0') {
		s++;
	}
	if(*s == c) 
		return s;

	else 
		return c;

}

/* Hello world
enter character to search
e
after searching
ello world
*/
