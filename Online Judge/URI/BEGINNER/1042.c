#include <stdio.h>

void bubble_sort (int a[], int n)
{
    int i,j,flag,temp;
    for(i = 0; i<10; i++)
    {
      flag = 0;
      for(j = 0; j<2; j++)
      {
       if(a[j] > a[j+1])
       {
         flag = 1;
        temp = a[j+1];
        a[j+1] = a[j];
        a[j] = temp;
       }
      }
       if(flag == 0)
        break;
    }
    for(i=0;i<n;i++)
         printf("%d\n",a[i]);
}



int main()
{
    int a[3],i,x,y,z;
    for(i=0;i<3;i++)
        scanf("%d",&a[i]);
    x= a[0];
    y= a[1];
    z= a[2];
    bubble_sort(a,3);
    printf("\n");
    printf("%d\n%d\n%d\n",x,y,z);

  return 0;
}

