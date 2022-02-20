#include <bits/stdc++.h>
using namespace std;

const int DEBUGGER = 0;
#define io ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define Fin freopen("0in.txt","r",stdin);
#define Fout freopen("0out.txt","w",stdout);
#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define mll map<ll, ll>
#define umll unordered_map<ll, ll>
#define uset unordered_set<ll>
#define pb push_back
#define pf push_front
#define mp make_pair
#define ff first
#define ss second
#define outa(a) cout<<a<<endl
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
    ll n, m;
    cin >> n >> m;
    mll mp;
    for(int i=0; i<n; i++){
        ll x;
        cin >> x;
        ll y=x%m;
        mp[y]++;
    }

    ll ct=0;
    for(auto i : mp){
        dbg(i.ff);
        if(i.ff == 0 && i.ss > 0)
            ct++;
        else if(mp.count(m-i.ff) == 0)
            ct += i.ss;
        else if(m-i.ff == i.ff)
            ct++;
        else if(m-i.ff > i.ff){
            ll a = i.ss;
            ll b = mp[m-i.ff];
            if(abs(a-b)<=1)
                ct++;
            else if(a>b){
                a -= (b+1);
                ct++;
                ct += a;
            }
            else{
                b -= (a+1);
                ct++;
                ct += b;
            }
        }
    }

    outa(ct);

}

int main(){
    io;
    int t(1), cs(1);
    cin >> t;
    while(t--)
        solve();

    return 0;
}


