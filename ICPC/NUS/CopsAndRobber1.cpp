#include <bits/stdc++.h>
#define DEBUG
#define d1(x) std::cout << #x " = " << (x) << std::endl
#define d2(x, y) std::cout << #x " = " << (x) << " " #y " = " << (y) << std::endl
#define disp(array, fr, to)                                              \
    {                                                                    \
        std::cout << #array " : ";                                       \
        for (int _i = fr; _i <= to; _i++) std::cout << array[_i] << " "; \
        std::cout << std::endl;                                          \
    }

#define ed end()
#define bg begin()
#define mkp make_pair
#define pb push_back
#define vv(T) v<v(T)>
#define v(T) vector<T>
#define all(x) (x).bg, (x).ed
#define newline puts("")
#define si(x) ((int)x.size())
#define rep(i, n) for (int i = 1; i <= n; ++i)
#define rep0(i, n) for (int i = 0; i < n; ++i)
#define srep(i, s, t) for (int i = s; i <= t; ++i)
#define drep(i, s, t) for (int i = t; i >= s; --i)

using namespace std;
typedef long long ll;
typedef int long long il;
typedef pair<int, int> pii;
const int maxn = 10010;
const int inf = 0x7F7F7F7F;
const ll inf_ll = 1ll * inf * inf;
const int Mod = 1e9 + 7;
const double eps = 1e-7;
int n, m;

int c;
char mp[1000][1000];
ll a[maxn];

int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
int head[maxn], cnt = 0;
struct edge {
    int v, next;
    ll c;
} e[maxn * 2];

void add(int u, int v, ll c) {
    e[cnt].v = v;
    e[cnt].c = c;
    e[cnt].next = head[u];
    head[u] = cnt++;
    e[cnt].v = u;
    e[cnt].c = 0;
    e[cnt].next = head[v];
    head[v] = cnt++;
}

ll ans;
int S, T;
int dis[maxn], cur[maxn];

bool bfs(int s, int t) {
    memset(dis, -1, sizeof(dis));
    dis[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = head[u]; ~i; i = e[i].next) {
            int v = e[i].v;
            ll c = e[i].c;
            if (c && dis[v] == -1) {
                dis[v] = dis[u] + 1;
                q.push(v);
                if (v == t) return true;
            }
        }
    }
    return dis[t] != -1;
}

ll dfs(int u, int t, ll flow) {
    if (u == t) return flow;
    ll delta = flow;
    for (int i = cur[u]; ~i; i = e[i].next) {
        cur[u] = i;
        int v = e[i].v;
        ll c = e[i].c;
        if (c > 0 && dis[v] == dis[u] + 1) {
            ll d = dfs(v, t, min(c, delta));
            if (!d) dis[v] = 0;
            e[i].c -= d;
            e[i ^ 1].c += d;
            delta -= d;
            if (delta == 0) break;
        }
    }
    return flow - delta;
}

ll dinic(int s, int t) {
    ll ans = 0;
    while (bfs(s, t)) {
        memcpy(cur, head, sizeof(cur));
        // d1(ans);
        ans += dfs(s, t, inf);
    }
    return ans;
}

int main() {
    memset(head, -1, sizeof(head));
    cnt = 0;
    scanf("%d%d%d", &m, &n, &c);
    for (int i = 0; i < n; i++) {
        scanf("%s", mp[i]);
    }
    for (int i = 0; i < c; i++) {
        scanf("%d", &a[i]);
    }
    S = 2 * n * m + 100;
    T = S + 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int u = i * m + j;
            if (mp[i][j] == '.' || mp[i][j] == 'B')
                add(u, u + n * m, inf);
            else
                add(u, u + n * m, a[mp[i][j] - 'a']);
            for (int k = 0; k < 4; k++) {
                int tx = i + dir[k][0];
                int ty = j + dir[k][1];
                if (tx >= n || tx < 0 || ty >= m || ty < 0) {
                    add(u + n * m, T, inf);
                } else {
                    add(u + n * m, tx * m + ty, inf);
                }
            }
            if (mp[i][j] == 'B') add(S, u, inf);
        }
    }
    ans = dinic(S, T);
    // d1(ans);
    if (ans >= inf)
        puts("-1");
    else
        printf("%lld\n", ans);
    return 0;
}
