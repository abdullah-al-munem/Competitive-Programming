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

    string str;
    cin >> str;
    sort(str.begin(), str.end());
    str.erase(std::unique(str.begin(), str.end()), str.end());
    int len = str.size();
    if(len%2==0)
        cout << "CHAT WITH HER!\n";
    else
        cout << "IGNORE HIM!\n";
    return 0;
}

