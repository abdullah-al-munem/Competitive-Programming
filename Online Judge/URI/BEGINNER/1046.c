#include <stdio.h>

int main()

{
    int a,b,c,temp;
    scanf("%d%d",&a,&b);
    if (a<b)
        c = b-a;
    else
        c = 24 - (a-b);
   printf("O JOGO DUROU %d HORA(S)\n",c);
    return 0;

}

