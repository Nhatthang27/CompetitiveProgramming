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
const int MAX = 1e6 + 1;

int myPow(int x, int y) {
    int res = 1;
    while (y) {
        if (y & 1) res = res * x % MOD;
        x = x * x % MOD;
        y >>= 1;
    }
    return res;
}

int frac[MAX], finv[MAX];
void make_inv() {
    frac[0] = 1;
    for (int i = 1; i < MAX; i++) frac[i] = 1LL * frac[i - 1] * i % MOD;
    finv[MAX - 1] = myPow(frac[MAX - 1], MOD - 2);
    for (int i = MAX - 1; i >= 1; i--) finv[i - 1] = 1LL * finv[i] * i % MOD;
}

int nCk(int n, int k) {
    return k > n ? 0 : 1LL * frac[n] * finv[k] % MOD * finv[n - k] % MOD;
}
void solve() {
    int n, k;
    cin >> n >> k;
    vector<char> s(n + 1);
    vector<int> locate;
    int num1 = 0;
    fu(i, 1, n) {
        cin >> s[i];
        num1 += (s[i] == '1');
        if (s[i] == '1') {
            locate.push_back(i);
        }
    }
    if (k == 1) {
        cout << 1 << "\n";
        return;
    }

    if (num1 % k != 0) {
        cout << "0\n";
        return;
    }

    if (num1 == 0) {
        cout << nCk(n - 1, k - 1) << "\n";
        return;
    }

    int res = 1;
    int val = num1 / k;
    for (int i = val; i < (int)locate.size(); i += val) {
        if (i > 0) {
            res *= (locate[i] - locate[i - 1]);
        }
        res %= MOD;
    }
    cout << res << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    make_inv();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}