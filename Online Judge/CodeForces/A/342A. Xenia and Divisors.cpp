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

ll ans[3];
void solve(){
    ll n;
    cin >> n;
    ll cnt[8] = {0};
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        cnt[a]++;
    }
    int flg=1;
    for(int i=0; i<n/3; i++){
        if(cnt[4] > 0 && cnt[2] > 0 && cnt[1] > 0){
            ans[0]++, cnt[4]--, cnt[2]--, cnt[1]--;
            continue;
        }
        if(cnt[6] > 0 && cnt[2] > 0 && cnt[1] > 0){
            ans[1]++, cnt[6]--, cnt[2]--, cnt[1]--;
            continue;
        }
        if(cnt[6] > 0 && cnt[3] > 0 && cnt[1] > 0){
            ans[2]++, cnt[6]--, cnt[3]--, cnt[1]--;
            continue;
        }
        flg = 0;
        break;
    }
    if(flg == 0)
        pr("-1");
    else{
        for(int i=0; i<ans[0]; i++)
            pr("1 2 4");
        for(int i=0; i<ans[1]; i++)
            pr("1 2 6");
        for(int i=0; i<ans[2]; i++)
            pr("1 3 6");
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



