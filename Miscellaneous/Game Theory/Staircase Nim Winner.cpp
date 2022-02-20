#include <bits/stdc++.h>
using namespace std;

vector<int> tree[50004], cost[50004];
int findLevel(vector<int> adj[], int s, int dest, int v);

void addEdge(int s, int d) {
    tree[s].push_back(d);
    tree[d].push_back(s);
}

string findWinner(int n, int levels[])
{
	int res = 0;
	for (int i = 1; i <= n; i++){
        // odd
        if(levels[i]&1){
            /* cause the XOR sum of even number x are always zero.
               So we can ignore those. And the the XOR sum of odd number
               x are always x. Thus, we can count once.
            */
            int e = cost[i][0];
            res ^= e;
        }
	}


	if (res > 0)
		return "First";
	else
		return "Second";
}


int main(){

    int n = 6;
    addEdge(1,2);
    addEdge(1,3);
    addEdge(2,6);
    addEdge(3,4);
    addEdge(3,5);

    cost[1].push_back(0);
    cost[2].push_back(2);
    cost[3].push_back(2);
    cost[4].push_back(1);
    cost[5].push_back(3);
    cost[6].push_back(2);

    int levels[n+1];
    for(int i=1;i<=n;i++){
        levels[i] = findLevel(tree, 1, i, n);
    }

    cout << findWinner(n, levels) << endl;


}

bool BFS(vector<int> adj[], int src, int dest, int v, int parent[], int dist[])
{

	queue<int> q1;
	bool visited[v];
	for (int i = 1; i <= v; i++) {
		visited[i] = false;
		dist[i] = INT_MAX;
		parent[i] = -1;
	}
	visited[src] = true;
	dist[src] = 0;
	q1.push(src);

	while (!q1.empty()) {
		int u = q1.front();
        q1.pop();
		for (int i = 0; i < adj[u].size(); i++) {
			if (visited[adj[u][i]] == false) {
				visited[adj[u][i]] = true;
				dist[adj[u][i]] = dist[u] + 1;
				parent[adj[u][i]] = u;
				q1.push(adj[u][i]);

				if (adj[u][i] == dest){
                    return true;
				}
			}
		}
	}


	return false;
}

int findLevel(vector<int> adj[], int s, int dest, int v)
{
	int dist[v];
	int parent[v];

	if (BFS(adj, s, dest, v, parent, dist) == false) {
        //cout << "you shouldn't come here :p\n";
		return 0;
	}

	return dist[dest];
}

