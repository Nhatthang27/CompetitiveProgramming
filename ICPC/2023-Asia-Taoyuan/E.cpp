
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, minDist;
    cin >> n >> minDist;
    int left = LONG_LONG_MAX, right = LONG_LONG_MIN;
    int bottom = LONG_LONG_MAX, top = LONG_LONG_MIN;
    vector<vector<int>> adj(n + 1, vector<int>());

    vector<array<int, 4>> rect(n + 1);
    // bottom left, top right
    for (int i = 1; i <= n; i++)
    {
        cin >> rect[i][0] >> rect[i][1] >> rect[i][2] >> rect[i][3];
        left = min(left, rect[i][0]);
        right = max(right, rect[i][2]);
        bottom = min(bottom, rect[i][1]);
        top = max(top, rect[i][3]);
    }

    vector<vector<int>> dist(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            array<int, 4> a = rect[i];
            array<int, 4> b = rect[j];
            if (i == j || a[0] > b[0])
                continue;
            if (max(a[1], b[1]) < min(a[3], b[3]))
            {
                adj[i].push_back(j);
                // cerr << i << " " << j << "\n";
            }
        }
    }

    // topological sort
    vector<int> inDeg(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j : adj[i])
        {
            inDeg[j]++;
        }
    }

    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        dp[i] = rect[i][2] - rect[i][0];
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (inDeg[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> order;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (int v : adj[u])
        {
            inDeg[v]--;
            if (inDeg[v] == 0)
            {
                q.push(v);
            }
        }
    }

    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        int u = order[i];
        for (int v : adj[u])
        {
            dp[v] = max(dp[v], dp[u] + minDist + rect[v][2] - rect[v][0]);
            maxLen = max(maxLen, dp[v]);
        }
        maxLen = max(maxLen, dp[u]);
    }
    // cerr << left << " " << right << " " << top << " " << bottom << "\n";
    // cout << "last: " << dp[order[n - 1]] << "\n";
    cout << max(0ll, (right - left - maxLen) * (top - bottom)) << "\n";
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