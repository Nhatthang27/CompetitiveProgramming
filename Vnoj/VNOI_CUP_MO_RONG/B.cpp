
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
    int n, q;
    cin >> n >> q;
    vector<vector<int>> a(4, vector<int>());
    fu(i, 1, 3)
    {
        int nz = 0;
        cin >> nz;
        fu(j, 1, nz)
        {
            int x;
            cin >> x;
            a[i].push_back(x);
        }
        reverse(a[i].begin(), a[i].end());
    }

    while (q-- > 0)
    {
        vector<bool> color(n + 1, false);
        vector<vector<int>> block = a;
        int x, y, z;
        cin >> x >> y >> z;
        while (x-- > 0)
        {
            color[block[1].back()] = !color[block[1].back()];
            block[1].pop_back();
        }

        while (y-- > 0)
        {
            color[block[2].back()] = !color[block[2].back()];
            block[2].pop_back();
        }

        while (z-- > 0)
        {
            color[block[3].back()] = !color[block[3].back()];
            block[3].pop_back();
        }

        bool ok = true;
        fu(i, 1, n)
        {
            if (color[i] == true)
            {
                ok = false;
                break;
            }
        }
        if (ok == false)
        {
            cout << "Lihwy\n";
            continue;
        }
        if (block[1].size() == 0 && block[2].size() == 0 && block[3].size() == 0)
        {
            cout << "MofK\n";
            continue;
        }
        ok = false;
        fu(i, 1, 2)
        {
            if (block[i].size() == 0)
                continue;
            fu(j, i + 1, 3)
            {
                if (block[j].size() == 0)
                    continue;
                if (block[i].back() == block[j].back())
                {
                    ok = true;
                    break;
                }
            }
        }
        if (ok == true)
        {
            cout << "MofK\n";
        }
        else
        {
            cout << "Lihwy\n";
        }
    }
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