
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
    auto ask = [&](int res) {
        cout << res << "\n";
        cout.flush();
        string rep;
        cin >> rep;
        return rep;
    };

    int l = 1, r = 1e6;
    int res = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (ask(mid) == "<") {
            r = mid - 1;
        } else {
            res = mid;
            l = mid + 1;
        }
    }
    cout << "! " << res << "\n";
    cout.flush();
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
}