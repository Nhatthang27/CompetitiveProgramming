
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

    map<int, int> mp;
    fu(i, 1, k) {
        int b, c;
        cin >> b >> c;
        mp[b] += c;
    }

    // get sum of k largest value
    vector<int> a;
    for (auto x : mp) a.push_back(x.ss);
    sort(a.begin(), a.end(), greater<int>());
    // for (int x : a) cout << x << " ";

    int sum = 0;
    fu(i, 0, n - 1) {
        if (i >= a.size()) break;
        sum += a[i];
    }
    cout << sum << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}