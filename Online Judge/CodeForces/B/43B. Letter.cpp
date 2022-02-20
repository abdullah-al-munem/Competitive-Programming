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
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    //cout << s1 << "\n" << s2 << endl;
    map<char,int> mp;
    for(int i=0; i<s1.length(); i++)
        mp[s1[i]]++;

    int flg=1;
    for(int i=0; i<s2.length(); i++){
        if(mp[s2[i]]>0 || s2[i]==' '){
            mp[s2[i]]--;
            continue;
        }
        else{
            flg=0;
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
    //cin >> t;
    while(t--)
        solve();

    return 0;
}



