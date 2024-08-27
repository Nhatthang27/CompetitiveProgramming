
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
    string s;
    cin >> s;

    vector<int> cnt(26, 0);
    for (char c : s)
    {
        cnt[c - 'a']++;
    }

    string res1 = "", res2 = "", res3 = "";
    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] % 2 == 0)
        {
            for (int j = 0; j < cnt[i] / 2; j++)
            {
                res1 += (char)('a' + i);
                res2 = (char)('a' + i) + res2;
            }
        }
        else
        {
            res3 += (char)('a' + i);
            if (cnt[i] > 1)
            {
                for (int j = 0; j < cnt[i] / 2; j++)
                {
                    res1 += (char)('a' + i);
                    res2 = (char)('a' + i) + res2;
                }
            }
        }
    }

    string res = res1 + res2 + res3;
    if (res3.size() == 1)
    {
        res = res1 + res3 + res2;
    }
    if (res3.size() == 2)
    {
        res = min(res, res3[0] + res1 + res3.substr(1, 1) + res2);
    }
    if (res3.size() > 2)
    {
        res = min(res, res3[0] + res1 + res3.substr(1, 1) + res2 + res3.substr(2));
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