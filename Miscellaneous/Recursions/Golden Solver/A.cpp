#include <bits/stdc++.h>
using namespace std;

/// Please read this comment...
/* It was a great workshop Sir. We hope that you will continue a series of
   workshop in different topics for us. Recursion and dp both are same actually,
   I don't think we need any workshop of dp after this. I sincerely request you to
   take a workshop on those topics which you think that we might need to.

   Thank You Sir.

*/
int isPrime(int n){
    if(n<=1)
        return 0;

    int limit = sqrt(n+1);
    for(int i=2; i<=limit; i++){
        if(n%i == 0)
            return 0;
    }
    return 1;
}

bitset<20> rem;
void f(int n, int pos, int arr[]){
    if(pos == n){
        if(!isPrime(arr[n-1] + 1))
            return;
        cout << arr[0];
        for(int i=1; i<n; i++)
            cout << " " << arr[i];
        cout << endl;
        return;
    }

    for(int i=2; i<=n; i++){
        if(!rem[i]){
            if(isPrime(i+arr[pos-1])){
                arr[pos] = i;
                rem[i] = 1;
                f(n, pos+1, arr);
                rem[i] = 0;
            }
        }
    }

}

int main(){
    int cs = 0;
    int n;
    while(cin>>n){
        int arr[n];
        arr[0] = 1;
        if(cs)
            cout << endl;
        cs++;
        printf("Case %d:\n", cs);
        f(n, 1, arr);
    }

    return 0;
}
