#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 998244353;

void solve_case(int k, int n)
{
    // DP array: dp[x][l] - số cách tạo tích x với dãy có độ dài tối đa l
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));

    // Khởi tạo: dp[1][l] = n cho mọi l
    for (int l = 1; l <= n; l++)
        dp[1][l] = 1;

    // Tính DP cho từng x từ 2 đến k
    for (int x = 2; x <= k; x++)
    {
        for (int d = 1; d * d <= x; d++)
        {
            if (x % d == 0)
            {
                // Thêm số cách của ước số d
                for (int l = 1; l <= n; l++)
                {
                    dp[x][l] = (dp[x][l] + dp[d][l - 1]) % MOD;
                    if (d != x / d)
                        dp[x][l] = (dp[x][l] + dp[x / d][l - 1]) % MOD;
                }
            }
        }
    }

    // Tính tổng số cách tạo x với mọi độ dài từ 1 đến n
    vector<int> result(k + 1, 0);
    for (int x = 1; x <= k; x++)
    {
        for (int l = 1; l <= n; l++)
        {
            result[x] = (result[x] + dp[x][l]) % MOD;
        }
    }

    // In kết quả
    for (int x = 1; x <= k; x++)
    {
        cout << result[x] << " ";
    }
    cout << "\n";
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k, n;
        cin >> k >> n;
        solve_case(k, n);
    }
    return 0;
}
