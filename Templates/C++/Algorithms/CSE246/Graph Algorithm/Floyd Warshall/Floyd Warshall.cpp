#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000

int D[10005][10005];
int adj[10005][10005];
int next[10005][10005];
int n,e;

void floydWarshall(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            D[i][j] = adj[i][j];
        }
        D[i][i] = 0;
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                //D[i][j] = min(D[i][j], D[i][k]+D[k][j]);
                if(D[i][k]+D[k][j] < D[i][j]){
                    D[i][j] = D[i][k]+D[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }
}

void negativeCycle(){
    int flg=0;
    for(int i=1; i<=n; i++){
        if(D[i][i] < 0){
            flg = 1;
            break;
        }
    }

    if(flg)
        cout << "Has Negative Cycle\n";
    else
        cout << "Hasn't any Negative Cycle\n";

}

vector<int> constructPath(int u, int v){

    if(next[u][v] == -1)
        return {};

    vector<int> path = { u };
    while(u != v) {
        u = next[u][v];
        path.push_back(u);
    }
    return path;
}

void printPath(vector<int>& path){

    int n = path.size();
    for (int i = 0; i < n - 1; i++)
        cout << path[i] << " -> ";
    cout << path[n - 1] << endl;
}

void displayMatrix(int v) {
    int i, j;
    for(i = 1; i <= v; i++) {
       for(j = 1; j <= v; j++) {
          cout << adj[i][j] << " ";
       }
       cout << endl;
    }
}

int main(){


    cin >> n >> e;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++)
            adj[i][j] = INF;
    }

    for(int i=0; i<e; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = w;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(adj[i][j] == INF)
                next[i][j] = -1;
            else
                next[i][j] = j;
        }
    }

    floydWarshall();

    //displayMatrix(n);
    negativeCycle();

    vector<int> path;

    cout << D[4][5] << endl;
    cout << "Shortest path from 4 to 5: ";
    path = constructPath(4, 5);
    printPath(path);


    return 0;
}


/*
input:
6 9
1 2 2
1 5 5
2 5 2
3 5 8
4 3 6
4 5 10
4 1 7
4 6 2
6 1 2

output:
8

*/
