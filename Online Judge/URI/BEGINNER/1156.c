#include<stdio.h>
int main()
{
    float s=0.0,i,j;
    for(i=1.0,j=1.0;j<=39;j+=2)
    {
        s=s+j/i;
        i=i*2;
    }
    printf("%.2f\n",s);
    return 0;
}
