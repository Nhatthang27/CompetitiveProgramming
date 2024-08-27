
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define tpl tuple<int, int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> adj(n + 1, vector<pii>());
    fu(i, 1, m) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }
    int sta, fin;
    cin >> sta >> fin;
    if (sta == fin) {
        cout << 0 << "\n";
        return;
    }
    vector<map<int, int>> dist(n + 1, map<int, int>());
    dist[sta][0] = 0;

    queue<tpl> pq;

    for (auto [v, c] : adj[sta]) {
        dist[v][c] = 1;
        pq.push({1, v, c});
    }
    int res = LONG_LONG_MAX;
    while (!pq.empty()) {
        auto [d, u, c] = pq.front();
        if (u == fin) {
            res = min(res, dist[u][c]);
        }
        pq.pop();
        // if (res != LONG_LONG_MAX && dist[u][c] > res) {
        //     continue;
        // }
        if (dist[u][c] < d)
            continue;
        for (auto [v, c2] : adj[u]) {
            int cost = (c != c2);
            if (dist[v].find(c2) == dist[v].end() ||
                dist[v][c2] > dist[u][c] + cost) {
                dist[v][c2] = dist[u][c] + cost;
                pq.push({dist[v][c2], v, c2});
            }
        }
    }
    // for (auto [v, c] : adj[fin]) {
    //     if (dist[v].find(c) != dist[v].end()) {
    //         res = min(res, dist[v][c]);
    //     }
    // }
    cout << res << "\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}