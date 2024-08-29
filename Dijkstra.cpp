/*
    * Author : AyushK22
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector <int>
#define vb vector <bool>
#define vp vector <pair <int, int>>
#define all(x) x.begin(),x.end()

void Dijkstra (int src, vi &dis, vector <vp> &adj, vb &vis, vi &par) {
    priority_queue <pair <int,int>, vp, greater <pair <int,int>>> pq;
    pq.push({0,src});
    while (!pq.empty()) {
        pair <int,int> p = pq.top();
        pq.pop();
        if (vis[p.second]) continue;
        vis[p.second] = true;
        dis[p.second] = p.first;
        for (auto it : adj[p.second]) {
            if (dis[p.second] + it.second < dis[it.first]) {
                pq.push({dis[p.second] + it.second, it.first});
                dis[it.first] = dis[p.second] + it.second;
                par[it.first] = p.second;
            }
        }
    }
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m; cin >> n >> m;
    vector <vp> adj (n+1);
    for (int i = 0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vi dis (n+1, 1e16), par (n+1);
    vb vis (n+1);
    Dijkstra (1,dis,adj,vis,par);
}
