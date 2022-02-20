//Code cycles through an array
// Meaning after the last element you get the 1st element

#include <iostream>

using namespace std;

int main(void)
{
    const int sz= 5;
    int a[sz]= {1,2,3,4,5};
    int n;
    cin >> n;
    //Cycle through the array a
    for(int i=0, j=0; j<n; i = (i+1)%sz, j++){
        cout<< a[i] <<" ";

        //cin.get();
    }
    cout << endl;
    return 0;
}

