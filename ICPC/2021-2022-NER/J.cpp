
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
    int n, k, x;
    cin >> n >> k >> x;

    int start = x;
    set<int> old;
    old.insert(x);

    while (n-- > 0) {
        int win, lose;
        bool type1, type2;
        cin >> win >> lose >> type1 >> type2;
        set<int> cur;

        for (int x : old) {
            if (x < start - k) {
                if (type1) {
                    cur.insert(x + win);
                } else {
                    cur.insert(x - lose);
                }
            } else if (x > start + k) {
                if (type2) {
                    cur.insert(x + win);
                } else {
                    cur.insert(x - lose);
                }
            } else {
                if (type1) {
                    cur.insert(x + win);
                } else {
                    cur.insert(x - lose);
                }
                if (type2) {
                    cur.insert(x + win);
                } else {
                    cur.insert(x - lose);
                }
            }
        }
        old = cur;
    }
    cout << *max_element(old.begin(), old.end()) << "\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0) {
        solve();
    }
}