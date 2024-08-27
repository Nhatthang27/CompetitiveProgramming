
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
    double rt, rj, st, sj;
    cin >> rt >> rj >> st >> sj;
    if (rt == rj) {
        if (st == sj) {
            cout << "SAME";
        } else if (st < sj) {
            cout << "TAOYUAN";
        } else {
            cout << "JAKARTA";
        }
        return;
    }
    double t = (rt - 1) * sj;
    double j = (rj - 1) * st;
    if (t == j) {
        cout << "SAME";
    } else if (t < j) {
        cout << "TAOYUAN";
    } else {
        cout << "JAKARTA";
    }
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0) {
        solve();
    }
}