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
    int arr[n+2], t1 = 0, t2 = 0, t3 = 0;
    list<int> one, two, three;
    list<int>::iterator it1,it2,it3;

    for(int i=1; i<=n; i++){
        cin >> arr[i];
        if(arr[i] == 1){
            t1++;
            one.pb(i);
        }
        else if(arr[i] == 2){
            t2++;
            two.pb(i);
        }
        else{
            t3++;
            three.pb(i);
        }
    }
    it1 = one.begin();
    it2 = two.begin();
    it3 = three.begin();

    if(t1 == 0 || t2 == 0 || t3 == 0)
        cout << "0\n";
    else{
        int total = min(t1,min(t2,t3));
        cout << total << endl;
        for(int i=0; i<total; i++){
            cout << *it1 << " " << *it2 << " " << *it3 << endl;
            it1++, it2++, it3++;
        }
    }

    return 0;
}


