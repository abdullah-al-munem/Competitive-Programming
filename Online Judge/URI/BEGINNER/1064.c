#include<stdio.h>
int main()
{
     double n,s=0;
     int count = 0, i;

     for (i = 0; i < 6; ++i)
     {
      scanf("%lf", &n);
      if(n >= 0){
       count++;
       s=s+n;
      }
     }
     float a = s/count;
     printf("%d valores positivos\n", count);
     printf("%.1f\n", a);

     return 0;
}
