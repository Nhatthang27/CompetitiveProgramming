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
    vector<tuple<int, int, int>> a(n + 1);
    vector<int> value;
    fu(i, 1, n) {
        int x, y, z;
        cin >> x >> y >> z;
        a[i] = {x, y, z};
    }

    sort(a.begin() + 1, a.end(),
         [](tuple<int, int, int> &a, tuple<int, int, int> &b) {
             return get<1>(a) < get<1>(b);
         });
    map<int, int> dp;
    dp[0] = 0;
    int res = 0;
    fu(i, 1, n) {
        int l = get<0>(a[i]);
        int r = get<1>(a[i]);
        int c = get<2>(a[i]);
        auto it = dp.lower_bound(l);
        it--;
        int reward = it->second + c;
        res = max(res, reward);
        dp[r] = res;
    }
    cout << res;
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
}