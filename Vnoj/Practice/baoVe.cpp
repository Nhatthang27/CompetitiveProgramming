
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
    vector<int> pre;

    Karp(int _n = 0, int _src = 0, int _sink = 0) {
        n = _n, src = _src, sink = _sink;
        adj.assign(n + 7, vector<int>());
        cap.assign(n + 7, vector<int>(n + 7, 0));
        pre.assign(n + 7, -1);
    }

    void add_edge(int u, int v, int w) {
        adj[u].push_back(v);
        adj[v].push_back(u);
        cap[u][v] += w;
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
};

void solve() {
    int n;
    cin >> n;
    Karp karp(n, n, 1);
    int u, v, w;
    while (cin >> u >> v >> w) {
        karp.add_edge(u, v, w);
    }
    cout << karp.getMaxFLow() << "\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0) {
        solve();
    }
}