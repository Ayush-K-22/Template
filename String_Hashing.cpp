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

// To Find Power in O(1)
int power [200002][2];
void fill () {
    int cur1 = 1, cur2 = 1;
    for (int i = 0; i<2e5+2; i++) {
        power[i][0] = cur1;
        cur1 = (cur1*31)%MOD1;
        power[i][1] = cur2;
        cur2 = (cur2*31)%MOD2;
    }
}

// Find wheather there is a substring
// with given target of length k
bool isPossible (int tar, vi &hash, int k) {
    int r = k;
    while (r < hash.size()-1) {
        int l = r - k + 1;
        int num = (hash[r] - hash[l-1] + MOD1) % MOD1;
        num = (num*power[l-1][0]) % MOD1;
        if (num == tar) return true;
        r++;
    }
    return false;
}

// Give hash value of a string
int getHash (vi &v, string &s, int mod, int pol) {
    int ans = 0, n = s.length();
    for (int i = 0; i<s.length(); i++)
        ans = (ans + ((s[i]-'a'+1) * power[n-1-i][pol])) % mod;
    return ans;
}

void fill_hash (vi &v, string &s, int mod, int pol) {
    int n = s.length();
    for (int i = 0; i<s.length(); i++)
        v[i+1] = (v[i] + (s[i]-'a'+1) * power[n-1-i][pol]) % mod;
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(NULL);
    string s;
    int n = s.length();
    vi hash1 (n+1), hash2 (n+1);
    fill_hash (hash1,s,MOD1,0);
    fill_hash (hash2,s,MOD2,1);
    return 0;
}