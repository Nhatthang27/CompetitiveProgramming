#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

int getSum(int a, int b, int c, int d) {
    vector<int> z;
    z.push_back(a);
    z.push_back(b);
    z.push_back(c);
    z.push_back(d);
    int res = 0;
    sort(z.begin(), z.end());
    do {
        res = max(res, abs(z[0] - z[1]) + abs(z[1] - z[2]) + abs(z[2] - z[3]) +
                           abs(z[3] - z[0]));
    } while (next_permutation(z.begin(), z.end()));
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    sort(a.begin(), a.end(), greater<int>());
    cout << abs(a[0] - a[n - 1]) + abs(a[n - 1] - a[1]) + abs(a[1] - a[n - 2]) +
                abs(a[n - 2] - a[0])
         << '\n';
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
    // getSum(1, 2, 3, 4);
}