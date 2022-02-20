#include <bits/stdc++.h>
#include<vector>
using namespace std;

vector<int> arr[100];
int in[101], low[101], vis[101];
int timer;

void dfs(int node, int par){

    vis[node] = 1;
    in[node] = low[node] = timer;
    timer++;

    for(int child : arr[node]){
        if(child == par) continue;

        if(vis[child] == 1){
            //edge node - child is a back edge
            //put in value of the ancestor of this node
            low[node] = min(low[node], in[child]);
        }
        else{
            //edge node - child is a forward edge
            dfs(child, node);

            if(low[child] > in[node])
                cout<< node << " - " << child << " is a bridge\n";

            low[node] = min(low[node], low[child]);

        }

    }

}


int main(){

    int n, m, x, y;
    cin>>n>>m;
    while(m--)
        cin>>x>>y, arr[x].push_back(y), arr[y].push_back(x);

    dfs(1, -1);
    return 0;
}
