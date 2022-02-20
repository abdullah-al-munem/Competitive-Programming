#include<iostream>
#include <iomanip>
using namespace std;
int main()
{
    int i,j,k,n;
    cin >> n;
    for(i=0;i<n;i++)
    {
        for(j=i;j<n-1;j++)
            cout << " ";
        for(k=0;k<=i;k++)
            cout << "#";
        cout << endl;
    }
    return 0;
}

