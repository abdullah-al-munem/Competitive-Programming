#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define Mod 1000000007
using namespace std;

int main(){

    int x1,y1,x2,y2,x3,y3,x4,y4;
    cin >> x1 >> y1 >> x2 >> y2;
    int distX = abs(x1-x2);
    int distY = abs(y1-y2);

    if(x1==x2){
        y3=y1;
        y4=y2;
        x3=x4=x1+abs(y1-y2);
        cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
    }
    else if(y1==y2){
        x3=x1;
        x4=x2;
        y3=y4=y1+abs(x1-x2);
        cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
    }
    else if(distX == distY)
        cout << x1 << " " << y2 << " " << x2 << " " << y1 <<endl;
    else
        cout<<-1<< endl;

    return 0;
}


