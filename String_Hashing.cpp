/*
    * Author : AyushK22
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector <int>
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

class String_Hash {        
    public :
        // f(x) = a1*x^(n-1) + a2*x^(n-2) + ... + a_n;

        static int binpow(int a, int b, int m) {
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

        static int mod_div (int a, int b, int mod) {
            return (a * binpow (b, mod - 2, mod)) % mod;
        }

        static int getHash (string &s, int mod, int pol) {
            int ans = 0, n = s.length();
            for (int i = 0; i<s.length(); i++)
                ans = (ans + ((s[i]-'a'+1) * power[n-1-i][pol])) % mod;
            return ans;
        }

        static void fill_hash (vi &v, string &s, int mod, int pol) {
            int n = s.length();
            for (int i = 0; i<s.length(); i++)
                v[i+1] = (v[i] + (s[i]-'a'+1) * power[n-1-i][pol]) % mod;
        }

        // Find wheather there is a substring with given target of length k
        static bool isPossible (int tar, vi &hash, int k) {
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

        // 1 - Based Indexing
        static int get_Val (int l, int r, int mod, vi &hash, string &s, int pol) {
            int n = s.length();
            int ans = (hash[r] - hash[l-1] + mod) % mod;
            return mod_div (ans, power[n-r][pol],mod);
        }
};

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(NULL);
    fill();
    return 0;
}
