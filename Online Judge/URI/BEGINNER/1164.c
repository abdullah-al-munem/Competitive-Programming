#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int i,s=0,a,j,c=0;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a);
        for(j=1;j<a;j++)
        {
            if(a%j==0)
            {
                s=s+j;
            }
        }

        if(s==a)
            printf("%d eh perfeito\n",a);
        else
            printf("%d nao eh perfeito\n",a);
        s=0;
    }


    return 0;
}

