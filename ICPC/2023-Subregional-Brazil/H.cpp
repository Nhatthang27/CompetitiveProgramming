
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

struct cmp {
    bool operator()(pii a, pii b) {
        return a.ff < b.ff;
    }
};
void solve() {
    int n, sal;
    cin >> n >> sal;
    vector<array<int, 3>> a(n);
    fu(i, 0, n - 1) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    sort(a.begin(), a.end(), [&](array<int, 3> x, array<int, 3> y) {
        return x[2] < y[2];
    });

    set<pii> vec;
    int res = 0;
    fu(i, 0, n - 1) {
        pii cur = {a[i][0], a[i][1]};
        auto aft = lower_bound(vec.begin(), vec.end(), cur, cmp());
        int l2 = (*aft).ff;
        int r2 = (*aft).ss;
        if (aft != vec.end()) {
            if (l2 <= cur.ss) {
                if (aft != vec.begin()) {
                    aft--;
                    int l1 = (*aft).ff;
                    int r1 = (*aft).ss;
                    if (r1 >= cur.ff) {
                        int add = max((int)0, l2 - r1) * sal;
                        if (add > a[i][2]) {
                            res += add - a[i][2];
                            vec.erase(aft);
                            vec.insert({l1, r2});
                        }

                    } else {
                        int add = (l2 - cur.ff) * sal;
                        if (add > a[i][2]) {
                            res += add - a[i][2];
                            vec.erase(aft);
                            vec.insert({cur.ff, r2});
                        }
                    }
                } else {
                    int add = (l2 - cur.ff) * sal;
                    if (add > a[i][2]) {
                        res += add - a[i][2];
                        vec.erase(aft);
                        vec.insert({cur.ff, r2});
                    }
                }
            } else {
            }
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0) {
        solve();
    }
}