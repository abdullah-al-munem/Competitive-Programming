#include<stdio.h>
#include<math.h>
int main()
{
    int n,i,a,s=1;
    scanf("%d",&n);
    for(i=2;i<=n;i+=2)
    {
        s=pow(i,2);
        printf("%d^2 = %d\n",i,s);
    }
    return 0;
}

