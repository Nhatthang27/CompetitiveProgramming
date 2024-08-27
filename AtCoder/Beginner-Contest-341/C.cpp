#include <bits/stdc++.h>
#define ll long long
#define fu(i, a, b) for (ll i = a; i <= b; i++)
#define fd(i, a, b) for (ll i = a; i >= b; i--)
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;
const ll MAX = 600;
const ll X[] = {0, -1, 0, 1};
const ll Y[] = {-1, 0, 1, 0};


char a[MAX][MAX];
ll numRow, numCol;
ll numStep;
char steps[MAX];

void enter() {
    cin >> numRow >> numCol >> numStep;
    fu(i, 1, numStep) cin >> steps[i];
    fu(r, 1, numRow) fu(c, 1, numCol) cin >> a[r][c];
}

bool inBoard(ll x, ll y) {
    return x >= 1 && x <= numRow && y >= 1 && y <= numCol;
}

bool check(ll x, ll y) {
    fu(i, 1, numStep) {
        ll chose;
        if (steps[i] == 'L') chose = 0;
        if (steps[i] == 'U') chose = 1;
        if (steps[i] == 'R') chose = 2;
        if (steps[i] == 'D') chose = 3;
        x = x + X[chose];
        y = y + Y[chose];
        if (!inBoard(x, y) || a[x][y] == '#') return false;
    }
    return true;
}

void solve() {
    ll res = 0;
    fu(x, 1, numRow) {
        fu(y, 1, numCol) {
            if (a[x][y] == '.' && check(x, y)) {
                res++;
            }
        }
    }
    cout << res;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//    freopen("input.inp", "r", stdin);
    enter();
    solve();
//    check(3, 5);
}


