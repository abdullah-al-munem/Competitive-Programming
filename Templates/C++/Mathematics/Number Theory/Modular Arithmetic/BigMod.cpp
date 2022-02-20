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

//ll Mod=1e9+7;
#define Mod 1000000007

///Iterative
/*
ll bigmod(ll b, ll p, ll M = Mod)
{
    ll ans=1;
    while(p)
    {
        if(p&1)
            ans = (ans*b) % M;
        b = (b*b) % M;
        p = p/2;
    }
    return ans;
}
*/

///recursive
ll bigmod(ll a, ll b, ll M = Mod)
{
    // a^0 = 1;
    // base case
    if(b==0)
        return (ll)1%M; // 1%M == 1

    ll x = bigmod(a, b/2, M);
    x = (x*x) % M;
    if(b&1)
        x = (a*x) % M;
    return x;

}
/**/

int  main()
{
    ll a,b,m;
    // a^b
    cin >> a >> b >> m;
    cout<<bigmod(a,b,m)<<", ";
    cout<<bigmod(a,b)<<nn;
    cout <<endl;

    return 0;
}


