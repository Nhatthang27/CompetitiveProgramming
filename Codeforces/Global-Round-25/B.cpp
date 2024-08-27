
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
    vector<int> p(n + 1);
    fu(i, 1, n) {
        cin >> p[i];
    }

    int idx = -1;
    fu(i, 1, k - 1) {
        if (p[i] > p[k]) {
            idx = i;
            break;
        }
    }

    vector<int> p1(n + 1), p2(n + 1);
    fu(i, 1, n) {
        p1[i] = p2[i] = p[i];
    }

    int res = 0;
    if (idx != -1) {
        swap(p1[idx], p1[k]);
        int point = (idx == 1 ? 0 : 1);
        fu(i, idx + 1, n) {
            if (p1[i] > p1[idx]) {
                break;
            }
            point++;
        }
        res = max(res, point);
    }
    int point = 0;
    swap(p2[1], p2[k]);
    fu(i, 2, n) {
        if (p2[i] > p2[1]) {
            break;
        }
        point++;
    }
    res = max(res, point);
    cout << res << '\n';
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}