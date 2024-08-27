
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;
const int MAX = 70;
const int MOD = 1e9 + 7;
const int NUM_PRIME = 19;
const vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};
void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), cnt(MAX + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    vector<vector<int>> f(MAX + 1, vector<int>(2, 0));
    for (int i = 1; i <= MAX; i++) {
        if (cnt[i] == 0) {
            f[i][0] = 1;
            f[i][1] = 0;
        } else {
            f[i][0] = f[i][1] = (1LL << (cnt[i] - 1));
        }
    }

    auto getMask = [&](int x) {
        int mask = 0;
        for (int i = 0; i < NUM_PRIME; i++) {
            if (x < primes[i]) {
                break;
            }
            while (x % primes[i] == 0) {
                mask ^= (1LL << i);
                x /= primes[i];
            }
        }
        return mask;
    };
    vector<vector<int>> dp(MAX + 1, vector<int>(1LL << NUM_PRIME, 0));
    dp[0][0] = 1;
    for (int i = 0; i < MAX; i++) {
        int next_mask = getMask(i + 1);
        for (int mask = 0; mask < (1LL << NUM_PRIME); mask++) {
            if (dp[i][mask] == 0) {
                continue;
            }
            dp[i + 1][next_mask] += dp[i][mask] * f[i + 1][0];
            dp[i + 1][mask] %= MOD;

            dp[i + 1][next_mask ^ mask] += dp[i][mask] * f[i + 1][1];
            dp[i + 1][next_mask ^ mask] %= MOD;
        }
    }
    cout << dp[MAX][0] << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0) {
        solve();
    }
}