
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

struct Karp {
    int n, src, sink;
    vector<vector<int>> adj;
    vector<vector<int>> cap;
    vector<vector<int>> g;
    vector<int> pre;

    Karp(int _n = 0, int _src = 0, int _sink = 0) {
        n = _n, src = _src, sink = _sink;
        adj.assign(n + 7, vector<int>());
        g.assign(n + 7, vector<int>());
        cap.assign(n + 7, vector<int>(n + 7, 0));
        pre.assign(n + 7, -1);
    }

    void add_edge(int u, int v, int w) {
        if (cap[u][v] != 0) return;
        adj[u].push_back(v);
        adj[v].push_back(u);
        cap[u][v] = w;
        g[u].push_back(v);
    }

    int bfs() {
        fill(pre.begin(), pre.end(), -1);
        queue<pii> q;
        pre[src] = -2;
        q.push({src, LONG_LONG_MAX});
        while (!q.empty()) {
            auto [u, flow] = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (pre[v] != -1 || cap[u][v] == 0) continue;
                pre[v] = u;
                int newFlow = min(flow, cap[u][v]);
                if (v == sink) return newFlow;
                q.push({v, newFlow});
            }
        }
        return 0;
    }

    int getMaxFLow() {
        int maxFlow = 0;
        while (int flow = bfs()) {
            maxFlow += flow;
            int cur = sink;
            while (cur != src) {
                int prev = pre[cur];
                cap[prev][cur] -= flow;
                cap[cur][prev] += flow;
                cur = prev;
            }
        }
        return maxFlow;
    }

    vector<pii> getCouple() {
        vector<pii> res;
        fu(u, 1, n) {
            if (u == src || u == sink) continue;
            for (int v : g[u]) {
                if (v == src || v == sink) continue;
                if (cap[u][v] == 0) {
                    res.push_back({u, v});
                }
            }
        }
        return res;
    }
};
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int src = n + m + 1, sink = n + m + 2;
    Karp karp(n + m + 2, src, sink);
    fu(i, 1, k) {
        int u, v;
        cin >> u >> v;
        karp.add_edge(u, v + n, 1);
    }
    fu(i, 1, n) {
        karp.add_edge(src, i, 1);
    }
    fu(i, 1, m) {
        karp.add_edge(i + n, sink, 1);
    }
    karp.getMaxFLow();
    vector<pii> res = karp.getCouple();
    cout << res.size() << '\n';
    for (auto [u, v] : res) {
        cout << u << ' ' << v - n << '\n';
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