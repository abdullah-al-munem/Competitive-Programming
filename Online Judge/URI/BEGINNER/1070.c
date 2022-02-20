#include <stdio.h>

int main()
{
     int n,a,i;

     scanf("%d", &n);
     a=n+12;
     for (i = n; i <= a; i++)
     {
      if(i % 2 == 1)
       printf("%d\n", i);
     }

     return 0;
}

