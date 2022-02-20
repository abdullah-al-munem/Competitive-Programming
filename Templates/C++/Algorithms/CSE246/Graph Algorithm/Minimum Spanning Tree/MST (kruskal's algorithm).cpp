#include <bits/stdc++.h>
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
int sz[MAXN];
vector<edge> adj;

void init(int n){

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

int mst(int n)
{
    sort(adj.begin(), adj.end());
    init(n);

    int ct = 0, s = 0;

    for(int i = 0; i < (int)adj.size(); i++) {
        int u = findRoot(adj[i].u);
        int v = findRoot(adj[i].v);
        if(u != v) {
            if(sz[u] >= sz[v]){
                par[v] = u;
                sz[u] = sz[u]+sz[v];
            }
            else{
                par[u] = v;
                sz[v] = sz[u]+sz[v];
            }
            ct++;
            s += adj[i].w;
            if(ct == n - 1)
                break;
        }
    }
    return s;
}

/*
void print_path(int n){
    cout << "The path is: ";
    for(int i=1; i<=n; i++)
        cout << par[i] << " --> " << i << " cost: " << adj[i].w << endl;

}
*/

int main()
{

    int n, e;
    cin >> n >> e;
    for (int i = 1; i <= e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge get;
        get.u = u;
        get.v = v;
        get.w = w;
        adj.push_back(get);
    }
    cout << "Minimum Cost Path: " << mst(n) << endl;
    //print_path(n);

    return 0;
}


