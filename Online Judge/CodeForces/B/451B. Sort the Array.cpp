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
    ll n;
    cin >> n;
    ll arr[n];
    ll rev[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];

    int st=-1, ed=n, flg=0;
    for(int i=1; i<n; i++){
        if(arr[i-1]<arr[i] && flg==1){
            ed = i;
            break;
        }
        if(arr[i-1]>arr[i] && flg==0){
            st = i;
            flg=1;
        }
    }

    dbg(st);
    dbg(ed);

    if(st!=-1)
        reverse(arr+st-1,arr+ed);

    flg=0;
    for(int i=1; i<n; i++){
        if(arr[i]<arr[i-1]){
            flg=1;
            break;
        }
    }

    if(flg)
        pr("no");
    else if(st==-1)
        pr("yes\n1 1");
    else
        cout << "yes\n" << st << " " << ed << endl;

}

int main(){
    io;
    int t(1), cs(1);
    //cin >> t;
    while(t--)
        solve();

    return 0;
}



