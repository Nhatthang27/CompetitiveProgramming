
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
    cin >> n;
    vector<string> a(n + 1);
    fu(i, 0, n - 1) cin >> a[i];

    map<int, pair<int, char>> mp;
    fu(i, 0, n - 1)
    {
        string s = a[i].substr(0, a[i].size() - 1);
        int x = stoi(s);
        mp[i].ff = x;
        mp[i].ss = a[i][a[i].size() - 1];
    }

    vector<int> path;
    int res = LONG_LONG_MIN;
    int choose = 1;

    fu(i, 0, n - 1)
    {
        vector<bool> vst(n + 1, 0);
        vector<int> cur_path;
        int u = i;
        int point = 0;
        while (!vst[u])
        {
            cur_path.push_back(u);
            vst[u] = 1;
            int x = mp[u].ff;
            char c = mp[u].ss;

            if (c == '+')
            {
                point += x;
            }
            else if (c == '-')
            {
                point -= x;
            }
            else if (c == '*')
            {
                point *= x;
            }
            else
            {
                point /= x;
            }
            u = x;
        }
        if (point > res)
        {
            res = point;
            path = cur_path;
            choose = i;
        }
        else if (point == res && cur_path.size() < path.size())
        {
            path = cur_path;
            choose = i;
        }
    }
    cout << choose << "\n";
    cout << res << "\n";
    for (auto x : path)
    {
        cout << x;
        if (x != path.back())
            cout << "->";
    }
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