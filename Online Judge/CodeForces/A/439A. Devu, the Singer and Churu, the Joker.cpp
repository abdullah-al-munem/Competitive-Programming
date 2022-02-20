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

    int n,d;
    cin >> n >> d;
    int arr[n];
    int sum = 0;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        sum += arr[i];
    }

    int m = (n-1)*10;

    sum += m;

    if(sum > d)
        cout << "-1\n";
    else{
        int total = m/5;
        int r = d-sum;
        total += r/5;
        cout << total << endl;
    }

    return 0;
}


