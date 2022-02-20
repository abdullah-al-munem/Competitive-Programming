#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define Mod 1000000007
using namespace std;

int main(){
    int a,b;
    cin >> a >> b;

    int m = min(a,b);

    if(m%2==0)
        cout << "Malvika\n";
    else
        cout << "Akshat\n";

    return 0;
}



