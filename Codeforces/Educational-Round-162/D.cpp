#include <bits/stdc++.h>
#define ll long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

struct SparseTable {
    const int LOG = 19;
    vector<vector<int>> mi, ma;

    SparseTable(vector<int> a, int n) {
        mi.resize(n + 1, vector<int>(LOG + 1));
        ma.resize(n + 1, vector<int>(LOG + 1));

        fu(i, 1, n) { mi[i][0] = ma[i][0] = a[i]; }
        fu(j, 1, LOG) {
            fu(i, 1, n - getMask(j) + 1) {
                mi[i][j] = min(mi[i][j - 1], mi[i + getMask(j - 1)][j - 1]);
                ma[i][j] = max(ma[i][j - 1], ma[i + getMask(j - 1)][j - 1]);
            }
        }
        // fu(i, 1, n) { cout << mi[i][0] << "\n"; }
        // fu(i, 1, n) {
        //     fu(j, i, n) {
        //         cout << i << "," << j << " min=" << getMin(i, j) << " "
        //              << " max=" << getMax(i, j) << "\n";
        //     }
        // }
    }

    int getMask(int n) { return (1 << n); }

    int getMin(int l, int r) {
        int k = (int)log2(r - l + 1);
        return min(mi[l][k], mi[r - getMask(k) + 1][k]);
    }

    int getMax(int l, int r) {
        int k = (int)log2(r - l + 1);
        return max(ma[l][k], ma[r - getMask(k) + 1][k]);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    vector<ll> sum(n + 1, 0);

    fu(i, 1, n) { cin >> a[i]; }
    fu(i, 1, n) { sum[i] += sum[i - 1] + a[i]; }
    SparseTable sp = SparseTable(a, n);

    fu(i, 1, n) {

        int res1 = -1;
        if (i - 1 >= 1 && a[i - 1] > a[i])
            res1 = 1;
        else {
            int l = 1, r = i - 1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (sum[i - 1] - sum[mid - 1] <= a[i]) {
                    r = mid - 1;
                } else {
                    if (sp.getMax(mid, i - 1) != sp.getMin(mid, i - 1)) {
                        res1 = i - mid;
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
            }
        }

        int res2 = -1;
        if (i + 1 <= n && a[i + 1] > a[i])
            res2 = 1;
        else {
            int l = i + 1, r = n;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (sum[mid] - sum[i] <= a[i]) {
                    l = mid + 1;
                } else {
                    if (sp.getMax(i + 1, mid) != sp.getMin(i + 1, mid)) {
                        res2 = mid - i;
                        r = mid - 1;
                    } else {
                        l = mid + 1;
                    }
                }
            }
        }

        if (res1 == -1) {
            cout << res2 << " ";
        } else if (res2 == -1) {
            cout << res1 << " ";
        } else {
            cout << min(res1, res2) << " ";
        }
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}