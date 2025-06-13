/*
    * Author : AyushK22
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector <int>

class SparseTable {
private:
    vector <vi> st; vi log; int n;

    int queryType (int num1, int num2) {
        return gcd (num1,num2);
    }

    void buildLog() {
        log.resize(n + 1); log[1] = 0;
        for (int i = 2; i <= n; ++i)
            log[i] = log[i / 2] + 1;
    }

    void buildSparseTable(vi &arr) {
        int k = log[n] + 1;
        st.assign(n, vi (k));
        
        for (int i = 0; i < n; ++i)
            st[i][0] = arr[i];

        for (int j = 1; (1 << j) <= n; ++j)
            for (int i = 0; (i + (1 << j) - 1) < n; ++i)
                st[i][j] = queryType (st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }

public:
    SparseTable(vi &arr) {
        n = arr.size();
        buildLog();
        buildSparseTable(arr);
    }

    int rangeQuery(int l, int r) {
        int j = log[r - l + 1];
        return queryType (st[l][j], st[r - (1 << j) + 1][j]);
    }
};

// 0 - based indexing