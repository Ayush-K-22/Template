/*
    * Author : AyushK22
*/

#include<bits/stdc++.h>
using namespace std;
#define vi vector <int>

void dfs (int node, int par, vector <vi> &adj, vi &cycle, vi &parent) {
    parent[node] = par;
    for (auto it : adj[node]) {
        if (it == par) continue;
        if (parent[it] == -1) dfs (it,node,adj,cycle,parent);
        else if (!cycle.size()) {
            cycle.push_back(it);
            int cur = node;
            while (cur != it) {
                cycle.push_back(cur);
                cur = parent[cur];
            }
            cycle.push_back(it);
        }
    }
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m; cin >> n >> m;
    vector <vi> adj (n+1);
    for (int i = 0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}