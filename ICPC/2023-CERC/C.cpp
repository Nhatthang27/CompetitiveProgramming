
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
    int nG, nC, nT;
    cin >> nG >> nC >> nT;
    vector<int> g(nG + 1), c(nC + 1), t(nT + 1);
    fu(i, 1, nC) cin >> c[i];
    fu(i, 1, nG) cin >> g[i];
    fu(i, 1, nT) cin >> t[i];

    vector<int> cake(nC + 1, 0);
    fu(i, 1, nC) {
        fu(j, 1, nG) {
            int x;
            cin >> x;
            cake[i] += x * g[j];
        }
    }

    fu(i, 1, nC) {
        int z;
        cin >> z;
        while (z-- > 0) {
            int tool;
            cin >> tool;
            cake[i] += t[tool];
        }
    }
    int res = 0;
    fu(i, 1, nC) {
        res += max(0LL, c[i] - cake[i]);
        cout << cake[i] << " ";
    }
    cout << "\n";
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