#include<iostream>
using namespace std;
int main()
{
    int a[3],b[3],k=0,l=0,i;
    for(i=0;i<3;i++)
        cin >> a[i];
    for(i=0;i<3;i++)
        cin >> b[i];
    for(i=0;i<3;i++)
    {
        if(a[i]>b[i])
            k++;
        if(a[i]<b[i])
            l++;
        if(a[i]==b[i])
            continue;
    }
    cout << k <<" " << l <<endl;
    return 0;
}

