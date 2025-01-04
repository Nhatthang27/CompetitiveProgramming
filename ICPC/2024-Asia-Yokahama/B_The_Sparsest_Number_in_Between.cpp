
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int a, b;
    cin >> a >> b;

    int res = 0;
    int ans = -1;
    for (int i = 62; i >= 0; i--)
    {
        if ((a >> i) & 1)
            res |= (1LL << i);
        else
        {
            int tmp = res | (1LL << i);
            if (tmp <= b)
            {
                if (ans == -1)
                {
                    ans = tmp;
                    continue;
                }
                if (__builtin_popcount(tmp) <= __builtin_popcount(ans))
                {
                    ans = tmp;
                }
            }
        }
    }
    cout << ans << "\n";
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