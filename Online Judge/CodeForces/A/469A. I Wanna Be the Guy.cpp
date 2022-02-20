#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define Mod 1000000007
using namespace std;

int main(){

    int n, p, q;
    cin >> n >> p;
    set<int> s;
    for(int i=0; i<p; i++){
        int a;
        cin >> a;
        s.insert(a);
    }

    cin >> q;
    for(int i=0; i<q; i++){
        int a;
        cin >> a;
        s.insert(a);
    }

    if(s.size() < n)
        cout << "Oh, my keyboard!\n";
    else
        cout << "I become the guy.\n";

    return 0;
}

