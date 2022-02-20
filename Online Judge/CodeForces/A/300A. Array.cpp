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
    int n, x;
    cin >> n;
    vector<int> pve, neg, zro;
    for(int i = 0; i < n; ++i) {
        cin >> x;
        if (x == 0)
            zro.pb(x);
        else if (x > 0)
            pve.pb(x);
        else
            neg.pb(x);
    }
    if(pve.size() == 0) {
        x = neg[0];
        pve.pb(x);
        x = neg[1];
        pve.pb(x);
        neg.erase(neg.begin() + 0);
        neg.erase(neg.begin() + 0);
    }
    cout << "1 " << neg[0] << endl;
    cout << pve.size() << " ";
    for(int i = 0; i < pve.size(); ++i){
        cout << pve[i] << " ";
    }
    cout << endl;
    cout << neg.size() + zro.size() - 1 << " ";
    for(int i = 1; i < neg.size(); ++i){
        cout << neg[i] << " ";
    }
    for(int i = 0; i < zro.size(); ++i){
        cout << zro[i] << endl;
    }

    return 0;
}

