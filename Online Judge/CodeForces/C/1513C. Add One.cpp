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
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mset(a,v) memset(a,v,sizeof(a))
#define mset2(a,v) memset(&a,v,sizeof(a))
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define dbg(a) if(DEBUGGER)cout<<#a<<" = "<<a<<endl
#define M_PI 3.14159265358979323846
#define Mod 1000000007

ll d[200015];

int main(){
    io;
    int t, cs = 1;
    cin >> t;
    for(int i=0; i<10; i++)
        d[i] = 1;
    d[10] = 2;
    for(int i=11; i<200015; i++){
        d[i] = d[i-11+2]+d[i-11+1];
        if(d[i] >= Mod)
            d[i] -= Mod;
    }


    while(t--){
        ll n, m;
        cin >> n >> m;
        string s = "";
        while(n!=0){
            s+=(n%10)+'0';
            n/=10;
        }
        reverse(s.begin(),s.end());

        ll len = 0;
        int limit = s.size();
        for(int i=0; i<limit; i++){
            len = len+d[s[i]-'0'+m];
            if(len >= Mod)
                len -= Mod;
        }

        cout << len << endl;
    }

    return 0;
}

