#include <bits/stdc++.h>
#include<string>
using namespace std;

int main()
{
    int n;
    string a;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a;
        int len = a.size();
        if(len>10){
            cout<< a[0] << len-2 << a[len-1] <<endl;
        }
        else
            cout<< a <<endl;
    }
    return 0;
}

