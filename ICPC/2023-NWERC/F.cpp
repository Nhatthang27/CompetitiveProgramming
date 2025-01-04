#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;
int a, b, x, y;
map<pair<int, string>, int> a_rm_masks, b_rm_masks;

void solve() {
    string str_a, str_b;
    cin >> a >> b >> x >> y;
    str_a = to_string(a);
    str_b = to_string(b);

    int gcd_xy = __gcd(x, y);
    x /= gcd_xy;
    y /= gcd_xy;

    int gcd_ab = __gcd(a, b);
    if (a / gcd_ab == x && b / gcd_ab == y) {
        cout << "possible\n";
        cout << a << " " << b;
        return;
    }

    int na = (int)str_a.size();
    int nb = (int)str_b.size();

    for (int mask = 0; mask < (1 << na); mask++) {
        int val_a = 0;
        string cur_str_a = "";
        string remain = "";
        for (int i = 0; i < na; i++) {
            if (((mask >> i) & 1)) {
                cur_str_a += str_a[i];
            } else {
                remain += str_a[i];
                val_a = val_a * 10 + str_a[i] - '0';
            }
        }
        // cerr << "here: " << val_a << "\n";
        if (val_a % x == 0 && !cur_str_a.empty() && val_a != 0 && !remain.empty() && remain[0] != '0') {
            sort(cur_str_a.begin(), cur_str_a.end());
            a_rm_masks[{val_a / x, cur_str_a}] = val_a;
            // cerr << "a: " << val_a / x << " " << val_a << "\n";
        }
    }

    for (int mask = 0; mask < (1 << nb); mask++) {
        int val_b = 0;
        string cur_str_b = "";
        string remain = "";

        for (int i = 0; i < nb; i++) {
            if (((mask >> i) & 1)) {
                cur_str_b += str_b[i];
            } else {
                remain += str_b[i];
                val_b = val_b * 10 + str_b[i] - '0';
            }
        }

        // cerr << "here: " << val_b << "\n";

        if (val_b % y == 0 && !cur_str_b.empty() && val_b != 0 && !remain.empty() && remain[0] != '0') {
            sort(cur_str_b.begin(), cur_str_b.end());
            b_rm_masks[{val_b / y, cur_str_b}] = val_b;
            // cerr << "b: " << val_b / y << " " << val_b << "\n";
        }
    }

    for (auto& ele : a_rm_masks) {
        pair<int, string> state_k = ele.first;
        if (b_rm_masks.count(state_k) > 0) {
            int val_a = ele.second;
            int val_b = b_rm_masks[state_k];

            // cerr << "val_a: " << val_a << "\n";
            // cerr << "val_b: " << val_b << "\n";

            cout << "possible\n";
            cout << val_a << " " << val_b;
            return;
        }
    }
    cout << "impossible";
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0) {
        solve();
    }
}