
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
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(x + 1);
    vector<int> store;

    fu(i, 1, x) cin >> a[i];
    sort(a.begin() + 1, a.end());

    store.push_back(n - a[x] + a[1] + 1);
    fu(i, 2, x) { store.push_back(a[i] - a[i - 1] + 1); }
    sort(store.begin(), store.end());

    int res = x - 2;

    vector<int> odd, even;
    for (int num : store) {
        if (num == 3)
            res++;
        else if (num > 3) {
            if (num % 2 == 0)
                even.push_back(num - 2);
            else
                odd.push_back(num - 2);
        }
    }
    for (int num : odd) {
        if (y >= num / 2) {
            y -= num / 2;
            res += num;
        } else {
            res += 2 * y;
            y = 0;
            break;
        }
    }
    if (y > 0) {
        for (int num : even) {
            if (y >= num / 2) {
                y -= num / 2;
                res += num;
            } else {
                res += 2 * y;
                y = 0;
                break;
            }
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