
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
    int n, k, q;
    cin >> n >> k >> q;
    vector<vector<int>> a(n + 1, vector<int>(k + 1));
    vector<vector<int>> reg(k, vector<int>(n));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            cin >> a[i][j];
            a[i][j] |= a[i - 1][j];
            reg[j - 1][i - 1] = a[i][j];
        }
    }
    while (q--) {
        int m;
        cin >> m;
        int mx = 0, mn = INT_MAX;
        for (int i = 0; i < m; ++i) {
            int x, c;
            char op;
            cin >> x >> op >> c;
            --x;
            if (op == '<') {
                int p = lower_bound(reg[x].begin(), reg[x].end(), c) - reg[x].begin() - 1;
                mx = max(mx, 0ll);
                mn = min(mn, p);
            } else {
                int p = upper_bound(reg[x].begin(), reg[x].end(), c) - reg[x].begin();
                mx = max(mx, p);
                mn = min(mn, n - 1);
            }
        }
        if (mx >= n || mn <= -1 || mx > mn) {
            cout << "-1\n";
        } else {
            cout << mx + 1 << '\n';
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0) {
        solve();
    }
}