
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
    int n, q;
    cin >> n >> q;
    vector<int> xorSum(n + 1);
    map<int, vector<int>> pos;
    fu(i, 1, n) {
        int x;
        cin >> x;
        xorSum[i] = xorSum[i - 1] ^ x;
        pos[xorSum[i]].push_back(i);
    }

    while (q-- > 0) {
        int l, r;
        cin >> l >> r;
        int xor_lr = xorSum[r] ^ xorSum[l - 1];
        if (xor_lr == 0) {
            cout << "YES\n";
        } else {
            auto it = lower_bound(pos[xorSum[r]].begin(), pos[xorSum[r]].end(), l);
            if (*it < r) {
                int l1 = *it + 1;
                // cout << l1 << "\n";
                int need = xorSum[l1 - 1] ^ xor_lr;
                it = lower_bound(pos[need].begin(), pos[need].end(), l1);
                // cout << *it << "\n";
                if (it != pos[need].end() && *it < r) {
                    cout << "YES\n";
                } else {
                    cout << "NO\n";
                }
            } else {
                cout << "NO\n";
            }
        }
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