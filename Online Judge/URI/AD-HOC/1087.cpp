#include<bits/stdc++.h>
using namespace std;

int  main()
{
    while(1){

        int a,b,c,d;
        cin >> a >> b >> c >> d;
        if(a==0 && b==0 && c==0 && d==0)
            break;

        if(a == c && b == d)
            cout << "0\n";
        else if(a+b == c+d)
            cout << "1\n";
        else if(a == c || b == d)
             cout << "1\n";
        else if((c-a) == -(d-b) || -(c-a) == -(d-b) || -(c-a) == (d-b) || (c-a) == (d-b))
            cout << "1\n";
        else
            cout << "2\n";
    }

    return 0;
}


