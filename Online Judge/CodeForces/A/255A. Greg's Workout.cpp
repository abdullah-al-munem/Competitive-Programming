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

    int n;
    cin >> n;
    int arr[n+1];
    int c=0, bi=0, ba=0;
    for(int i=0; i<n; i++)
        cin >> arr[i];

    for(int i=0; i<n; i+=3)
        c += arr[i];

    for(int i=1; i<n; i+=3)
        bi += arr[i];

    for(int i=2; i<n; i+=3)
        ba += arr[i];

    if(c > bi && c > ba)
        cout << "chest\n";
    else if(bi > c && bi > ba)
        cout << "biceps\n";
    else
        cout << "back\n";

    return 0;
}



