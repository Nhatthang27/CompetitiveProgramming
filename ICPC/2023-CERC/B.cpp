
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
    vector<char> gender(n + 1);
    fu(i, 1, n) cin >> gender[i];

    vector<int> boy, girl;
    vector<pii> p(n + 1);
    fu(i, 1, n) cin >> p[i].ff >> p[i].ss;

    auto distance = [&](int u, int v) {
        return (p[u].ff - p[v].ff) * (p[u].ff - p[v].ff) +
               (p[u].ss - p[v].ss) * (p[u].ss - p[v].ss);
    };

    fu(i, 1, n) {
        if (gender[i] == 'B') {
            boy.push_back(i);
        } else {
            girl.push_back(i);
        }
    }

    int nBoy = boy.size();
    int nGirl = girl.size();
    double res = 0;
    fu(i, 0, nBoy / 2 - 1) {
        int j = i + nBoy / 2;
        res += sqrt(distance(boy[i], boy[j]));
    }

    fu(i, 0, nGirl / 2 - 1) {
        int j = i + nGirl / 2;
        res += sqrt(distance(girl[i], girl[j]));
    }
    cout << fixed << setprecision(9) << res << "\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0) {
        solve();
    }
}