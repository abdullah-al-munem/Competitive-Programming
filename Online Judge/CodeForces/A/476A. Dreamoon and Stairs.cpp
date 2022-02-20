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


int main(){
    int n, m;
    cin >> n >> m;
    int flg = 1;
    for(int i=(n+1)/2; i<=n; i++){
        if(i%m == 0){
            cout << i << endl;
            flg = 0;
            break;
        }
    }
    if(flg)
        cout << "-1" << endl;


    return 0;
}

