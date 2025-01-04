#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAX = 200;

int a[MAX + 1][MAX + 1], g[MAX + 1][MAX + 1][MAX + 1], dp[MAX + 1][MAX + 1];
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    // assign all values to LONG_LONG_MAX
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = LONG_LONG_MAX;
            for (int z = 0; z <= m; z++)
            {
                g[i][j][z] = LONG_LONG_MAX;
            }
        }
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    auto get = [&](int row, int col, int turn)
    {
        return (col + turn <= m ? a[row][col + turn] : a[row][(col + turn) % m]);
    };
    // dp i j turn

    for (int turn = 0; turn <= m - 1; turn++)
    {
        g[1][1][turn] = k * turn + a[1][1 + turn];
        dp[1][1] = min(dp[1][1], g[1][1][turn]);
    }

    for (int j = 2; j <= m; j++)
    {
        for (int turn = 0; turn <= m - 1; turn++)
        {
            g[1][j][turn] = g[1][j - 1][turn] + get(1, j, turn);
            dp[1][j] = min(dp[1][j], g[1][j][turn]);
        }
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int turn = 0; turn <= m - 1; turn++)
            {

                g[i][j][turn] = min(g[i][j][turn], k * turn + dp[i - 1][j] + get(i, j, turn));

                if (j > 1)
                {
                    g[i][j][turn] = min(g[i][j][turn], g[i][j - 1][turn] + get(i, j, turn));
                }
                dp[i][j] = min(dp[i][j], g[i][j][turn]);
            }
        }
    }

    cout << dp[n][m] << "\n";
}

int32_t main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        solve();
    }
}