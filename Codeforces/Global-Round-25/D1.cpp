
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
    int n, k;
    cin >> n >> k;
    if (n < k) {
        cout << "NO\n";
        return;
    }

    int a, b;
    a = n - k + 1;
    b = 1;
    int sum = n / a;
    n %= a;
    sum += n;
    if (sum == k) {
        cout << "YES\n";
        cout << 2 << "\n";
        cout << a << " " << b << "\n";
    } else {
        cout << "NO\n";
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