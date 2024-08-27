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
    int n, m, A, B, C;
    cin >> n >> m >> A >> B >> C;
    vector<int> a(n + 1, 0);
    fu(i, 1, n)
    {
        cin >> a[i];
    }

    vector<vector<bool>> mp(n + 1, vector<bool>(n + 1, 0));
    fu(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        u++;
        v++;
        mp[u][v] = mp[v][u] = 1;
    }

    int res = 0;
    fu(i, 1, n - 2)
    {
        fu(j, i + 1, n - 1)
        {
            fu(k, j + 1, n)
            {
                if (!mp[i][j] && !mp[j][k] && !mp[k][i])
                {
                    res += A * a[i] + B * a[j] + C * a[k];
                }
            }
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