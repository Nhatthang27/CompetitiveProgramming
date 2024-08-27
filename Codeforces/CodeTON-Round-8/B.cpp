
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
    vector<int> a(n + 1);
    vector<bool> vst(n + 1, false);
    vector<int> res(n + 1);

    fu(i, 1, n) cin >> a[i];

    int mex;
    if (a[1] == 1) {
        res[1] = 0;
        mex = 1;
    } else {
        res[1] = -a[1];
        mex = 0;
    }
    vst[res[1]] = true;

    fu(i, 2, n) {
        while (mex - a[i] < 0 || vst[mex - a[i]])
            mex++;
        res[i] = mex - a[i];
        vst[res[i]] = true;
    }
    fu(i, 1, n) cout << res[i] << " ";
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