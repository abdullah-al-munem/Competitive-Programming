
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,t,l;
    string s;
    string orginal_string = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    cin >> n;
    while(n--){
        bool b = true;
        int p = 0;
        cin >> t;
        cin >> s;
        for(int i = 0; i < t; i++){
            if(s[i] != orginal_string[i]){
               if(orginal_string[i] != s[((int)(s[i]) - 65)] or p > 0){
                     b = false;
                     break;
               }else{
                   swap(s[i],s[((int)(s[i]) - 65)]);
                   p++;
               }
            }
        }
     cout << ((b == true and p < 2)? "There are the chance.\n" : "There aren't the chance.\n");
    }
    return 0;
}
