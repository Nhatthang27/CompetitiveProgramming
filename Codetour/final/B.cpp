
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
    string op;
    cin >> n;
    int len = (1 << n);
    int result = n;
    int cnt = n;

    vector<int> a(len + 1);
    fu(i, 1, len) cin >> a[i];
    cin >> op;

    fu(i, 0, op.size() - 1)
    {
        if (op[i] == '0')
        {
            result--;
            if (result < cnt)
            {
                fu(u, 1, len / 2)
                {
                    a[u] += a[u + len / 2];
                }
                len >>= 1;
            }
        }
        if (op[i] == '1')
        {
            result++;
        }
        cnt = min(cnt, result);
    }

    string ans = "";
    fu(i, 1, (1 << result) - len) ans += "0 ";
    fu(i, 1, len) ans += to_string(a[i]) + " ";
    cout << ans << "\n";
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