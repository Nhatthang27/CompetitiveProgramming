
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
    int n, x;
    cin >> n >> x;
    vector<int> a(n + 1);
    set<int> s;
    fu(i, 1, n) { cin >> a[i]; }

    int l = 1, r = n + 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        s.insert(a[m]);
        if (a[m] <= x) {
            l = m;
        } else {
            r = m;
        }
    }
    if (a[l] == x) {
        cout << "0\n";
        return;
    }

    int p = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] == x)
            p = i;
    }

    if (s.find(x) == s.end()) {
        cout << "1\n";
        cout << p << ' ' << l << '\n';
        return;
    }
    int p1 = 0;
    fu(i, 1, n) {
        if (a[i] < x && s.find(a[i]) == s.end()) {
            p1 = i;
            break;
        }
    }
    if (p1 == 0) {
        cout << "1\n";
        cout << l << ' ' << p << '\n';
    } else {
        cout << "2\n";
        cout << p1 << ' ' << p << '\n';
        cout << l << ' ' << p1 << '\n';
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