
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
    vector<vector<pii>> adj(n + 1, vector<pii>());
    vector<pair<pii, int>> edges;
    fu(i, 1, m) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        edges.push_back({{u, v}, w});
    }
    // vector<vector<int>> d1(n + 1, vector<int>(n + 1, 1e18)), d2(n + 1, vector<int>(n + 1, 1e18));
    // dijkstra find shortest path from one node to all nodes
    // dijkstra find second shortest path from one node to all nodes

    // fu(src, 1, n) {
    //     priority_queue<pii, vector<pii>, greater<pii>> pq;
    //     pq.push({0, src});
    //     d1[src][src] = 0;
    //     while (!pq.empty()) {
    //         auto [du, u] = pq.top();
    //         pq.pop();
    //         if (du > d2[src][u]) continue;
    //         for (auto [v, w] : adj[u]) {
    //             int curDis = du + w;
    //             if (d1[src][v] > curDis) {
    //                 swap(d1[src][v], curDis);
    //                 pq.push({d1[src][v], v});
    //             }
    //             if (d2[src][v] > curDis) {
    //                 d2[src][v] = curDis;
    //                 pq.push({d2[src][v], v});
    //             }
    //         }
    //     }
    // }
    // fu(u, 1, n - 1) {
    //     fu(v, u + 1, n) {
    //         cout << u << " " << v << " " << d1[u][v] << " " << d2[u][v] << "\n";
    //     }
    // }
    // fu(i, 1, m) {
    //     int u = edges[i - 1].ff.ff, v = edges[i - 1].ff.ss, w = edges[i - 1].ss;
    //     if (d1[u][v] == w) {
    //         cout << d2[u][v] << "\n";
    //     } else {
    //         cout << d1[u][v] << "\n";
    //     }
    // }
    vector<int> d1(n + 1, 1e18), d2(n + 1, 1e18);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 1});
    d1[1] = 0;
    while (!pq.empty()) {
        auto [du, u] = pq.top();
        pq.pop();
        cout << du << " " << u << "\n";
        if (du > d2[u]) continue;
        for (auto [v, w] : adj[u]) {
            int curDis = du + w;
            if (d1[v] > curDis) {
                swap(d1[v], curDis);
                pq.push({d1[v], v});
            }
            if (d2[v] > curDis) {
                d2[v] = curDis;
                pq.push({d2[v], v});
            }
        }
    }
    // fu(i, 1, n) {
    //     cout << 1 << " " << i << " " << d1[i] << " " << d2[i] << "\n";
    // }
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0) {
        solve();
    }
}