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
#define r(a) a.begin(),a.end()
#define mset(a,v) memset(a,v,sizeof(a))
#define mset2(a,v) memset(&a,v,sizeof(a))
#define dsort(a) sort(a,a+n,greater<int>())
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define dbg(a) if(DEBUGGER)cout<<#a<<" = "<<a<<endl
#define M_PI 3.14159265358979323846
#define Mod 1000000007

void solve(){
    int n;
    cin >> n;
    ll arr[n], sum = 0;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        sum ^= arr[i];
    }

    if(sum == 0){
        cout << "YES\n";
        return;
    }
    ll cum[n+1];
    cum[n] = 0;
    for(int i=n-1; i>=0; i--)
        cum[i] = arr[i]^cum[i+1];

    ll n1=0,n2=0,n3=0;
    for(int i=0; i<n-2; i++){
        n1 ^= arr[i];
        n2=0;
        for(int j=i+1; j<n-1; j++){
            n2 ^= arr[j];
            n3 = cum[j+1];
            if(n1==n2 && n2==n3){
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
    return;
}

int main(){
    io;
    int t=1;
    cin >> t;
    while(t--)
        solve();

    return 0;
}

