
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define ff first
#define ss second
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<pii> price(n + 1);
    vector<int> ori(n + 1);
    vector<int> buy(n + 1, 0);
    fu(i, 1, n) {
        int p;
        cin >> p;
        price[i] = {p, i};
        ori[i] = p;
    }

    sort(price.begin(), price.end());
    int turn = k / m + (k % m != 0);

    fu(i, 1, turn) {
        int id = price[i].ss;
        if (i < turn) {
            buy[id] = m;
        } else if (i == turn) {
            if (k % m == 0) {
                buy[id] = m;
            } else {
                buy[id] = k % m;
            }
        }
    }

    int res = 0;
    int total = 0;
    fu(i, 1, n) {
        if (buy[i] > 0) {
            res += buy[i] * (ori[i] + total);
            total += buy[i];
        }
    }
    cout << res << "\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}