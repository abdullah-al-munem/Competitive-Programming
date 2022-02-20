#include <bits/stdc++.h>
using namespace std;

int n;
struct Box{
    int coins;
    int weight;
};

Box b[1005];
int cap;
int dp[1005][1005];
int choice[1005][1005];

int knapsack(int i, int rem){

    if(i==n)
        return 0;
    if(dp[i][rem] != -1)
        return dp[i][rem];

    int opt1 = knapsack(i+1, rem);
    int opt2 = 0;
    if(b[i].weight <= rem){
        opt2 = b[i].coins + knapsack(i+1, rem-b[i].weight);
    }

    if(opt1 >= opt2){
        choice[i][rem] = 0;
        return dp[i][rem] = opt1;
    }

    choice[i][rem] = 1;
    return dp[i][rem] = opt2;
}

int main(){

    cin >> n >> cap;

    for(int i=0; i<n; i++)
        cin >> b[i].coins >> b[i].weight;

    for(int i=0; i<=n; i++){
        for(int j=0; j<=cap; j++)
            dp[i][j] = -1;
    }

    cout << knapsack(0, cap) << endl;
    cout << "The boxes numbered ";

    int box = 0;
    int rem = cap;
    while(box != n){
        if(choice[box][rem] == 0){
            box++;
        }
        else{
            cout << box << " ";
            rem -= b[box].weight;
            box++;
        }
    }

    cout << "should be taken\n";

    return 0;
}
