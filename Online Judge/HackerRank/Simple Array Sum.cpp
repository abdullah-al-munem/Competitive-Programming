#include<iostream>
using namespace std;
int main()
{
    int n,i;
    cin >> n;
    int a[n];
    for(i=0;i<n;i++)
        cin >> a[i];
    int s = 0;
    for(i=0;i<n;i++)
        s = s+a[i];
    cout << s << endl;
}

