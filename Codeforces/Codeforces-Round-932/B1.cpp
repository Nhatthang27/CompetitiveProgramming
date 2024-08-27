
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
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    vector<bool> yes(n + 1, false);
    int mex = -1;
    fu(i, 1, n) {
        cin >> a[i];
        yes[a[i]] = true;
    }
    fu(i, 0, n) {
        if (!yes[i]) {
            mex = i;
            break;
        }
    }
    // cout << mex << "\n";
    int res = -1;
    int mex1 = mex;
    vector<int> cnt(n + 1, 0);
    fu(i, 1, n) {
        cnt[a[i]]++;
        if (a[i] < mex && cnt[a[i]] == 1) {
            mex1--;
        }
        if (mex1 == 0) {
            res = i;
            break;
        }
    }
    if (res == -1) {
        cout << -1 << "\n";
        return;
    }
    int mex2 = mex;
    cnt.assign(n + 1, 0);
    fu(i, res + 1, n) {
        cnt[a[i]]++;
        if (a[i] < mex && cnt[a[i]] == 1) {
            mex2--;
        }
        if (mex2 == 0) {
            cout << 2 << "\n";
            cout << 1 << " " << res << "\n";
            cout << res + 1 << " " << n << "\n";
            return;
        }
    }
    cout << -1 << "\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}