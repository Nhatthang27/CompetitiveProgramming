#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 998244353;

// Hàm tính số cách để tạo các dãy có tích bằng x
void solve_case(int k, int n)
{
    vector<int> dp(k + 1, 0); // DP array
    dp[1] = n;                // Có 1 cách để tạo tích bằng 1: [1]

    // Tính DP cho từng x từ 2 đến k
    for (int x = 2; x <= k; x++)
    {
        for (int d = 1; d * d <= x; d++)
        {
            if (x % d == 0)
            {
                dp[x] = (dp[x] + dp[d]) % MOD; // Thêm số cách của ước số d
                if (d != x / d)
                    dp[x] = (dp[x] + dp[x / d]) % MOD; // Thêm số cách của ước số x / d
            }
        }
    }

    vector<int> result;
    for (int x = 1; x <= k; x++)
    {
        cout << dp[x] << " ";
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
