
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

vector<vector<int>> mulitple(vector<vector<int>> &a, vector<vector<int>> &b) {
    vector<vector<int>> res(a.size(), vector<int>(b[0].size(), 0));
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b[0].size(); j++) {
            for (int k = 0; k < a[0].size(); k++) {
                res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return res;
}

vector<vector<int>> exponent(vector<vector<int>> &a, int n) {
    vector<vector<int>> res(a.size(), vector<int>(a.size(), 0));
    for (int i = 0; i < a.size(); i++) {
        res[i][i] = 1;
    }
    while (n > 0) {
        if (n & 1) {
            res = mulitple(res, a);
        }
        a = mulitple(a, a);
        n >>= 1;
    }
    return res;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> base(1, vector<int>(10, 0));
    auto init = [&](int x) {
        while (x > 0) {
            base[0][x % 10]++;
            x /= 10;
        }
    };
    init(n);

    vector<vector<int>> mul(10, vector<int>(10, 0));
    for (int j = 0; j < 10; j++) {
        if (j == 0) {
            mul[9][j] = 1;
            continue;
        }
        mul[j - 1][j] = 1;
        if (j == 1) {
            mul[9][j] = 1;
        }
    }

    mul = exponent(mul, k);
    vector<vector<int>> res = mulitple(base, mul);

    int ans = 0;
    for (int i = 0; i < 10; i++) {
        ans = (ans + res[0][i]) % MOD;
    }
    cout << ans << '\n';
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}