
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;
const int MOD = 1e9 + 7;

struct custom_hash
{
    size_t operator()(const pair<int, int> &p) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        size_t hash1 = hash<int>{}(p.first);
        size_t hash2 = hash<int>{}(p.second);
        return hash1 ^ (hash2 + 0x9e3779b9 + (hash1 << 6) + (hash1 >> 2) + FIXED_RANDOM);
    }
};
unordered_map<pair<int, int>, bool, custom_hash> VALID_COL({{{0, 3}, true}, {{1, 0}, true}, {{1, 1}, true}, {{1, 2}, true}, {{2, 0}, true}, {{2, 1}, true}, {{2, 2}, true}, {{3, 0}, true}, {{3, 1}, true}, {{3, 2}, true}});

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(m + 1, vector<int>((1 << (2 * n)) + 1, 0));

    auto isValidCol = [&](int prev, int cur)
    {
        return VALID_COL[{prev, cur}];
    };

    auto isValidRow = [&](int prev, int cur)
    {
        return (make_pair(prev, cur) != make_pair(0LL, 2LL)) && (make_pair(prev, cur) != make_pair(1LL, 0LL));
    };

    auto isValidFirstCol = [&](int cur)
    {
        return cur != 2;
    };

    auto isValidLastCol = [&](int cur)
    {
        return cur != 1;
    };

    auto isValidFirstRow = [&](int cur)
    {
        return cur != 0;
    };
    auto isValidLastRow = [&](int cur)
    {
        return cur != 3;
    };

    vector<unordered_map<string, int>> dp(m + 1);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                if (i == 0 && !isValidFirstRow(k))
                    continue;
                if (j == 0 && !isValidFirstCol(k))
                    continue;
                if (i == m - 1 && !isValidLastRow(k))
                    continue;
                if (j == n - 1 && !isValidLastCol(k))
                    continue;
            }
        }
    }
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