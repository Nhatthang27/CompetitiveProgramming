
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
    int limit;
    cin >> limit;

    vector<int> res;
    map<int, bool> mp;
    function<void(vector<int>&, int)> backtrack = [&](vector<int>& cur, int id) {
        if (id > limit) {
            if (cur.size() > res.size()) {
                res = cur;
            }
            return;
        }
        if (cur.size() > res.size()) {
            res = cur;
        }
        fu(val, id, limit) {
            if (mp[val]) continue;
            int sum_and = val;
            bool ok = true;
            for (int x : cur) {
                sum_and &= x;
                if (mp[sum_and]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                mp[val] = true;
                sum_and = val;
                for (int x : cur) {
                    sum_and &= x;
                    mp[sum_and] = true;
                }
                cur.push_back(val);
                backtrack(cur, val + 1);
                cur.pop_back();

                mp[val] = false;
                sum_and = val;
                for (int x : cur) {
                    sum_and &= x;
                    mp[sum_and] = false;
                }
            }
        }
    };
    vector<int> cur;
    backtrack(cur, 1);
    cout << res.size() << '\n';
    for (int x : res) {
        cout << x << ' ';
    }
    cout << '\n';
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}