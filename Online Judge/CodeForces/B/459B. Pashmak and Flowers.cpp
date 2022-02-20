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

    for(ll i=0; i<n; i++)
        cin >> arr[i];

    sort(arr, arr+n);

    ll mn = arr[n-1]-arr[0], cnt1,cnt2,i;
    cnt1 = cnt2 = i =1;
    while(i < n && arr[i] == arr[i-1]){
        cnt1++;
        i++;
    }

    if(i==n){
        cout << mn << " " << (n*(n-1))/2 << endl;
        return;
    }

    i=n-2;
    while(arr[i] == arr[i+1]){
        cnt2++;
        i--;
    }

    cout << mn << " " << cnt1*cnt2 << endl;

}

int main(){
    io;
    int t(1), cs(1);
    //cin >> t;
    while(t--)
        solve();

    return 0;
}



