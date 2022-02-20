#include<stdio.h>
int main()
{
    int n,i,s=0;
    float a,c=0.0;
    while(1)
    {
        scanf("%d",&n);
        if(n<0)
            break;
        else
        {
            s=s+n;
            c++;
        }
    }
    a=s/c;
    printf("%.2f\n",a);
    return 0;
}

