
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;
const int MAX = 24;

void solve() {
    int n;
    cin >> n;

    vector<int> val((1 << MAX) + 7, 0);
    vector<int> dp((1 << MAX) + 7, 0);

    fu(i, 1, n) {
        char x;
        int v = 0;
        fu(j, 1, 3) {
            cin >> x;
            if (x <= 'x')
            v |= (1 << (x - 'a'));
        }
        val[v]++;
    }

    fu(i, 0, (1 << MAX) - 1) {
        dp[i] = val[i];
    }

    fu(i, 0, MAX - 1) {
        fu(mask, 0, (1 << MAX) - 1) {
            dp[mask | (1 << i)] += dp[mask];
            // if (mask & (1 << i)) {
            //     dp[mask] += dp[mask ^ (1 << i)];
            // }
        }
    }

    int res = 0;
    fu(mask, 0, (1 << MAX) - 1) {
        // int x = n - dp[mask];
        res ^= (dp[mask] * dp[mask]);
        // res ^= (x * x);
        // res ^= (n - dp[mask]) * (n - dp[mask]);
    }
    cout << res << "\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0) {
        solve();
    }
}