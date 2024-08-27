
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
    unordered_map<int, int> mi;

    int res = 0;
    vector<int> color;
    fu(i, 1, n) {
        int d, c;
        cin >> d >> c;
        color.push_back(c);
        if (mi.find(c) == mi.end()) {
            mi[c] = d;
        } else {
            mi[c] = min(d, mi[c]);
        }
    }
    sort(color.begin(), color.end());
    color.erase(unique(color.begin(), color.end()), color.end());
    fu(i, 0, color.size() - 1) {
        res = max(res, mi[color[i]]);
    }
    cout << res << "\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0) {
        solve();
    }
}