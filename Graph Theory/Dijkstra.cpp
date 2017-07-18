#include <bits/stdc++.h>
using namespace std;
#define MAX 2000 + 5

vector <int> edge[MAX], cost[MAX];
int INF = 1e9 + 5;

struct data{
    int city, dist;
    bool operator < (const data& p) const{
        return dist > p.dist;
    }
};

int dijkstra(int src, int destination){
    int d[MAX];
    for(int i = 0; i <= MAX; i++) d[i] = INF;
    priority_queue <data> Q;
    data u, v;
    u.city = src, u.dist = 0;
    Q.push(u);
    d[src] = 0;

    while(!Q.empty()){
        u = Q.top(); Q.pop();
        int ucost = d[u.city];
        for(int i = 0; i < edge[u.city].size(); i++){
            v.city = edge[u.city][i];
            v.dist = cost[u.city][i] + ucost;
            if(d[v.city] > v.dist){
                d[v.city] = v.dist;
                Q.push(v);
            }
        }
    }
    return d[destination];
}
int main(){
    int n, e, src, dist, ans;
    cin >> n >> e;
    for(int i = 0; i < e; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].push_back(v);
        edge[v].push_back(u);
        cost[u].push_back(w);
        cost[v].push_back(w);
    }
    cin >> src >> dist;
    ans = dijkstra(src, dist);
    cout << "Mimimum distance " << src << " to " << dist << ": " << ans << "\n";
    return 0;
}
