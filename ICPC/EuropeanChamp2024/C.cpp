
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
    vector<vector<int>> adj(n + 1, vector<int>());
    fu(i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> ant(n + 1, 1);
    vector<int> deg(n + 1, 0);
    set<pii> s;

    fu(u, 1, n) {
        deg[u] = adj[u].size();
        if (deg[u] == 1)
            s.insert({1, u});
    }

    while (!s.empty()) {
        auto [num_u, u] = *s.begin();
        s.erase(s.begin());

        for (int p : adj[u]) {
            if (ant[p] != 0) {
                if (ant[p] < ant[u]) {
                    cout << "NO\n";
                    return;
                }
                deg[p]--;
                ant[p] += ant[u];
                ant[u] = 0;
                if (deg[p] == 1)
                    s.insert({ant[p], p});
            }
        }
    }
    cout << "YES\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0) {
        solve();
    }
}