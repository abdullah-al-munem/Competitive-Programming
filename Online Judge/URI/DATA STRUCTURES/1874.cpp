#include <bits/stdc++.h>
using namespace std;;

int main()
{
    int n,m,x;
    while(1){
        int c=0;
        scanf("%d",&n);
        scanf("%d",&m);
        scanf("%d",&x);
        if(n == 0 && m == 0 && x == 0)
            return 0;
        int arr[n][m],i,j;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++)
                scanf("%d",&arr[i][j]);
        }
        for(i=m-1;i>=0;i--){
            if(c == x)
                break;
            for(j=n-1;j>=0;j--){
                if(c == x)
                    break;
                else if(arr[j][i] == 0){
                    scanf("%d",&arr[j][i]);
                    c++;
                }

            }

        }
        for(i=0;i<n;i++){
            for(j=0;j<m;j++)
                printf("%d ",arr[i][j]);
            printf("\n");
        }

    }

    return 0;
}
