#include<bits/stdc++.h>
using namespace std;

bitset<20> used;
int number[20];

// call with: permutation(1, n);
// all the entries in used is 0 initially
// n = total number, at = the position for putting numbers
void permutation(int at, int n){

    //base case
    if(at == n+1){
        for(int i=1; i<=n; i++)
            printf("%d ", number[i]);
        printf("\n");
        return;
    }
    // The used bit-set for checking a number in already placed or not.
    // Because we start i form 1 every times.
    for(int i=1; i<=n; i++) if(!used[i]){

        used[i] = 1;
        number[at] = i;
        permutation(at+1, n);
        used[i] = 0;
    }
}

int main(){

    int n;
    cin >> n;
    permutation(1, n);

    return 0;
}


