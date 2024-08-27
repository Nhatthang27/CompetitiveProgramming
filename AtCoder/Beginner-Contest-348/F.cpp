
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
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    fu(i, 1, n) {
        fu(j, 1, m) {
            cin >> a[i][j];
        }
    }

    vector<vector<bitset<2001>>> store(1000, vector<bitset<2001>>(m + 1, 0));
    int res = 0;
    fu(i, 1, n) {
        bitset<2001> cur;
        fu(j, 1, m) {
            cur ^= store[a[i][j]][j];
            store[a[i][j]][j][i] = 1;
        }
        res += cur.count();
    }
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