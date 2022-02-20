#include <bits/stdc++.h>
using namespace std;
int ct2;
void f(int n, char str[], int p, int ct, int ct2, int k){
    if(p==n){
        str[p] = 0; // null character
        cout << str << endl;
        return;
    }

    str[p] = 'a';
    f(n, str, p+1, 0, ct2, k);
    if(ct<1 && ct2 <k){
        str[p] = 'b';
        ct2++;
        f(n, str, p+1, 1, ct2, k);
    }

}

int main(){

    int n, ct=0, k;
    cin >> n >> k;
    char str[1002];
    f(n,str,0, ct, ct2, k);
    return 0;
}
