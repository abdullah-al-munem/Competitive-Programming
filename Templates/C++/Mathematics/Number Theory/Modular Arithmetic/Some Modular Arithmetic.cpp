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

/*

    Some formulas:
    a1 = b1(mod n)
    a2 = b2(mod n)

    a1 + a2 = b1 + b2(mod n)
    a1 - a2 = b1 - b2(mod n)
    a1 * a2 = b1 * b2(mod n)

    for big numbers:

     A^B mod C = ( (A mod C)^B ) mod C
    (A + B) mod C = (A mod C + B mod C) mod C
    (A - B) mod C = (A mod C - B mod C) mod C
    (A * B) mod C = (A mod C * B mod C) mod C

    b * b^-1 = 1 (mod n)

*/


// for series
int findSum(int n, int M) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
        sum %= M;
    }
    return sum;
}

int findFactorial(int n, int M) {
  int factorial = 1;
  for (int i = 1; i <= n; i++) {
    factorial *= i;
    factorial %= M;
  }
  return factorial;
}


int  main()
{


    return 0;
}


