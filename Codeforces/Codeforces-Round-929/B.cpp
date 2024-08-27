
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
    vector<int> a(n + 1);
    ll s = 0;
    ll n1 = 0;
    ll n2 = 0;
    fu(i, 1, n) {
        ll x;
        cin >> x;
        a[i] = x;
        s += x;
        n1 += (x == 1);
        n2 += (x == 2);
    }
    if (s % 3 == 0) {
        cout << 0 << "\n";
    } else if (s % 3 == 1) {
        fu(i, 1, n) {
            if ((s - a[i]) % 3 == 0) {
                cout << 1 << "\n";
                return;
            }
        }
        cout << 2 << "\n";
    } else {
        cout << 1 << "\n";
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