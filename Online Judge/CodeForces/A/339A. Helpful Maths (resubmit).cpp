#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define Mod 1000000007
using namespace std;


int main(){

    string str, str2;
    cin >> str;
    int strlen = str.size();
    sort(str.begin(), str.end());

    for(int i=0; i<strlen; i++){
        if(str[i] == '+')
            continue;

        str2.pb(str[i]);
        if(i!=(strlen-1))
            str2.pb('+');

    }
    cout << str2 << endl;

    return 0;
}
