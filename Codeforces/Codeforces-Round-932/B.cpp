
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
    vector<bool> check(n + 1, 0), checkL(n + 1, 0), checkR(n + 1, 0);
    int mex = 0;
    fu(i, 1, n) {
        cin >> a[i];
        check[a[i]] = true;
    }
    while (check[mex])
        mex++;

    int pos = -1;
    int mex1 = 0;
    // cout << mex << "\n";
    fu(i, 1, n) {
        if (!checkL[a[i]] && a[i] < mex) {
            mex1++;
        }
        if (mex1 == mex) {
            pos = i;
            break;
        }
        checkL[a[i]] = true;
    }

    if (pos == -1) {
        cout << -1 << "\n";
        return;
    }

    int mex2 = 0;
    fu(i, pos + 1, n) {
        if (!checkR[a[i]] && a[i] < mex) {
            mex2++;
        }
        checkR[a[i]] = true;
    }
    if (mex1 == mex2) {
        cout << 2 << "\n";
        cout << 1 << " " << pos << "\n";
        cout << pos + 1 << " " << n << "\n";
    } else {
        cout << -1 << "\n";
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