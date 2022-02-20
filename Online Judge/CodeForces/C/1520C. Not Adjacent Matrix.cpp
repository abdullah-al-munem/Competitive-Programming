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
    int n;
    cin >> n;
    if(n==1){
        outa("1");
        return;
    }
    if(n==2){
        outa("-1");
        return;
    }

    int k=0;
    for(int i=1; i<=n*n; i+=2){
        k++;
        cout << i << " ";
        if(k%n==0)
            cout << endl;
    }
    for(int i=2; i<=n*n; i+=2){
        k++;
        cout << i << " ";
        if(k%n==0)
            cout << endl;
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



