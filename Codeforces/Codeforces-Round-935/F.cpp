
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set                                                            \
    tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,         \
         tree_order_statistics_node_update>

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
    vector<int> v(n + 1), p(n + 1);
    fu(i, 1, n) { cin >> v[i]; }
    fu(i, 1, n) { cin >> p[i]; }
    ordered_set s;
    fu(i, 1, n) s.insert({v[i], i});

    int res = *max_element(v.begin(), v.end());
    int num = 1;

    fu(k, 2, n) {
        s.erase(s.find({v[p[k - 1]], p[k - 1]}));
        s.insert({0, p[k - 1]});
        pair<int, int> it = *s.find_by_order(n - k);
        int ans = it.first * k;
        if (ans > res) {
            res = ans;
            num = k;
        }
    }
    cout << res << " " << num << "\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}