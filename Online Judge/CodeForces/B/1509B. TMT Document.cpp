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

    int t, cs = 1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        char str[n];
        int t=0, m=0, flg = 1;
        for(int i=0; i<n; i++)
            cin >> str[i];

        /*if(str[0] == 'M')
            flg = 0;*/

        for(int i=0; i<n; i++){
            if(str[i]=='T')
                t++;
            else{
                m++;
                if(m>t)
                    flg = 0;
            }
        }
        t=0,m=0;
        for(int i=n-1; i>=0; i--){
            if(str[i]=='T')
                t++;
            else{
                m++;
                if(m>t)
                    flg = 0;
            }
        }

        if(2*m != t || t != 2*m)
            flg = 0;

        if(flg)
            cout << "YES\n";
        else
            cout << "NO\n";

    }

    return 0;
}

