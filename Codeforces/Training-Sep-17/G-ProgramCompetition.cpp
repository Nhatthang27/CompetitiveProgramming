
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
    fu(i, 2, n) {
        int pi;
        cin >> pi;
        adj[pi].push_back(i);
    }

    int res = 0;
    function<int(int, int, int)> dfs = [&](int u, int par, int total) -> int {
        for (int v : adj[u]) {
            if (v == par) continue;
            total = dfs(v, u, total);
        }
        if (total > 0) {
            total--;
            res++;
        }
        return total + 1;
    };
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}