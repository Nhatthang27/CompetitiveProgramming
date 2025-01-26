
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> a(2, vector<int>(n + 1));
    vector<pair<int, int>> c(2 * n + 1);
    for (int j = 0; j < 2; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> a[j][i];
            c[a[j][i]] = {j, i};
        }
    }
    int mi_0 = 0, mi_1 = 0;
    for (int i = 1; i <= 2 * n; i++)
    {
        int row = c[i].first;
        int col = c[i].second;

        int new_row = row ^ 1;
        int new_col = i;

        swap(a[row][col], a[new_row][new_col]);
        swap(c[a[row][col]], c[a[new_row][new_col]]);

        swap(a[new_row][col], a[row][new_col]);
        swap(c[a[new_row][col]], c[a[row][new_col]]);
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