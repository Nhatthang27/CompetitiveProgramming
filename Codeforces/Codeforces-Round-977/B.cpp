
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
    int n, x;
    cin >> n >> x;
    map<int, int> mp, mp2;
    fu(i, 0, n - 1)
    {
        int a;
        cin >> a;
        mp[a]++;
    }
    for (auto i : mp)
    {
        if (i.ss > 1)
        {
            mp2[i.ff] = i.ss;
        }
    }

    int mex = 0;
    while (true)
    {
        if (mp[mex] == 0)
        {
            // cout << mex << "\n";
            for (auto i : mp2)
            {
                if (i.ff > mex)
                {
                    break;
                }
                if ((mex - i.ff) % x == 0)
                {
                    mp[mex]++;
                    mp[i.ff]--;
                    mp2[i.ff]--;
                    if (mp2[i.ff] <= 1)
                    {
                        mp2.erase(i.ff);
                    }
                    break;
                }
            }
            if (mp[mex] == 0)
            {
                break;
            }
            // cout << mex << "\n";
        }
        mex++;
    }
    cout << mex << "\n";
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