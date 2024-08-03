/*
    * Author : AyushK22
*/

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define int long long
#define vi vector <int>
#define vp vector <pair <int, int>>
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define all(x) x.begin(),x.end()
const int MOD1 = 1e9 + 7;
const int MOD2 = 1e9 + 9;

int ind = 0;
map <int, pair <int,int>> mp;

void dfs (int node, int par, vector <vi> &parent, vector <vi> &adj, vi &level, int cur_level){
    parent[node][0] = par;
    level[node] = cur_level;
    for (int i = 1; i<parent[0].size(); i++) {
        parent[node][i] = parent[parent[node][i-1]][i-1];
    }

    for (auto it : adj[node])
        if (it != par)
            dfs (it,node,parent,adj,level,cur_level+1);
}

int get_Kth_Parent (int k, int node, vector <vi> &parent){
    int ct = 0;
    while (k) {
        if (k&1) node = parent[node][ct];
        k = k >> 1;
        ct++;
    }
    return node;
}

int get_LCA (int a, int b, vector <vi> &parent, vi &level) {
    if (level[a] < level[b]) swap (a,b);
    a = get_Kth_Parent (level[a] - level[b], a, parent);

    if (a == b) return a;

    for (int i = parent[0].size()-1; i>=0; i--) {
        int x = parent[a][i];
        int y = parent[b][i];
        if (x != y) {
            a = x;
            b = y;
        }
    }
    return parent[a][0];
}

void dfs (int node, int par, vector <vi> &adj, vi &flat) {
    flat.push_back(node);
    mp[node].first = ind;
    ind++;
 
    for (auto it : adj[node]){
        if (it != par)
            dfs (it,node,adj,flat);
    }
 
    flat.push_back(node);
    mp[node].second = ind;
    ind++;
}

int32_t main () {
    int n; cin >> n;
    vector <vi> adj (n+1);
    for (int i = 0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    // Extracting Binary Lifting Node Array
    vector <vi> parent (n+1, vi (20, 0));
    vi level (n+1);
    dfs (1,0,parent,adj,level,1);

    vi flat, v; // v stores nodes values
    dfs (1,0,adj,flat);
    vi array;
    set <int> se;
    for (auto it : flat) {
        if (se.find(it) == se.end()){
            array.push_back(v[it-1]);
            se.insert(it);
        }
        else
            array.push_back(0);
    }
}