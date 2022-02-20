#include <stdio.h>
int main()
{
    int a, b, n, i,s=0,c=0;
    scanf("%d", &a);
    do
    {
        scanf("%d", &n);
    }
    while(a>=n);
    for(i=1; s<n; i++)
    {
        s+=a;
        a++;
        c++;
    }
    printf("%d\n",c);
    return 0;
}

