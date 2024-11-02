
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;
struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2> &pair) const
    {
        return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
};

void solve()
{
    int _n, m;
    cin >> _n >> m;

    int n = _n - m;
    vector<int> a(2000007);
    vector<int> num_zero(2000007, 0);

    int id = 0;
    int cnt_zero = 0;
    fu(i, 1, _n)
    {
        cin >> a[i];
        cnt_zero += (a[i] == 0);
        if (a[i] != 0)
        {
            a[++id] = a[i];
            num_zero[id] = cnt_zero;
        }
    }

    unordered_map<pii, int, pair_hash> dp;
    int ans = 0;
    while (a[n] == 0 && n > 0)
        n--;
    if (n == 0)
    {
        cout << 0 << endl;
        return;
    }
    fu(i, 1, n)
    {
        fu(j, 0, num_zero[i])
        {
            int intel = j;
            int stren = num_zero[i] - j;
            if (a[i] < 0)
            {
                if (stren >= abs(a[i]))
                {
                    dp[{i, j}] = max(dp[{i, j}], dp[{i - 1, intel}] + 1);
                }
            }
            else
            {
                if (intel >= a[i])
                {
                    // dp[i][j] = max(dp[i][j], dp[i - 1][stren] + 1);
                    dp[{i, j}] = max(dp[{i, j}], dp[{i - 1, stren}] + 1);
                }
            }
            ans = max(ans, dp[{i, j}]);
        }
    }

    
    // 1 2 -3 -4 -5
    // 1 2  3  4  5

    // (1, 0) = 0 (1, 1) = 1
    // (2, 0) = 0 (2, 1) = 1 (2, 2) = 2
    // (3, 0) = 1 (3, 1) = 1 (3, 2) = 2 (3, 3) = 2
    // (4, 0) = 1 (4, 1) = 1 (4, 2) = 2 (4, 3) = 3 (4, 4) = 3
    // (5, 0) = 1 (5, 1) = 1 (5, 2) = 2 (5, 3) = 2 (5, 4) = 2 (5, 5) = 2

    cout << ans << endl;
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