
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
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    x /= __gcd(x, y);
    y /= __gcd(x, y);
    int maxArea = a * b;
    int k = sqrt((int)(maxArea / (x * y)));
    cout << maxArea << "\n";
    cout << x * y << "\n";
    int l = 0, r = k;
    int res = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (mid * x <= a && mid * y <= b) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << res * x << " " << res * y << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0) {
        solve();
    }
}