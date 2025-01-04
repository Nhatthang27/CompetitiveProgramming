
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
    vector<int> a(n + 1);
    vector<int> deg(n + 1, 0), val(n + 1, 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i], deg[a[i]]++;

    vector<int> cut;

    for (int i = 1; i <= n; i++)
    {
        if (deg[i] == 0)
            cut.push_back(i);
    }
    if (cut.empty())
    {
        cout << 2 << "\n";
        return;
    }
    int year = 1;
    while (!cut.empty())
    {
        vector<int> newCut;
        for (int id : cut)
        {
            deg[a[id]]--;
            val[a[id]] += val[id];
            if (deg[a[id]] <= 0)
            {
                newCut.push_back(a[id]);
                year = max(year, val[a[id]]);
            }
            val[id] = 0;
        }
        cut = newCut;
    }
    cout << year + 2 << "\n";
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