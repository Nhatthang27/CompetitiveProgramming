#include <bits/stdc++.h>
#define int long long

using namespace std;

const int O = 1e3 + 5;
const int inf = 1e18;
const int base = 100;

int n, m, X, p[O], row[O][O], col[O][O];
int a[O][O];

int sqr3(int x)
{
    return p[x + base];
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen("input.in", "r"))
    {
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    }

    cin >> n >> m >> X;

    for (int i = -9; i <= 9; ++i)
    {
        p[i + base] = 1;
        for (int j = 1; j <= X; ++j)
            p[i + base] *= i;
        // cout << i << " " << p[i] << endl;
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            char x;
            cin >> x;
            a[i][j] = x - '0';
            row[i][j] = row[i][j - 1];
            col[i][j] = col[i - 1][j];

            if (j > 1)
                row[i][j] += sqr3(a[i][j - 1] - a[i][j]);
            if (i > 1)
                col[i][j] += sqr3(a[i - 1][j] - a[i][j]);
        }
    }

    bool flag = true;
    for (int i = 2; i <= n; ++i)
    {
        for (int j = 2; j <= m; ++j)
        {
            int cur = sqr3(a[i - 1][j - 1] - a[i - 1][j]);
            cur += sqr3(a[i - 1][j] - a[i][j]);
            cur += sqr3(a[i][j] - a[i][j - 1]);
            cur += sqr3(a[i][j - 1] - a[i - 1][j - 1]);

            flag &= (cur == 0);

            // if (cur)
            cout << "vcl " << i << " " << j << " " << cur << endl;
        }
    }

    int q;
    cin >> q;
    for (int i = 1; i <= q; ++i)
    {
        int x, y, u, v;
        cin >> x >> y >> u >> v;

        if (!flag)
        {
            cout << "INVALID\n";
            continue;
        }

        int res = 0;
        if (x < u)
            res += (col[u][y] - col[x][y]);
        if (x > u)
            res -= (col[x][y] - col[u][y]);
        if (y < v)
            res += (row[u][v] - row[u][y]);
        if (y > v)
            res -= (row[u][y] - row[u][v]);

        cout << res << "\n";
    }
}
