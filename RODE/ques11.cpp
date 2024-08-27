
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
    vector<int> a(n + 1, 0);
    fu(i, 1, n) cin >> a[i];
    vector<int> dp1(n + 1, 0); // k - 1
    vector<int> dp2(n + 1, 0); // k

    fu(i, 1, k - 1) dp1[i] = dp1[i - 1] + a[i];
    fu(i, 1, k) dp2[i] = dp2[i - 1] + a[i];

    dp1[k] 
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}