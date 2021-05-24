#include <stdio.h>
int main()
{
	int a, b,d; 
	printf ("Enter two integer values: ");
	scanf ("%d%d", &a, &b);
	 d=a^b;
	if (d < 0)
		printf ("opposite signs %d \n", d);
	  
	else
	  	printf ("same sign %d\n",d);

return 0;
}
/* Enter two integer values: 12 -11
opposite signs -7 
*/
