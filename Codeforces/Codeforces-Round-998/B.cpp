
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> res(n, -1);
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];

            if (a[i][j] < n)
            {
                if (res[a[i][j]] != -1)
                {
                    cout << -1 << endl;
                    return;
                }
                res[a[i][j]] = i;
            }
        }
        sort(a[i].begin(), a[i].end());
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            if (a[i][j] + n != a[i][j + 1])
            {
                cout << -1 << endl;
                return;
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << res[i] + 1 << " ";
    cout << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
}