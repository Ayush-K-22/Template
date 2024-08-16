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
#define vb vector <bool>
#define vp vector <pair <int, int>>
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define all(x) x.begin(),x.end()
const int MOD1 = 1e9 + 7;
const int MOD2 = 1e9 + 9;

void Input (vi &v, int n){
    for (int i = 0; i < n; i++){
        int a; cin >> a;
        v.push_back(a);
    }
}

bool Comparator(const pair<int,int>& a, const pair<int,int>& b) {
}

void Solve () {
    
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(NULL);
    // cout << fixed << setprecision(0);
    int t; cin >> t;
    while (t--)
        Solve();
    return 0;
}