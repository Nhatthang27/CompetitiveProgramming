
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
    fu(i, 1, n) { cin >> a[i]; }
    if (n == 1) {
        cout << 1 << "\n";
        return;
    }
    sort(a.begin() + 1, a.end());
    int med = n / 2 + (n % 2 == 1);
    int medOri = a[med];
    int res = 0;
    fu(i, med, n) { res += (a[i] == a[med]); }
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