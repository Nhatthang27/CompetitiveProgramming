
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
    string t;
    cin >> t;
    int len = t.size();
    t = " " + t;
    int n;
    cin >> n;
    vector<vector<string>> bag(n + 1);
    fu(i, 1, n) {
        int k;
        cin >> k;
        while (k-- > 0) {
            string s;
            cin >> s;
            bag[i].push_back(s);
        }
    }
    vector<vector<int>> dp(n + 1, vector<int>(len + 1, LONG_LONG_MAX));
    dp[0][0] = 0;
    fu(i, 1, n) {
        dp[i] = dp[i - 1];
        fu(j, 1, len) {
            if (dp[i - 1][j - 1] == LONG_LONG_MAX)
                continue;
            for (auto s : bag[i]) {
                int sz = s.size();
                if (s == t.substr(j, sz)) {
                    dp[i][j + sz - 1] =
                        min(dp[i][j + sz - 1], dp[i - 1][j - 1] + 1);
                }
            }
        }
    }
    cout << (dp[n][len] == LONG_LONG_MAX ? -1 : dp[n][len]);
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
}