#include<bits/stdc++.h>
#include <stdio.h>
#include<stdlib.h>
#include <iostream>
#include<queue>
#include<vector>
#include <limits.h>
using namespace std;

/// unweighted graph
void add_edge(vector<int> adj[], int src, int dest)
{
	adj[src].push_back(dest);
	adj[dest].push_back(src);
}

bool BFS(vector<int> adj[], int src, int dest, int v, int parent[], int dist[])
{

	queue<int> q1;
	bool visited[v];
	for (int i = 0; i < v; i++) {
		visited[i] = false;
		dist[i] = INT_MAX;
		parent[i] = -1;
	}
	visited[src] = true;
	cout<< "BFS traversal: " << src << " ";
	dist[src] = 0;
	q1.push(src);

	while (!q1.empty()) {
		int u = q1.front();
        q1.pop();
		for (int i = 0; i < adj[u].size(); i++) {
			if (visited[adj[u][i]] == false) {
				visited[adj[u][i]] = true;
				cout<< adj[u][i] << " ";
				dist[adj[u][i]] = dist[u] + 1;
				parent[adj[u][i]] = u;
				q1.push(adj[u][i]);

				if (adj[u][i] == dest){
                    cout<< endl;
                    return true;
				}
			}
		}
	}


	return false;
}

void printShortestDistance(vector<int> adj[], int s, int dest, int v)
{
	int parent[v], dist[v];

	if (BFS(adj, s, dest, v, parent, dist) == false) {
		cout << "Given source and destination are not connected" << endl;
		return;
	}

	vector<int> path;
	int crawl = dest;
	//cout << "crawl: " << crawl <<endl;
	path.push_back(crawl);
	//int i=0;
	while (parent[crawl] != -1) {
		path.push_back(parent[crawl]);
		crawl = parent[crawl];
		//cout << "crawl "<< i << ": " << crawl <<endl;
		//i++;
	}

	cout << "Shortest path length is : " << dist[dest] <<endl;

	cout << "Path is: ";
	for (int i = path.size() - 1; i >= 0; i--){
        cout << path[i];
        if(i!=0){
            cout << " -> ";
        }
	}
    cout << endl;
}

int main()
{

	int v = 8;

	vector<int> adj[v];

	add_edge(adj, 1, 3);
	add_edge(adj, 1, 2);
	add_edge(adj, 2, 3);
	add_edge(adj, 3, 4);
	int source = 1, dest = 4;
	printShortestDistance(adj, source, dest, v);

	return 0;
}
