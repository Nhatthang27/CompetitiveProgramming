
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
    vector<int> a(n + 1, 0);
    vector<int> b(m + 1, 0);
    fu(i, 1, n) cin >> a[i];
    fu(i, 1, m) cin >> b[i];
    int cnt = 0;
    fu(i, 1, n) {
        fu(j, 1, m) {
            if (a[i] + b[j] <= k)
                cnt++;
        }
    }
    cout << cnt << "\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}