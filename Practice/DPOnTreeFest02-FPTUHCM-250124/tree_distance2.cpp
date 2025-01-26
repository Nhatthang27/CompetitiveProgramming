#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;
int n;
vector<vector<int>> adj;

void enter()
{
    cin >> n;
    adj.resize(n + 1);
    fu(i, 1, n - 1)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
void solve()
{
    vector<int> down(n + 1, 0);
    vector<int> up(n + 1, 0);
    vector<int> numChild(n + 1, 0);
    vector<int> res(n + 1, 0);
    int sum = 0;
    function<void(int, int)> dfsDown = [&](int u, int p)
    {
        numChild[u] = 1;
        for (int v : adj[u])
        {
            if (v == p)
                continue;
            dfsDown(v, u);
            numChild[u] += numChild[v];
        }
        for (int v : adj[u])
        {
            if (v == p)
                continue;
            sum += n * (n - numChild[v]);
        }
    };

    dfsDown(1, -1);
    cout << sum << "\n";
    fu(i, 1, n) cout << res[i] << " ";
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    enter();
    solve();
}