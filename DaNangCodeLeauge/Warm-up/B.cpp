
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
    fu(i, 0, s.size() - 1) {
        if (s[i] == 'F') {
            continue;
        } else if (s[i] == 'D') {
            if (i == 0) {
                cout << "No\n";
                return;
            }
            if ((i > 0 && s[i - 1] != 'F') && (i > 1 && s[i - 2] != 'F')) {
                cout << "No\n";
                return;
            }
        } else {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}