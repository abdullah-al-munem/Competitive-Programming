#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);

    int l = 2*n-1;
    for(int r=0; r<l; r++)
    {
      for(int c=0; c<l; c++)
      {
        int m = r<c? r:c;
        m=m<l-r? m:l-r-1;
        m=m<l-c? m:l-c-1;
        printf("%d ",n-m);
      }

      printf("\n");
    }

    return 0;
}

