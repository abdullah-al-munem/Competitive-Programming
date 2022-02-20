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

    int n, c;
    cin >> n >> c;
    int arr[n], mx = INT_MIN, pos;

    for(int i=0; i<n; i++)
        cin >> arr[i];

    for(int i=0; i<n-1; i++){
        if(arr[i]-arr[i+1] > mx){
            mx = arr[i]-arr[i+1];
            pos = i;
        }
    }

    int rem = arr[pos] - arr[pos+1] - c;
    if(rem > 0)
        cout << rem << endl;
    else
        cout << "0" << endl;

    return 0;
}

