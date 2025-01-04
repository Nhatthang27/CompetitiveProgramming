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
    int n;
    cin >> n;
    vector<int> a(n + 1);
    fu(i, 1, n) cin >> a[i];
    vector<int> dp((1LL << n) + 1, 0);
    vector<int> gcd((1LL << n) + 1, 0);

    for (int mask = 1; mask < (1LL << n); mask++) {
        vector<int> pos;
        fu(i, 0, n - 1) {
            if ((mask >> i) & 1) {
                pos.push_back(n - i);
            }
        }

        if (pos.size() == 1) {
            gcd[mask] = a[pos[0]];
        } else {
            gcd[mask] = __gcd(a[pos[0]], a[pos[1]]);
            fu(i, 2, pos.size() - 1) {
                gcd[mask] = __gcd(gcd[mask], a[pos[i]]);
            }
        }
    }

    // map<pair<int, int>, bool> mp;

    // function<int(int, int)> solve = [&](int parent, int mask) -> int {
    //     mp[{parent, mask}] = true;
    //     if (mask == 0) return 0;
    //     if (dp[mask] != 0) return dp[mask];

    //     vector<int> pos;
    //     fu(i, 0, n - 1) {
    //         if ((mask >> i) & 1) {
    //             pos.push_back(n - i);
    //         }
    //     }
    //     if (pos.size() == 1) {
    //         return dp[mask] = a[pos[0]];
    //     }

    //     for (int submask = mask; submask > 0; submask = (submask - 1) & mask) {
    //         if (submask == mask) continue;
    //         cerr << submask << ' ' << mask << ' ' << gcd[submask] << '\n';

    //         if (mp[{mask, submask}] || mp[{mask, mask ^ submask}]) continue;

    //         dp[mask] += gcd[submask];
    //         dp[mask] += solve(mask, mask ^ submask);
    //     }
    //     return dp[mask];
    // };

    map<int, int> mp;
    int mask = (1LL << n) - 1;
    int res = 0;

    for (int submask = mask; submask > 0; submask = (submask - 1) & mask) {
        if (!mp[submask]) res += gcd[submask];
        mp[submask] = 1;
        if (!mp[mask ^ submask]) res += gcd[mask ^ submask];
        mp[mask ^ submask] = 1;
    }
    cout << res << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0) {
        solve();
    }
}
