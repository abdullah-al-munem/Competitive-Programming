#include <bits/stdc++.h>
using namespace std;

// as we can take highest n-1 element at a time, we don't need to check XOR sum
void findWinner(int n, int m){
    if(m == 1) {
        cout<<"2\n"; // Player 1 loses if all towers are height 1 (edge case)
    }
    else if(n % 2 == 0) {
        cout<<"2\n"; // Player 1 loses if there are an even number of towers
    }
    else {
        cout<<"1\n"; // Player 1 wins
    }

}

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        findWinner(n, m);
    }

	return 0;
}
