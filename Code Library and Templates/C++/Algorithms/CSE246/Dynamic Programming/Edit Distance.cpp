#include <bits/stdc++.h>
using namespace std;
string w1;
string w2;
int l1, l2;
int dp[1005][1005]; // row>=l1+1, col>= l2+1
char choices[1005][1005];

int f(int p1, int p2){
    if(p1==l1){
        for(int i=p2, j=p1; i<=l2-p2; i++, j++){
            choices[j][i] = 'I';
        }
        return l2-p2;
    }
    if(p2==l2){
        for(int i=p1, j=p2; i<l1-p1; i++, j++){
            choices[i][j] = 'D';
        }
        return l1-p1;
    }

    if(dp[p1][p2] != -1)
        return dp[p1][p2];

    if(w1[p1]==w2[p2]){
        choices[p1][p2] = 'N';
        return f(p1+1, p2+1);
    }


    int ins = 1+f(p1, p2+1);
    int rep = 1+f(p1+1, p2+1);
    int del = 1+f(p1+1, p2);

    if(ins <= rep && ins <= del){
        choices[p1][p2] = 'I';
        return dp[p1][p2] = ins;
    }

    if(rep <= ins && rep <= del){
        choices[p1][p2] = 'R';
        return dp[p1][p2] = rep;
    }

    choices[p1][p2] = 'D';
    return dp[p1][p2] = del;

}

void print_steps(){
    int p1 = 0;
    int p2 = 0;
    cout << "Min step: " << f(0,0) << endl;
    int limit = max(l1,l2);
    if(l1>l2){
        while(p1 != l1){
            if(choices[p1][p2] == 'I'){
                cout << "Insert\n";
                p2++;
            }
            else if(choices[p1][p2] == 'R'){
                cout << "Replace\n";
                p1++;
                p2++;
            }
            else if(choices[p1][p2] == 'N'){
                cout << "Next\n";
                p1++;
                p2++;
            }
            else{
                cout << "Delete\n";
                p1++;
            }
            /*cout << "p1: " << p1 << endl;
            cout << "p2: " << p2 << endl;
            p1++;
            p2++;*/
        }
    }
    else{
        while(p2 != l2){
            if(choices[p1][p2] == 'I'){
                cout << "Insert\n";
                p2++;
            }
            else if(choices[p1][p2] == 'R'){
                cout << "Replace\n";
                p1++;
                p2++;
            }
            else if(choices[p1][p2] == 'N'){
                cout << "Next\n";
                p1++;
                p2++;
            }
            else{
                cout << "Delete\n";
                p1++;
            }
            /*cout << "p1: " << p1 << endl;
            cout << "p2: " << p2 << endl;
            p1++;
            p2++;*/
        }
    }

}

int main(){
    memset(&dp, -1, sizeof(dp));
    cin >> w1 >> w2;
    l1 = w1.size();
    l2 = w2.size();

    //cout << f(0,0) << endl;
    print_steps();

    return 0;
}

