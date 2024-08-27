
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
    string s1 = "";
    string s2 = "";
    bool cc = false;
    for (int i = 1; i <= 2 * n; i += 2) {
        if (!cc) {
            s1 += "##";
            s2 += "..";
        } else {
            s1 += "..";
            s2 += "##";
        }
        cc ^= 1;
    }
    fu(i, 1, n) {
        if (i % 2 == 1) {
            cout << s1 << "\n";
            cout << s1 << "\n";
        } else {
            cout << s2 << "\n";
            cout << s2 << "\n";
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