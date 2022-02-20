#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
typedef     long long int   ll;
#define     pb              push_back
#define     pii             pair<ll,ll>
#define     gcd(a,b)        __gcd(a,b)
#define     lcm(a,b)        (a*b)/gcd(a,b)

//ax+by = g.c.d(a,b)
//Extended Euclidean Algorithm/ Extended GCD
ll egcd(ll a, ll b, ll &x, ll &y){

    // base case
    if(a == 0){
        x = 0;
        y = 1;
        return b;
    }

    ll x1, y1;
    ll d = egcd(b%a, a, x1, y1);
    // formula
    x = y1 - (b/a)*x1;
    y = x1;

    return d;
}

int main()
{

    ll a, b, x, y;

    cin >> a >> b;

    int ans = egcd(a, b, x, y);
    cout << "GCD: " << ans << "\n";
    printf("x: %lld \ny: %lld \n", x,y);
    return 0;

}


