for (int v : adj[u]) {
            if (v != par) {
                dp[u][1] =
                    max(dp[u][1], sum - max(dp[0][v], dp[1][v]) + dp[0][v] +
                    1);
            }
        }