#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define Mod 1000000007
using namespace std;


int main()
{
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        int strlen = str.size();
        if(strlen>10){
            string str2;
            str2.pb(str[0]);
            str2.append(to_string(strlen-2));
            str2.pb(str[strlen-1]);
            cout << str2 << endl;
        }
        else
            cout << str << endl;
    }

	return 0;
}


