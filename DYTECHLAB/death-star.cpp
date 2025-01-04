
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
    int highestBitPosition = 0;

    // Find the highest bit position
    for (int i = 30; i >= 0; --i) {
        if ((n & (1LL << i))) {
            highestBitPosition = i;
            int x = n * (1LL << (highestBitPosition + 1));
            int y = n + x;

            cout << x << ' ' << y << '\n';
            break;
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