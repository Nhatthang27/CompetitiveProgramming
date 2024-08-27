#include <bits/stdc++.h>
#define ll long long
#define fu(i, a, b) for (ll i = a; i <= b; i++)
#define fd(i, a, b) for (ll i = a; i >= b; i--)
using namespace std;
const ll MAX = 65;
const ll X[] = {0, -1, 0, 1};
const ll Y[] = {-1, 0, 1, 0};

char a[MAX][MAX];
ll n;
ll dp[MAX][MAX][MAX][MAX];
ll sx, sy, su, sv;
ll res = -1;

struct Status {
    ll x, y, u, v;
    Status (ll _x, ll _y, ll _u, ll _v) {
        x = _x, y = _y, u = _u, v = _v;
    }
};

void enter() {
    bool hehe = false;
    cin >> n;
    fu(i, 1, n)
    fu(j, 1, n) {
        cin >> a[i][j];
        if (a[i][j] == 'P') {
            if (hehe == false) {
                sx = i;
                sy = j;
                hehe = true;
            } else {
                su = i;
                sv = j;
            }
        }
    }
}

bool isInBoard(ll x, ll y) {
    return (x >= 1 && x <= n && y >= 1 && y <= n);
}

void bfs() {
    dp[sx][sy][su][sv] = 0;
    queue<Status> q;
    q.push(Status(sx, sy, su, sv));
    while(!q.empty()) {
        Status cur = q.front();
        q.pop();
        ll x = cur.x, y = cur.y, u = cur.u, v = cur.v;
        if (x == u && y == v) {
            res = dp[x][y][u][v];
            break;
        }
        fu(i, 0, 3) {

            ll nx = x + X[i];
            ll ny = y + Y[i];

            ll nu = u + X[i];
            ll nv = v + Y[i];

            if (!isInBoard(nx, ny) || a[nx][ny] == '#') {
                nx = x;
                ny = y;
            }
            if (!isInBoard(nu, nv) || a[nu][nv] == '#') {
                nu = u;
                nv = v;
            }
            if (dp[nx][ny][nu][nv] == -1) {
                dp[nx][ny][nu][nv] = dp[x][y][u][v] + 1;
                q.push(Status(nx, ny, nu, nv));
            }
        }
    }

}
void solve() {
    fu(x, 1, n)
    fu(y, 1, n)
    fu(u, 1, n)
    fu(v, 1, n)
    dp[x][y][u][v] = -1;

    bfs();
    cout << res;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("input.inp", "r", stdin);
    enter();
    solve();
}

