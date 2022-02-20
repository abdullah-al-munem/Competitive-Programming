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

ll sum(ll n){
    if(n==0)
        return 0;

    return n%10+sum(n/10);
}

void sup(ll n){
    ll a = sum(n);
    if(a < 10){
        cout << a << endl;
        return;
    }
    sup(a);
}

int main(){
    //cout << sup(9875) << endl;
    string n;
    int k;
    cin >> n >> k;
    ll sum = 0;
    ll limit = n.size();
    for(int i=0; i<limit; i++){
        ll a = n[i]-'0';
        sum += a;
    }
    dbg(sum);

    sum *= k;
    sup(sum);
    return 0;
}
