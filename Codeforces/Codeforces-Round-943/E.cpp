
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

    int len = n / 2 + (n % 2 == 1);
    for (int i = 1; i <= len; i++) {
        cout << 1 << " " << i << "\n";
    }
    cout << n << " " << n << "\n";
    for (int i = len; i <= n - 2; i++) {
        cout << n << " " << n - i << "\n";
    }
    cout << "\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}