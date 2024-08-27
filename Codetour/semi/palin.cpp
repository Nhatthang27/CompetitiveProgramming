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
                }
            }
        }
    }
    res2 = res1;
    reverse(res2.begin(), res2.end());
    string res = res1 + res2 + res3;
    if (res3.size() == 1)
    {
        res = res1 + res3 + res2;
    }
    if (res3.size() > 1)
    {
        for (int center = 0; center < res3.size(); center++)
        {
            int ff = (center == 0 ? 1 : 0);
            res = min(res, res1 + res3[center] + res2 + res3.substr(0, center) + res3.substr(center + 1));
            res = min(res, res3[ff] + res1 + res3[center] + res2 + res3.substr(ff + 1, center - ff - 1) + res3.substr(center + 1));
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