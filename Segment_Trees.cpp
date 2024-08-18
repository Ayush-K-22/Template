/*
    * Author : AyushK22
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector <int>

class SegTree_SinglePoint {
    private :
        vi SegTree;

    public :
        SegTree_SinglePoint (int n) {
            SegTree.resize(4*n, -1);
        }

        int Combine (int u, int v){
            return u + v;
        }

        void build (vi &v, int st, int end, int ind) {
            if (st == end) {
                SegTree[ind] = v[st];
                return;
            }
            int mid = (st+end)/2;
            build (v,st,mid,2*ind);
            build (v,mid+1,end,2*ind+1);
            SegTree[ind] = Combine(SegTree[2*ind], SegTree[2*ind+1]);
        }

        int getAns (int st, int end, int ind, int left, int right){
            if (end < left || st > right) return 0;
            if (left <= st && right >= end) return SegTree[ind];
            else {
                int mid = (st+end)/2;
                return Combine (getAns (st,mid,2*ind,left,right), getAns (mid+1,end,2*ind+1,left,right));
            }
        }

        void Updation (int tar_ind, int val, int st, int end, int ind) {
            if (st == end){
                SegTree[ind] = val;
                return;
            }
        
            int mid = (st+end)/2;
            if (tar_ind <= mid) Updation (tar_ind,val,st,mid,2*ind);
            else Updation (tar_ind,val,mid+1,end,2*ind+1);
        
            SegTree[ind] = Combine (SegTree[2*ind], SegTree[2*ind+1]);
        }
};

class SegTree_LazyPropagation {
    private :
        vi SegTree, Lazy;

    public :
        SegTree_LazyPropagation (int n) {
            SegTree.resize(4*n, -1);
            Lazy.resize(4*n);
        }

        int Combine (int u, int v){
            return u + v;
        }

        void build (vi &v, int st, int end, int ind) {
            if (st == end) {
                SegTree[ind] = v[st];
                return;
            }
            int mid = (st+end)/2;
            build (v,st,mid,2*ind);
            build (v,mid+1,end,2*ind+1);
            SegTree[ind] = Combine (SegTree[2*ind], SegTree[2*ind+1]);
        }

        void Propagate (int ind, int st, int end) {
            SegTree[ind] += Lazy[ind];
            if (st != end) {
                Lazy[2*ind] += Lazy[ind];
                Lazy[2*ind+1] += Lazy[ind];
            }
            Lazy[ind] = 0;
        }

        void Updation (int val, int st, int end, int ind, int left, int right) {
            if (Lazy[ind]) 
                Propagate(ind,st,end);
        
            if (end < left || st > right) return;
        
            if (left <= st && right >= end){
                Lazy[ind] = val;
                return;
            }
            else {
                int mid = (st+end)/2;
                Updation(val,st,mid,2*ind,left,right);
                Updation(val,mid+1,end,2*ind+1,left,right);
            }
        }

        int getAns (int st, int end, int ind, int left, int right){
            if (end < left || st > right) return 0;
        
            if (Lazy[ind])
                Propagate(ind,st,end);
        
            if (left <= st && right >= end) return SegTree[ind];
            else {
                int mid = (st+end)/2;
                return getAns(st,mid,2*ind,left,right) + getAns(mid+1,end,2*ind+1,left,right);
            }
        }
};
