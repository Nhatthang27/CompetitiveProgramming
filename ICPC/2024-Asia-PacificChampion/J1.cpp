#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dis(n + 1, vector<int>(n + 1, LONG_LONG_MAX));
    vector<vector<int>> pre(n + 1, vector<int>(n + 1, -1));
    fu(u, 1, n) dis[u][u] = 0;
    vector<vector<pii>> adj(n + 1, vector<pii>());
    fu(i, 1, m) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        dis[u][v] = dis[v][u] = w;
    }

    fu(k, 1, n) {
        fu(i, 1, n) {
            fu(j, 1, n) {
                if (dis[i][k] == LONG_LONG_MAX || dis[k][j] == LONG_LONG_MAX)
                    continue;
                if (dis[i][j] > dis[i][k] + dis[k][j]) {
                    dis[i][j] = dis[i][k] + dis[k][j];
                    pre[i][j] = k;
                }
            }
        }
    }
    vector<int> path;
    int last = n;
    while (pre[1][last] != -1) {
        path.push_back(last);
        last = pre[1][last];
    }
    path.push_back(1);

    vector<bool> inPath(n + 1, false);
    for (int u : path) {
        cout << u << " ";
        inPath[u] = true;
    }
    // cout << "\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
}