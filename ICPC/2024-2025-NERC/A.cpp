
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
    vector<int> goal(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> goal[i];
    }

    vector<int> pos(n + 1), cur(n + 1);
    for (int i = 1; i <= n; i++)
    {
        pos[i] = cur[i] = i;
    }

    vector<pair<int, int>> res;
    for (int i = n; i >= 1; i--)
    {
        for (int j = pos[goal[i]]; j > 1; j--)
        {
            int x = cur[j];
            int y = cur[j - 1];
            res.push_back({x, y});
            pos[x]--;
            pos[y]++;
            swap(cur[j], cur[j - 1]);
        }
        for (int j = pos[goal[i]]; j < i; j++)
        {
            int y = cur[j];
            int x = cur[j + 1];
            res.push_back({x, y});
            pos[x]--;
            pos[y]++;
            swap(cur[j + 1], cur[j]);
        }
    }
    cout << (int)res.size() << "\n";
    for (auto [x, y] : res)
    {
        cout << x << " " << y << "\n";
    }
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