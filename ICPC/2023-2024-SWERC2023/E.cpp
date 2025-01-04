
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

void handle(int n, vector<int> h, set<int> s, unordered_map<int, int> mp, pii &res) {
    fu(i, 1, n - 1) {
        if (h[i] > h[i + 1]) {
            // delete all the height less than h[i]
            while (!s.empty() && *s.begin() < h[i]) s.erase(s.begin());
            s.insert(h[i]);
            continue;
        }
        auto it = s.lower_bound(h[i + 1]);
        if (it != s.begin()) {
            --it;
            if (*it >= h[i]) {
                int preHeight = *it;
                int preId = mp[preHeight];

                int tu = preHeight - h[i];
                int mau = h[i + 1] - h[i];
                int c = i - preId;

                tu = c * mau + tu;
                int gcd = __gcd(tu, mau);
                tu /= gcd;
                mau /= gcd;

                // maximize
                if (res.ss * tu > res.ff * mau) {
                    res = {tu, mau};
                }
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> h(n + 1);
    set<int> s;
    unordered_map<int, int> mp;
    fu(i, 1, n) cin >> h[i], mp[h[i]] = i;

    pii res = {0, 1};

    handle(n, h, s, mp, res);

    reverse(h.begin() + 1, h.end());
    mp.clear();
    fu(i, 1, n) mp[h[i]] = i;
    s.clear();

    handle(n, h, s, mp, res);

    if (res.ss == 1)
        cout << res.ff << endl;
    else
        cout << res.ff << "/" << res.ss << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0) {
        solve();
    }
}