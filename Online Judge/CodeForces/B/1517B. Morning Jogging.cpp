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

multiset<pii> mst;
int arr[101][101];

void solve(){
    mst.clear();
    int n, m;
    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            arr[i][j] = -1;
            int a;
            cin >> a;
            mst.insert(mp(a,i));
        }
    }

    for(int i=0; i<m; i++){
        auto itr = mst.begin();
        arr[(*itr).ss][i] = (*itr).ff;
        mst.erase(itr);
    }

    while(!mst.empty()){
        auto itr = mst.begin();
        int j = 0;
        while(arr[itr->ss][j] != -1)
            j++;
        arr[itr->ss][j] = itr->ff;
        mst.erase(itr);
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }

}

int main(){
    io;
    int t=1;
    cin >> t;
    while(t--)
        solve();

    return 0;
}

