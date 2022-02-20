#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define Mod 1000000007
using namespace std;

int main(){

    ll n, k;
    cin >> n >> k;

    ll od = n/2;
    if(n%2==1)
        od++;

    ll ans;
    if(k<=od)
        ans = (2*k)-1;
    else
        ans = (k-od)*2;

    cout << ans << endl;

    return 0;
}


