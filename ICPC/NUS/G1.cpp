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

    int getFlow(map<pair<int, int>, int>& res) {
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
        fu(u, 1, n) {
            for (int id : adj[u]) {
                if (id % 2 == 0) {
                    res[{u, edges[id].v}] += edges[id].flow;
                }
            }
        }
        return f;
    }
};

void solve() {
    // make graph
    int n, longest = 1;
    cin >> n;
    vector<int> a(n + 1);
    fu(i, 1, n) {
        cin >> a[i];
    }
    vector<int> dp(n + 1, 1);
    fu(i, 2, n) {
        fu(j, 1, i - 1) {
            if (a[i] % a[j] == 0 || a[j] % a[i] == 0) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        longest = max(longest, dp[i]);
    }
    if (longest == 1) {
        cout << longest << " " << n << "\n";
        fu(i, 1, n) cout << i << "\n";
        return;
    }
    vector<pii> edges;
    fu(i, 1, n - 1) {
        fu(j, i + 1, n) {
            if (a[i] % a[j] == 0 || a[j] % a[i] == 0) {
                if (dp[j] == dp[i] + 1) {
                    edges.push_back({i, j});
                }
            }
        }
    }

    int numNode = n + 2, s = n + 1, t = n + 2;
    for (int i = 1; i <= n; i++) {
        if (dp[i] == 1) {
            edges.push_back({s, i});
        }
        if (dp[i] == longest) {
            edges.push_back({i, t});
        }
    }
    // for (auto e : edges) {
    //     cout << e.ff << " " << e.ss << '\n';
    // }

    Dinic dinic = Dinic(numNode, s, t);
    for (auto e : edges) {
        dinic.add_edge(e.ff, e.ss, 1);
    }
    map<pair<int, int>, int> flowing;
    int maxFlow = dinic.getFlow(flowing);

    vector<int> after(n + 5, -1);
    for (auto entry : flowing) {
        auto [u, v] = entry.first;
        cout << u << ' ' << v << ' ' << entry.second << '\n';
        int flow = entry.second;
        if (u != s && v != t && flow == 1) {
            // int real_u = u / 2;
            // int real_v = v / 2;
            // if (real_u != real_v)
            //     after[real_u] = real_v;
            if (u != v) {
                after[u] = v;
                // cout << u << " " << after[u] << "\n";
            }
        }
    }

    vector<vector<int>> chains;
    vector<bool> done(n, false);
    // fu(u, 1, n) {
    //     cout << u << " " << dp[u] << " " << after[u] << '\n';
    // }
    fu(u, 1, n) if (!done[u] && dp[u] == 1 && after[u] != -1) {
        vector<int> chain;
        int current = u;
        // cout << u << "\n";
        while (current != -1) {
            done[current] = true;
            chain.emplace_back(current);
            current = after[current];
        }

        chains.emplace_back(chain);
    }

    cout << chains[0].size() << ' ' << chains.size() << '\n';
    for (auto chain : chains) {
        for (int u : chain) cout << u << ' ';
        cout << '\n';
    }
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
}
