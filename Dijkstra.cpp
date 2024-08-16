/*
    * Author : AyushK22
*/
 
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector <int>
#define vb vector <bool>
#define vp vector <pair <int, int>>

void Dijkstra (int src, vi &dis, vector <vp> &adj, vb &vis) {
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
            }
        }
    }
}