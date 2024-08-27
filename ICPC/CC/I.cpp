
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;
struct Edge {
    int u, v, w;
    Edge(int u = 0, int v = 0, int w = 0) : u(u), v(v), w(w) {}
};
void solve() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;

    vector<Edge> edges(m + 1);
    vector<vector<int>> g(n + 1);

    fu(i, 1, m) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = Edge(u, v, w);
        g[u].push_back(i);
        g[v].push_back(i);
    }

    vector<int> d(n + 1, 1e18);
    vector<vector<int>> pre(n + 1);

    // dijkstra
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    d[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        pii front = pq.top();
        pq.pop();
        int u = front.ss, du = front.ff;
        if (du != d[u]) continue;
        for (auto i : g[u]) {
            pii tmp = (edges[i].u == u ? pii(edges[i].v, edges[i].w) : pii(edges[i].u, edges[i].w));
            int v = tmp.ff, w = tmp.ss;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                pre[v].clear();
                pre[v].push_back(i);
                pq.push({d[v], v});
            } else if (d[v] == d[u] + w) {
                pre[v].push_back(i);
            }
        }
    }
    vector<bool> chose(m + 1);
    queue<int> q;
    q.push(t);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto i : pre[u]) {
            if (!chose[i]) {
                chose[i] = 1;
                q.push(edges[i].u + edges[i].v - u);
            }
        }
    }
    int res = 0;
    fu(i, 1, m) {
        if (!chose[i]) {
            res += edges[i].w;
        }
    }
    cout << res << '\n';
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0) {
        solve();
    }
}