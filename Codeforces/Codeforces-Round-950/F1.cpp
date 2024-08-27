
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

    vector<pair<int, int>> a(k);
    for (auto &c : a) cin >> c.first >> c.second;

    vector<pair<int, int>> b = a;

    sort(a.begin(), a.end(), [&](pair<int, int> x, pair<int, int> y) {
        if (x.first == y.first) return x.second < y.second;
        return x.first < y.first;
    });

    for (int i = 1; i < k; ++i) {
        a[i].second = (a[i].first == a[i - 1].first ? a[i - 1].second : a[i].second);
    }

    vector<int> minLeft(k + 1, 2e9);
    for (int i = k - 1; i >= 0; --i) {
        minLeft[i] = min(minLeft[i + 1], a[i].second);
    }

    map<int, int> maxDown;
    for (int i = 0; i < k; ++i) {
        maxDown[minLeft[i]] = max(maxDown[minLeft[i]], a[i].first);
    }

    int ans = 0, currrentX = 1;
    for (; maxDown.count(currrentX) != 0; currrentX++) {
    };

    for (auto [u, v] : maxDown) {
        ans += (u - 1) * (v - currrentX + 1);
        currrentX = v + 1;
    }

    if (maxDown[m] != n) {
        ans += m * (n - currrentX + 1);
    }

    cout << ans << "\n";

    for (auto [u, v] : b) {
        if (maxDown[v] == u) {
            cout << "1 ";
        } else {
            cout << "0 ";
        }
    }
    cout << "\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}