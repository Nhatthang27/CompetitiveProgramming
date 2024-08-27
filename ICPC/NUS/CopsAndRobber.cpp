
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
const int X[] = {0, 0, 1, -1};
const int Y[] = {1, -1, 0, 0};
void solve() {
    int nRow, nCol, nType;
    cin >> nCol >> nRow >> nType;
    vector<string> inp(nRow);
    fu(i, 0, nRow - 1) cin >> inp[i];
    vector<int> type(nType + 1);
    fu(i, 1, nType) cin >> type[i];

    int numNode = 2 * nRow * nCol + 2;
    int src = numNode - 1, sink = numNode;
    Karp karp(numNode, src, sink);

    for (int i = 0; i < nRow; i++) {
        for (int j = 0; j < nCol; j++) {
            int u = i * nCol + j + 1;
            int cost = (inp[i][j] == '.' || inp[i][j] == 'B') ? LONG_LONG_MAX : type[inp[i][j] - 'a' + 1];
            karp.add_edge(u, u + nRow * nCol, cost);

            bool isEnd = false;
            for (int k = 0; k < 4; k++) {
                int x = i + X[k];
                int y = j + Y[k];

                if (x >= 0 && x < nRow && y >= 0 && y < nCol) {
                    int v = x * nCol + y + 1;
                    karp.add_edge(u + nRow * nCol, v, cost);
                } else {
                    isEnd = true;
                }
            }
            if (isEnd) {
                karp.add_edge(u + nRow * nCol, sink, LONG_LONG_MAX);
            }
            if (inp[i][j] == 'B') {
                karp.add_edge(src, u, LONG_LONG_MAX);
            }
        }
    }
    int maxFlow = karp.getMaxFLow();
    cout << (maxFlow == LONG_LONG_MAX ? (long long)-1 : maxFlow) << '\n';
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0) {
        solve();
    }
}