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

void cmb(int idx,ll sum,vector<ll>& v,vector<ll>& num){
    if(idx==num.size()){
        v.pb(sum);
        return;
    }
    cmb(idx+1,sum,v,num);
    cmb(idx+1,(sum*10 + num[idx]),v,num);
}

bool isprime(ll n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return 0;
    }
    return 1;
}

void solve(){
    ll n;
    string s;
    cin >> n >> s;

    vl num;
    umll a;
    for(ll i=0; i<n; i++){
        ll b = s[i]-'0';
        a[b]++;
        num.pb(b);
    }

    vl np{1,4,6,8,9};
    for(int i=0; i<np.size(); i++){
        if(a[np[i]] > 0){
            pr(1);
            pr(np[i]);
            return;
        }
    }

    vl p{2,3,5,7};
    for(int i=0; i<p.size(); i++){
        if(a[p[i]] > 1){
            pr(2);
            cout << p[i] << p[i] << endl;
            return;
        }
    }

    //{2,3,5,7,23,25,27,235,237,257,35,37,357,57,2357};
    vl v;
    cmb(0,(ll)0,v,num);
    sort(all(v));
    /*for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    } */
    cout << endl;
    for(int i=1; i<v.size(); i++){
        if(!isprime(v[i])){
            ll val=v[i], cnt=0;
            while(val){
                cnt++;
                val/=10;
            }

            pr(cnt);
            pr(v[i]);
            return;
        }
    }

}

int main(){
    io;
    int t(1), cs(1);
    cin >> t;
    while(t--)
        solve();

    return 0;
}



