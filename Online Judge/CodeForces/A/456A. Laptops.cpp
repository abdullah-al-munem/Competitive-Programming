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

struct Laptop{
    int price;
    int quality;
};

bool cmp(Laptop a, Laptop b){
    return a.price < b.price;
}

int main(){

    int n;
    cin >> n;
    Laptop arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i].price >> arr[i].quality;

    sort(arr, arr+n, cmp);

    bool flg = false;
    for(int i=1; i<n; i++){
        if(arr[i].quality < arr[i-1].quality){
            flg = true;
            break;
        }
    }

    if(flg)
        cout << "Happy Alex\n";
    else
        cout << "Poor Alex\n";

    return 0;
}


