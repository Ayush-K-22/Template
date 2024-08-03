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

int Combine (int a, int b) {
    return a+b;
}

// Building a Seg Tree
void build (vi &v, int st, int end, int ind, vi &SegTree) {
    if (st == end) {
        SegTree[ind] = v[st];
        return;
    }
    int mid = (st+end)/2;
    build (v,st,mid,2*ind,SegTree);
    build (v,mid+1,end,2*ind+1,SegTree);
    SegTree[ind] = Combine(SegTree[2*ind], SegTree[2*ind+1]);
}

// Sum queries of single point updation segtree
int getSum (int st, int end, int ind, vi &SegTree, int left, int right){
    if (end < left || st > right) return 0;
    if (left <= st && right >= end) return SegTree[ind];
    else {
        int mid = (st+end)/2;
        int a = getSum(st,mid,2*ind,SegTree,left,right);
        int b = getSum(mid+1,end,2*ind+1,SegTree,left,right);
        return Combine(a,b);
    }
}

// Point Updation for sum queries
void Updation (int tar_ind, int val, int st, int end, int ind, vi &SegTree) {
    if (st == end){
        SegTree[ind] = val;
        return;
    }
 
    int mid = (st+end)/2;
    if (tar_ind <= mid) Updation (tar_ind,val,st,mid,2*ind,SegTree);
    else Updation (tar_ind,val,mid+1,end,2*ind+1,SegTree);
 
    SegTree[ind] = Combine(SegTree[2*ind],SegTree[2*ind+1]);
}

// Range Updation for Sum Queries
void Updation (int val, int st, int end, int ind, vi &SegTree, vi &lazy, int left, int right) {
    if (lazy[ind]) {
        SegTree[ind] += lazy[ind];
        if (st != end) {
            lazy[2*ind] += lazy[ind];
            lazy[2*ind+1] += lazy[ind];
        }
        lazy[ind] = 0;
    }
 
    if (end < left || st > right) return;
 
    if (left <= st && right >= end){
        lazy[ind] = val;
        return;
    }
    else {
        int mid = (st+end)/2;
        Updation(val,st,mid,2*ind,SegTree,lazy,left,right);
        Updation(val,mid+1,end,2*ind+1,SegTree,lazy,left,right);
    }
}

// Sum queries for range updation segtree
int getSum (int st, int end, int ind, vi &SegTree, int left, int right, vi &lazy){
    if (end < left || st > right) return 0;
 
    if (lazy[ind]) {
        SegTree[ind] += lazy[ind];
        if (st != end) {
            lazy[2*ind] += lazy[ind];
            lazy[2*ind+1] += lazy[ind];
        }
        lazy[ind] = 0;
    }
 
    if (left <= st && right >= end) return SegTree[ind];
    else {
        int mid = (st+end)/2;
        int a = getSum(st,mid,2*ind,SegTree,left,right,lazy);
        int b = getSum(mid+1,end,2*ind+1,SegTree,left,right,lazy);
        return Combine(a,b);
    }
}

void Solve () {
    
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(NULL);
    Solve();
    return 0;
}