#include<stdio.h>
int main()
{
    int n,i,j,k=0,a,b;
    scanf("%d",&n);
    for(i = 0;i < n;i++)
    {
        scanf("%d %d",&a,&b);
        if(a%2==0)
        a++;
        for(j = 0;j < b;j++)
        {
            k += a;
            a += 2;;
        }
        printf("%d\n",k);
        k=0;
    }
    return 0;
}


