#include <stdio.h>
int main()
{
    int a,b,c=0,i;
    scanf("%d%d", &a, &b);
    if(a<b)
    {
        for(i=a; i<=b; i++)
        {
            if(i%13==0) continue;
            c+=i;
        }
    }
    else if(a>b)
    {
        for(i=b; i<=a; i++)
        {
            if(i%13==0) continue;
            c+=i;
        }
    }
    printf("%d\n",c);
    return 0;
}
