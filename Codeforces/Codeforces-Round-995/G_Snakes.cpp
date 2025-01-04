
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<pair<char, int>> queries(q + 1);
    vector<vector<int>> dis(n + 1, vector<int>(n + 1, 0));
    vector<int> inc(n + 1, 0);
    for (int i = 1; i <= q; i++)
    {
        char type;
        int snake;
        cin >> snake >> type;
        queries[i] = {snake, type};
        inc[snake] += (type == '+');
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                continue;
            int min_dis = 0;
            int j_desc = 0;
            for (int k = 1; k <= q; k++)
            {
                auto [snake, type] = queries[k];
                if (type == '+' && snake == i)
                {
                    if (j_desc > 0)
                    {
                        j_desc--;
                    }
                    else
                    {
                        min_dis++;
                    }
                }
                if (type == '-' && snake == j)
                    j_desc++;
            }
            dis[i][j] = min_dis;
        }
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         if (i == j)
    //             continue;
    //         cerr << i << " " << j << " " << dis[i][j] << "\n";
    //     }
    // }
    // cerr << "\n";

    vector<vector<int>> dp(1 << n, vector<int>(n + 1, LONG_LONG_MAX));
    for (int i = 1; i <= n; i++)
        dp[(1 << (i - 1))][i] = 0;
    for (int mask = 1; mask < (1 << n); mask++)
    {
        for (int i = 1; i <= n; i++)
        {
            // cerr << mask << " " << i << "\n";
            if (!((mask >> (i - 1)) & 1) || dp[mask][i] == LONG_LONG_MAX)
                continue;
            for (int j = 1; j <= n; j++)
            {
                if ((mask >> (j - 1)) & 1)
                    continue;
                int newMask = mask | (1 << (j - 1));
                if (dp[newMask][j] > dp[mask][i] + dis[i][j])
                    dp[newMask][j] = dp[mask][i] + dis[i][j];
            }
        }
    }

    int res = LONG_LONG_MAX;
    for (int i = 1; i <= n; i++)
    {
        // cerr << i << " " << dp[(1 << n) - 1][i] << "\n";
        res = min(res, dp[(1 << n) - 1][i] + inc[i]);
    }
    cout << res + n;
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0)
    {
        solve();
    }
}