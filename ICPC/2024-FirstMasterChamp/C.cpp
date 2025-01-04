/*
  Code by: linvg
*/

#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b)-1; i >= (a); --i)

string to_upper(string a) {
    for (int i = 0; i < (int)a.size(); ++i)
        if (a[i] >= 'a' && a[i] <= 'z')
            a[i] -= 'a' - 'A';
    return a;
}
string to_lower(string a) {
    for (int i = 0; i < (int)a.size(); ++i)
        if (a[i] >= 'A' && a[i] <= 'Z')
            a[i] += 'a' - 'A';
    return a;
}

template <class T> T gcd(T a, T b) {
    T r;
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
template <class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template <class T> T sqr(T x) { return x * x; }
template <class T> T cube(T x) { return x * x * x; }

// #define DBG

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#endif

const int INF = 0x3f3f3f3f3f;
const int MOD = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> phi(m + 1);
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (gcd(i, j) == 1)
                phi[i].push_back(j);
        }
    }

    vector<vector<int>> dp(3, vector<int>(m + 1, 0));
    for (int i = 1; i <= m; ++i)
        dp[1][i] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int k : phi[j]) {
                dp[2][j] = (dp[2][j] + dp[1][k]) % MOD;
            }
        }
        for (int j = 1; j <= m; ++j) {
            dp[1][j] = dp[2][j];
            dp[2][j] = 0;
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; ++i) {
        ans = (ans + dp[1][i]) % MOD;
    }
    cout << ans << '\n';
}

int32_t main() {

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    // int t;
    // cin >> t;
    // while (t--)
    solve();
    return 0;
}