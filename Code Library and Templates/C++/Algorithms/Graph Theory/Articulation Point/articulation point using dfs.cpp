#include <bits/stdc++.h>
#include<vector>
using namespace std;

vector<int> arr[100];
int in[101], low[101], vis[101];
int timer;
bool isArticulationPoint[101];
int parent[101];

void dfs(int node, int par){

    vis[node] = 1;
    in[node] = low[node] = timer;
    timer++;
    int noOfChildren = 0;
    for(int child : arr[node]){
        int v = child;
        if(child == par) continue;
        parent[v] = node;
        if(vis[child] == 1){
            //edge node - child is a back edge
            //put in value of the ancestor of this node
            low[node] = min(low[node], in[child]);
        }
        else{
            //edge node - child is a forward edge
            dfs(child, node);

            if(low[child] >= in[node] && node != par)
                isArticulationPoint[node] = 1;

            low[node] = min(low[node], low[child]);

            noOfChildren++;

        }

    }

    if(node == par and noOfChildren > 1) isArticulationPoint[node] = 1;

}


int main(){

    int n, m, x, y;
    cin>>n>>m;
    int i=1;
    while(i<=m){
        cin>>x>>y, arr[x].push_back(y), arr[y].push_back(x);
        i++;
    }

    dfs(1, 1);
    int c = 0;
    for(int i = 1; i<=n;i++){
		if (isArticulationPoint[i]) {
			cout<<i<<endl;
			c++;
		}
	}
	if(c==0)
        cout << "No articulation point has been found!\n";

    return 0;

}
