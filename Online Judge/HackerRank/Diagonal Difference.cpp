#include<iostream>
using namespace std;
int main()
{
    int n,i,j;
    cin >> n;
    int a[n][n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            cin >> a[i][j];
    }
    int s1=0,s2=0,s3;
    for(i=0;i<n;i++)
    {
        for(j=i;j<=i;j++)
            s1 = s1 + a[i][j];
    }
    int m = 1;
    for(i=0;i<n;i++)
    {
        for(j=n-m;j>=n-m;j--)
        {
            s2 = s2 + a[i][j];
        }
        m ++;
    }
    if(s1>s2)
        s3 = s1-s2;
    else
        s3 = s2 - s1;
    cout << s3 <<endl;
    return 0;
}

