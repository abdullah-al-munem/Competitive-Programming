#include <bits/stdc++.h>
using namespace std;

void f(int n, char binary[], int p){
    if(p==n){
        binary[p] = 0; // null character
        cout << binary << endl;
        return;
    }
    binary[p] = '0';
    f(n, binary, p+1);
    binary[p] = '1';
    f(n, binary, p+1);

}

int main(){

    int n;
    cin >> n;
    char binary[n+1];
    f(n,binary,0);
    return 0;
}
