
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
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    fu(i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Find diameter
    function<void(int, vector<int> &)> bfs = [&](int root, vector<int> &d) {
        queue<int> q;
        q.push(root);
        d[root] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (d[v] == -1) {
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            }
        }
    };

    vector<int> d1(n + 1, -1);
    vector<int> d2(n + 1, -1);
    bfs(1, d1);

    int leaf1 = max_element(d1.begin(), d1.end()) - d1.begin();
    d1.assign(n + 1, -1);
    bfs(leaf1, d1);

    int leaf2 = max_element(d1.begin(), d1.end()) - d1.begin();
    bfs(leaf2, d2);

    int diameter = *max_element(d2.begin(), d2.end());
    vector<int> center;

    fu(u, 1, n) {
        if ((d1[u] + d2[u]) != diameter) {
            continue;
        }
        if ((diameter % 2 == 0) && (d1[u] == diameter / 2)) {
            center.push_back(u);
        }
        if ((diameter % 2 == 1) &&
            (d1[u] == diameter / 2 || d2[u] == diameter / 2)) {
            center.push_back(u);
        }
    }

    vector<pii> res;
    if (diameter % 2 == 0) {
        fu(r, 0, diameter / 2) { res.push_back({center[0], r}); }
    } else {
        for (int r = diameter / 2; r >= 0; r -= 2) {
            res.push_back({center[0], r});
            res.push_back({center[1], r});
        }
    }
    cout << res.size() << "\n";
    for (pii p : res) {
        cout << p.ff << " " << p.ss << "\n";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}