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

    set<int> row, column;
    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        for(int j=0; j<m; j++){
            if(str[j] == 'S'){
                row.insert(i);
                column.insert(j);
            }
        }
    }

    int r = row.size();
    int c = column.size();

    cout << (n*m) - (r*c) << endl;

    return 0;
}



