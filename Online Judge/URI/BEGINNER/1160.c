#include<stdio.h>
int main()
{
    int i,a,b,j=0,n;
    double c,d;
    scanf("%d",&n);
    for(i = 0; i < n;i++)
    {
            j=0;
    scanf("%d %d %lf %lf",&a,&b,&c,&d);
    while(a<=b)
    {
        a = a + ((a*c)/100);
        b = b + ((b*d)/100);
        j++;
        if(j>100)
        {
            printf("Mais de 1 seculo.\n");
            break;
        }
    }
    if(j <= 100)
        printf("%d anos.\n",j);
    }
    return 0;
}

