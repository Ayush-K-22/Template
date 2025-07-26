/*
    * Author : AyushK22
*/

#include<bits/stdc++.h>
using namespace std;

class RollingHash {
    private:
        int n, MOD = 1e9 + 7, base1 = 31, base2 = 37;
        vector <int> hash1, hash2, power1, power2;
    public:
        RollingHash (const string &s) {
            n = s.size();
            hash1.resize(n + 1, 0); hash2.resize(n + 1, 0);
            power1.resize(n + 1, 1); power2.resize(n + 1, 1);
            for (int i = 1; i <= n; i++) {
                power1[i] = (1LL * power1[i - 1] * base1) % MOD;
                power2[i] = (1LL * power2[i - 1] * base2) % MOD;
                hash1[i] = (1LL * hash1[i - 1] * base1 + s[i - 1]) % MOD;
                hash2[i] = (1LL * hash2[i - 1] * base2 + s[i - 1]) % MOD;
            }
        }

        pair <int,int> getHashVal (int l, int r) { // 1-based Indexing
            int hash_val1 = (hash1[r] - 1LL * hash1[l - 1] * power1[r - l + 1] % MOD + MOD) % MOD;
            int hash_val2 = (hash2[r] - 1LL * hash2[l - 1] * power2[r - l + 1] % MOD + MOD) % MOD;
            return {hash_val1, hash_val2};
        }

        bool isPossible (pair <int,int> hash_val, int len) {
            pair <int,int> temp;
            for (int i = 1; i + len - 1 <= n; i++) {
                temp = getHashVal(i, i + len - 1);
                if (temp == hash_val) return true;
            }
            return false;
        }
};

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(NULL);
    return 0;
}
