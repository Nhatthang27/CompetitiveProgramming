#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...)
#endif

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
#define int ll

#define fi first
#define se second
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int INFi = 2e9, MOD = 1e9 + 7;
const ll INF = 2e18;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    function<bool(int, int)> dfs = [&](int v, int p) -> bool {
        bool ans = false;
        for (auto &u : g[v]) {
            if (u != p) {
                if (!dfs(u, v)) {
                    ans = true;
                }
            }
        }
        return ans;
    };
    while (q--) {
        int v;
        cin >> v;
        v--;
        cout << (dfs(v, -1) ? "Ron\n" : "Hermione\n");
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
//     _        _        _
//   <(.)__   =(.)__   >(.)__
//    (___/    (___/    (___/
