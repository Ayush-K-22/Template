#include<bits/stdc++.h>
using namespace std;

class LCA {
    #define vi vector <int>
    private :
        vector <vi> parent;
        vector <int> level;

        void dfs (int node, int par, vector <vi> &adj, int cur_level){
            parent[node][0] = par;
            level[node] = cur_level;
            for (int i = 1; i<parent[0].size(); i++) {
                parent[node][i] = parent[parent[node][i-1]][i-1];
            }

            for (auto it : adj[node])
                if (it != par)
                    dfs (it,node,adj,cur_level+1);
        }

    public :
        LCA (vector <vi> &Adj) {
            int n = Adj.size();
            parent.resize(n, vi (20));
            level.resize(n);
            dfs (1,0,Adj,1);
        }

        int get_Kth_Parent (int k, int node){
            int ct = 0;
            while (k) {
                if (k&1) node = parent[node][ct];
                k = k >> 1;
                ct++;
            }
            return node;
        }

        int get_LCA (int a, int b) {
            if (level[a] < level[b]) swap (a,b);
            a = get_Kth_Parent (level[a] - level[b], a);

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
};

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(NULL);
}