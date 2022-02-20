#include<stdio.h>
#include<iostream>

using namespace std;

struct DSU{

    int n;
    int par[];
    int sz[];
    void init(){

        for(int i = 1; i<=n; i++){

            par[i] = -1;
            sz[i] = 1;
        }

    }

    int findRoot(int u){

        while(par[u]!=-1){

            u = par[u];
        }

        return u;
    }

    void unionDS(int a, int b){

        a = findRoot(a);
        b = findRoot(b);

        if(sz[a] >= sz[b]){

            par[b] = a;
            sz[a] = sz[a]+sz[b];
        }
        else{

            par[a] = b;
            sz[b] = sz[a]+sz[b];
        }
    }

    int query(int a, int b){

        a = findRoot(a);
        b = findRoot(b);

        if(a == b)
            return 1;
        else
            return 0;
    }

};


int main(){




    return 0;
}



