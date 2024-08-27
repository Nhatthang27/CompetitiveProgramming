
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
    int x;
    cin >> x;
    vector<int> res(32, 0);
    for (int i = 0; i <= 31; i++) {
        res[i] = (x >> i) & 1;
    }
    for (int i = 1; i <= 30; i++) {
        if (res[i] == 2) {
            res[i] = 0;
            res[i + 1]++;
        }
        if (res[i] != 0 && res[i - 1] != 0) {
            res[i] = 0;
            res[i - 1] = -1;
            res[i + 1]++;
        }
    }
    cout << 32 << "\n";
    for (int i = 0; i <= 31; i++) {
        cout << res[i] << " ";
    }
    cout << "\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
