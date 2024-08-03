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

int binpow(int a, int b, int m) {
    a %= m;
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

void PrintAllSubsequence (vi &v) {
    int n = v.size();
    int total = pow (2,n);

    for (int i = 0; i<total; i++) {
        cout << "{ ";
        for (int j = 0; j<n; j++)
            if ((1 << j) & i) cout << v[j] << " ";
        cout << "}\n";
    }
}

void All_Subsequence_Sum (vi &v) {
    int n = v.size();
    int total = pow (2,n);
    vi dp (total);

    for (int i = 1; i<total; i++) {
        dp[i] = dp[i & (i-1)] + v[__builtin_ctz(i)];
    }

    for (auto it : dp) cout << it << " ";
}

void PrintAllSubmaskOf_mask (int mask) {
    int s = mask;
    while (s > 0) {
    s = (s-1) & mask;
    }
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(NULL);
    int num = 1 << 6;
    // Here only 6th bit is set;

    bool flag = (1 << 6) & num;
    // Check if 6th bit is set or not;

    int x = num & (num-1); // This turn off the least significant bit of n
    vi v = {1, 3, 5};
    All_Subsequence_Sum(v);
    return 0;
}