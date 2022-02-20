#include <bits/stdc++.h>
using namespace std;

const int DEBUGGER = 0;
#define io ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define Fin freopen("0in.txt","r",stdin);
#define Fout freopen("0out.txt","w",stdout);
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mii map<int, int>
#define umii unordered_map<int, int>
#define uset unordered_set<int>
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
    ll n,x,t;
    cin >> n >> x >> t;

    ll tx = t/x;
    if(tx>n){
        cout << ((n-1)*n)/2 << endl;
        return;
    }

    cout << tx*n - ((tx*(tx+1))/2) << endl;

    /*int st[n], ft[n];
    int df=0;

    st[0] = 0;
    ft[0] = t;
    for(int i=1; i<n; i++){
        st[i] = st[i-1]+x;
        ft[i] = st[i]+t;
    }

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(ft[i]>=st[j])
                df++;
        }
    }

    outa(df);*/
}

int main(){
    io;
    int t(1), cs(1);
    cin >> t;
    while(t--)
        solve();

    return 0;
}
