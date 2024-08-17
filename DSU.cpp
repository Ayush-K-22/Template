/*
    * Author : AyushK22
*/

#include<bits/stdc++.h>
using namespace std;
#define vi vector <int>

class DSU {
    private :
        vi parent, size, rank;

    public :
        DSU (int n) {
            for (int i = 0; i<=n; i++){
                parent.push_back(i);
                rank.push_back(0);
                size.push_back(1);
            }
        }

        int getParent (int node) {
            if (parent[node] == node) return node;
            return parent[node] = getParent (parent[node]);
        }

        void UnionBySize (int u, int v) {
            int pu = getParent(u);
            int pv = getParent(v);

            if (pu == pv) return;
            if (size[pu] > size[pv]) {
                parent[pv] = pu;
                size[pu] += size[pv];
            }
            else {
                parent[pu] = pv;
                size[pv] += size[pu];
            }
        }

        void UnionByRank (int u, int v) {
            int pu = getParent(u);
            int pv = getParent(v);

            if (pu == pv) return;
            if (rank[pu] == rank[pv]) {
                parent[pu] = pv;
                rank[pv]++;
            }
            else if (rank[pu] > rank[pv])
                parent[pv] = pu;
            else
                parent[pu] = pv;
        }
};