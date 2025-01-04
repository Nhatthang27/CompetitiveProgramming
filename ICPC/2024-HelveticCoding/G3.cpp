#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...)
#endif

const int MN = 300;
using BS = bitset<MN + 1>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) [&]() {
        int N, M, C;
        cin >> N >> M >> C;
        struct Edge {
            int to, id;
        };
        vector<vector<Edge>> adj(N);
        for (int i = 0; i < M; ++i) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            adj[a].push_back({b, i});
            adj[b].push_back({a, i});
        }

        vector<int> sz(N), tin(N), low(N);
        struct Bridge {
            int id, sz1, rt;
        };
        vector<Bridge> bridges;
        int T = 0;
        auto dfs = [&](auto self, int v, int pid, int rt) -> void {
            sz[v] = 1;
            tin[v] = low[v] = ++T;
            for (auto [to, id] : adj[v]) {
                if (id == pid) continue;
                if (sz[to]) {
                    low[v] = min(low[v], tin[to]);
                } else {
                    self(self, to, id, rt);
                    low[v] = min(low[v], low[to]);
                    sz[v] += sz[to];
                    if (low[to] > tin[v]) {
                        bridges.push_back({id, sz[to], rt});
                    }
                }
            }
        };
        int comps = 0;
        multiset<int> szs;
        for (int i = 0; i < N; ++i) {
            if (sz[i]) continue;
            comps++;
            dfs(dfs, i, -1, i);
            szs.insert(sz[i]);
        }

        ll ans = 1e18;
        auto score = [&](const multiset<int> &ms) -> ll {
            BS bs;
            bs[0] = 1;
            for (int x : ms) {
                bs |= bs << x;
            }
            ll ret = 1e18;
            for (int i = 0; i <= N; ++i) {
                if (!bs[i]) continue;
                ret = min(ret, 1LL * i * i + 1LL * (N - i) * (N - i));
            }
            return ret;
        };
        ll base = 1LL * (szs.size() - 1) * C;
        {  // use bridge
            for (auto [id, sz1, rt] : bridges) {
                int sz2 = sz[rt] - sz1;
                szs.erase(szs.find(sz[rt]));
                szs.insert(sz1);
                szs.insert(sz2);
                ans = min(ans, base + score(szs));
                szs.erase(szs.find(sz1));
                szs.erase(szs.find(sz2));
                szs.insert(sz[rt]);
            }
        }
        if (szs.size() > 1) {
            ans = min(ans, base + score(szs));
        }
        if (ans == 1e18)
            cout << -1 << '\n';
        else
            cout << ans << '\n';
    }();
}
