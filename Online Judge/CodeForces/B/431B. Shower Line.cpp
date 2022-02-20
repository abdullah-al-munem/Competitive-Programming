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
    int g[5][5];
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++)
            cin >> g[i][j];
    }

    int p[5], ans=-1, tmp=0;
    for(int i=0; i<5; i++)
        p[i] = i;

    do{
        //01234
        tmp = g[p[0]][p[1]] + g[p[1]][p[0]];
        tmp += g[p[2]][p[3]] + g[p[3]][p[2]];

        //1234
        tmp += g[p[1]][p[2]] + g[p[2]][p[1]];
        tmp += g[p[3]][p[4]] + g[p[4]][p[3]];

        //234
        tmp += g[p[2]][p[3]] + g[p[3]][p[2]];

        //34
        tmp += g[p[3]][p[4]] + g[p[4]][p[3]];

        ans = max(ans,tmp);
    }
    while(next_permutation(p, p+5));

    pr(ans);

}

int main(){
    io;
    int t(1), cs(1);
    //cin >> t;
    while(t--)
        solve();

    return 0;
}


