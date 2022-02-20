#include <bits/stdc++.h>
#include<string>
using namespace std;

int main() {

    string str, str2, str3;
    cin >> str;
    int len = str.size();

    for(int i=0; i<len; i++){
        if(str[i] != '+'){
            str2.push_back(str[i]);
        }
    }

    sort(str2.begin(), str2.end());
    len = str2.size();
    for(int i=0; i<len; i++){
        str3.push_back(str2[i]);
        if(i != len-1){
            str3.push_back('+');
        }
    }
    cout << str3 <<endl;

    return 0;
}


