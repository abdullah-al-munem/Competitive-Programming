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
#define mset2(a,v) memset(&a,v,sizeof(a))
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define M_PI 3.14159265358979323846
#define Mod 1000000007
using namespace std;

int main(){
    int t, cs = 1;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int arr[n];
        for(int i=0; i<n; i++)
            arr[i] = i+1;

        int ct = 0;
        int p = (n-1)/2;
        if(k==0){
            for(int i=0; i<n; i++)
                cout << i+1 << " ";
            cout << endl;
        }
        else if(k>p)
            cout << "-1\n";
        else{
            int j = 1;
            for(int i=0; i<k; i++){
                swap(arr[j], arr[j+1]);
                j+=2;
            }
            for(int i=0; i<n; i++)
                cout << arr[i] << " ";
            cout << endl;
        }
    }

    return 0;
}

