#include <bits/stdc++.h>
using namespace std;

#define FOR(i, l, r) for (int i = (l); i <= (r); ++i)
#define REP(i, n) FOR(i, 0, (n) - 1)
#define ssize(x) int(x.size())
#ifdef DEBUG
auto &operator<<(auto &o, pair<auto, auto> p) {
    return o << "(" << p.first << ", " << p.second << ")";
}
auto operator<<(auto &o, auto x) -> decltype(x.end(), o) {
    o << "{";
    int i = 0;
    for (auto e : x) o << "," + !i++ << e;
    return o << "}";
}
#define debug(X...) cerr << "[" #X "]: ", [](auto... $) { ((cerr << $ << "; "), ...) << endl; }(X)
#else
#define debug(...) \
    {}
#endif

/*
 * Opis: O(V^2 E) Dinic bez skalowania.
 *   funkcja \texttt{get\_flowing()} zwraca dla każdej oryginalnej krawędzi ile przez nią leci.
 */
struct Dinic {
    using T = int;
    struct Edge {
        int v, u;
        T flow, cap;
    };
    int n;
    vector<vector<int>> graph;
    vector<Edge> edges;
    Dinic(int N) : n(N), graph(n) {}
    void add_edge(int v, int u, T cap) {
        debug(v, u, cap);
        int e = ssize(edges);
        graph[v].emplace_back(e);
        graph[u].emplace_back(e + 1);
        edges.emplace_back(v, u, 0, cap);
        edges.emplace_back(u, v, 0, 0);
    }
    vector<int> dist;
    bool bfs(int source, int sink) {
        dist.assign(n, 0);
        dist[source] = 1;
        deque<int> que = {source};
        while (ssize(que) and dist[sink] == 0) {
            int v = que.front();
            que.pop_front();
            for (int e : graph[v])
                if (edges[e].flow != edges[e].cap and dist[edges[e].u] == 0) {
                    dist[edges[e].u] = dist[v] + 1;
                    que.emplace_back(edges[e].u);
                }
        }
        return dist[sink] != 0;
    }
    vector<int> ended_at;
    T dfs(int v, int sink, T flow = numeric_limits<T>::max()) {
        if (flow == 0 or v == sink)
            return flow;
        for (; ended_at[v] != ssize(graph[v]); ++ended_at[v]) {
            Edge &e = edges[graph[v][ended_at[v]]];
            if (dist[v] + 1 == dist[e.u])
                if (T pushed = dfs(e.u, sink, min(flow, e.cap - e.flow))) {
                    e.flow += pushed;
                    edges[graph[v][ended_at[v]] ^ 1].flow -= pushed;
                    return pushed;
                }
        }
        return 0;
    }
    T operator()(int source, int sink) {
        T answer = 0;
        while (bfs(source, sink)) {
            ended_at.assign(n, 0);
            while (T pushed = dfs(source, sink))
                answer += pushed;
        }
        return answer;
    }
    map<pair<int, int>, T> get_flowing() {
        map<pair<int, int>, T> ret;
        REP(v, n)
        for (int i : graph[v]) {
            if (i % 2)  // considering only original edges
                continue;
            Edge &e = edges[i];
            ret[{v, e.u}] += e.flow;
        }
        return ret;
    }
};

vector<bool> visited;
vector<int> dp;
constexpr int INF = int(1e9);

void dfs(int u, vector<vector<int>> &rev_graph) {
    visited[u] = true;
    dp[u] = 0;

    for (int v : rev_graph[u]) {
        if (!visited[v]) dfs(v, rev_graph);
        dp[u] = max(dp[u], dp[v] + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<long long> a(n);
    REP(i, n)
    cin >> a[i];

    vector<vector<int>> graph(n), rev_graph(n);
    dp = vector<int>(n, 0);
    visited = vector<bool>(n, false);

    REP(i, n)
    FOR(j, i + 1, n - 1) {
        if (a[i] % a[j] == 0 or a[j] % a[i] == 0) {
            graph[i].emplace_back(j);
            rev_graph[j].emplace_back(i);
        }
    }

    visited = vector<bool>(n);
    REP(u, n)
    if (!visited[u])
        dfs(u, rev_graph);

    debug(dp);

    int max_len = 0;
    REP(u, n)
    max_len = max(max_len, dp[u]);

    vector<vector<int>> layers(max_len + 1);
    REP(u, n)
    layers[dp[u]].emplace_back(u);
    debug(layers);

    Dinic dinic(2 * n + 2);
    int source = 2 * n;
    int sink = 2 * n + 1;

    REP(u, n)
    dinic.add_edge(2 * u, 2 * u + 1, 1);

    for (int u : layers[0])
        dinic.add_edge(source, 2 * u, 1);
    for (int u : layers.back())
        dinic.add_edge(2 * u + 1, sink, 1);

    REP(i, max_len) {
        for (int u : layers[i]) {
            for (int v : layers[i + 1]) {
                if (a[u] % a[v] == 0 or a[v] % a[u] == 0)
                    dinic.add_edge(2 * u + 1, 2 * v, 1);
            }
        }
    }

    int answer = dinic(source, sink);
    cout << max_len + 1 << ' ' << answer << '\n';

    if (max_len == 0) {
        REP(u, n)
        cout << u + 1 << '\n';
        return 0;
    }

    auto flowing = dinic.get_flowing();
    debug(flowing);
    vector<int> ptr(n, -1);
    for (auto entry : flowing) {
        auto [u, v] = entry.first;
        int flow = entry.second;
        if (u != source and v != sink and flow == 1) {
            int real_u = u / 2;
            int real_v = v / 2;
            assert(a[real_u] % a[real_v] == 0 or
                   a[real_v] % a[real_u] == 0);
            if (real_u != real_v)
                ptr[real_u] = real_v;
        }
    }

    vector<vector<int>> chains;
    vector<bool> done(n, false);
    REP(u, n)
    if (!done[u] and dp[u] == 0 and ptr[u] != -1) {
        vector<int> chain;
        int current = u;
        while (current != -1) {
            done[current] = true;
            chain.emplace_back(current);
            current = ptr[current];
        }

        chains.emplace_back(chain);
    }

    for (auto chain : chains) {
        for (int u : chain) cout << u + 1 << ' ';
        cout << '\n';
    }
}