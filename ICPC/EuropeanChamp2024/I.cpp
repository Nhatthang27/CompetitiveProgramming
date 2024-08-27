
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
    vector<int> x(n + 1), y(n + 1), r(n + 1);
    fu(i, 1, n) cin >> x[i] >> y[i] >> r[i];
    vector<vector<int>> adj(n + 1);

    auto isTangent = [&](int i, int j) {
        int dx = x[i] - x[j];
        int dy = y[i] - y[j];
        int d = dx * dx + dy * dy;
        int dr = r[i] + r[j];
        return d == dr * dr;
    };

    fu(i, 1, n) {
        fu(j, i + 1, n) {
            if (isTangent(i, j)) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    vector<int> col(n + 1, -1);
    vector<int> d(2);

    function<void(int, int, bool &)> dfs = [&](int u, int c, bool &ok) {
        // if (!ok)
        //     return;
        d[c]++;
        col[u] = c;
        for (int v : adj[u]) {
            if (col[v] == -1) {
                dfs(v, 1 - c, ok);
            } else if (col[v] == c) {
                ok = false;
                // return;
            }
        }
    };

    fu(i, 1, n) {
        if (col[i] == -1) {
            d = {0, 0};
            bool ok = true;
            dfs(i, 0, ok);
            if (ok && d[0] != d[1]) {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0) {
        solve();
    }
}