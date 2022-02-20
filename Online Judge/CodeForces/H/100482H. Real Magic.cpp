#include <bits/stdc++.h>
using namespace std;

#define N 100005

vector<int> adj[N];
int color[N], color2[N], ans[N];
int c=0;

void dfs(int u){
    if(!color[u])
        c++;
    color[u]=1;

    for(int i=0;i<adj[u].size();i++){
        if(!color[adj[u][i]])
            dfs(adj[u][i]);
    }

}

void dfs2(int u){
    if(!color2[u])
        ans[u]=c-1;
    color2[u]=1;
    for(int i=0;i<adj[u].size();i++){
        if(!color2[adj[u][i]])
            dfs2(adj[u][i]);
    }
 }

int main(){
    int t; int cs=1;
    cin >> t;
    while(t--){
        int n, m;
        // n = nodes
        // m = edges
        cin >> n >> m;
        for(int i=0;i<m;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        for(int i=1;i<=n;i++){
            c=0;
            if(!color[i]){
                dfs(i);
                dfs2(i);
            }
        }
        printf("Case #%d:\n",cs++);

        for(int i=1;i<=n;i++){
            if(i>1)
                printf(" ");
            printf("%d",ans[i]);
        }
        printf("\n");
        memset(ans,0,sizeof(ans));
        memset(color,0,sizeof(color));
        memset(color2,0,sizeof(color2));

        for(int i=0;i<N;i++)
            adj[i].clear();
    }
    return 0;
}

