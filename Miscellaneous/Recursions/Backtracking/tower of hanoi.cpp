#include <bits/stdc++.h>
using namespace std;

void printMoves(int n, int src, int spare, int dest){
    if(n == 0)
        return;

    printMoves(n-1, src, dest, spare);
    printf("Move from Tower %d to Tower %d\n", src, dest);
    printMoves(n-1, spare, src, dest);

}

int main(){

    printMoves(5, 1, 2, 3);
    return 0;
}
