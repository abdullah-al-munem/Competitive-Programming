#include <bits/stdc++.h>
using namespace std;

const int DEBUGGER = 1;
#define io ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define Fin freopen("0in.txt","r",stdin);
#define Fout freopen("0out.txt","w",stdout);
#define ll long long
#define vl vector<ll>
#define pll pair<ll, ll>
#define mll map<ll, ll>
#define umll unordered_map<ll, ll>
#define uset unordered_set<ll>
#define pb push_back
#define pf push_front
#define mp make_pair
#define ff first
#define ss second
#define pr(a) cout<<a<<endl
#define all(a) a.begin(),a.end()
#define mset(a,v) memset(a,v,sizeof(a))
#define mset2(a,v) memset(&a,v,sizeof(a))
#define dsort(a) sort(a,a+n,greater<int>())
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define dbg(a) if(DEBUGGER)cout<<#a<<" = "<<a<<endl
#define M_PI 3.14159265358979323846
#define Mod 1000000007


void solve(){
    ll n;
    cin >> n;
    vl v(n);
    for(int i=0; i<n; i++)
        cin >> v[i];

    sort(all(v));

    int idx=-1, mn = INT_MAX;
    for(int i=1; i<n; i++){
        if(v[i]-v[i-1] < mn){
            mn = v[i]-v[i-1];
            idx = i;
        }
    }

    vl v2, v3;
    for(int i=0; i<n; i++){
        if(i==idx || i==idx-1)
            continue;

        if(v[i]>v[idx-1])
            v2.pb(v[i]);
        if(v[i]<=v[idx])
            v3.pb(v[i]);
    }

    cout << v[idx-1] << " ";
    for(int i=0; i<v2.size(); i++)
        cout << v2[i] << " ";
    for(int i=0; i<v3.size(); i++)
        cout << v3[i] << " ";
    pr(v[idx]);

}

int main(){
    io;
    int t(1), cs(1);
    cin >> t;
    while(t--)
        solve();

    return 0;
}



