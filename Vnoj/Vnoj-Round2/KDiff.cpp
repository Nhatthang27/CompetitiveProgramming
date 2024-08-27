
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
    vector<int> a(n + 1);
    fu(i, 1, n) cin >> a[i];

    unordered_map<int, int> cnt;
    for (int l = 1, r = 1; r <= n; r++) {
        cnt[a[r]]++;
        while (cnt.size() == k) {
            cnt[a[l]]--;
            if (cnt[a[l]] == 0) cnt.erase(a[l]);
            l++;
            if (cnt.size() < k) {
                cout << l - 1 << " " << r << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0) {
        solve();
    }
}