#include<stdio.h>
int main()
{
    int n,m,i,j;
    scanf("%d%d",&n,&m);
    int d =1;
    for(i = 1;i <= m/n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(j == n)
                printf("%d",d);
            else
                printf("%d ",d);
            d++;
        }

        printf("\n");
    }
    return 0;
}
