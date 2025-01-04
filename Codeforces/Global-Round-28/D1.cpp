
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;
const int MAX = 3e5 + 7;
int a[MAX], b[MAX];
int n, m;
vector<int> store;
int rmq[20][MAX];

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];

    int ff = a[1];

    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);

    store.clear();
    for (int i = 1; i <= m; ++i)
    {
        if (b[i] <= ff)
        {
            store.push_back(0);
        }
        else
        {
            int pos = lower_bound(a + 1, a + n + 1, b[i]) - a;
            store.push_back(n - pos + 1);
        }
    }
    sort(store.begin(), store.end());
    for (int i = 1; i <= store.size(); ++i)
        rmq[0][i] = store[i - 1];
    for (int i = 1; i < 20; ++i)
    {
        for (int j = 1; j <= store.size(); ++j)
        {
            rmq[i][j] = rmq[i - 1][j];
            if (j + (1 << (i - 1)) <= store.size())
                rmq[i][j] = max(rmq[i][j], rmq[i - 1][j + (1 << (i - 1))]);
        }
    }
    auto get_max = [&](int l, int r) -> int
    {
        int len = r - l + 1;
        int k = 31 - __builtin_clz(len);
        return max(rmq[k][l], rmq[k][r - (1 << k) + 1]);
    };

    for (int i = 1; i <= m; ++i)
    {
        int sum = 0;
        for (int j = 1; j + i - 1 <= m; j += i)
        {
            sum += get_max(j, j + i - 1) + 1;
        }
        cout << sum << ' ';
    }
    cout << '\n';
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
