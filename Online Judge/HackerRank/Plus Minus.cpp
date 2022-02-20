#include<iostream>
#include <iomanip>
using namespace std;
int main()
{
    double k=0,l=0,m=0;
    int n,i;
    cin >> n ;
    int a[n];
    for(i=0;i<n;i++)
        cin >> a[i];
    for(i=0;i<n;i++)
    {
        if(a[i]>0)
            k++;
        else if(a[i]<0)
            l++;
        else if(a[i]==0)
            m++;
    }
    double p,ne,z;
    p = k/n;
    ne = l/n;
    z = m/n;

    cout<<fixed<<setprecision(6)<<p<<endl;
    cout<<fixed<<setprecision(6)<<ne<<endl;
    cout<<fixed<<setprecision(6)<<z<<endl;
    return 0;
}

