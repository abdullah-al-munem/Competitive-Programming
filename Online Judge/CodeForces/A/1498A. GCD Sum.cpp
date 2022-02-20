#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define Mod 1000000007
using namespace std;

ll sumDigits(ll num){
    ll m, sum = 0;
    while(num != 0){
        m = num%10;
        sum = sum + m;
        num /= 10;
    }

    return sum;
}

int main(){
    //int gcd = __gcd(a, b);
    int t;
    cin >> t;
    while(t--){
        ll a;
        cin >> a;
        ll sum = sumDigits(a);
        ll ans;
        //cout << sum << endl;
        while(1){
            if(__gcd(a, sum) > 1){
                ans = a;
                break;
            }
            a++;
            sum = sumDigits(a);
        }

        cout << ans << endl;
    }
    return 0;
}
