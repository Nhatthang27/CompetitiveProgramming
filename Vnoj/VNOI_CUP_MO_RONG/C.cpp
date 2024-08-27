
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> sir(n + 1, 0);
    vector<vector<int>> emps(n + 1);
    fu(i, 2, n)
    {
        int s = 0;
        cin >> s;
        sir[i] = s;
        emps[s].push_back(i);
    }
    vector<int> strSir(n + 1, 0), strEmp(n + 1, 0);
    fu(i, 2, n)
    {
        cin >> strSir[i];
    }
    fu(i, 2, n)
    {
        cin >> strEmp[i];
    }
    vector<int> dp(1 << n, LONG_LONG_MAX);
    // fu(i, 1, n)
    // {
    //     cout << i << " -> ";
    //     for (int emp : emps[i])
    //     {
    //         cout << emp << " ";
    //     }
    //     cout << "\n";
    // }
    fu(i, 1, n) dp[1 << (i - 1)] = 0;
    for (int mask = 1; mask < (1 << n); mask++)
    {
        fu(i, 1, n)
        {
            if (mask & (1 << (i - 1)))
                continue;
            int newMask = mask | (1 << (i - 1));
            int newCost = dp[mask];
            if (mask & (1 << (sir[i] - 1)))
                newCost += strSir[i];
            for (int emp : emps[i])
            {
                if (mask & (1 << (emp - 1)))
                    newCost += strEmp[emp];
            }
            dp[newMask] = min(dp[newMask], newCost);
        }
    }
    vector<int> res(n + 1, LONG_LONG_MAX);
    for (int mask = 0; mask < (1 << n); mask++)
    {
        int cnt = __builtin_popcount(mask);
        res[cnt] = min(res[cnt], dp[mask]);
    }
    fu(i, 1, n)
    {
        cout << res[i] << " ";
    }
    cout << "\n";
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        solve();
    }
}