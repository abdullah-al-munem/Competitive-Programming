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
    int arr[n], h[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];

    int mn = INT_MAX, mx = INT_MIN;

    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1; j++){
            if(arr[j+1]-arr[j] > mx)
                mx = arr[j+1]-arr[j];
        }
    }

    for(int i=0; i<n-2; i++){
        for(int j=0; j<n-2; j++){
            if(arr[j+2]-arr[j] < mn)
                mn = arr[j+2]-arr[j];
        }
    }

    if(mx > mn)
        cout << mx << endl;
    else
        cout << mn << endl;


    return 0;
}



