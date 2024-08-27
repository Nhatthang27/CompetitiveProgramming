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

struct Karp {
    int n, src, sink;
    vector<vector<int>> adj, g;
    vector<vector<int>> cap;
    vector<int> pre;

    Karp(int _n = 0, int _src = 0, int _sink = 0) {
        n = _n, src = _src, sink = _sink;
        adj.assign(n + 7, vector<int>());
        g.assign(n + 7, vector<int>());
        cap.assign(n + 7, vector<int>(n + 7, 0));
        pre.assign(n + 7, -1);
    }

    void add_edge(int u, int v, int w) {
        g[u].push_back(v);
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

    vector<vector<int>> getPaths() {
        vector<vector<int>> res;
        vector<int> path;
        vector<bool> visited(n + 7, false);
        function<void(int)> dfs = [&](int u) {
            visited[u] = true;
            path.push_back(u);
            vector<int> newPath;
            if (u == sink) {
                for (int x : path) {
                    if (x == src || x == sink || x % 2 == 1) continue;
                    newPath.push_back(x / 2);
                }
                res.push_back(newPath);
            } else {
                for (int v : g[u]) {
                    if (!visited[v] && cap[u][v] == 0) {
                        dfs(v);
                    }
                }
            }
            path.pop_back();
            visited[u] = false;
        };
        dfs(src);
        return res;
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

    int numNode = 2 * n + 2, src = 2 * n + 1, sink = 2 * n + 2;
    Karp karp(numNode, src, sink);
    fu(u, 1, n) {
        karp.add_edge(2 * u - 1, 2 * u, 1);
    }
    fu(i, 1, n) {
        if (dp[i] == 1) {
            karp.add_edge(src, 2 * i - 1, 1);
        }
        if (dp[i] == longest) {
            karp.add_edge(2 * i, sink, 1);
        }
    }
    fu(i, 1, n - 1) {
        fu(j, i + 1, n) {
            if (a[i] % a[j] == 0 || a[j] % a[i] == 0) {
                if (dp[j] == dp[i] + 1) {
                    karp.add_edge(2 * i, 2 * j - 1, 1);
                }
            }
        }
    }
    // get max flow
    int maxFlow = karp.getMaxFLow();
    auto paths = karp.getPaths();
    cout << paths[0].size() << " " << paths.size() << '\n';
    for (auto path : paths) {
        for (int u : path) {
            cout << u << " ";
        }
        cout << '\n';
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
}