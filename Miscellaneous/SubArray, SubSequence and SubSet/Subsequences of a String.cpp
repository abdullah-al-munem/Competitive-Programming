#include <bits/stdc++.h>
using namespace std;

string ans[10005];

int subsequences(string str){
    if(str.size()==0){
        ans[0]="";
        return 1;
    }

    int tmp = subsequences(str.substr(1));

    for(int i=0; i<tmp; i++)
        ans[i+tmp] = str[0]+ans[i];

    return 2*tmp;
}


int main(){
    string str;
    cin >> str;

    int total = subsequences(str);
    for(int i=0; i<total; i++){
        cout << ans[i] << endl;
    }

    return 0;
}
