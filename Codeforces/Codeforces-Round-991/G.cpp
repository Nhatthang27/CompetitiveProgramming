
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define ff first
#define ss second
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1, vector<int>());
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto bfs = [&](int start, const vector<vector<int>> &adj) {
        int n = adj.size();
        vector<int> dist(n, -1);
        queue<int> q;

        q.push(start);
        dist[start] = 0;

        int farthestNode = start, maxDist = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : adj[node]) {
                if (dist[neighbor] == -1) {  // Nếu chưa thăm
                    dist[neighbor] = dist[node] + 1;
                    q.push(neighbor);

                    // Cập nhật đỉnh xa nhất
                    if (dist[neighbor] > maxDist) {
                        maxDist = dist[neighbor];
                        farthestNode = neighbor;
                    }
                }
            }
        }
        return make_pair(farthestNode, maxDist);
    };

    auto findPath = [&](int start, int end, const vector<vector<int>> &adj) {
        int n = adj.size();
        vector<int> parent(n, -1);
        queue<int> q;

        q.push(start);
        parent[start] = start;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : adj[node]) {
                if (parent[neighbor] == -1) {
                    parent[neighbor] = node;
                    q.push(neighbor);

                    if (neighbor == end) break;
                }
            }
        }

        vector<int> path;
        for (int cur = end; cur != start; cur = parent[cur]) {
            path.push_back(cur);
        }
        path.push_back(start);
        reverse(path.begin(), path.end());
        return path;
    };

    auto [farthest1, _] = bfs(1, adj);

    auto [farthest2, diameter] = bfs(farthest1, adj);

    vector<int> diameterPath = findPath(farthest1, farthest2, adj);

    // for (int x : diameterPath) cout << x << ' ';
    // cout << '\n';

    if ((int)diameterPath.size() == 2) {
        cout << 1 << '\n';
        return;
    }

    int res = 2;
    for (int i = 1; i < (int)diameterPath.size() - 1; i++) {
        res += adj[diameterPath[i]].size() - 2;
    }

    int g1 = -1, g2 = -1;
    for (int u = 1; u <= n; u++) {
        if (g1 == -1) {
            g1 = u;
        } else if (adj[u].size() >= adj[g1].size()) {
            g2 = g1;
            g1 = u;
        } else if (g2 == -1 || adj[u].size() > adj[g2].size()) {
            g2 = u;
        }
    }
    vector<int> subPath = findPath(g1, g2, adj);

    int ans = (int)adj[g1].size() + (int)adj[g2].size() - 2;
    for (int i = 1; i < (int)subPath.size() - 1; i++) {
        ans += adj[subPath[i]].size() - 2;
    }

    cout << max(res, ans) << '\n';
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}