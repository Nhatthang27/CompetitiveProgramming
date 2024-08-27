
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;
const int INF = 1e18;
const int MAX = 1e6;
vector<int> dp;
vector<int> a(7, 0);

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    dp.assign(MAX + 7, INF);
    dp[0] = 0;
    a[1] = 1;
    a[2] = 3;
    a[3] = 6;
    a[4] = 10;
    a[5] = 15;
    fu(i, 1, MAX) {
        dp[i] = INF;
        fu(j, 1, 5) {
            if (i - a[j] >= 0 && dp[i - a[j]] != INF) {
                dp[i] = min(dp[i], dp[i - a[j]] + 1);
            }
        }
    }
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        if (n <= MAX)
            cout << dp[n] << "\n";
        else {
            int ans = (n - MAX) / 15 + 1;
            n = n - ans * 15;
            cout << dp[n] + ans << "\n";
        }
    }
}