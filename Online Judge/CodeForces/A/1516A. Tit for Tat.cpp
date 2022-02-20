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
#define all(a) a.begin(),a.end()
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
    int t, cs = 1;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int arr[n];

        for(int i=0; i<n; i++)
            cin >> arr[i];

        for(int i=0; i<n; i++){
            while(arr[i]>0 && k>0){
                arr[i]--;
                arr[n-1]++;
                k--;
            }
        }

        for(int i=0; i<n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    return 0;
}