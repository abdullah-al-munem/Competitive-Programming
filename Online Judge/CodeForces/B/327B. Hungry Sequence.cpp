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

bool mark[10000007];
vl prime;
void sieve(int n){

    int i,j;
    for(int i=1; i<n; i++)
        mark[i]=true;
    mark[1]=false;
    for(i=4; i<=n; i+=2)
        mark[i]=false;
    for(i=3; i*i<=n; i+=2){
        if(mark[i]){
            for(j=i*i; j<n; j+=i+i)
                mark[j]=false;
        }
    }
    prime.push_back(2);
    for(i=3; i<=n; i+=2)
    {
        if(mark[i])
            prime.push_back(i);
    }
}

void solve(){
    int n;
    cin >> n;
    sieve(10000005);
    dbg(prime.size());
    for(int i=0; i<n; i++)
        cout << prime[i] << " ";

    cout << endl;

}

int main(){
    io;
    int t(1), cs(1);
    //cin >> t;
    while(t--)
        solve();

    return 0;
}



