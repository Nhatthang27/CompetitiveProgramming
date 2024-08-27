
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
    vector<pii> a(n + 1);
    auto checkColiinear = [](pii x, pii y, pii z) -> bool {
        return (y.ss - x.ss) * (z.ff - y.ff) == (z.ss - y.ss) * (y.ff - x.ff);
    };
    map<int, bool> mp;

    fu(i, 1, n) cin >> a[i].ff >> a[i].ss;

    int cnt = 0;
    fu(i, 1, n - 2) {
        if (mp[i])
            continue;
        fu(j, i + 1, n - 1) {
            if (mp[i] || mp[j])
                continue;
            fu(k, j + 1, n) {
                if (mp[i] || mp[j] || mp[k])
                    continue;
                if (!checkColiinear(a[i], a[j], a[k])) {
                    cnt++;
                    mp[i] = mp[j] = mp[k] = true;
                    // cout << i << " " << j << " " << k << endl;
                }
            }
        }
    }
    cout << cnt;
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
}