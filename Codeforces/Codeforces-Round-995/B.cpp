
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
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    int sum = a + b + c;
    if (n % sum == 0)
    {
        cout << (n / sum) * 3 << "\n";
    }
    else
    {
        int path = n / sum * sum;
        int ans = (n / sum) * 3;
        if (path + a >= n)
        {
            cout << ans + 1 << "\n";
        }
        else if (path + a + b >= n)
        {
            cout << ans + 2 << "\n";
        }
        else
        {
            cout << ans + 3 << "\n";
        }
    }
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