
#include <bits/stdc++.h>
#define ll long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

void solve() {
    ll n;
    cin >> n;
    ll x;
    ll g = -1;
    vector<ll> a(n + 3);

    fu(i, 1, n) {
        cin >> x;
        if (g == -1)
            g = x;
        else
            g = __gcd(g, x);
        a[i] = x;
    }
    sort(a.begin() + 1, a.begin() + n + 1);
    if (a[2] != a[1]) {
        cout << "YES\n";
    } else if (a[1] == a[n]) {
        cout << "NO\n";
    } else if (g == a[1]) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
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