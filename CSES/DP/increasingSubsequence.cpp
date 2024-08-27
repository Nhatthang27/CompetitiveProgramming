
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
    vector<int> e;
    fu(i, 1, n) {
        auto it = lower_bound(e.begin(), e.end(), a[i]);
        if (it == e.end())
            e.push_back(a[i]);
        else
            *it = a[i];
    }
    cout << e.size();
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
}