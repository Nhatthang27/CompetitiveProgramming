
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;

    ordered_set s;
    fu(i, 1, n) {
        int x;
        cin >> x;
        s.insert({x, i});
    }

    vector<int> res;
    int id = 0;
    while (q-- > 0) {
        ++id;
        int x;
        cin >> x;
        s.insert({x, n + id});
        res.push_back(s.order_of_key({x, n + id}) + 1);
    }
    for (int x : res) cout << x << '\n';
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
}