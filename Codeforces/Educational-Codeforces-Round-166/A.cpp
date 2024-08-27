
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

    char num_before = '0';
    char char_before = 'a';
    for (int i = 0; i < n; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            if (i > 0 && (s[i - 1] < '0' || s[i - 1] > '9')) {
                cout << "NO\n";
                return;
            }
            if (s[i] < num_before) {
                cout << "NO\n";
                return;
            }
            num_before = s[i];
        } else {
            if (s[i] < char_before) {
                cout << "NO\n";
                return;
            }
            char_before = s[i];
        }
    }
    cout << "YES\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}