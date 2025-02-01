/*
    * Author : AyushK22
*/

#include<bits/stdc++.h>
using namespace std;

class RollingHash {
    private:
        int n, MOD = 1e9 + 7;
        vector <int> hash1, hash2, power1, power2;
    public:
        RollingHash (vector <int> &v) {
            n = v.size();
            hash1.resize(n + 1, 0); hash2.resize(n + 1, 0);
            power1.resize(n, 1); power2.resize(n, 1);
            for (int i = 1; i<n; i++) {
                power1[i] = (1LL * power1[i-1] * 31) % MOD;
                power2[i] = (1LL * power2[i-1] * 37) % MOD;
            }
            for (int i = 1; i <= n; i++) {
                hash1[i] = (1LL * hash1[i-1] + 1LL * v[i-1] * power1[n-i]) % MOD;
                hash2[i] = (1LL * hash2[i-1] + 1LL * v[i-1] * power2[n-i]) % MOD;
            }
        }

        int modDiv (int x, int y) {
            auto binpow = [&](int a, int b) {
                int res = 1;
                while (b > 0) {
                    if (b & 1)
                        res = (1LL * res * a) % MOD;
                    a = (1LL * a * a) % MOD;
                    b >>= 1;
                }
                return res;
            };
            return (1LL * x * binpow(y, MOD-2)) % MOD;
        }

        pair <int,int> getHashVal (int l, int r) { // 1 - Based Indexing
            int hash_val1 = (hash1[r] - hash1[l-1] + MOD) % MOD;
            hash_val1 = modDiv(hash_val1, power1[n-r]);
            int hash_val2 = (hash2[r] - hash2[l-1] + MOD) % MOD;
            hash_val2 = modDiv(hash_val2, power2[n-r]);
            return {hash_val1, hash_val2};
        }

        bool isPossible (pair <int,int> hash_val, int len) {
            pair <int,int> temp;
            for (int i = 1; i+len-1 <= n; i++) {
                temp = getHashVal(i, i+len-1);
                if (temp == hash_val) return true;
            }
            return false;
        }
};

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(NULL);
    return 0;
}
