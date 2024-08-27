
#include <bits/stdc++.h>
#define ll long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

ll getSum(ll u, ll len) {
    ll dau = u - (len - 1);
    return (u + dau) * len / 2;
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n + 3);
    vector<ll> sum(n + 3, 0);
    fu(i, 1, n) cin >> a[i];
    fu(i, 1, n) sum[i] += sum[i - 1] + a[i];
    ll q;
    cin >> q;
    while (q-- > 0) {
        ll res;
        ll lef, u;
        cin >> lef >> u;
        res = lef;
        ll l = lef;
        ll r = n;
        ll ma = 0;
        while (l <= r) {
            ll mid = (l + r) / 2;
            ll s1 = sum[mid] - sum[lef - 1];
            ll s2 = sum[mid + 1] - sum[lef - 1];
            s1 = getSum(u, s1);
            s2 = getSum(u, s2);
            if (s1 < s2) {
                l = mid + 1;
            } else {
                res = mid;
                r = mid - 1;
            }
        }
        cout << res << " ";
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