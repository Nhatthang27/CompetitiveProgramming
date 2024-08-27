
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
    int h = (s[0] - '0') * 10 + s[1] - '0';
    if (h == 0) {
        cout << "12" << s.substr(2) << " " << "AM\n";
        return;
    }
    if (h < 12) {
        cout << s << " " << "AM\n";
    } else {
        if (s[0] == '1' && s[1] == '2') {
            cout << s << " " << "PM\n";
        } else {
            if (h - 12 < 10) {
                cout << "0";
            }
            cout << h - 12 << s.substr(2) << " " << "PM\n";
        }
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