#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);
    for (int i = 2; i <= n; ++i) {
        int x;
        cin >> x;
        adj[x].pb(i);
        adj[i].pb(x);
    }

    vector<int> val(n + 1);
    fu(i, 1, n) cin >> val[i];
    vector<int> lcs;
    // longest increasing subsequence

    vector<int> ans(n + 1);

    auto dfs = [&](int u, int par, vector<int> lcs, auto&& dfs) -> void {
        auto it = lower_bound(all(lcs), val[u]);
        if (it == lcs.end()) {
            lcs.pb(val[u]);
        } else {
            *it = val[u];
        }
        ans[u] = sz(lcs);
        for (int v : adj[u]) {
            if (v == par) continue;
            dfs(v, u, lcs, dfs);
        }
    };

    dfs(1, -1, lcs, dfs);
    for (int i = 2; i <= n; ++i) {
        cout << ans[i] << " \n"[i == n];
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0) {
        solve();
    }
}