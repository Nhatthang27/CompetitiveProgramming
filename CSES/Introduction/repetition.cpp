
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    string s;
    int res = 0;
    cin >> s;

    int cnt = 1;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == s[i - 1])
        {
            cnt++;
        }
        else
        {
            res = max(res, cnt);
            cnt = 1;
        }
    }
    res = max(res, cnt);
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