#include<bits/stdc++.h>
using namespace std;

int number[20];
int n, k;

// call with: permutation(1, 0);
// at = the position for putting numbers, last = the last input number
void combination(int at, int last){

    //base case
    if(at == k+1){
        for(int i=1; i<=k; i++)
            printf("%d ", number[i]);
        printf("\n");
        return;
    }
    /* k-at always less then n-i, after putting i in at, there are
       n-i numbers and k-at positions left. So, k-at always less than or equal
       to n-i.
       Thus,  k-at <= n-i
            -> i <= n-k+at

        i = last+1 because, in this case(for combination) order doesn't matters.
        So we have to avoid repetition. Otherwise, if we start with i = 1, then
        it will print both (1,2) and (2,1) for example.
    */
    for(int i = last+1; i <= n-k+at; i++){

        number[at] = i;
        combination(at+1, i);
    }
}

int main(){

    cin >> n >> k;
    combination(1, 0);

    return 0;
}
