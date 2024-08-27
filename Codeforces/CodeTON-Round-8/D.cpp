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
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(n + 1, vector<int>(n + 1, 0));
    fu(i, 1, n) {
        fu(j, i, n) {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> dp(n + 1, vector<int>());
    auto addElement = [&](vector<int> &v, vector<int> x, int add = 0) {
        for (int i = 0; i < x.size(); i++) {
            v.push_back(x[i] + add);
        }
        sort(v.begin(), v.end(), greater<int>());
        v.resize(min(k, (int)v.size()));
    };

    addElement(dp[1], {a[1][1], 0});
    fu(r, 2, n) {
        addElement(dp[r], dp[r - 1]);
        fd(l, r, 1) {
            if (l - 2 > 0)
                addElement(dp[r], dp[l - 2], a[l][r]);
            else
                addElement(dp[r], {a[l][r]});
        }
    }
    for (int x : dp[n]) {
        cout << x << ' ';
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