
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
    vector<int> a(n + 1);
    vector<int> cnt(n + 1);
    fu(i, 1, n) cin >> a[i];
    int res = 0;
    for (int r = 1, l = 1; r <= n; r++) {
        cnt[a[r]]++;
        while (cnt[a[r]] > 1) {
            cnt[a[l]]--;
            l++;
        }
        res += r - l + 1;
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