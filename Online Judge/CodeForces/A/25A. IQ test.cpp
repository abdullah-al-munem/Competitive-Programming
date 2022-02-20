#include <bits/stdc++.h>
#define Fin freopen("0in.txt","r",stdin);
#define Fout freopen("0out.txt","w",stdout);
#define ll long long int
#define pii pair<int, int>
#define mii map<int, int>
#define umii unordered_map<int, int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mset(a,v) memset(a,v,sizeof(a))
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define M_PI 3.14159265358979323846
#define Mod 1000000007
using namespace std;

int main(){

    int t;
    cin >> t;
    while(t--){
        ll n,w;
        cin >> n >> w;
        vector<int> ct(21);
        for(ll i=0; i<n; i++){
            int a;
            cin >> a;
            ct[log2(a)]++;
        }

        ll h = 0;
        ll t = n;

        while(t>0){
            ll u = w;
            for(int i=19; ~i; i--) { // ~i means i>=0
                while(ct[i]>0 && u >= (1<<i)) // 1<<i means 2^i
                    u -= (1<<i),ct[i]--,t--;
            }
            h++;
        }

        cout << h << endl;

    }
    return 0;
}

