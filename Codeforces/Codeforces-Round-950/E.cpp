
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
    vector<vector<int>> a(n + 1, vector<int>(m + 1)), b(n + 1, vector<int>(m + 1));
    vector<int> c(n * m + 11), r(n * m + 11), fc(n * m + 11), fr(n * m + 11);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> b[i][j];
        }
    }

    fu(i, 1, n) {
        fu(j, 1, m) {
            c[a[i][j]] = i;
            r[a[i][j]] = j;
        }
    }

    fu(i, 1, n) {
        fu(j, 1, m) {
            fc[c[b[i][j]]] = i;
            fr[r[b[i][j]]] = j;
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] != b[fc[i]][fr[j]]) {
                cnt++;
            }
        }
    }
    cout << (cnt == 0 ? "YES\n" : "NO\n");
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}