#include <bits/stdc++.h>
using namespace std;

vector <int> g[128];
int seen[128];

void DFS(int u){
    seen[u] = 1;
    cout << u << " ";
    for(int i = 0; i < g[u].size(); i++){
        int v = g[u][i];
        if(!seen[v]) DFS(v);
    }
}

int main(){
    int n, e, u, v;
    cin >> n >> e;
    for(int i = 0; i < e; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    DFS(0);
    return 0;
}
