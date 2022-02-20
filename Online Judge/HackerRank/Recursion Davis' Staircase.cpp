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

int dp[200100];

int f(int n){
    if(n == 0)
        return 1;

    if(dp[n] != -1)
        return dp[n];

    int op1(0), op2(0), op3(0);
    if(n-1>=0)
        op1 += (f(n-1))%10000000007;
    if(n-2>=0)
        op2 += (f(n-2))%10000000007;
    if(n-3>=0)
        op3 += (f(n-3))%10000000007;

    return dp[n] = (op1+op2+op3)%10000000007;
}

int main(){
    mset(dp,-1);
    int t, cs = 1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << f(n) << endl;
    }
    return 0;
}
