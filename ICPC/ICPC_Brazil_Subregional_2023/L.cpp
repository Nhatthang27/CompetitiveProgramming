
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
    string s;
    cin >> s;
    int n = s.size();
    int k;
    cin >> k;

    vector<multiset<char>> ms(k);
    fu(i, 0, n - 1) {
        ms[i % k].insert(s[i]);
    }
    string res = "";
    fu(i, 0, n - 1) {
        res += *ms[i % k].begin();
        ms[i % k].erase(ms[i % k].begin());
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