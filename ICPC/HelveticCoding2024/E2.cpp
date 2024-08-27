
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;
const int MOD = 1e9 + 7;

void solve() {
    auto add = [&](int &a, int b) {
        a += b;
        if (a >= MOD) {
            a -= MOD;
        }
    };

    auto mul = [&](int a, int b) {
        return a * b % MOD;
    };

    int n, m;
    cin >> m >> n;
    vector<int> s(m + 1), l(m + 1);
    fu(i, 1, m) {
        cin >> s[i];
    }
    fu(i, 1, m) {
        cin >> l[i];
    }
    vector<int> t(m + 1);
    fu(i, 1, m) {
        t[i] = s[i] + l[i];
    }
    vector<vector<int>> ways(m + 1, vector<int>(m + 1, 0));
    fu(i, 1, m) {
        fu(j, 1, m) {
            ways[i][j] = t[i] * t[j] - l[i] * l[j];
        }
    }

    auto mulMatrix = [&](vector<vector<int>> a, vector<vector<int>> b) {
        vector<vector<int>> c(m + 1, vector<int>(m + 1, 0));
        fu(i, 1, m) {
            fu(j, 1, m) {
                fu(k, 1, m) {
                    add(c[i][j], mul(a[i][k], b[k][j]));
                }
            }
        }
        return c;
    };

    auto expMatrix = [&](vector<vector<int>> a, int b) {
        vector<vector<int>> res(m + 1, vector<int>(m + 1, 0));
        fu(i, 1, m) {
            res[i][i] = 1;
        }
        while (b) {
            if (b & 1) {
                res = mulMatrix(res, a);
            }
            a = mulMatrix(a, a);
            b >>= 1;
        }
        return res;
    };

    ways = expMatrix(ways, n);
    vector<int> base(m + 1, 0), res(m + 1, 0);
    base[1] = 1;
    fu(i, 1, m) {
        fu(j, 1, m) {
            add(res[j], mul(ways[i][j], base[i]));
        }
    }

    int ans = 0;
    fu(i, 1, m) {
        add(ans, res[i]);
    }
    cout << ans << "\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0) {
        solve();
    }
}