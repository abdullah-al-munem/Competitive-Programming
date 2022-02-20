#include<bits/stdc++.h>
using namespace std;

void checkBalancedArray()
{
    int i,j,n,m;
    cin >> n;
    if(n%4)
    {
        cout <<"NO\n";
        return ;
    }
    cout <<"YES\n";
    for(i=2; i<=n; i+=2)
        cout <<i<<" ";
    for(i=1; i<n-1; i+=2)
        cout <<i<<" ";
    cout <<i+n/2<<endl;
    return ;
}

int  main()
{
    int i,n;
    cin >> n;
    for(i=1; i<=n; i++)
        checkBalancedArray();
    return 0;
}

