
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
    int n, q;
    cin >> n >> q;
    vector<vector<int>> p(n + 7, vector<int>(20, -1));
    fu(v, 2, n) {
        int u;
        cin >> u;
        p[v][0] = u;
    }

    fu(j, 1, 19) {
        fu(i, 1, n) {
            if (p[i][j - 1] != -1) {
                p[i][j] = p[p[i][j - 1]][j - 1];
            }
        }
    }

    while (q-- > 0) {
        int u, k;
        cin >> u >> k;
        fd(i, 19, 0) {
            if (u == -1)
                break;
            if (k >= (1 << i)) {
                u = p[u][i];
                k -= (1 << i);
            }
        }
        cout << u << "\n";
    }
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
}