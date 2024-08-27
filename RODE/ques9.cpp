
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
    int res = 0;
    int n = s.size();
    bool dg = false, up = false, low = false;
    int curSz = n;
    int cnt3 = 0;
    fu(i, 0, n - 1)
    {
        int cc = 1;
        while (i + 1 <= n - 1 && s[i + 1] == s[i])
        {
            cc++;
            i++;
        }
        // cout << i << " " << cc << "\n";
        if (cc == 3)
            cnt3++;
    }
    fu(i, 0, n - 1)
    {
        char c = s[i];
        if ('0' <= c && c <= '9')
            dg = true;
        if ('A' <= c && c <= 'Z')
            up = true;
        if ('a' <= c && c <= 'z')
            low = true;
    }
    if (n < 6)
    {
        if (!dg)
        {
            res++;
            if (curSz < 6)
                curSz++;
        }
        if (!low)
        {
            res++;
            if (curSz < 6)
                curSz++;
        }
        if (!up)
        {
            res++;
            if (curSz < 6)
                curSz++;
        }
        if (curSz < 6)
        {
            res += 6 - curSz;
        }
    }
    else if (n > 20)
    {
        res += n - 20;
        if (!dg)
            res++;
        if (!up)
            res++;
        if (!low)
            res++;
        cout << res;
        return;
    }
    else
    {
        if (!dg)
            res++;
        if (!up)
            res++;
        if (!low)
            res++;
    }
    cout << max(res, cnt3);
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