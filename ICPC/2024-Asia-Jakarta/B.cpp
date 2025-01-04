
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

void solve()
{
    int n, d, s;
    cin >> n >> d >> s;

    n /= s;
    d /= s;

    // cout << d << " " << n << "\n";

    int mul = 1;
    if (d == 0)
    {
        mul = 1;
    }
    else if (n >= 2 * d)
    {
        mul = 2 * d;
    }
    else if (n <= d + 1)
    {
        mul = n;
    }
    else
    {
        for (int x = 2; x <= MAX; x++)
        {
            int g = min(n / x, d / (x - 1));
            mul = max(mul, x * g);
        }
    }

    cout << s * mul;
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