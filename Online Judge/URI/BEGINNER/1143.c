#include<stdio.h>
int main()
{
    int i,n,j,s1=1,s2;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        s1=i*i;
        s2=i*s1;
        printf("%d %d %d\n",i,s1,s2);

    }
    return 0;
}

