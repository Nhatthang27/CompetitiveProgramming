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
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1, 0);
    fu(i, 1, n) cin >> a[i];

    vector<int> pair(n + 1, 0);
    vector<int> res(n + 1, 0);
    int good = LONG_LONG_MAX;
    function<void(int, int, int)> backtrack = [&](int id, int mi, int ma)
    {
        if (id > n)
        {
            if (ma - mi < good)
            {
                good = ma - mi;
                res = pair;
            }
            return;
        }

        if (pair[id])
        {
            backtrack(id + 1, mi, ma);
            return;
        }
        for (int i = 1; i <= k; i++)
        {
            int pId = id + i;
            if (pId > n)
                continue;
            if (pair[pId])
                continue;
            pair[id] = pId;
            pair[pId] = id;
            backtrack(id + 1, min(mi, a[id] + a[pId]), max(ma, a[pId] + a[id]));
            pair[id] = pair[pId] = 0;
        }
    };
    backtrack(1, LONG_LONG_MAX, LONG_LONG_MIN);
    cout << good << "\n";
    fu(i, 1, n)
    {
        if (res[i] > i)
            cout << i << " " << res[i] << "\n";
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