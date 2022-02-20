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
#define outa(a) cout<<a<<endl
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
    int n;
    cin >> n;
    ll arr[n];
    int d=1,a=1, p=0;
    for(int i=0; i<n; i++)
        cin >> arr[i];

    if(n<=2){
        outa("0");
        return;
    }

    for(int i=1; i<n; i++){
        if(arr[i]<arr[i-1])
            a=0;
        if(arr[i]>arr[i-1])
            d=0;
    }
    dbg(a);
    dbg(d);
    if(a || d){
        int dif1 = abs(arr[0]-arr[1]);
        int flg = 1;
        for(int i=1; i<n-1; i++){
            int dif2 = abs(arr[i]-arr[i+1]);
            if(dif2 != dif1){
                flg = 0;
                break;
            }
        }
        if(flg)
            outa("0");
        else
            outa("-1");
        return;
    }
    ll c=0, m=0;
    for(int i=1; i<n-1; i++){
        if(arr[i]<arr[i-1] && arr[i]<arr[i+1]){
            c = arr[i+1] - arr[i];
            m = (arr[i-1]+c)-arr[i];
            break;
        }
        else if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
            c = arr[i] - arr[i-1];
            m = (arr[i]+c)-arr[i+1];
            break;
        }
    }

    //ll c = arr[p] - arr[p-1];
    //ll m = (arr[p]+c)-arr[p+1];


    if(arr[0] >= m || m==0)
        outa("-1");
    else{
        int flg = 1;
        for(int i=0; i<n-1; i++){
            if((arr[i]+c)%m != arr[i+1]){
                flg = 0;
                break;
            }
        }
        if(flg)
           cout << m << " " << c << endl;
        else
            outa("-1");
    }


}

int main(){
    io;
    int t(1), cs(1);
    cin >> t;
    while(t--)
        solve();

    return 0;
}


