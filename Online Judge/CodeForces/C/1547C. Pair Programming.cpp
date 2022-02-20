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
    ll k, n, m;
    cin >> k >> n >> m;
    ll a1[n], a2[m];

    for(int i=0; i<n; i++)
        cin >> a1[i];
    for(int i=0; i<m; i++)
        cin >> a2[i];

    int flg=1, i=0, j=0;
    vl ans;
    while(i<n || j<m){
        if(i<n && a1[i]==0){
            ans.pb(a1[i]);
            k++;
            i++;
        }
        else if(j<m && a2[j]==0){
            ans.pb(a2[j]);
            k++;
            j++;
        }
        else if(i<n && a1[i] <= k)
            ans.pb(a1[i]), i++;
        else if(j<m && a2[j] <= k)
            ans.pb(a2[j]), j++;
        else{
            flg=0;
            break;
        }

    }

    if(flg){
        for(int i=0; i<n+m; i++)
            cout << ans[i] << " ";
        cout << endl;
    }
    else
        pr("-1");

}

int main(){
    io;
    int t(1), cs(1);
    cin >> t;
    while(t--)
        solve();

    return 0;
}



