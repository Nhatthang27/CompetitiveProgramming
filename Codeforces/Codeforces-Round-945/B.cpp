
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

struct SparseTable {
    const int LOG = 19;
    vector<vector<int>> _or;

    SparseTable(vector<int> a, int n) {
        _or.resize(n + 1, vector<int>(LOG, 0));
        fu(i, 1, n) _or[i][0] = a[i];
        fu(j, 1, LOG - 1) {
            fu(i, 1, n) {
                if (i + (1 << j) - 1 <= n) {
                    _or[i][j] = _or[i][j - 1] | _or[i + (1 << (j - 1))][j - 1];
                }
            }
        }
    }

    int getMask(int n) { return (1 << n); }

    int get(int l, int r) {
        int res = 0;
        fd(j, LOG - 1, 0) {
            if (l + getMask(j) - 1 <= r) {
                res |= _or[l][j];
                l += getMask(j);
            }
        }
        return res;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    fu(i, 1, n) cin >> a[i];
    SparseTable st(a, n);
    function<bool(int)> check = [&](int k) -> bool {
        int base = st.get(1, k);
        fu(i, 2, n - k + 1) {
            int j = i + k - 1;
            if (st.get(i, j) != base) return false;
        }
        return true;
    };

    int l = 1, r = n;
    while (l < r) {
        int m = (l + r) / 2;
        if (check(m))
            r = m;
        else
            l = m + 1;
    }
    cout << l << "\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}