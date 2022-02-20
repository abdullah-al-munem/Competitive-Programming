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
    transform(str.begin(), str.end(), str.begin(), ::tolower);

    for(int i=0; i<strlen; i++){
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'y')
            continue;

        str2.pb('.');
        str2.pb(str[i]);
    }
    cout << str2 << endl;

    return 0;
}
