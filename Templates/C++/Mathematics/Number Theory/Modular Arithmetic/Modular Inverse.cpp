#include<bits/stdc++.h>
using namespace std;
typedef     long long int   ll;
typedef     long double     ld;
typedef     vector<ll>      vll;
#define     fi              first
#define     print(v)        for(ll i:v) cout<<i<<ss
#define     se              second
#define     pb              push_back
#define     nn              "\n"
#define     all(p)          p.begin(),p.end()
#define     zz(v)           (ll)v.size()
#define     S(a)            scanf("%lld",&a)
#define     SS(a,b)         scanf("%lld %lld",&a,&b)
#define     SSS(a,b,c)      scanf("%lld %lld %lld",&a,&b,&c)
#define     ss              ' '
#define     pii             pair<ll,ll>
#define     gcd(a,b)        __gcd(a,b)
#define     lcm(a,b)        (a*b)/gcd(a,b)
const double eps = 1e-7;

ll Mod=1e9+7;

//Extended Euclidean Algorithm
void EEA(ll a, ll b, ll &x, ll &y){

    // base case
    if(a == 1){
        x = 1;
        y = 0;
        return;
    }

    ll x1, y1;
    EEA(b%a, a, x1, y1);
    // formula
    x = y1 - (b/a)*x1;
    y = x1;

}

ll modInverse(ll a, ll m){

    if(gcd(a,m) != 1)
        return -1;
    ll x, y;
    EEA(a, m, x, y);
    // for the value of x return a value under 0 to m,
    //+m because x can be negative but we want positive value
    x = (x%m+m)%m;
    return x;
}

int main()
{

    ll a,m;
    // a^-1%m
    while(cin>>a>>m)
    {
        ll x = modInverse(a,m);
        cout<<x<<ss;
        cout << (x*a)%m; // always, it will be return 1 if the modInverse is correct
        cout << nn;
    }

    return 0;

}

