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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> list(m + 1);
    vector<bool> kw(n + 1, false);
    int no = -1;

    fu(i, 1, m)
    {
        cin >> list[i];
    }
    fu(i, 1, k)
    {
        int x;
        cin >> x;
        kw[x] = true;
    }

    fu(i, 1, n)
    {
        if (!kw[i])
        {
            no = i;
            break;
        }
    }

    if (k < n - 1)
    {
        for (int i = 1; i <= m; i++)
            cout << 0;
        cout << "\n";
        return;
    }

    if (no == -1)
    {
        for (int i = 1; i <= m; i++)
            cout << 1;
        cout << "\n";
        return;
    }

    for (int i = 1; i <= m; i++)
    {
        if (list[i] == no)
            cout << 1;
        else
            cout << 0;
    }
    cout << "\n";
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