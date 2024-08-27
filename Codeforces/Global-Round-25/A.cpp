
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
    string s;
    cin >> s;
    s = " " + s;
    bool adj = false;
    int sum = 0;
    fu(i, 1, n) {
        if (s[i] == '1') sum++;
        if (i > 1) {
            if (s[i] == '1' && s[i - 1] == '1') {
                adj = true;
            }
        }
    }
    if (adj && sum == 2) {
        cout << "NO\n";
        return;
    }
    if (sum % 2 == 1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}