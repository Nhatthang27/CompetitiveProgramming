#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>
#define fi first
#define se second
#define loop_up(i, a, b) for (ll i = a; i <= b; ++i)
#define loop_down(i, a, b) for (ll i = b; i >= a; --i)
#define fastio                                                                 \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(0);                                                                \
    cout.tie(0);
#define IOFile(in, out)                                                        \
    freopen(in, "r", stdin);                                                   \
    freopen(out, "w", stdout);
using namespace std;
const ll maxN = 2e5 + 0307;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n + 1), b(n + 1), cnt1(n + 1, 0), cnt2(n + 1, 0);
    loop_up(i, 1, n) cin >> a[i];
    loop_up(i, 1, n) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll dem1 = 0;
    vector<ll> save1, save2, ans1, ans2;
    for (ll x : a)
        cnt1[x]++;
    for (ll x : b)
        cnt2[x]++;
    loop_up(x, 1, n) {
        if (cnt1[x] == 2) {
            ans1.push_back(x);
        }
        if (cnt1[x] == 1) {
            save1.push_back(x);
        }
        if (cnt2[x] == 1) {
            save2.push_back(x);
        }
        if (cnt2[x] == 2) {
            ans2.push_back(x);
        }
    }

    for (ll i = 1; i <= min((ll)ans1.size(), k); i++) {
        cout << ans1[i - 1] << " " << ans1[i - 1] << " ";
    }
    for (ll i = 1; i <= 2 * k - 2 * min((ll)ans1.size(), k); i++) {
        cout << save1[i - 1] << " ";
    }
    cout << "\n";
    for (ll i = 1; i <= min((ll)ans2.size(), k); i++) {
        cout << ans2[i - 1] << " " << ans2[i - 1] << " ";
    }
    for (ll i = 1; i <= 2 * k - 2 * min((ll)ans2.size(), k); i++) {
        cout << save2[i - 1] << " ";
    }
    cout << "\n";
}
int main() {
    //    IOFile("test.inp","test.out");
    fastio ll numTest = 1;
    cin >> numTest;
    while (numTest--) {
        solve();
    }
}