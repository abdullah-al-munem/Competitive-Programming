#include<stdio.h>
#include<math.h>
int main()
{
    double a, b,c,area1,area2,area3,area4,area5, pi = 3.14159;
    scanf("%lf%lf%lf",&a,&b,&c);
    area1=(a*c)/2;
    area2=pi*pow(c,2);
    area3=(((a+b)/2)*c);
    area4=b*b;
    area5=a*b;
    printf("TRIANGULO: %.3lf\n", area1);
    printf("CIRCULO: %.3lf\n", area2);
    printf("TRAPEZIO: %.3lf\n", area3);
    printf("QUADRADO: %.3lf\n", area4);
    printf("RETANGULO: %.3lf\n", area5);
    return 0;
}
