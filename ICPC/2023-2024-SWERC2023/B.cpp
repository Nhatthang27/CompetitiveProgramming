
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;
// 2 3
// 2 3
// 4 5 6
// 4 5 7
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>());

    vector<pii> cnt(m + 1, {0, 0});
    fu(i, 1, n) {
        int k;
        cin >> k;
        a[i].resize(k + 1);
        fu(j, 1, k) {
            cin >> a[i][j];
            cnt[a[i][j]].ff++;
            cnt[a[i][j]].ss = a[i][j];
        }
    }
    sort(cnt.begin() + 1, cnt.end(), greater<pii>());
    // for (auto x : cnt) cout << x.ff << " " << x.ss << endl;

    map<int, bool> mp;
    int res = min(n, m);
    fu(i, 1, m) {
        mp[cnt[i].ss] = true;
        int dem = 0;
        fu(j, 1, n) {
            bool ok = true;
            fu(z, 1, a[j].size() - 1) {
                if (!mp[a[j][z]]) {
                    ok = false;
                    break;
                }
            }
            if (!ok) dem++;
        }
        // cout << i << " " << dem << endl;
        res = min(res, i + dem);
    }
    cout << res << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0) {
        solve();
    }
}