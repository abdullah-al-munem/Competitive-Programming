#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define Mod 1000000007
using namespace std;

int main(){

    int n, k;
    cin >> n >> k;
    int ct(0);
    while(n--){
        string s;
        cin >> s;
        int l(0);
        for(int i=0; i<s.size(); i++){
            if(s[i] == '4' || s[i] == '7')
                l++;
        }
        if(l<=k)
            ct++;
    }
    cout << ct << endl;
    return 0;
}

