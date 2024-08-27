
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
    int n, f, k;
    cin >> n >> f >> k;
    vector<int> a(n + 1);
    fu(i, 1, n) cin >> a[i];
    int fav = a[f];
    int l = 0, r = 0;
    sort(a.begin() + 1, a.end(), greater<int>());
    fu(i, 1, n) {
        if (a[i] == fav) {
            if (l == 0) l = i;
            r = i;
        }
    }
    if (r <= k) {
        cout << "YES\n";
    } else if (l > k) {
        cout << "NO\n";
    } else {
        cout << "MAYBE\n";
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