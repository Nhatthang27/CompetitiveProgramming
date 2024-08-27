
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
    fu(i, 1, n) cin >> a[i];
    int one = 0, two = 0;
    fu(i, 1, n) {
        if (a[i] == 1)
            one++;
        else if (a[i] == 2)
            two++;
        else {
            one += a[i] - 2;
            two++;
        }
    }
    cout << one / 2 + two / 2 << '\n';
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}