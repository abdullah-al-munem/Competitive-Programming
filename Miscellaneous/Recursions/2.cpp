#include <bits/stdc++.h>
using namespace std;

void f(int n, int s, int d, int sp1, int sp2){
    if(n<=0)
        return;

    f(n-1, s, sp1, sp2, d);
    f(n-2, sp1, sp2, s, d);
    printf("Move from Tower %d to Tower %d\n", s, d);
    printf("Move from Tower %d to Tower %d\n", sp1, d);
    f(n-2, sp2, d, s, sp1);
}

int main(){

    f(3, 1, 4, 2, 3);
    return 0;
}
