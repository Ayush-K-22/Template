#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector <int>
 
// Array Indexing is 0-based while SegTree is 1-based

template <typename A> class SegTree_SinglePoint {
    private :
        vector <A> SegTree;
        int n;
 
    public :
        SegTree_SinglePoint (vector <A> &v) {
            n = v.size();
            SegTree.resize(4*n, -1);
            build (v,0,n-1,1);
        }
 
        A Combine (A u, A v) {
            return u + v;
        }

        void Update (int i, A x) {
            Updation (i,x,0,n-1,1);
        }

        A Query (int l, int r) {
            return getAns (0,n-1,1,l,r);
        }
 
    private :
        void build (vector <A> &v, int st, int end, int ind) {
            if (st == end) {
                SegTree[ind] = v[st];
                return;
            }
            int mid = (st+end)/2;
            build (v,st,mid,2*ind);
            build (v,mid+1,end,2*ind+1);
            SegTree[ind] = Combine(SegTree[2*ind], SegTree[2*ind+1]);
        }

        A getAns (int st, int end, int ind, int left, int right){
            if (end < left || st > right) return 0;
            if (left <= st && right >= end) return SegTree[ind];
            else {
                int mid = (st+end)/2;
                return Combine (getAns (st,mid,2*ind,left,right), getAns (mid+1,end,2*ind+1,left,right));
            }
        }
 
        void Updation (int tar_ind, A val, int st, int end, int ind) {
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
 
template <typename A> class SegTree_LazyPropagation {
    private :
        vector <A> SegTree, Lazy;
        int n;

    public :
        SegTree_LazyPropagation (vector <A> &v) {
            n = v.size();
            SegTree.resize(4*n, -1);
            Lazy.resize(4*n);
            build (v,0,n-1,1);
        }

        A Combine (A u, A v) {
            return u + v;
        }

        A Query (int l, int r) {
            return getAns (0,n-1,1,l,r);
        }

        void Update (int l, int r, A x) {
            Updation (x,0,n-1,1,l,r);
        }

        void Propagate (int ind, int st, int end) {
            SegTree[ind] += Lazy[ind];
            if (st != end) {
                Lazy[2*ind] += Lazy[ind];
                Lazy[2*ind+1] += Lazy[ind];
            }
            Lazy[ind] = 0;
        }
 
    private :
        void build (vector <A> &v, int st, int end, int ind) {
            if (st == end) {
                SegTree[ind] = v[st];
                return;
            }
 
            int mid = (st+end)/2;
            build (v,st,mid,2*ind);
            build (v,mid+1,end,2*ind+1);
            SegTree[ind] = Combine (SegTree[2*ind], SegTree[2*ind+1]);
        }

        void Updation (A val, int st, int end, int ind, int left, int right) {
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

        A getAns (int st, int end, int ind, int left, int right){
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
