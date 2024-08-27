
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

struct Dinic {
    struct Edge {
        int u, v, cap;
        Edge(int u, int v, int cap) : u(u), v(v), cap(cap) {}
    };

    vector<Edge> edges;
    vector<vector<int>> adj;
    int n, m;
    int src, sink;
    vector<int> level;

    Dinic(int n, int src, int sink) : n(n), src(src), sink(sink) {
        adj.assign(n + 7, vector<int>());
        level.assign(n + 7, -1);
    }

    void addEdge(int u, int v, int cap) {
        adj[u].push_back(edges.size());
        edges.push_back(Edge(u, v, cap));
        adj[v].push_back(edges.size());
        edges.push_back(Edge(v, u, 0));
    }

    bool bfs() {
        fill(level.begin(), level.end(), -1);
        level[src] = 0;
        queue<int> q;
        q.push(src);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int id : adj[u]) {
                int v = edges[id].v;
                int cap = edges[id].cap;
                if (level[v] == -1 && cap > 0) {
                    level[v] = level[u] + 1;
                    q.push(v);
                }
            }
        }
        return level[sink] != -1;
    }

    int dfs(int u, int flow) {
        if (u == sink) return flow;
        for (int id : adj[u]) {
            int v = edges[id].v;
            int cap = edges[id].cap;
            if (level[v] == level[u] + 1 && cap > 0) {
                int cur_flow = min(flow, cap);
                int new_flow = dfs(v, cur_flow);
                if (new_flow > 0) {
                    edges[id].cap -= new_flow;
                    edges[id ^ 1].cap += new_flow;
                    return new_flow;
                }
            }
        }
        return 0;
    }

    int maxFlow() {
        int flow = 0;
        while (bfs()) {
            while (int new_flow = dfs(src, 1e18)) {
                flow += new_flow;
            }
        }
        return flow;
    }
};
void solve() {
    int n, m, src, sink;
    cin >> n >> m >> src >> sink;
    Dinic dinic(n, src, sink);

    fu(i, 1, m) {
        int u, v, w;
        cin >> u >> v >> w;
        dinic.addEdge(u, v, w);
    }

    cout << dinic.maxFlow() << '\n';
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0) {
        solve();
    }
}