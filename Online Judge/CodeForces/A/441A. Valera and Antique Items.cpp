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
    int n, v;
    cin >> n >> v;
    vector<int> vect;

    for(int i=1; i<=n; i++){
        int a;
        cin >> a;
        bool flg = false;
        for(int j=0; j<a; j++){
            int e;
            cin >> e;
            if(v>e)
                flg = true;
        }

        if(flg)
            vect.pb(i);
    }

    cout << vect.size() << endl;
    for(int i=0; i<vect.size(); i++){
        cout << vect[i] << " ";
    }
    cout << endl;

    return 0;
}



