#include <stdio.h>
#include <string.h>

int main () {
   char src[40];
   char dest[12];
  
   memset(dest, '\0', sizeof(dest));
   strcpy(src, "This is tutorialspoint.com");
   strncpy(dest, src, 10);

   printf("strncpy copied string : %s\n", dest);
   strcpy_s(dest,5,src);
   printf("strcpy_s copied string : %s\n", dest);
   
   return(0);
}
