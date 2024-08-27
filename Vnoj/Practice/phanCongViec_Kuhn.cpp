
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

struct Kuhn {
    int n, m;
    vector<vector<int>> adj;
    vector<int> mt;
    vector<bool> vis;

    Kuhn(int _n = 0, int _m = 0) {
        n = _n, m = _m;
        adj.assign(n + 1, vector<int>());
        mt.assign(m + 1, -1);
        vis.assign(n + 1, 0);
    }

    void add_edge(int u, int v) {
        adj[u].push_back(v);
    }

    bool dfs(int u) {
        if (vis[u])
            return 0;
        vis[u] = 1;
        for (int v : adj[u]) {
            if (mt[v] < 0 || dfs(mt[v])) {
                mt[v] = u;
                return 1;
            }
        }
        return 0;
    }

    int getMaxMatching() {
        int res = 0;
        fu(u, 1, n) {
            vis.assign(n + 1, 0);
            res += dfs(u);
        }
        return res;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> task(n + 1, vector<int>(n + 1));
    int min_time = LONG_LONG_MAX;
    int max_time = 0;
    fu(i, 1, n) {
        fu(j, 1, n) {
            cin >> task[i][j];
            min_time = min(min_time, task[i][j]);
            max_time = max(max_time, task[i][j]);
        }
    }
    auto isGood = [&](int time) -> bool {
        Kuhn kuhn(n, n);
        fu(i, 1, n) {
            fu(j, 1, n) {
                if (task[i][j] >= time) {
                    kuhn.add_edge(i, j);
                }
            }
        }
        return kuhn.getMaxMatching() == n;
    };
    int res = 0;
    int l = min_time, r = max_time;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (isGood(mid)) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << res << "\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0) {
        solve();
    }
}
