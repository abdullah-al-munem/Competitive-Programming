#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define Mod 1000000007
using namespace std;

int main(){

    int a,b,c, mx = INT_MIN;
    cin >> a >> b >> c;

    if(a+b*c > mx)
        mx = (a+b*c);
    if(a*(b+c) > mx)
         mx = a*(b+c);
    if(a*b*c > mx)
         mx = a*b*c;
    if((a+b)*c > mx)
         mx = (a+b)*c;
    if(a*b+c > mx)
         mx = a*b+c;
    if(a+b+c > mx)
         mx = a+b+c;


    cout << mx << endl;

    return 0;
}

