#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define Mod 1000000007
using namespace std;

int main(){

    string str1, str2;
    cin >> str1 >> str2;
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    if(str1 < str2)
        cout << "-1\n";
    else if(str1 > str2)
        cout << "1\n";
    else
        cout << "0\n";

    return 0;
}
