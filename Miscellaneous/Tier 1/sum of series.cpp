#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n,a;
    cin >> n;
    while(n--){
        cin >> a;
        //int b = a-1; // number of pairs
        int sum = (a*(a+1))/2;
        cout << sum << endl;
    }

    return 0;
}

