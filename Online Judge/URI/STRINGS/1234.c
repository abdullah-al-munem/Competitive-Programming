#include<stdio.h>
#include<iostream>
#include<string.h>
int main()
{
    char a[100];
    int i,j,l;
    while(std::cin.getline(a,50))
    {
        //gets(a);
        j=0;
        l=strlen(a);
        for(i = 0;i < l;i++)
        {
            if(a[i]!=' ')
            {
                j++;
                if(a[i]>96 && j%2==1)
                    a[i]-=32;
                else if(a[i]<96 && j%2==0)
                    a[i]+=32;
            }
        }
        a[l]='\0';
        printf("%s\n",a);
    }
    return 0;
}
