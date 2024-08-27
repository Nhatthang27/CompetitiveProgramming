
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
    map<int, int> mp_b;
    vector<int> a(n + 1);
    fu(i, 1, n) cin >> a[i];
    vector<int> b(n + 1);
    fu(i, 1, n) cin >> b[i], mp_b[b[i]]++;
    int m;
    cin >> m;
    vector<int> d(m + 1);
    fu(i, 1, m) cin >> d[i];

    map<int, int> mp;
    fu(i, 1, n) {
        if (a[i] != b[i]) {
            mp[b[i]]++;
        }
    }
    map<int, int> mp_d;
    fu(i, 1, m) {
        mp_d[d[i]]++;
    }
    for (auto [key, value] : mp) {
        if (mp_d[key] < value) {
            cout << "NO\n";
            return;
        }
    }
    if (mp[d[m]] == 0 && mp_b[d[m]] == 0) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}