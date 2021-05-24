#include <stdio.h>
int main()
{
    int  num,n,pos,res,temp;
    printf("enter the number of bits\n");
    scanf("%d",&n);
    printf("enter the position\n");
    scanf("%d",&pos);//considering the 1st bit position starts with 0
    res=-1<<pos;
    temp=pos+n;
    res=~((-1<<temp)^res);
    printf("the result is %d",res);
    return 0;
}

/* enter the number of bits
4
enter the position
3
the result is -121
*/
