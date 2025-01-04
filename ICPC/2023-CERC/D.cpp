
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
    vector<vector<int>> lun(n + 1, vector<int>(3));
    fu(i, 1, n) cin >> lun[i][0] >> lun[i][1] >> lun[i][2];
    sort(lun.begin() + 1, lun.end(),
         [](vector<int> &a, vector<int> &b) { return a[2] < b[2]; });
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0) {
        solve();
    }
}