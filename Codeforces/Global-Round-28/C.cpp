
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
    int n = s.size();

    pair<int, int> res;
    string maxXor = "";

    int id = -1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            id = i;
            break;
        }
    }
    if (id == -1)
    {
        cout << 1 << " " << n << " " << n << " " << n << "\n";
        return;
    }
    int len = n - id;
    for (int l = 0; l < n - len; l++)
    {
        if (s[l] == '0')
            continue;
        string cur = s.substr(l, len);
        string curXor = s;
        for (int i = 0; i < cur.size(); i++)
        {
            if (cur[i] == curXor[id + i])
                curXor[id + i] = '0';
            else
                curXor[id + i] = '1';
        }
        if (curXor > maxXor)
        {
            maxXor = curXor;
            res = make_pair(l, l + len - 1);
        }
    }

    cout << 1 << " " << s.size() << " " << res.first + 1 << " " << res.second + 1 << "\n";
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