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
    io;
    int n;
    cin >> n;
    int u = 0, l = 0, pos = -1;
    for(int i=0; i<n; i++){
        int a,b;
        cin >> a >> b;
        if(a&1)
            u++;
        if(b&1)
            l++;
        if(a&1 && b&1)
            pos = i;
    }
    if(l%2==0 && u%2==0)
        cout << "0\n";
    else if(l == 1 && u == 1 && pos != -1)
        cout << "-1\n";
    else if(l == n && u == n && n%2 == 1)
        cout << "-1\n";
    else if(l%2==1 && u%2==1)
        cout << "1\n";
    else
        cout << "-1\n";

    return 0;
}

