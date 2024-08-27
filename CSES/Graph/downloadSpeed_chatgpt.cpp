#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; fd--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1, vector<int>());
    vector<vector<int>> cap(n + 1, vector<int>(n + 1, 0));
    vector<tuple<int, int, int>> edges;  // Store the original edges

    fu(i, 1, m) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(v);
        adj[v].push_back(u);
        cap[u][v] += w;
        edges.push_back(make_tuple(u, v, w));  // Store the edge
    }

    int src = 1, sink = n;
    int flow = 0;
    vector<int> pre(n + 1, -1);

    auto bfs = [&](int src, int sink) {
        fill(pre.begin(), pre.end(), -1);
        queue<pair<int, int>> q;
        q.push({src, 1e18});
        pre[src] = -2;
        while (!q.empty()) {
            auto [u, f] = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (pre[v] == -1 && cap[u][v] > 0) {
                    int new_flow = min(f, cap[u][v]);
                    pre[v] = u;
                    if (v == sink) return new_flow;
                    q.push({v, new_flow});
                }
            }
        }
        return 0ll;
    };

    vector<vector<int>> allPaths;  // Store all paths

    while (int new_flow = bfs(src, sink)) {
        flow += new_flow;
        int cur = sink;
        vector<int> path;
        while (cur != src) {
            path.push_back(cur);
            int p = pre[cur];
            cap[p][cur] -= new_flow;
            cap[cur][p] += new_flow;
            cur = p;
        }
        path.push_back(src);
        reverse(path.begin(), path.end());
        allPaths.push_back(path);
    }

    cout << "Maximum Flow: " << flow << '\n';
    cout << "Paths with maximum flow:\n";
    for (const auto& path : allPaths) {
        for (size_t i = 0; i < path.size(); ++i) {
            if (i > 0) cout << " -> ";
            cout << path[i];
        }
        cout << '\n';
    }

    cout << "Paths based on original edges:\n";
    for (const auto& path : allPaths) {
        bool validPath = true;
        for (size_t i = 0; i < path.size() - 1; ++i) {
            int u = path[i];
            int v = path[i + 1];
            auto it = find_if(edges.begin(), edges.end(), [u, v](const tuple<int, int, int>& edge) {
                return get<0>(edge) == u && get<1>(edge) == v;
            });
            if (it == edges.end()) {
                validPath = false;
                break;
            }
        }
        if (validPath) {
            for (size_t i = 0; i < path.size(); ++i) {
                if (i > 0) cout << " -> ";
                cout << path[i];
            }
            cout << '\n';
        }
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