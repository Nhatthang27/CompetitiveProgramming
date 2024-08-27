#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

long long maximumValueSum(vector<int> &nums, int k,
                          vector<vector<int>> &edges) {
    int n = nums.size();
    vector<vector<int>> adj(n);
    vector<vector<long long>> dp(n, vector<int>(2, 0));

    for (auto &e : edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    function<void(int, int)> dfs = [&](int u, int p) {
        bool isLeaf = true;
        long long cnt = 0, sum = 0, dif = 0, minDif = LONG_LONG_MAX;

        for (int v : adj[u]) {
            if (v == p)
                continue;
            isLeaf = false;
            dfs(v, u);
            sum += dp[v][0];
            if (dp[v][1] > dp[u][0]) {
                cnt++;
                dif += dp[v][1] - dp[v][0];
                minDif = min(minDif, dif);
            }
        }
        if (isLeaf) {
            dp[u][0] = nums[u];
            dp[u][1] = nums[u] ^ k;
        } else {
            // if (cnt % 2 == 0) {
            //     dp[u][0] = sum + dif + nums[u];
            //     dp[u][1] = sum + dif - minDif + nums[u] ^ k;
            // } else {
            //     dp[u][0] = sum + dif - minDif + nums[u];
            //     dp[u][1] = sum + dif + nums[u] ^ k;
            // }

            dp[u][0] = sum + dif + nums[u] - (cnt % 2 == 0 ? 0 : minDif);
            dp[u][1] = sum + dif + nums[u] ^ k - (cnt % 2 == 0 ? minDif : 0);
        }
    };
    dfs(0, -1);
    return max(dp[0][0], dp[0][1]);
}
