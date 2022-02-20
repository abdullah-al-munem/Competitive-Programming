#include<stdio.h>
int main()
{
    int NUMBER,hours ;
    float SALARY1, SALARY;
    scanf("%d%d%f",&NUMBER, &hours, &SALARY1);
    SALARY = hours*SALARY1;
    printf("NUMBER = %d\n", NUMBER);
    printf("SALARY = U$ %.2f\n", SALARY);
    return 0;
}
