/*
  Code by: linvg
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
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
#include "debug.h"
#endif

const int INF = 0x3f3f3f3f3f;
const int N = 2e5 + 5;

string s[N];

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> cnt(n, vector<int>(2));
    rep(i, 0, n) {
        cin >> s[i];
        for (char c : s[i]) {
            cnt[i][c - '0']++;
        }
    }

    map<int, int> mp;
    mp[1] = -1, mp[0] = -1;
    int res = 0, extra = 0;
    rep(i, 0, n) {
        if (cnt[i][0] == cnt[i][1]) {
            res += cnt[i][0];
            extra += cnt[i][1];
        } else if (cnt[i][0] > cnt[i][1]) {
            res += cnt[i][1];
            if (cnt[i][1] > 0) {
                if (mp[1] == -1)
                    mp[1] = 0;
                mp[1] += cnt[i][1];
            }
        } else {
            res += cnt[i][0];
            if (cnt[i][0] > 0) {
                if (mp[0] == -1)
                    mp[0] = 0;
                mp[0] += cnt[i][0];
            }
            mp[0] += cnt[i][0];
        }
    }
    if (mp.find(1) != mp.end() && mp.find(0) != mp.end()) {
        cout << res << '\n';
        return;
    }
    res = INF;
    if (mp[1]) {
        for (int i = 0; i < n; ++i) {
            int ct1 = mp[1] + extra - cnt[i][1];

            res = min(res, ct1 + cnt[i][0]);
        }
        cout << res << '\n';
    } else {
        for (int i = 0; i < n; ++i) {
            int ct0 = mp[0] + extra - cnt[i][0];

            res = min(res, ct0 + cnt[i][1]);
        }
        cout << res << '\n';
    }
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