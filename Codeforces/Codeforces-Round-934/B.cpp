
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
    int n, k;
    cin >> n >> k;
    vector<int> cnt1(n + 7, 0), cnt2(n + 7, 0);
    fu(i, 1, n) {
        int x;
        cin >> x;
        cnt1[x]++;
    }
    fu(i, 1, n) {
        int x;
        cin >> x;
        cnt2[x]++;
    }

    vector<int> res1, res2;
    vector<int> v1, v2;
    fu(x, 1, n) {
        if (cnt1[x] == 2)
            res1.push_back(x);
        if (cnt2[x] == 2)
            res2.push_back(x);
        if (cnt1[x] == 1)
            v1.push_back(x);
        if (cnt2[x] == 1)
            v2.push_back(x);
    }

    fu(i, 1, min(k, (int)res1.size())) {
        cout << res1[i - 1] << " " << res1[i - 1] << " ";
    }
    fu(i, 1, 2 * k - 2 * min(k, (int)res1.size())) { cout << v1[i - 1] << " "; }
    cout << "\n";
    fu(i, 1, min(k, (int)res2.size())) {
        cout << res2[i - 1] << " " << res2[i - 1] << " ";
    }
    fu(i, 1, 2 * k - 2 * min(k, (int)res2.size())) { cout << v2[i - 1] << " "; }
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