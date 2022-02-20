#include <stdio.h>

int main()
{
 int n;

 scanf("%d", &n);

 int a = n / 365;
 int rA = n % 365;
 int rM = rA % 30;
 int m = rA / 30;
 int d = rM % 30;

 printf("%d ano(s)\n%d mes(es)\n%d dia(s)\n", a, m, d);

 return 0;
}
