
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

vector<int> countPairsOfConnectableServers(vector<vector<int>> &edges,
                                           int signalSpeed) {
    int n = edges.size();
    vector<vector<pair<int, int>>> adj(n + 1);

    for (auto &e : edges) {
        adj[e[0]].push_back({e[1], e[2]});
        adj[e[1]].push_back({e[0], e[2]});
    }

    vector<int> down(n + 1, 0), up(n + 1, 0);
    function<int(int, int, int)> dfsDown = [&](int u, int par, int len) -> int {
        int cnt = (len % signalSpeed == 0);
        for (auto [v, w] : adj[u]) {
            if (v == par)
                continue;
            cnt += dfsDown(v, u, len + w);
        }
        return cnt;
    };
    vector<int> res(n + 1, 0);
    for (int u = 0; u <= n; u++) {
        int total = 0;
        for (auto [v, w] : adj[u]) {
            int tmp = dfs(v, u, w);
            res[u] += total * tmp;
            total += tmp;
        }
    }
    return res;
}