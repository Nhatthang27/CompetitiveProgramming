/*
    Code by: KoKoDuDu
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pll pair<int, int>
#define db double
#define fi first
#define se second
const int maxN = 2e5 + 0307;
const int MOD = 1e9 + 7;
const int INF = 1e18;
void solve() {
    string s;
    cin >> s;
    int k, ans = 0;
    cin >> k;
    vector<int> dp(10, 0);
    for (int i = 0; i < s.size(); i++) {
        int t = s[i] - '0';
        dp[t]++;
    }
    while (k >= 10) {
        for (int num = 10; num > 0; num--) {
            dp[num % 10] += dp[(num - 1) % 10];
            dp[num % 10] %= MOD;
        }
        k -= 10;
    }

    for (int num = 0; num < 10; num++) {
        if (num + k >= 10) {
            dp[1] += dp[num];
            dp[1] %= MOD;
            dp[(num + k) % 10] += dp[num];
            dp[(num + k) % 10] %= MOD;
            dp[num] = 0;
        }
    }
    for (int i = 0; i < 10; i++) {
        ans += dp[i];
        ans %= MOD;
    }
    cout << ans << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int numTest = 1;
    cin >> numTest;
    while (numTest--) {
        solve();
    }
    return 0;
}
