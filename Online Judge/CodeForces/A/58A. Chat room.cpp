#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define Mod 1000000007
using namespace std;

int main(){

    string str, str2, ptn = "hello";
    cin >> str;
    //str.erase(unique(str.begin(), str.end()), str.end());
    int hf = 1, ef = 1, lf = 1, of = 1;
    for(int i=0; str[i] != '\0'; i++){
        if(str[i] == 'h' || str[i] == 'e' || str[i] == 'l' || str[i] == 'o'){
            if(str[i] == 'h' && hf == 1 && ef == 1 && lf == 1 && of == 1){
                str2.pb(str[i]);
                hf = 0;
                //cout << "ih: " << i << endl;
            }
            if(str[i] == 'e' && ef == 1 && lf == 1 && of == 1 && hf == 0){
                str2.pb(str[i]);
                ef = 0;
                //cout << "ie: " << i << endl;
            }
            if(str[i] == 'l' && lf <= 2 && of == 1 && hf == 0 && ef == 0){
                str2.pb(str[i]);
                lf++;
                //cout << "il: " << i << endl;
            }
            if(str[i] == 'o' && of == 1 && lf > 2 && hf == 0 && ef == 0){
                str2.pb(str[i]);
                of = 0;
                //cout << "io: " << i << endl;
            }
        }

    }


    if(str2 == ptn)
        cout << "YES\n";
    else
        cout << "NO\n";

    //cout << str2 << endl;
    return 0;
}

