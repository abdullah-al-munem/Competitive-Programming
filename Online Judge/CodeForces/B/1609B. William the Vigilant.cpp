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
    ll n, q;
    string s;
    cin >> n >> q >> s;
    string ptn = "abc";
    ll cnt = 0;
    for(int i=0; i<n-2; i++){
        if(s[i] == ptn[0] && s[i+1] == ptn[1] && s[i+2] == ptn[2]){
            cnt++;
            i+=2;
        }
    }
    n--;
    while(q--){
        ll p;
        char ch;
        cin >> p >> ch;
        p--;

        if(s[p] == ch)
            goto x;

        if(s[p] == 'a' && p <= n-2){
            if(s[p+1] == 'b' && s[p+2] == 'c')
                cnt--;
        }
        else if(s[p] == 'b' && p <= n-1 && p >= 1){
            if(s[p-1] == 'a' && s[p+1] == 'c')
                cnt--;
        }
        else if(s[p] == 'c' && p>=2){
            if(s[p-2] == 'a' && s[p-1] == 'b')
                cnt--;
        }

        s[p] = ch;

        if(ch == 'a' && p <= n-2){
            if(s[p+1] == 'b' && s[p+2] == 'c')
                cnt++;
        }
        else if(ch == 'b' && p <= n-1 && p >= 1){
            if(s[p-1] == 'a' && s[p+1] == 'c')
                cnt++;
        }
        else if(ch == 'c' && p>=2){
            if(s[p-2] == 'a' && s[p-1] == 'b')
                cnt++;
        }

        x:
        cout << cnt << endl;
    }

}

int main(){
    io;
    int t(1), cs(1);
    //cin >> t;
    while(t--)
        solve();

    return 0;
}



