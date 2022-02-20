#include<iostream>
using namespace std;
long int catalan( int n) {
    // Base case
    if (n <= 1){
        return 1;
    }
    long int result = 0;
    // catalan(n) is sum of
    // catalan(i)*catalan(n-i-1)
    for (int i=0; i<n; i++){
        result += catalan(i)*catalan(n-i-1);
    }
    return result;
}

int main(){
    int n;
    cin >> n;
    /*
    for (int i=0; i<=n; i++)
        cout << catalan(i) << " ";
    */
    cout << catalan(n) <<endl;
    return 0;
}

