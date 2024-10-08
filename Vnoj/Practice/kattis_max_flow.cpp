#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define ff first
#define ss second
#define BIT(a, i) ((a >> i) & 1)
#define MASK(i) (1int << i)
#define SZ(a) (int)a.size()
using namespace std;
const int INF = 1e18;
struct FlowEdge {
    int u, v;
    long long cap, flow;
    FlowEdge(int _u = -1, int _v = -1, long long _cap = -1) {
        u = _u, v = _v, cap = _cap;
        flow = 0;
    }
};

struct Dinic {
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int _n = 0, int _s = 0, int _t = 0) {
        n = _n, s = _s, t = _t;
        adj.resize(n + 7);
        level.resize(n + 7);
        ptr.resize(n + 7);
    }

    void add_edge(int u, int v, int cap) {
        edges.emplace_back(u, v, cap);
        edges.emplace_back(v, u, 0);
        adj[u].push_back(m);
        adj[v].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int id : adj[u]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].v] != -1)
                    continue;

                level[edges[id].v] = level[u] + 1;
                q.push(edges[id].v);
            }
        }
        return level[t] != -1;
    }

    int dfs(int u, int pushed) {
        if (pushed == 0)
            return 0;
        if (u == t)
            return pushed;
        for (int& cid = ptr[u]; cid < (int)adj[u].size(); cid++) {
            int id = adj[u][cid];
            int v = edges[id].v;
            if (level[u] + 1 != level[v] || edges[id].cap - edges[id].flow < 1)
                continue;
            int tr = dfs(v, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    int getFlow(vector<FlowEdge>& res) {
        int f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            int pushed;
            while (pushed = dfs(s, INF)) {
                f += pushed;
            }
        }
        for (auto e : edges) {
            if (e.flow > 0) {
                res.push_back(e);
            }
        }
        return f;
    }
};

void solve() {
    int numNode, numEdge, s, t;
    cin >> numNode >> numEdge >> s >> t;
    Dinic dinic = Dinic(numNode, s, t);
    fu(i, 1, numEdge) {
        int u, v, cap;
        cin >> u >> v >> cap;
        dinic.add_edge(u, v, cap);
    }
    vector<FlowEdge> res;
    int maxFlow = dinic.getFlow(res);
    cout << numNode << " " << maxFlow << " " << res.size() << '\n';
    for (auto e : res) {
        cout << e.u << " " << e.v << " " << e.flow << '\n';
    }
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
}
