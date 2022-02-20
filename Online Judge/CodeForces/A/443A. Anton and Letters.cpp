#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define Mod 1000000007
using namespace std;

int main(){

    string str;
    getline(cin, str);
    sort(str.begin(), str.end());
    str.erase(unique( str.begin(), str.end() ), str.end());
    //cout << str << endl;
    //int ans = str.size() - 4;
    for(int i=0; i<str.size(); i++){
        if(str[i] == ',' || str[i] == '{' || str[i] == '}' || str[i] == ' '){
            str.erase(str.begin()+i);
            i--;
        }
    }
    cout << str.size() << endl;

    return 0;
}


