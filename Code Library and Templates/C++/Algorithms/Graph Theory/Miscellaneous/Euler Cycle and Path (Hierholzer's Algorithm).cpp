// A C++ program to print Eulerian circuit in given
// directed graph using Hierholzer algorithm
#include <bits/stdc++.h>
using namespace std;

void printCircuit(vector< vector<int> > adj)
{
	// adj represents the adjacency list of
	// the directed graph
	// edge_count represents the number of edges
	// emerging from a vertex
	unordered_map<int,int> edge_count;

	for (int i=0; i<adj.size(); i++)
	{
		//find the count of edges to keep track
		//of unused edges
		edge_count[i] = adj[i].size();
	}

	if (!adj.size())
		return; //empty graph

	// Maintain a stack to keep vertices
	stack<int> curr_path;

	// vector to store final circuit
	vector<int> circuit;

	// start from any vertex
	curr_path.push(0);
	int curr_v = 0; // Current vertex

	while (!curr_path.empty())
	{
		// If there's remaining edge
		if (edge_count[curr_v])
		{
			// Push the vertex
			curr_path.push(curr_v);

			// Find the next vertex using an edge
			int next_v = adj[curr_v].back();

			// and remove that edge
			edge_count[curr_v]--;
			adj[curr_v].pop_back();

			// Move to next vertex
			curr_v = next_v;
		}

		// back-track to find remaining circuit
		else
		{
			circuit.push_back(curr_v);

			// Back-tracking
			curr_v = curr_path.top();
			curr_path.pop();
		}
	}

	// we've got the circuit, now print it in reverse
	for (int i=circuit.size()-1; i>=0; i--)
	{
		cout << circuit[i];
		if (i)
		cout<<" -> ";
	}
}


void dfs(vector< vector<int> > adj, bool visited[], list<int> &path, int source) {

	visited[source] = true;
	//cout << source << " ";
	path.push_back(source);

	for (int i = 0; i < adj[source].size(); i++){
        int next = adj[source][i];
        if (visited[next] == 0)
            dfs(adj, visited, path, next);
    }

}

void printPath(vector< vector<int> > adj, int e, int v) {

	list< int > path;
	bool* visited = new bool[e];
	for (int i = 0; i < e; i++)
		visited[i] = false;

    dfs(adj, visited, path, 0);
    int i=0, len = path.size();

    while( !path.empty() ) {
        cout << path.front();
        path.pop_front();
        if (i < len-1){
            cout<<" -> ";
            i++;
        }

    }

}


// Driver program to check the above function
int main()
{
	vector< vector<int> > adj1, adj2, adj3;

	// Input Graph 1
	adj1.resize(3);

	// Build the edges
	adj1[0].push_back(1);
	adj1[1].push_back(2);
	adj1[2].push_back(0);
	cout<< "Circuit: ";
	printCircuit(adj1);
	cout << endl;

	// Input Graph 2
	adj2.resize(7);
	adj2[0].push_back(1);
	adj2[0].push_back(6);
	adj2[1].push_back(2);
	adj2[2].push_back(0);
	adj2[2].push_back(3);
	adj2[3].push_back(4);
	adj2[4].push_back(2);
	adj2[4].push_back(5);
	adj2[5].push_back(0);
	adj2[6].push_back(4);
	cout<< "Circuit: ";
	printCircuit(adj2);
    cout << endl;

	adj3.resize(5);

	// Build the edges
	adj3[0].push_back(1);
	adj3[1].push_back(2);
	adj3[2].push_back(3);
	adj3[3].push_back(1);
	adj3[1].push_back(4);
	cout<< "Path: ";
	printPath(adj3, 5, 5); // 0 -> 1 -> 2 -> 3 -> 1 -> 4
	cout << endl;


	return 0;
}
