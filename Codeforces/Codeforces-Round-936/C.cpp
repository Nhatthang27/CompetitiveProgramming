
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
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n + 1, vector<int>());
    fu(i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> numChild(n + 1, 0), child(n + 1, 0);
    function<void(int, int)> dfs = [&](int u, int p) {
        numChild[u] = 1;
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            dfs(v, u);
            numChild[u] += numChild[v];
        }
    };
    dfs(1, -1);

    function<void(int, int, int, int &)> check = [&](int u, int p, int x,
                                                     int &dem) {
        if (dem >= k) {
            return;
        }
        int sum = 1;
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            check(v, u, x, dem);
            sum += child[v];
        }
        if (sum >= x && u != 1 && dem < k) {
            dem++;
            child[u] = 0;
        } else {
            child[u] = sum;
        }
    };

    int l = 1;
    int r = n;
    int res = 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        child = numChild;
        int dem = 0;
        check(1, -1, mid, dem);
        if (dem >= k && child[1] >= mid) {
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
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}