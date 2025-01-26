
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    string path;
    cin >> path;
    vector<vector<int>> a(n, vector<int>(m, 0));
    vector<int> row(n, 0), col(m, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            row[i] += a[i][j];
            col[j] += a[i][j];
        }
    }
    int sum = 0;
    if (path[0] == 'R')
    {
        a[0][0] = sum - col[0];
        row[0] += a[0][0];
        col[0] += a[0][0];
    }
    else
    {
        a[0][0] = sum - row[0];
        row[0] += a[0][0];
        col[0] += a[0][0];
    }
    int x = 0, y = 0;
    for (int i = 0; i < path.size() - 1; i++)
    {
        if (path[i] == 'R')
        {
            y++;
            if (path[i + 1] == 'R')
            {
                a[x][y] = sum - col[y];
                row[x] += a[x][y];
                col[y] += a[x][y];
            }
            else
            {
                a[x][y] = sum - row[x];
                row[x] += a[x][y];
                col[y] += a[x][y];
            }
        }
        else
        {
            x++;
            if (path[i + 1] == 'R')
            {
                a[x][y] = sum - col[y];
                row[x] += a[x][y];
                col[y] += a[x][y];
            }
            else
            {
                a[x][y] = sum - row[x];
                row[x] += a[x][y];
                col[y] += a[x][y];
            }
        }
    }
    a[n - 1][m - 1] = sum - row[n - 1];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
}