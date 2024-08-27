
#include <bits/stdc++.h>
#define int unsigned long long
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
    unordered_map<int, int> mp;
    fu(i, 1, n) {
        cin >> a[i];
        mp[a[i]]++;
    }
    sort(a.begin(), a.end());
    int lcm = 1;
    fu(i, 1, n) {
        lcm = lcm / __gcd(lcm, a[i]) * a[i];
        if (lcm > a[n]) {
            cout << n << "\n";
            return;
        }
    }

    auto calc = [&](int x) {
        int lcm = 1, num = 0;
        for (auto [p, cnt] : mp) {
            if (x % p == 0) {
                lcm = lcm * p / __gcd(lcm, p);
                num += cnt;
            }
        }
        return (lcm == x ? num : 0);
    };

    int res = 0;
    for (int i = 2; i * i <= a[n]; i++) {
        if (a[n] % i == 0) {
            if (mp.find(i) == mp.end()) {
                res = max(res, calc(i));
            }
            if (mp.find(a[n] / i) == mp.end()) {
                res = max(res, calc(a[n] / i));
            }
        }
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