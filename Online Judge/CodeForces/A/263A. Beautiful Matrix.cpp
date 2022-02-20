#include <bits/stdc++.h>
#include<string>
using namespace std;

int main() {

    int sum = 0, tmp;
    int arr[5][5], loc1, loc2;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j< 5; j++){
            cin >> arr[i][j];
            if(arr[i][j]==1){
                loc1 = i+1;
                loc2 = j+1;
            }
        }
    }

    if(loc1 > 3)
        sum = sum + (loc1-3);
    else
        sum = sum + (3-loc1);

    if(loc2 > 3)
        sum = sum + (loc2-3);
    else
        sum = sum + (3-loc2);

    cout << sum << endl;

    return 0;
}


