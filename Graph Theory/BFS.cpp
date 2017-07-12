#include <bits/stdc++.h>
using namespace std;
#define MAX 100 + 5
vector <int> adj[MAX];      //for storing graph
int visited[MAX];           //for indicating node state; 0 for not visited, 1 for visited
int level[MAX];             //for counting the level

void addEdge(int v, int w){
	adj[v].push_back(w);    //directed
	adj[w].push_back(v);	//undirected
}

void BFS(int src, int n){
	queue <int> Q;
	Q.push(src);
	visited[src] = 1;
	level[src] = 0;
	while(!Q.empty()){
		int u = Q.front();
		cout << u << " ";
		for(int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i];
			if(visited[v] == 0){
				level[v] = level[u] + 1;
				visited[v] = 1;
				Q.push(v);
			}
		}
		Q.pop();
	}
	cout << "\n";
	for(int i = 0; i < n; i++)  //printing all distance
		cout << src << " to " << i << " distance = " << level[i] << "\n";
}

int main(){
//    int node, edge, x, y;
//    cin >> node >> edge;
//    for(int i = 0; i < edge; i++) {
//      cin >> x >> y;
//      addEdge(x, y);
//    }
    int n;
    cin >> n;
    addEdge(0, 1);
    addEdge(1, 2);
    addEdge(1, 4);
    addEdge(3, 5);
    addEdge(2, 4);
    addEdge(4, 5);
    BFS(2, n);     // 2 is the source node
    return 0;
}
