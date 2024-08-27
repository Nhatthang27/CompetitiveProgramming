#include <bits/stdc++.h>
#define ll long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define ff first
#define ss second
using namespace std;

void solve() {
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n + 1, 0);
    fu(i, 1, n) cin >> a[i];
    vector<ll> s(n + 1, 0);
    fu(i, 1, n) {
        s[i] += s[i - 1];
        if (a[i] != 1) {
            s[i] += a[i];
        }
    }
    while (q-- > 0) {
        ll l, r;
        cin >> l >> r;
        if (l != r) {
            if (s[r] - s[l - 1] < (r - l + 1)) {
                cout << "NO\n";
            } else {
                cout << "YES\n";
            }
        } else {
            cout << "NO\n";
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}