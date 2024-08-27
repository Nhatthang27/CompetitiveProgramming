
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
    int n, s, day;
    cin >> n >> s >> day;
    vector<pii> tasks(n + 1);
    fu(i, 1, n) cin >> tasks[i].first >> tasks[i].second;
    sort(tasks.begin() + 1, tasks.end());
    int start = 0;
    for (int i = 1; i <= n; i++)
    {
        int len = tasks[i].first - start;
        if (len >= s)
        {
            cout << "YES\n";
            return;
        }
        start = tasks[i].second;
    }
    if (day - start >= s)
    {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
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