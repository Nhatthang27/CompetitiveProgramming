#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tpl tuple<int, int, int>
#define ff first
#define ss second
using namespace std;

void solve() {

    // Read input
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1, vector<int>());
    vector<vector<int>> edge(m + 1, vector<int>(4));

    fu(i, 1, m) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(i);
        adj[v].push_back(i);
        edge[i] = {u, v, w, 0};
    }

    // Dijkstra
    auto dijkstra = [&](int sta, int fin, vector<int> &dis) {
        vector<int> pre(
            n + 1, -1); // pre[u] = id of edge (u, pre[u] + u - edge[pre[u]][0]
        dis.assign(n + 1, LONG_LONG_MAX);
        dis[sta] = 0;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, sta});
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d != dis[u])
                continue;
            for (auto id : adj[u]) {
                int v = edge[id][0] + edge[id][1] - u;
                int w = edge[id][2];
                if (dis[v] > dis[u] + w) {
                    pre[v] = id;
                    dis[v] = dis[u] + w;
                    pq.push({dis[v], v});
                }
            }
        }
        if (sta == 1 && fin == n) {
            while (pre[fin] != -1) {
                edge[pre[fin]][3] = 1;
                fin = edge[pre[fin]][0] + edge[pre[fin]][1] - fin;
            }
        }
    };

    vector<int> d1, dn;
    dijkstra(1, n, d1);
    if (d1[n] == LONG_LONG_MAX) {
        cout << -1;
        return;
    }
    dijkstra(n, 1, dn);
    int res = LONG_LONG_MAX;
    fu(i, 1, m) {
        if (edge[i][3] == 0) {
            int u = edge[i][0], v = edge[i][1], w = edge[i][2];
            if (d1[u] != LONG_LONG_MAX && dn[v] != LONG_LONG_MAX)
                res = min(res, d1[n] + dn[v] + w + d1[u]);
            if (d1[v] != LONG_LONG_MAX && dn[u] != LONG_LONG_MAX)
                res = min(res, d1[n] + dn[u] + w + d1[v]);
        }
    }
    cout << (res == LONG_LONG_MAX ? -1 : res);
}

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
}