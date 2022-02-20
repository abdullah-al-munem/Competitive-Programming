#include <bits/stdc++.h>
using namespace std;

int main(){

    int a;
    cin >> a;
    if(a&1){
        // odd
        cout << "NO\n";
    }
    else{
        // even
        if(a==2 || a==0)
            cout << "NO\n";
        else
            cout << "YES\n";

    }
    return 0;
}
