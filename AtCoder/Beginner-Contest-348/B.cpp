
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pii> p(n + 1);
    fu(i, 1, n) cin >> p[i].ff >> p[i].ss;

    auto getDist = [&](pii a, pii b) {
        return (a.ff - b.ff) * (a.ff - b.ff) + (a.ss - b.ss) * (a.ss - b.ss);
    };

    fu(i, 1, n) {
        pii res = {0, 0};
        fu(j, 1, n) {
            if (i == j) continue;
            if (getDist(p[i], p[j]) > res.first) {
                res = {getDist(p[i], p[j]), j};
            }
        }
        cout << res.ss << "\n";
    }
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0) {
        solve();
    }
}