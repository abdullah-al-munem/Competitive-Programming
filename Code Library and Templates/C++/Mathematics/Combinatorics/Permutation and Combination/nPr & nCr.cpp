#include<bits/stdc++.h>
#define Fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define Freed freopen ("0in.txt","r",stdin);
#define Fout freopen ("0out.txt","w",stdout);
#define ll long long int
#define pb push_back
#define mp make_pair
#define pi acos(-1.0)
#define Mod 1000000007
#define limit 1000008
using namespace std;

///nPr O(r)
// arrange things, order matters, no duplicates
ll nPr(ll n,ll r)
{
    ll ans=1;
    for(ll i=n,j=0; j<r; i--,j++)
        ans = (ans*i)%Mod;
    return ans;
}

///nCr O(n*r)
// Select things, order doesn't matters, can have duplicates
long long int ncr[2000][2000];
long long int nCr(long long int n, long long int r)
{
    if(n==r) return 1;
    if(r==1) return n;
    if(ncr[n][r]) return ncr[n][r];
    return ncr[n][r] = (nCr(n-1,r-1)+nCr(n-1,r))%Mod;
}


int  main()
{
    ll n,r;
    cin >> n >> r;

    cout <<nPr(n,r)<<endl;
    cout <<nCr(n,r)<<endl;

    return 0;
}
