#include <bits/stdc++.h>
using namespace std;

const int DEBUGGER = 0;
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
    ll n, k;
    cin >> n >> k;
    vl v(n);
    set<int> st;
    for(int i=0; i<n; i++){
        cin >> v[i];
        st.insert(v[i]);
    }

    if(st.size()==1){
        pr("0");
        return;
    }

    ll tmp = v[k-1];
    int flg=1;
    for(int i=k; i<n; i++){
        if(v[i] != tmp){
            flg=0;
            break;
        }
    }

    ll cnt=0;
    for(int i=k-2; i>0; i--){
        if(v[i] != tmp)
            break;
        if(v[i] == tmp)
            cnt++;
    }
    dbg(cnt);
    // -(k-p)
    if(flg)
        pr(k-1-cnt);
    else
        pr("-1");


}

int main(){
    io;
    int t(1), cs(1);
    //cin >> t;
    while(t--)
        solve();

    return 0;
}



