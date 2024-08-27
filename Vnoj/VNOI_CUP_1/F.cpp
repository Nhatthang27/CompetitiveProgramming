
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;
int k;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    unordered_map<string, int> mp;
    int res = 0;

    function<void(int, string)> backtrack = [&](int i, string cur) {
        if (i == n) {
            if (cur.empty()) return;
            mp[cur]++;
            // cout << cur << "\n";
            return;
        }

        backtrack(i + 1, cur);

        cur.push_back(s[i]);
        backtrack(i + 1, cur);
        cur.pop_back();
    };
    backtrack(0, "");
    for (auto [key, val] : mp) {
        res += (val == k);
    }
    cout << res << '\n';
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t >> k;
    while (t-- > 0) {
        solve();
    }
}