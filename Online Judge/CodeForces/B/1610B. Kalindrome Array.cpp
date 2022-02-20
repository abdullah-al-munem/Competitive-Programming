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

int isPalindrome(vl v, int n){

    for(ll i=0; i<n/2; i++){
        if(v[i] != v[n-i-1])
            return 0;
    }
    return 1;
}

vl copy1(vl v, ll a){
    vl v2;
    for(int i=0; i<v.size(); i++){
        if(v[i] != a)
            v2.pb(v[i]);
    }

    return v2;
}

void printV(vl v){
    for(int i=0; i<v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

void solve(){
    int n;
    cin >>n;
    vl v(n);
    for(int i=0; i<n; i++)
        cin >> v[i];

    if(n == 1 || n == 2){
        pr("YES");
        return;
    }
    if(isPalindrome(v,n)){
        pr("YES");
        return;
    }

    int flg;
    for(ll i=0; i<n/2; i++){
        if(v[i] != v[n-i-1]){
            vl v2 = copy1(v, v[i]);
            //printV(v2);
            vl v3 = copy1(v, v[n-i-1]);
            flg = (isPalindrome(v2, v2.size()) || isPalindrome(v3, v3.size()));
            break;
        }
    }

    if(flg)
        pr("YES");
    else
        pr("NO");


}

int main(){
    io;
    int t(1), cs(1);
    cin >> t;
    while(t--)
        solve();

    return 0;
}



