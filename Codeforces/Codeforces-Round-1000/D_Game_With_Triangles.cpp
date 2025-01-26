
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(m + 1);
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];

    sort(a.begin() + 1, a.end());
    sort(b.begin() + 1, b.end());
    vector<int> sum_a(n + 1, 0), sum_b(m + 1, 0);

    for (int i = 1; i <= n; i++)
        sum_a[i] = sum_a[i - 1] + a[i];
    for (int i = 1; i <= m; i++)
        sum_b[i] = sum_b[i - 1] + b[i];

    vector<int> res(max(n, m), 0);
    int len = min(n, m / 2);

    for (int j = 1; j <= min(n, m / 2); j++)
    {
        dp[0][j] = (sum_b[m] - sum_b[m - j]) - sum_b[j];
        res[j] = max(dp[0][j], res[j]);
    }

    for (int i = 1; i <= min(n / 2, m); i++)
    {
        int rest = n - 2 * i;
        // cerr << i << " " << 0 << "\n";
        dp[i][0] = (sum_a[n] - sum_a[n - i]) - sum_a[i];
        res[i] = max(dp[i][0], res[i]);
        len = max(len, i);
        for (int j = 1; j <= min((m - i) / 2, rest); j++)
        {
            len = max(len, i + j);
            dp[i][j] = dp[i][0] + (sum_b[m] - sum_b[m - j]) - sum_b[j];
            // cerr << i << " " << j << " " << dp[i][j] << "\n";
            res[i + j] = max(dp[i][j], res[i + j]);
        }
    }
    cout << len << "\n";
    for (int i = 1; i <= len; i++)
        cout << res[i] << " ";
    cout << "\n";
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
}