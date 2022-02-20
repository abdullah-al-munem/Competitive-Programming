#include <stdio.h>
int main()
{
   int i,n, p, min;
    scanf("%d", &n);
    int a[n];
    for(i=0; i<n; i++)
        scanf("%d", &a[i]);
    min=a[0];
    for(i=0; i<n; i++)
    {
        if(min>a[i])
        {
            min=a[i];
            p=i;
        }
    }
    printf("Menor valor: %d\nPosicao: %d\n", min, p);
    return 0;
}
