#include <bits/stdc++.h>
#define Fin freopen("0in.txt","r",stdin);
#define Fout freopen("0out.txt","w",stdout);
#define ll long long int
#define pii pair<int, int>
#define mii map<int, int>
#define umii unordered_map<int, int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mset(a,v) memset(a,v,sizeof(a))
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define M_PI 3.14159265358979323846
#define Mod 1000000007
using namespace std;

bool cmp(pii a, pii b){
    return (a.first < b.first);
}

int main(){
    int s,n;
    cin >> s >> n;
    vector<pii> v;
    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        v.pb(mp(a,b));
    }
    sort(v.begin(), v.end(), cmp);

    int flg = 1;
    for(int i=0; i<n; i++){
        if(v[i].ff >= s)
            flg = 0;
        else
            s += v[i].ss;
    }

    if(flg)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
