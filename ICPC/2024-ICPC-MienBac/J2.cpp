#include <bits/stdc++.h>
using namespace std;

struct EdmondsKarp
{
    int n, src, sink;
    vector<vector<int>> adj;
    vector<vector<int>> cap;
    vector<int> parent;

    EdmondsKarp(int _n, int _src, int _sink) : n(_n), src(_src), sink(_sink)
    {
        adj.assign(n + 1, vector<int>());
        cap.assign(n + 1, vector<int>(n + 1, 0));
    }

    void add_edge(int u, int v, int w)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
        cap[u][v] += w;
    }

    int bfs()
    {
        fill(parent.begin(), parent.end(), -1);
        queue<pair<int, int>> q;
        q.push({src, INT_MAX});
        parent[src] = -2;

        while (!q.empty())
        {
            int u = q.front().first;
            int flow = q.front().second;
            q.pop();

            for (int v : adj[u])
            {
                if (parent[v] == -1 && cap[u][v] > 0)
                {
                    parent[v] = u;
                    int new_flow = min(flow, cap[u][v]);
                    if (v == sink)
                        return new_flow;
                    q.push({v, new_flow});
                }
            }
        }
        return 0;
    }

    int max_flow()
    {
        int flow = 0, new_flow;
        parent.resize(n + 1);

        while (new_flow = bfs())
        {
            flow += new_flow;
            int cur = sink;
            while (cur != src)
            {
                int prev = parent[cur];
                cap[prev][cur] -= new_flow;
                cap[cur][prev] += new_flow;
                cur = prev;
            }
        }
        return flow;
    }
};

int main()
{
    int n = 7; // Số đỉnh từ 1 đến 7
    int src = 6, sink = 7;
    EdmondsKarp graph(n, src, sink);

    // Thêm các cạnh với dung lượng 1
    graph.add_edge(6, 1, 1);
    graph.add_edge(2, 7, 1);
    graph.add_edge(6, 4, 1);
    graph.add_edge(5, 7, 1);
    graph.add_edge(1, 3, 1);
    graph.add_edge(1, 4, 1);
    graph.add_edge(3, 2, 1);
    graph.add_edge(5, 2, 1);
    graph.add_edge(4, 3, 1);
    graph.add_edge(3, 5, 1);

    int maxFlow = graph.max_flow();
    cout << "Max Flow từ 6 đến 7: " << maxFlow << endl;

    return 0;
}
