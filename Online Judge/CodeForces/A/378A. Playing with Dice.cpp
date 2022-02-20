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

    int a, b;
    cin >> a >> b;
    int f=0, s=0, d=0;
    for(int i=1; i<=6; i++){
        if(abs(a-i)<abs(b-i))
            f++;
        else if(abs(a-i)>abs(b-i))
            s++;
        else
            d++;
    }

    cout << f << " " << d << " " << s << endl;

    return 0;
}


