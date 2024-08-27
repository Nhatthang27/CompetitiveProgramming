
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
    map<int, int> clr;
    vector<vector<pii>> adj(n + 1, vector<pii>());

    auto enter = [&]() {
        int idx = 1;
        fu(i, 1, m) {
            int u, v, c;
            cin >> u >> v >> c;
            adj[u].push_back({v, c});
            adj[v].push_back({u, c});
            if (clr.find(c) == clr.end()) {
                clr[c] = idx++;
            }
        }
    };
    enter();

    int sta, fin;
    cin >> sta >> fin;
    if (sta == fin) {
        cout << 0 << "\n";
        return;
    }

    vector<vector<int>> g(n + clr.size() + 1);
    fu(u, 1, n) {
        for (auto [v, c] : adj[u]) {
            g[u].push_back(n + clr[c]);
            g[n + clr[c]].push_back(u);

            g[v].push_back(n + clr[c]);
            g[n + clr[c]].push_back(v);
        }
    }

    fu(u, 1, n) {
        sort(g[u].begin(), g[u].end());
        g[u].erase(unique(g[u].begin(), g[u].end()), g[u].end());
        // cout << u << " -> ";
        // for (int clr : g[u]) {
        //     cout << clr - n << " ";
        // }
        // cout << "\n";
    }

    vector<int> dist(n + clr.size() + 1, -1);
    queue<int> q;

    dist[sta] = 0;
    q.push(sta);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    cout << dist[fin] / 2 << "\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}