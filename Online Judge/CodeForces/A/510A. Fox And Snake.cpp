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
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            int pos;
            if(i%2==1)
                cout << "#";
            else{
                if(j==m && flg == 1 && pos != i){
                    cout << "#";
                    flg = 0;
                    pos = i;
                }
                else if(j == 1 && flg == 0 && pos != i){
                    cout << "#";
                    flg = 1;
                    pos = i;
                }
                else
                    cout << ".";
            }
        }
        cout << endl;
    }

    return 0;
}


