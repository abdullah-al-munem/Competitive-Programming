#include<stdio.h>
#include<string.h>
int main()
{
    int i,n,l,j,s;
    char a[100];
    scanf("%d",&n);
    getchar();
    for(i = 0;i < n;i++)
    {
        s=0;
        scanf("%s",&a);
        //l = strlen(a);
        for(j = 0;a[j]!='\0';j++)
        {
            if(a[j]=='1')
                s+=2;
            else if( a[j]=='2' || a[j]=='3' || a[j]=='5')
                s+=5;
            else if( a[j]=='4')
                s+=4;
            else if( a[j]=='0' || a[j]=='9' || a[j]=='6')
                s+=6;
            else if( a[j]=='7')
                s+=3;
            else if( a[j]=='8')
                s+=7;
        }
        printf("%d leds\n",s);
    }
    return 0;
}

