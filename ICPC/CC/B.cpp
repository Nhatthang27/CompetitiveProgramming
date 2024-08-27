
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
    int limit, n;
    cin >> limit >> n;
    vector<int> a;
    fu(i, 1, n) {
        int x;
        cin >> x;
        if (x <= limit) a.push_back(x);
    }
    if (a.empty()) {
        cout << "0 0\n";
        return;
    }

    // knapsack for two bags, each is in one bag only
    auto knapsack = [&](int limit, vector<int> a, vector<int>& rest, vector<int>& chose) {
        vector<vector<int>> dp(a.size(), vector<int>(limit + 1, 0));
        fu(i, 0, a.size() - 1) {
            fu(j, 0, limit) {
                if (i == 0) {
                    dp[i][j] = (a[i] <= j ? a[i] : 0);
                } else {
                    dp[i][j] = dp[i - 1][j];
                    if (a[i] <= j) dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i]] + a[i]);
                }
            }
        }
        int res = dp[a.size() - 1][limit];
        int i = a.size() - 1, j = limit;
        while (i >= 0 && j >= 0) {
            if (i == 0) {
                if (dp[i][j] == a[i]) chose.push_back(a[i]);
                break;
            }
            if (dp[i][j] == dp[i - 1][j]) {
                rest.push_back(a[i]);
                i--;
            } else {
                chose.push_back(a[i]);
                j -= a[i];
                i--;
            }
        }
        return res;
    };

    // a rest chose
    vector<int> rest, chose;
    vector<int> base = a;
    int best = knapsack(2 * limit, base, rest, chose);
    int res1 = 1e18, res2 = -1e18;

    fd(limit1, min(limit, best), 1) {
        int limit2 = min(best - limit1, limit);
        vector<int> base = a;
        vector<int> rest1, tmp;
        int ans1 = 0;
        if (!base.empty()) {
            ans1 = knapsack(limit1, base, rest1, tmp);
        }

        int ans2 = 0;
        if (!rest1.empty()) {
            vector<int> rest2;
            ans2 = knapsack(limit2, rest1, rest2, tmp);
        };
        if (ans1 + ans2 >= res1 + res2) {
            if (abs(ans1 - ans2) < abs(res1 - res2)) {
                res1 = ans1;
                res2 = ans2;
            }
        }
    }
    if (res1 < res2) swap(res1, res2);
    if (res1 == LONG_LONG_MAX) {
        res1 = 0;
        res2 = 0;
    }
    cout << res1 << ' ' << res2 << '\n';
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0) {
        solve();
    }
}