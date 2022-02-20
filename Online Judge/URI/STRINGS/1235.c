#include<stdio.h>
#include<string.h>
int main()
{
    char a[100],b[100];
    int i,j,l,hl,n,k;
    scanf("%d",&n);
    getchar();
    for(i = 0;i < n;i++)
    {
        gets(a);
        l=strlen(a);
        hl=l/2;
        k=0;
        for(j = hl-1;j >= 0;j--)
        {
            b[k]=a[j];
            k++;
        }
        k=hl;
        for(j = l-1;j >= hl;j--)
        {
            b[k]=a[j];
            k++;
        }
        b[l]='\0';
        puts(b);
    }
    return 0;
}
