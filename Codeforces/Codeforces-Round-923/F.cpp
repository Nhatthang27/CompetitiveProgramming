#include <bits/stdc++.h>
#define ll long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define ff first
#define ss second
using namespace std;
const int MAX = 2e5 + 7;
const int INF = 1e9 + 7;

struct Edge {
    int u, v, w;
    Edge() {
        u = v = w = -1;
    }
    Edge(int _u, int _v, int _w) {
        u = _u;
        v = _v;
        w = _w;
    }
    bool operator<(const Edge &e) const {
        return w > e.w;
    }
};

struct DisjointSet {
    int numNode;
    vector<int> root, sz;

    DisjointSet() {}

    DisjointSet(int _n) {
        makeSet(_n);
    }

    void makeSet(int _n = 0) {
        numNode = _n;
        root.assign(numNode + 7, 0);
        sz.assign(numNode + 7, 0);
        fu(u, 1, numNode) {
            root[u] = u;
            sz[u] = 1;
        }
    }

    int findRoot(int u) {
        return root[u] = (u == root[u] ? u : findRoot(root[u]));
    }

    int join(int u, int v) {
        u = findRoot(u);
        v = findRoot(v);
        int dir = 0;
        if (u != v) {
            if (sz[u] < sz[v]) {
                dir = 2;
                swap(u, v);
            } else {
                dir = 1;
            }
            root[v] = u;
            sz[u] += sz[v];
            return true;
        }
        return dir;
    }
};

int t;
int numNode, numEdge;
vector<Edge> edges;

void enter() {
    cin >> numNode >> numEdge;
    edges.clear();

    fu(i, 1, numEdge) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
    }
}

vector<int> trace(vector<vector<int>>& adj, int from, int to) {
    vector<int> pre(numNode + 1, -1);
    queue<int> q;
    q.push(from);
    bool flag = false;
    while(!q.empty() && flag == false) {
        int u = q.front();
        q.pop();
        for(int v : adj[u]) {
            if (pre[v] == -1) {
                pre[v] = u;
                if (v == to) {
                    flag = true;
                    break;
                } else {
                    q.push(v);
                }
            }
        }
    }
    vector<int> path;
    while(to != from) {
        path.push_back(to);
        to = pre[to];
    }
    path.push_back(from);
    return path;
}

void solve() {
    DisjointSet dsu(numNode);
    sort(edges.begin(), edges.end());
    vector<Edge> lastE;
    vector<vector<int>> adj(numNode + 7, vector<int>(0));
    for (Edge e : edges) {
        int u = e.u;
        int v = e.v;
        int w = e.w;
        if (dsu.join(u, v)) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        } else {
            lastE.push_back(e);
        }
    }
    sort(lastE.begin(), lastE.end());
    int from = lastE.back().u;
    int to = lastE.back().v;
    cout << lastE.back().w << " ";

    vector<int> path = trace(adj, from, to);

    cout << path.size() << "\n";
    for(int u : path) {
        cout << u << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//    freopen("input.inp", "r", stdin);
    cin >> t;
    while (t-- > 0) {
        enter();
        solve();
    }
}
