
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;
const int N = 60;
const int MAX = 1e4;

int a[N + 1];
int n, total;
int dp[N + 1][N * MAX + 1];

void solve()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        total += a[i];
    }
    sort(a + 1, a + n + 1, greater<int>());

    for (int i = 1; i <= n; i++)
        dp[i][a[i]] = 1;
    // 5 4 3 1 1
    for (int i = 1; i <= n; i++)
    {
        for (int s = a[i]; s <= min(total / 2 + a[i], total); s++)
        {
            for (int j = 1; j < i; j++)
            {
                dp[i][s] += dp[j][s - a[i]];
            }
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int sum = total / 2 + 1; sum <= min(total / 2 + a[i], total); sum++)
        {
            res += dp[i][sum];
        }
    }
    cout << res;
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