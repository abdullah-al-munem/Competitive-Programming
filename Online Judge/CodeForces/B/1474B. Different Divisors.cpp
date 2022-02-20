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

#define limit 1000008

bool vis[limit];
vector<int>prime;
void seive()
{
    vis[0]=vis[1]=1;
    for(int i=4; i<limit; i+=2) vis[i] = 1;
    for(int i=3; i*i<limit; i+=2)
    {
        if(vis[i]) continue;
        for(int j=i*i; j<limit; j+=2*i)
        {
            vis[j] = 1;
        }
    }
    prime.pb(1);
    prime.pb(2);
    for(int j=3; j<limit; j+=2)
        if(vis[j]==0)
            prime.pb(j);
}


void solve(){

    ll d, a,b;
    cin >> d;
    int idx;
    for(int i=1; i<prime.size(); i++){
        if(prime[i]-1 >= d){
            a=prime[i];
            idx=i;
            break;
        }
    }
    for(int i=idx+1; i<prime.size(); i++){
        if(prime[i]-a >= d){
            b=prime[i];
            break;
        }
    }

    cout << a*b << endl;

}

int main(){
    io;
    seive();
    int t(1), cs(1);
    cin >> t;
    while(t--)
        solve();

    return 0;
}



