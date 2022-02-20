#include<iostream>
using namespace std;
int main()
{
    int n,i;
    cin >> n;
    long long a[n];
    for(i=0;i<n;i++)
        cin >> a[i];
    long long s;
    for(i=0;i<n;i++)
        s = s+a[i];
    cout << s <<endl;
    return 0;
}

