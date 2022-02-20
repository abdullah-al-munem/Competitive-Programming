#include <bits/stdc++.h>
using namespace std;

// iterative
bool findWinner(int n){
    bool winner[n+1];

    winner[0] = false;
    winner[1] = true;

    for(int i=2; i<=n; i++){
        if(winner[i-1] == false || winner[i-2] == false)
            winner[i] = true;
        else
            winner[i] = false;
    }

    cout << "The winning states are: ";
    for(int i=0; i<=n; i++){
        if(!winner[i])
            cout << i << " ";
    }
    cout << endl;

    return winner[n];

}

// dp array
bool win[100];
// recursive
bool findWinner_1(int n){

    // base case
    if(n == 0){
        win[0] = false;
        return win[0];
    }

    if(n == 1){
        win[1] = true;
        return win[0];
    }


    if(findWinner_1(n-1) == false || findWinner_1(n-2) == false){
        win[n] = true;
        return win[n];
    }

    win[n] = false;
    return win[n];

}

int main()
{
	int n = 21, x = 1, y = 2;
	if (findWinner_1(n)) // If A is not in losing state
		cout << "Winner: A\n";
	else
		cout << "Winner: B\n";

	return 0;
}
