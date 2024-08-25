#define ll long long

class Precompute {
    private :
        vector <ll> fact, mod_inv;
        ll mod = 1e9 + 7;
    public :
        ll binpow (ll a, ll b, ll m) {
            a %= m;
            ll res = 1;
            while (b > 0) {
                if (b & 1)
                    res = (res * a) % m;
                a = (a * a) % m;
                b >>= 1;
            }
            return res;
        }

        Precompute (ll n){
            fact.resize(n+1);
            mod_inv.resize(n+1);
            fact[0] = fact[1] = mod_inv[1] = mod_inv[0] = 1;
            for (ll i = 2; i<=n; i++){
                fact[i] = (fact[i-1] * i) % mod;
                mod_inv[i] = binpow(fact[i],mod-2,mod);
            }
        }

        ll nCr (ll n, ll r) {
            if (r > n) return 0;
            ll num = fact[n];
            ll inv_demo = (mod_inv[r] * mod_inv[n-r]) % mod;
            return (num * inv_demo) % mod;
        }

        ll nCr_NoMod (ll n, ll r) {
            ll ans = 1;
            for (ll i = 1; i<=min (r, n-r); i++)
                ans = (ans * (n-i+1))/i;
            return ans;
        }
};