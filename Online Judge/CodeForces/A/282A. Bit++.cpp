#include <bits/stdc++.h>
#include<string>
using namespace std;

int main()
{
    int n,sum=0;
    cin >> n;
    string str;
    for(int i=0; i<n; i++){
        cin >> str;
        int len = str.size();
        if(str[0] == '+')
            sum++;
        else if(str[0] == '-')
            sum--;
        else if(str[len-1] == '+')
            sum++;
        else if(str[len-1] == '-')
            sum--;
    }
    cout << sum <<endl;

    return 0;
}

