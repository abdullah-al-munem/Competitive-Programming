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

int main(){
    int n, m;
    cin >> n >> m;
    int ac[n], wa[m];
    int mx = INT_MIN, mn = INT_MAX, mn2 = INT_MAX;

    for(int i=0; i<n; i++){
        cin >> ac[i];
        if(ac[i]>mx)
            mx = ac[i];
        if(ac[i]<mn2)
            mn2 = ac[i];
    }

    for(int i=0; i<m; i++){
        cin >> wa[i];
        if(wa[i] < mn)
            mn = wa[i];
    }
    int ans, flg = 0;
    if(mx>=mn){
        flg = 0;
    }
    else if(2*mn2 <= mx){
        ans = mx;
        flg = 1;
    }
    else{
        for(int i=mx+1; i<mn; i++){
            mx++;
            if(2*mn2<=mx){
                flg = 1;
                ans = mx;
                break;
            }
        }
    }

    if(flg)
        cout << ans << endl;
    else
        cout << "-1\n";

    return 0;
}

