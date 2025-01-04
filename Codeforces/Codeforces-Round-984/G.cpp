
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
    map<pair<int, int>, int> mp;

    auto ask = [&](int l, int r) {
        if (mp.count({l, r})) {
            return mp[{l, r}];
        }
        cout << "xor " << l << ' ' << r << '\n';
        cout.flush();
        int res;
        cin >> res;
        mp[{l, r}] = res;
        return res;
    };

    int t = ask(1, n);
    if (t != 0) {
        int l = 1, r = n;
        int first, second, third;
        int p1 = 0, p2 = 0;
        while (l <= r) {
            int m = (l + r) / 2;
            int x = ask(1, m);
            if (x != 0) {
                r = m - 1;
                first = x;
                p1 = m;
            } else {
                l = m + 1;
            }
        }
        l = p1 + 1, r = n;
        while (l <= r) {
            int m = (l + r) / 2;
            int x = ask(1, m);
            if (x != 0 && x != first) {
                r = m - 1;
                second = x ^ first;
            } else {
                l = m + 1;
            }
        }
        third = t ^ first ^ second;
        cout << "ans " << first << ' ' << second << ' ' << third << '\n';
        cout.flush();
        return;
    }

    int start = 1;
    int x = ask(1, start);
    while (!x && start < n) {
        start <<= 1;
        x = ask(1, start);
    }
    int l = 1, r = start, first = 0, p1 = 0;
    while (l <= r) {
        int m = (l + r) / 2;
        int y = ask(1, m);
        if (y != 0) {
            first = y;
            p1 = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    int second = 0;
    if (first != x) {
        second = x;
        int third = first ^ second;
        cout << "ans " << first << ' ' << second << ' ' << third << '\n';
        cout.flush();
    } else {
        l = start, r = n;
        int third = 0;
        while (l <= r) {
            int m = (l + r) / 2;
            int y = ask(1, m);
            if (y == 0) {
                r = m - 1;
            } else {
                second = x ^ y;
                third = y;
                l = m + 1;
            }
        }
        cout << "ans " << first << ' ' << second << ' ' << third << '\n';
        cout.flush();
    }
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}