#include <stdio.h>
int main()
{
    int a,h,m,s;
    scanf("%d", &a);
    h = a/3600;
    m = ((a/60)-(h*60));
    s = (a - ((h*3600)+(m*60)));
    printf("%d:%d:%d\n", h,m,s);
    return 0;
}

