#include <bits/stdc++.h>
#define ll long long
#define fu(i, a, b) for (ll i = a; i <= b; i++)
#define fd(i, a, b) for (ll i = a; i >= b; i--)
using namespace std;
const ll MAX = 2e5 + 7;
const ll INF = 1e18;

ll n;
ll m;
struct SegmentTree {
    vector<ll> sum, lazy;
    ll n;

    SegmentTree(ll _n = 0) {
        n = _n;
        sum.assign(4 * n + 7, 0);
        lazy.assign(4 * n + 7, 0);
    }

    void pushDown(ll i, ll l, ll r) {
        ll m = (l + r) >> 1;

        sum[2 * i] += lazy[i] * (m - l + 1);
        sum[2 * i + 1] += lazy[i] * (r - m);

        lazy[2 * i] += lazy[i];
        lazy[2 * i + 1] += lazy[i];

        lazy[i] = 0;
    }

    void update(ll i, ll l, ll r, ll u, ll v, ll c) {
        if (l > v || r < u || l > r || v < u) return;
        if (u <= l && r <= v) {
            sum[i] += c * (r - l + 1);
            lazy[i] += c;
            return;
        }

        pushDown(i, l, r);
        ll m = (l + r) >> 1;
        update(2 * i, l, m, u, v, c);
        update(2 * i + 1, m + 1, r, u, v, c);

        sum[i] = sum[2 * i] + sum[2 * i + 1];
    }

    ll getSum(ll i, ll l, ll r, ll u, ll v) {
        if (l > v || r < u || l > r || v < u) return 0;
        if (u <= l && r <= v) return sum[i];

        pushDown(i, l, r);
        ll m = (l + r) >> 1;
        ll L = getSum(2 * i, l, m, u, v);
        ll R = getSum(2 * i + 1, m + 1, r, u, v);
        return L + R;
    }

    void update(ll l, ll r, ll c) {
        return update(1, 1, n, l, r, c);
    }
    ll getSum(ll l, ll r) {
        return getSum(1, 1, n, l, r);
    }
};

void solve() {
    cin >> n >> m;
    SegmentTree st(n);
    fu(i, 1, n) {
        ll x;
        cin >> x;
        st.update(i, i, x);
    }
    fu(i, 1, m) {
        ll x;
        cin >> x;
        x++;
        ll val = st.getSum(x, x);
        st.update(x, x, -val);
        if (val <= n - x) {
            st.update(x + 1, x + val, 1);
        } else {
            st.update(x + 1, n, 1);
            val -= n - x;
            st.update(1, n, val / n);
            st.update(1, val % n, 1);
        }

    }
    fu(i, 1, n) {
        cout << st.getSum(i, i) << " ";

    }

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//    freopen("input.inp", "r", stdin);
//    enter();
    solve();
}




