#include <bits/stdc++.h>
#include<string>
using namespace std;

int main() {

    string str;
    cin >> str;
    if(str[0] > 92)
        str[0] -= 32;
    cout << str <<endl;

    return 0;
}


