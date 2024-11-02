
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
    int bx, by;
    cin >> bx >> by;

    int dis_ab = (bx + by);
    if (dis_ab % 2 != 0) {
        cout << "-1 -1\n";
        return;
    }
    dis_ab /= 2;
    fu(cx, 0, dis_ab) {
        int cy = dis_ab - cx;
        int dis_cb = abs(cx - bx) + abs(cy - by);
        if (dis_cb == dis_ab) {
            cout << cx << " " << cy << "\n";
            return;
        }
    }
    cout << "-1 -1\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}