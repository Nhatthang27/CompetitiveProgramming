
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
    vector<int> a[3];
    a[1].assign(n + 1, 0);
    a[2].assign(n + 1, 0);
    for (int i = 1; i <= 2; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char c;
            cin >> c;
            a[i][j] = (c == '#');
        }
    }

    bool mul = false;
    bool ok = true;
    for (int i = 1; i <= n; i++)
    {
        if (a[1][i] && a[2][i])
            continue;
        if (a[1][i] == 0 && a[2][i] == 1)
        {
            if (i == n || a[1][i + 1] == 1)
            {
                ok = false;
                break;
            }
            a[1][i] = a[1][i + 1] = 1;
        }
        if (a[1][i] == 1 && a[2][i] == 0)
        {
            if (i == n || a[2][i + 1] == 1)
            {
                ok = false;
                break;
            }
            a[2][i] = a[2][i + 1] = 1;
        }
        if (a[1][i] == 0 && a[2][i] == 0)
        {
            if (i < n && a[1][i + 1] == 0 && a[2][i + 1] == 0)
            {
                mul = true;
                a[1][i] = a[1][i + 1] = a[2][i] = a[2][i + 1] = 1;
            }
        }
    }
    if (ok && !mul)
    {
        cout << "Unique\n";
    }
    else if (!ok)
    {
        cout << "None\n";
    }
    else
    {
        cout << "Multiple\n";
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