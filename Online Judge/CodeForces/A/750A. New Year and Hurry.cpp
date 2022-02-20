#include <bits/stdc++.h>
#include<string>
using namespace std;

int main() {

    int totalMin = 240;
    int n,k, eTime = 0, count=0;
    cin >> n >> k;
    int rMin = totalMin - k;
    for(int i=1; i<=n; i++){
        eTime = eTime+(5*i);
        if(eTime <= rMin)
            count++;
    }
    cout << count << endl;
    return 0;
}


