#include <bits/stdc++.h>
#include<string>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    int arr[n], flg=0;

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int sc = arr[m-1];
    for(int i=0; i<n; i++){
            if(arr[i]>=sc && arr[i]>0)
                flg++;
        }
        cout << flg <<endl;

    return 0;
}

