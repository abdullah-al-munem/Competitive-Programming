#include <bits/stdc++.h>
using namespace std;

#define Red 1
#define Green 2

vector<int> adj[10005];
int col[10005];
int n;

bool cmp(vector<int> a[], vector<int> b[]){
    return (a.first > b.first);
}

queue<int> q;
bool bipartite = true;
void bfs(int src){
    col[src] = Red;
    q.push(src);
    int u, v;
    while(!q.empty()){
        u = q.front();
        q.pop();
        for(int i=0; i<adj[u].size(); i++){
            int v = adj[u][i];
            if(col[v]==0){
                if(col[u] == Red)
                    col[v] = Green;
                if(col[u] == Green)
                    col[v] = Red;

                q.push(v);
            }
            else{
                if(col[u] == col[v])
                    bipartite = false;
            }
        }
    }

    if(bipartite)
        cout << "The graph is bipartite\n";
    else
        cout << "The graph is not bipartite\n";

}

int main(){

    int e;
    cin >> n >> e;
    for(int i=0;i<e;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int src;
    cin >> src;
    bfs(src);

    return 0;
}


