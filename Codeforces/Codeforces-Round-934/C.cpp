
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
    vector<int> cnt(n + 1, 0);
    fu(i, 1, n) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    int dem = 0;
    int mex = -1;
    vector<int> a;
    fu(i, 0, n) {
        if (cnt[i] == 1) {
            a.push_back(i);
        }
        if (cnt[i] == 0 && mex == -1) {
            mex = i;
        }
    }
    if (mex == -1) {
        mex = n + 1;
    }

    if (a.size() > 1) {
        cout << min(mex, a[1]) << "\n";
    } else {
        cout << mex << "\n";
    }
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}