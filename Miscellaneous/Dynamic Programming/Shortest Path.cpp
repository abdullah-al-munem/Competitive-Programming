#include <bits/stdc++.h>
using namespace std;

#define MAX_N 20
#define INF 99999999
#define EMPTY_VALUE -1

int memo[MAX_N+1], parent[MAX_N][MAX_N], cost[MAX_N][MAX_N];
int path[MAX_N], nPath;
vector<int>graph[MAX_N];

void initMemo() {
    for (int i = 0; i <= MAX_N; i++) {
        memo[i] = EMPTY_VALUE;
    }
}

void initCost(int v) {
    for (int i = 1; i <= v; i++){
        for (int j = 1; j <= v; j++){
            if(i==j)
                cost[i][j] = 0;
            else
                cost[i][j] = INF;

            parent[i][j] = i;
        }
    }
}

// this function is only applicable for DAG (Directed Acyclic Graph)
// O(n*n)
int shortestPath(int u, int v)
{
    // Base cases
    if (u == v) {
        return 0;
    }

    if (memo[u] != EMPTY_VALUE) {
        return memo[u];
    }

    // Initialize result
    int ans = INF;

    // Go to all adjacent(s) of u and recur
    for (int i = 1; i <= v; i++) {
        if (cost[u][i] != INF && u != i) {
            ans = min(ans, shortestPath(i, v) + cost[u][i]);
        }
    }

    memo[u] = ans;
    return memo[u];
}

// This function will work for both cyclic and acyclic graph
int shortestPath_2(int u, int v, int k)
{
    // Base cases
    if (u == v) {
        return 0;
    }

    if (memo[u] != EMPTY_VALUE) {
        return memo[u];
    }

    if (k <= 0)
        return INF;

    // Initialize result
    int ans = INF;

    // Go to all adjacent(s) of u and recur
    for (int i = 1; i <= v; i++) {
        if (cost[u][i] != INF && u != i) {
            ans = min(ans, shortestPath_2(i, v, k-1) + cost[u][i]);
        }
    }

    memo[u] = ans;
    path[nPath++] = parent[u][v];

    return memo[u];
}


void displayMatrix(int v) {
    int i, j;
    for(i = 1; i <= v; i++) {
       for(j = 1; j <= v; j++) {
          cout << cost[i][j] << " ";
       }
       cout << endl;
    }
    cout << endl;
}

void printPath(int dst){

    cout<< "Path: ";
    for(int i = nPath-1; i>=0; i--){
        cout << path[i] << " -> ";
    }
    cout << dst <<endl;

}

int main()
{
    //freopen("in", "r", stdin);
	int numNodes, numEdges;
    cin>>numNodes>>numEdges;

    //cout<< "1 \n";
    initMemo();
    initCost(numNodes);

    // Add Edges
    for(int i=0;i<numEdges;i++){
        int u, v, w;
        cin>>u>>v>>w;
        graph[u].push_back(v);
        cost[u][v] = w;
    }
    cout << endl;
    //displayMatrix(numNodes);

	int src, dist, k;
    cout << "Input source and distance for finding the shortest path: ";
    cin >> src >> dist;

    k = dist-1;
	//cout << "Weight of the shortest path is " << shortestPath(src, dist) <<endl;

    printf("Weight of the shortest path from %d to %d is: %d\n"
           , src, dist, shortestPath_2(src, dist, k));

    printPath(dist);

	return 0;
}


