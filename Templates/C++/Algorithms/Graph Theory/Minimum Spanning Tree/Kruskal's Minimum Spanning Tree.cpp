#include<bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include<vector>
#include <list>
using namespace std;
#define MAXN 100000

struct edge {
    int u, v, w;
    bool operator<(const edge& p) const
    {
        return w < p.w;
    }
};

int par[MAXN];
vector<edge> e;

void init(int n){

    for(int i = 1; i<=n; i++){
        par[i] = -1;
    }
}

int findRoot(int u){
    while(par[u]!=-1){
        u = par[u];
    }
    return u;
}

int mst(int n)
{
    sort(e.begin(), e.end());
    init(n);

    int count = 0, s = 0;
    for (int i = 0; i < (int)e.size(); i++) {
        int u = findRoot(e[i].u);
        int v = findRoot(e[i].v);
        if (u != v) {
            par[u] = v;
            count++;
            s += e[i].w;
            if (count == n - 1)
                break;
        }
    }
    return s;
}

int main()
{
    // READ("in");
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge get;
        get.u = u;
        get.v = v;
        get.w = w;
        e.push_back(get);
    }
    cout << "Minimum Cost Path: " << mst(n) << endl;
    return 0;
}


