
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
    if (a < b && b < c) {
        cout << "STAIR\n";
    } else if (a < b && b > c) {
        cout << "PEAK\n";
    } else {
        cout << "NONE\n";
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