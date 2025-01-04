
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;
const int MAX = 1e5;
const int MOD = 1e9 + 7;

int frac[MAX], finv[MAX];

int pw(int x, int k) {
    int res = 1, mul = x;
    while (k > 0) {
        if (k & 1) {
            res = res * mul % MOD;
        }
        k >>= 1;
        mul = mul * mul % MOD;
    }
    return res;
}

void prepare() {
    frac[0] = 1;
    for (int i = 1; i < MAX; i++) frac[i] = 1LL * frac[i - 1] * i % MOD;
    finv[MAX - 1] = pw(frac[MAX - 1], MOD - 2);
    for (int i = MAX - 1; i >= 1; i--)
        finv[i - 1] = finv[i] * i % MOD;
    // frac[0] = 1;
    // for (int i = 1; i < MAX; i++) frac[i] = 1LL * frac[i - 1] * i % MOD;
    // finv[MAX - 1] = pw(frac[MAX - 1], MOD - 2);
    // for (int i = MAX - 1; i >= 1; i--) finv[i - 1] = 1LL * finv[i] * i % MOD;
}

int comb(int k, int n) {
    return k > n ? 0 : 1LL * frac[n] * finv[k] % MOD * finv[n - k] % MOD;
}

void solve() {
    int k, n;
    cin >> k >> n;
    cout << comb(k, n) << '\n';
    cout << pw(k, n);
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    prepare();
    int t;
    t = 1;
    while (t-- > 0) {
        solve();
    }
}