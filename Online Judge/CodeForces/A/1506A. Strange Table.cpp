#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){

    int t;
    cin >> t;
    while(t--){
        ll n,m,x;
        cin >> n >> m >> x;
        x--;
        ll r = x%n;
        ll c = x/n;
        cout << r*m + c + 1 << endl;

    }
    return 0;
}
