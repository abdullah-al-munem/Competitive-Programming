#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define Mod 1000000007
using namespace std;

int main ()
{
    string dSong, rSong;
    cin >> rSong;
    int len = rSong.size();
    for(int i=0; i<len; i++){
        //WUB
        if(rSong[i] == 'W' && rSong[i+1] == 'U' && rSong[i+2] == 'B'){
            if(!dSong.empty())
                dSong.push_back(' ');
            i+=2;

        }
        else{
            dSong.push_back(rSong[i]);
            //cout << rSong[i] << " ";
        }
    }

    len = dSong.size();
    for(int i=0; i<len; i++){
        if(dSong[i] == ' ' && dSong[i+1] == ' '){
            dSong.erase(i,1);
            //i++;
            //cout << "i: " << i <<endl;
        }
        if(dSong[i] == ' ' && dSong[i-1] == ' '){
            dSong.erase(i-1,1);
            //i++;
        }
    }

    cout << dSong << endl;

    return 0;
}
