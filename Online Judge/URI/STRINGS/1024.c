#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,l=0,n,m;
    char a[100],b[100];
    scanf("%d",&n);
    fflush(stdin);
    //getchar();
    for(i = 0;i < n;i++)
    {
        gets(a);
        l = strlen(a);
        for(j=0;j<l;j++)
        {
            if((a[j]>='A' && a[j]<='Z') || (a[j]>='a' && a[j]<='z'))
                a[j] += 3;
        }
        m=l-1;
        for(j=0;j<l;j++)
        {
            b[j]=a[m];
            m--;
        }
        b[j]='\0';
        for(j = l/2;j < l;j++)
            b[j] -= 1;
        puts(b);
    }
    return 0;
}
