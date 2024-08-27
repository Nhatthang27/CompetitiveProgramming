
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;
#define MAX 1000100
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> prime({2, 3, 5, 7});
    fu(i, 1, n) cin >> a[i];

    struct Element {
        int mask, rest;
    };
    vector<Element> ele(n + 1);
    fu(i, 1, n) {
        int x = a[i];
        for (int j = 0; j < prime.size(); j++) {
            int cnt = 0;
            while (x % prime[j] == 0) {
                x /= prime[j];
                cnt++;
            }
            if (cnt & 1) {
                ele[i].mask |= (1LL << j);
            }
        }
        ele[i].rest = x;
    }

    map<int, vector<int>> vec;
    for (int i = 1; i <= n; i++) {
        vec[ele[i].rest].push_back(ele[i].mask);
    }

    vector<vector<int>> res(n + 1, vector<int>(1 << 4, 0));
    res[0][0] = 1;
    int id = 1;
    for (auto [rest, maskVec] : vec) {
        int sz = maskVec.size();
        vector<vector<vector<int>>> dp(sz + 1, vector<vector<int>>(1 << 4, vector<int>(2, 0)));
        dp[0][0][0] = 1;
        for (int i = 1; i <= sz; i++) {
            for (int mask = 0; mask < (1 << 4); mask++) {
                for (int odd = 0; odd < 2; odd++) {
                    dp[i][mask][odd] += dp[i - 1][mask][odd];
                    dp[i][mask][odd] += dp[i - 1][mask ^ maskVec[i - 1]][odd ^ 1];
                    dp[i][mask][odd] %= MOD;
                }
            }
        }
        for (int mask1 = 0; mask1 < (1 << 4); mask1++) {
            for (int mask2 = 0; mask2 < (1 << 4); mask2++) {
                if (rest == 1) {
                    res[id][mask1] += res[id - 1][mask1 ^ mask2] * (dp[sz][mask2][1] + dp[sz][mask2][0]);
                } else {
                    res[id][mask1] += res[id - 1][mask1 ^ mask2] * dp[sz][mask2][0];
                }
                res[id][mask1] %= MOD;
            }
        }
        id++;
    }
    // fu(i, 1, id) {
    //     cout << i << " " << res[i][0] << endl;
    // }
    cout << (res[id - 1][0] - 1 + MOD) % MOD << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0) {
        solve();
    }
}