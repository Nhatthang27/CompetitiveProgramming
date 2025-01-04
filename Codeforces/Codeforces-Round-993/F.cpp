
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;
const int MAX = 2e5 + 7;

struct custom_hash
{
    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        x ^= FIXED_RANDOM;
        return x ^ (x >> 16);
    }
};

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n + 1), b(m + 1);
    int sum_a = 0, sum_b = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i], sum_a += a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i], sum_b += b[i];

    int sum = sum_a * sum_b;
    unordered_map<int, int, custom_hash> isExist_a, isExist_b;

    for (int i = 1; i <= n; i++)
    {
        if (abs(sum_a - a[i]) < MAX)
            isExist_a[sum_a - a[i]] = 1;
    }
    for (int i = 1; i <= m; i++)
    {
        if (abs(sum_b - b[i]) < MAX)
        {
            isExist_b[sum_b - b[i]] = 1;
        }
    }

    while (q-- > 0)
    {
        int x;
        cin >> x;
        bool flag = false;
        for (int i = 1; i <= (int)sqrt(abs(x)); i++)
        {
            if (x % i == 0)
            {
                int j = x / i;
                // cout << i << " " << j << "\n";
                if ((isExist_a[i] && isExist_b[j]) || (isExist_a[j] && isExist_b[i]))
                {
                    cout << "YES\n";
                    flag = true;
                    break;
                }
                if ((isExist_a[-i] && isExist_b[-j]) || (isExist_a[-j] && isExist_b[-i]))
                {
                    cout << "YES\n";
                    flag = true;
                    break;
                }
            }
        }
        if (!flag)
        {
            cout << "NO\n";
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