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
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(n + 1, vector<int>(n + 1, 0));
    fu(i, 1, n) {
        fu(j, i, n) {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> dp(n + 1, vector<int>());
    fu(r, 1, n) {
        priority_queue<array<int, 3>> pq;

        pq.push({(r == 1 ? 0 : dp[r - 1][0]), r - 1, 0});
        fd(l, r, 1) {
            pq.push({(l <= 2 ? 0 : dp[l - 2][0]) + a[l][r], l - 2, 0});
        }

        while (!pq.empty() && dp[r].size() < k) {
            auto [val, l, idx] = pq.top();
            pq.pop();
            dp[r].push_back(val);
            if (l <= 0 || idx + 1 >= dp[l].size()) continue;

            if (l == r - 1) {
                pq.push({dp[l][idx + 1], l, idx + 1});
            } else {
                pq.push({dp[l][idx + 1] + a[l + 2][r], l, idx + 1});
            }
        }
    }
    for (int x : dp[n]) {
        cout << x << ' ';
    }
    cout << "\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}