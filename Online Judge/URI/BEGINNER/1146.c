#include<stdio.h>
int main()
{
    while(1)
    {
        int n,i;
        scanf("%d",&n);
        if(n==0)
            break;
        else
        {
            for(i=1;i<=n;i++)
            {
                printf("%d",i);
                if(i<n)
                    printf(" ");
            }
            printf("\n");

        }
    }
    return 0;
}
