#include<bits/stdc++.h>
using namespace std;

// queen[i] = column number of queen at i th row
int queen[20];

// arrays to mark if there is queen or not. we can use bit-set instead of array
int column [20], diagonal_1[40], diagonal_2[40];

// call with nQueen(1, 8) for 8 queen problem
// column, diagonal_1 and diagonal_2 are all 0 initially
// n = number of queen and also the chess board is n*n
// at = the position for putting the queens
void nQueen(int at, int n){

    //base case
    if(at == n+1){

        printf("(row, column) = ");
        for(int i=1; i<=n; i++)
            printf("(%d, %d) ", i, queen[i]);
        printf("\n");
        return;
    }

    for(int i=1; i<=n; i++){

        /* subtract of left to right diagonal positions of columns and rows are
           equal.
           For example if initial position, n = 8, column = 6 and row = 1 then,
           it will be 6-1 = 7-2 = ... = 5

           sum of right to left diagonal positions of columns and rows are
           equal.
           For example if initial position, n = 8, column = 8 and row = 1 then,
           it will be 8+1 = 7+2 = ... = 9

           we are not checking the row because we are putting queen in row wise.

        */
        if(column[i] || diagonal_1[i+at] || diagonal_2[n+i-at])
            continue;

        queen[at] = i;
        /* i-at can be negative and we can not have negative indexed array.
           so we are adding offset n with this to make it positive.
        */
        column[i] = diagonal_1[i+at] = diagonal_2[n+i-at] = 1;

        nQueen(at+1, n);
        column[i] = diagonal_1[i+at] = diagonal_2[n+i-at] = 0;
    }
}

int main(){

    int n;
    cin >> n;
    nQueen(1, n);

    return 0;
}
