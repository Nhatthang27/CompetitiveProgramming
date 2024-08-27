
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
    int n, m;
    cin >> n >> m;
    map<char, int> mp;
    fu(i, 1, n) {
        char c;
        cin >> c;
        mp[c]++;
    }
    int res = 0;
    vector<char> cha({'A', 'B', 'C', 'D', 'E', 'F', 'G'});
    for (char c : cha) {
        if (mp[c] < m) {
            res += m - mp[c];
        }
    }
    cout << res << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}