// HARSHIT SAH 25/DA/032

#include<bits/stdc++.h>
using namespace std;

int main(){
    int v,e; cin >> v >> e;

    vector<vector<pair<int,int>>> adj(v);
    for(int i=0; i<e; i++){
        int x,y,w; cin >> x >> y >> w;
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }

    vector<int> dist(v, 999999);
    dist[0] = 0;

    priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({0,0});

    while(!pq.empty()){
        pair<int,int> temp = pq.top();
        pq.pop();

        int d = temp.first;
        int u = temp.second;

        if (d > dist[u]) continue;
        
        for(auto [v,w] : adj[u]){
            if(w + dist[u] < dist[v]){
                dist[v] = dist[u] + w;
                pq.push({dist[v],v});
            }
        }
    }

    for(int x : dist) cout << x << " ";
}
