
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
    int n, k;
    cin >> n >> k;
    if (k == 1 || k > n)
    {
        cout << n << "\n";
        return;
    }
    int res = 0;
    while (n > 0)
    {
        if (n < k)
        {
            res += n;
            break;
        }
        int mul = 1;
        while (mul <= n)
        {
            mul *= k;
        }
        mul /= k;
        res++;
        n -= mul;
    }
    cout << res << endl;
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