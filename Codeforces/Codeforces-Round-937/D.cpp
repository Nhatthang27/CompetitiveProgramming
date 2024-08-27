
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pint pair<int, int>
#define ff first
#define ss second
using namespace std;
const int MAX = 1e5 + 5;
vector<int> g[MAX];

void sieve() {
    for (int i = 2; i * i < MAX; ++i) {
        for (int j = i; j * i < MAX; ++j) {
            g[i * j].push_back(i);
            if (i != j)
                g[i * j].push_back(j);
        }
    }
}
void solve() {
    int x;
    cin >> x;

    auto check = [&](int x) {
        while (x > 0) {
            if (x % 10 != 1 && x % 10 != 0) {
                return false;
            }
            x /= 10;
        }
        return true;
    };

    while (x > 1) {
        if (check(x)) {
            cout << "YES\n";
            return;
        }
        int d = -1;
        for (int u : g[x]) {
            if (check(u)) {
                d = u;
                break;
            }
        }
        if (d == -1 && !check(x)) {
            cout << "NO\n";
            return;
        } else {
            x /= d;
        }
    }
    cout << "YES\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    sieve();
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}