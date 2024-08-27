
#include <bits/stdc++.h>
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n + 1, vector<int>(n + 1, 0));
    fu(i, 1, n) fu(j, 1, n) cin >> a[i][j];

    multiset<int> s;
    vector<vector<bool>> vis(n + 1, vector<bool>(n + 1, false));
    auto inBoard = [&](int x, int y)
    {
        return x >= 1 && x <= n && y >= 1 && y <= n;
    };

    function<void(int, int, int, bool &kq)> isGood = [&](int x, int y, int mex, bool &kq)
    {
        if (kq)
        {
            return;
        }
        if (x == n && y == n)
        {
            kq = true;
            return;
        }
        vis[x][y] = true;
        fu(i, 0, 3)
        {
            int u = x + dx[i];
            int v = y + dy[i];
            if (inBoard(u, v) && !vis[u][v] && a[u][v] != mex)
            {
                isGood(u, v, mex, kq);
            }
        }
        vis[x][y] = false;
    };

    fu(res, 1, n * n + 1)
    {
        vis.assign(n + 1, vector<bool>(n + 1, false));
        if (a[1][1] == res || a[n][n] == res)
            continue;
        bool kq = false;
        isGood(1, 1, res, kq);
        if (kq)
        {
            cout << res << "\n";
            return;
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