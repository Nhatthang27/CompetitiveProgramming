
#include <bits/stdc++.h>
#define int long long
using namespace std;

struct custom_hash
{
    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        x ^= FIXED_RANDOM;
        return x ^ (x >> 16);
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<unordered_map<int, int, custom_hash>> adj(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    vector<int> pattern(n);
    for (int i = 0; i < n; i++)
    {
        cin >> pattern[i];
        pattern[i]--;
    }
    int u_index = 0;
    if (pattern[0] != 0)
    {
        cout << "No" << endl;
        return;
    }
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int u = q.front();
        // cerr << u + 1 << " -> ";
        q.pop();
        int sz = adj[u].size();
        for (int i = 0; i < sz; i++)
        {
            u_index++;
            int v = pattern[u_index];
            // cerr << v + 1 << " ";
            if (adj[u].find(v) == adj[u].end())
            {
                cout << "No" << endl;
                return;
            }
            adj[u].erase(v);
            adj[v].erase(u);
            q.push(v);
        }
        // cerr << endl;
    }
    cout << "Yes" << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // int t;
    // cin >> t;
    // while (t-- > 0)
    solve();
}