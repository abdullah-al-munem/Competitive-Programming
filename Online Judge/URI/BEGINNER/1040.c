#include<stdio.h>
int main()
{
   float a,b,c,d,e,A,A2;
   scanf("%f%f%f%f",&a,&b,&c,&d);
   A = (a * 2 + b * 3 + c * 4 + d) / 10;
   printf("Media: %.1f\n",A);
   if(A>= 7.0)
    printf("Aluno aprovado.\n");
   else if (A>=5.0 && A<=6.9)
   {
       printf("Aluno em exame.\n");
       scanf("%f",&e);
       printf("Nota do exame: %.1f\n",e);
       A2 = (A+e)/2.0;
       if(A2>=5.0)
        printf("Aluno aprovado.\n");
       else
        printf("Aluno reprovado.\n");
       printf("Media final: %.1f\n",A2);
   }
   else
    printf("Aluno reprovado.\n");

   return 0;
}

