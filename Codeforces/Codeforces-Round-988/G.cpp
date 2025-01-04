
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;
const int MAX = 1e6;
const int MOD = 998244353;

int spf[MAX + 1];
void prepare()
{
    for (int i = 1; i <= MAX; i++)
        spf[i] = i;
    for (int i = 2; i <= MAX; i++)
    {
        if (spf[i] == i)
        {
            for (int j = 2; i * j <= MAX; j++)
            {
                if (spf[i * j] == i * j)
                    spf[i * j] = i;
            }
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<int> dp(MAX + 1, 0);

    auto factorization = [&](int x)
    {
        vector<int> factors;
        while (x > 1)
        {
            int p = spf[x];
            factors.push_back(p);
            while (x % p == 0)
                x /= p;
        }
        return factors;
    };

    auto f = factorization(a[1]);
    for (int mask = 1; mask < (1 << (int)f.size()); mask++)
    {
        int mul = 1;
        for (int id = 0; id < f.size(); id++)
        {
            if ((mask >> id) & 1)
                mul *= f[id];
        }
        dp[mul] = 1;
    }

    for (int i = 2; i <= n; i++)
    {
        int cnt = 0;
        f = factorization(a[i]);
        int len = f.size();
        int total = 0;
        for (int mask = 1; mask < (1 << len); mask++)
        {
            int mul = 1;
            bool isAdd = __builtin_popcount(mask) % 2;
            for (int id = 0; id < len; id++)
            {
                if ((mask >> id) & 1)
                {
                    mul *= f[id];
                }
            }
            if (isAdd)
                total = (total + dp[mul]) % MOD;
            else
                total = (total - dp[mul] + MOD) % MOD;
        }

        for (int mask = 1; mask < (1 << len); mask++)
        {
            int mul = 1;
            for (int id = 0; id < len; id++)
            {
                if ((mask >> id) & 1)
                {
                    mul *= f[id];
                }
            }
            dp[mul] = (dp[mul] + total) % MOD;
        }
        if (i == n)
        {
            cout << total;
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    prepare();
    int t;
    // cin >> t;
    t = 1;
    while (t-- > 0)
    {
        solve();
    }
}