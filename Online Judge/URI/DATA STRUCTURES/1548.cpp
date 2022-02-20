#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    cin.ignore();
    while(n--)
    {
        int m;
        cin>>m;
        int a[m],b[m];
        for(int i=0;i<m;i++)
        {
            cin>>a[i];
            b[i]=a[i];
        }
        sort(a,a+m,greater<int>());
        int count=0;
        for(int i=0;i<m;i++)
        {
            if(a[i]==b[i])
                count++;
        }
        cout<<count<<endl;
        cin.ignore();
    }
    return 0;

}
