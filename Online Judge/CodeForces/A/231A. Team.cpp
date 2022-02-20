#include <bits/stdc++.h>
#include<string>
using namespace std;

int main()
{
    int n,a,b,c;
    cin >> n;
    int flg = 0;
    for(int i=0; i<n; i++){
        cin >> a >> b >> c;
        int sum = a+b+c;
        if(sum >=2)
            flg++;
    }
    cout << flg <<endl;
    return 0;
}

