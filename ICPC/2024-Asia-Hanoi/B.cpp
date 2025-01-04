#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k, m;
    cin >> n >> k >> m;

    vector<vector<int>> dis(n + 1, vector<int>(n + 1, INT_MAX));
    for (int u = 1; u <= n; u++)
    {
        for (int v = u + 1; v <= n; v++)
        {
            int d;
            cin >> d;
            dis[u][v] = dis[v][u] = d;
        }
    }

    vector<pair<int, int>> imp;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        imp.push_back({u, v});
    }
    vector<vector<int>> dp(1 << n, vector<int>(n + 1, INT_MAX));
    vector<vector<int>> pre(1 << n, vector<int>(n + 1, -1));
    for (int i = 0; i <= n - 1; i++)
    {
        dp[1 << i][i] = 0;
    }

    for (int mask = 1; mask < (1 << n); mask++)
    {
        for (int u = 0; u <= n - 1; u++)
        {
            if (!((mask >> u) & 1))
                continue;

            for (int v = 0; v <= n - 1; v++)
            {
                if ((mask >> v) & 1)
                    continue;

                if (dp[mask | (1 << v)][v] > dp[mask][u] + dis[u + 1][v + 1])
                {
                    dp[mask | (1 << v)][v] = dp[mask][u] + dis[u + 1][v + 1];
                    pre[mask | (1 << v)][v] = u;
                }
            }
        }
    }

    // imp_mask -> cost node_mask end
    vector<array<int, 3>> tmp(1 << m, {INT_MAX, -1, -1});

    for (int node_mask = 1; node_mask < (1 << n); node_mask++)
    {
        int num_1 = (__builtin_popcount(node_mask));
        if (num_1 > k || num_1 < 2)
            continue;

        int imp_mask = 0;
        for (int i = 0; i < m; i++)
        {
            auto [u, v] = imp[i];
            if ((node_mask >> (u - 1)) & 1 && (node_mask >> (v - 1)) & 1)
            {
                imp_mask |= (1 << i);
            }
        }
        for (int end = 0; end < n; end++)
        {
            if (dp[node_mask][end] < tmp[imp_mask][0])
            {
                tmp[imp_mask] = {dp[node_mask][end], node_mask, end};
            }
        }
    }

    // cost imp_mask node_mask end
    vector<array<int, 4>> route;
    for (int imp_mask = 1; imp_mask < (1 << m); imp_mask++)
    {
        if (tmp[imp_mask][0] == INT_MAX)
            continue;
        route.push_back({tmp[imp_mask][0], imp_mask, tmp[imp_mask][1], tmp[imp_mask][2]});
        // cerr << "imp_mask: ";
        // for (int i = 0; i < m; i++)
        //     cerr << ((imp_mask >> i) & 1);
        // cerr << "\n";
        // cerr << "node_imp_mask: ";
        // for (int i = 0; i < n; i++)
        // {
        //     cerr << ((tmp[imp_mask][1] >> i) & 1);
        // }
        // cerr << "\n";
        // cerr << "cost: " << tmp[imp_mask][0] << "\n\n";
    }

    vector<int> dp_route(1 << m, INT_MAX);
    // pre_route, add_route
    vector<pair<int, int>> last_route(1 << m);
    dp_route[0] = 0;
    for (int mask = 0; mask < (1 << m); mask++)
    {
        if (dp_route[mask] == INT_MAX)
            continue;
        for (auto [cost, imp_mask, node_mask, end] : route)
        {
            int newMask = (mask | imp_mask);
            if (dp_route[newMask] > dp_route[mask] + cost)
            {
                dp_route[newMask] = dp_route[mask] + cost;
                last_route[newMask] = {mask, imp_mask};
            }
        }
    }
    vector<vector<int>> res;
    int total = dp_route[(1 << m) - 1];

    int cur_mask = (1 << m) - 1;
    while (cur_mask != 0)
    {
        int pre_mask = last_route[cur_mask].first;
        int add_mask = last_route[cur_mask].second;
        auto [cost, node_mask, end] = tmp[add_mask];
        vector<int> path;
        int last_node = end;
        while (last_node != -1)
        {
            path.push_back(last_node + 1);
            int temp = last_node;
            last_node = pre[node_mask][last_node];
            node_mask ^= (1 << temp);
        }
        res.push_back(path);
        cur_mask = pre_mask;
    }
    cout << total << " " << res.size() << "\n";
    for (auto path : res)
    {
        cout << path.size() << " ";
        for (int u : path)
            cout << u << " ";
        cout << "\n";
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