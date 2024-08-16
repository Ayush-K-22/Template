void bfs (vi &path, vector <vi> &adj, vi &vis) {
    queue <int> q;
    for (auto it : path) {
        q.push(it);
        vis[it] = 1;
    }
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto it : adj[node]) {
            if (vis[it] == 0) {
                q.push(it);
                vis[it] = 1 + vis[node];
            }
        }
    }
}