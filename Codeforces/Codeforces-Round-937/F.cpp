
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
    int a, b, c;
    cin >> a >> b >> c;
    int sum = a + b + c;
    if (c == 0) {
        cout << -1 << "\n";
        return;
    }
    if (c - 1 == a) {
        int node = a + c - 1;
        int leaf = (a + 1) / 2;
        leaf -=
    } else {
        cout << -1 << "\n";
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