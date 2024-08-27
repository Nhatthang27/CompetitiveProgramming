
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

struct Karp {
    int n, src, sink;
    vector<vector<int>> adj;
    vector<vector<int>> cap;
    vector<int> pre;

    Karp(int _n = 0, int _src = 0, int _sink = 0) {
        n = _n, src = _src, sink = _sink;
        adj.assign(n + 7, vector<int>());
        cap.assign(n + 7, vector<int>(n + 7, 0));
        pre.assign(n + 7, -1);
    }

    void add_edge(int u, int v, int w) {
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
        int src = n + n + 1;
        int sink = n + n + 2;
        Karp karp(n + n + 2, src, sink);
        fu(i, 1, n) {
            karp.add_edge(src, i, 1);
            fu(j, 1, n) {
                if (task[i][j] <= time) {
                    karp.add_edge(i, n + j, 1);
                }
            }
        }
        fu(j, 1, n) {
            karp.add_edge(n + j, sink, 1);
        }
        return karp.getMaxFLow() == n;
    };
    int res = 0;
    int l = min_time, r = max_time;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (isGood(mid)) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
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