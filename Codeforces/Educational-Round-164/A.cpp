
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int cnt = n / m + (n % m != 0);
    cnt = n - cnt;
    if (cnt > k) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}