
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

int dem = 0;
void solve() {
    dem++;
    int n, skill;
    cin >> n >> skill;
    pii res = {skill, skill};
    vector<int> a(n + 1, 0);

    fu(i, 1, n - 1) {
        cin >> a[i];
        res.ff = max(res.ff, a[i]);
        res.ss = min(res.ss, a[i]);
    }

    vector<int> team;
    fu(i, 2, sqrt(n)) {
        if (n % i == 0) {
            team.push_back(i);
            if (i * i != n) {
                team.push_back(n / i);
            }
        }
    }

    auto compare = [&](pii a, pii b) { return (a.ff * b.ss > b.ff * a.ss); };

    fu(i, 1, n) {
        // cout << "pos: " << i << "\n";
        for (int len : team) {
            int ma = LONG_LONG_MIN;
            int mi = LONG_LONG_MAX;

            // cout << "len=" << len << "\n";
            fu(l, 1, len) {
                int sum = 0;
                for (int r = l; r <= n; r += len) {
                    if (r < i)
                        sum += a[r];
                    else if (r == i)
                        sum += skill;
                    else
                        sum += a[r - 1];
                }
                ma = max(ma, sum);
                mi = min(mi, sum);
            }
            if (compare(res, {ma, mi}))
                res = {ma, mi};
        }
    }
    int g = __gcd(res.ff, res.ss);
    res.ff /= g;
    res.ss /= g;
    cout << res.ff << " " << res.ss << "\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}