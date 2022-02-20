#include <bits/stdc++.h>
using namespace std;

int coins[10007][10007];
int r, c;
int dp[10007][10007];
char choices[10007][10007];
int letsRock(int cr, int cc){
    if(cr == r-1 && cc == c-1){
        return coins[r-1][c-1];
    }
    if(dp[cr][cc] != -1)
        return dp[cr][cc];
    if(cr == r-1){
        choices[cr][cc] = 'R';
        return coins[cr][cc]+letsRock(cr,cc+1);
    }
    if(cc == c-1){
        choices[cr][cc] = 'D';
        return coins[cr][cc]+letsRock(cr+1,cc);
    }

    int right = coins[cr][cc]+letsRock(cr,cc+1);
    int down = coins[cr][cc]+letsRock(cr+1,cc);
    if(right > down){
         choices[cr][cc] = 'R';
         return dp[cr][cc] = right;
    }

    choices[cr][cc] = 'D';
    return dp[cr][cc] = down;
}

void path_print(){
    int cr = 0;
    int cc = 0;
    cout << "Max Total: " << letsRock(0, 0) << endl;
    while(cr != r-1 || cc != c-1){
        if(choices[cr][cc] == 'R'){
            cout << "R\n";
            cc++;
            //cout << "cc " << cc << endl;
        }
        else{
            cout << "D\n";
            cr++;
            //cout << "cr " << cr << endl;
        }
    }
}

int main(){

    cin >> r >> c;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> coins[i][j];
        }
    }
    for(int i=0; i<=r; i++){
        for(int j=0; j<=c; j++)
            dp[i][j] = -1;
    }
    path_print();
    //cout << f(0,0) << endl;

    return 0;
}

