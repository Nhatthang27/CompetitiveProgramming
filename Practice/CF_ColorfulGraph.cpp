
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> color(n + 1, 0);
    map<int, set<int>> mp;
    fu(i, 1, n) cin >> color[i], mp[color[i]] = {};
    vector<vector<int>> adj(n + 1);
    fu(i, 1, m) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    fu(u, 1, n) {
        for (int v : adj[u]) {
            if (color[v] != color[u]) {
                mp[color[u]].insert(color[v]);
            }
        }
    }
    pii res = {-1, -1};
    for (auto p : mp) {
        int p_sz = p.ss.size();
        if (p_sz > res.second) {
            res = {p.ff, p_sz};
        } else if (p.ss.size() == res.second) {
            res = min(res, {p.ff, p_sz});
        }
    }
    cout << res.ff << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0) {
        solve();
    }
}