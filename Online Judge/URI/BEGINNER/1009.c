#include<stdio.h>
int main()
{
    char name ;
    double salary, sale, bonus, TOTAL;
    scanf("%s%lf%lf",&name, &salary, &sale);
    bonus = (sale*15)/100;
    TOTAL = salary+bonus;
    printf("TOTAL = R$ %.2lf\n", TOTAL);
    return 0;
}
