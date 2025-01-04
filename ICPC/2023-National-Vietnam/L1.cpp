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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(m + 1);
    fu(i, 1, m) cin >> a[i];

    vector<int> res(n + 1, 0);
    fu(l, 1, m) {
        vector<int> point(n + 1, 0), cnt(m + 1, 0);
        fu(i, 1, n) point[i] = 0;

        fu(r, l, min(l + k - 1, m)) {
            int rank = cnt[point[a[r]] + 1] + 1;
            res[a[r]] = max(res[a[r]], rank);
            point[a[r]]++;
            cnt[point[a[r]]]++;
        }

        fu(i, 1, n) {
            int rank = cnt[point[i] + 1] + 1;
            res[i] = max(res[i], rank);
        }
    }
    fu(i, 1, n) cout << res[i] << ' ';
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0) {
        solve();
    }
}
