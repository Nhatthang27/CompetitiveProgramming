
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

    int pre_gcd = 0;
    int id = -1;
    fu(i, 1, n - 1) {
        int gcd = __gcd(a[i], a[i + 1]);
        if (gcd < pre_gcd) {
            id = i - 1;
            break;
        }
        pre_gcd = gcd;
    }
    // cout << id << "\n";
    if (id == -1) {
        cout << "YES\n";
        return;
    }

    auto check = [&](vector<int> a) {
        int pre_gcd = 0;
        fu(i, 0, a.size() - 2) {
            int gcd = __gcd(a[i], a[i + 1]);
            if (gcd < pre_gcd) {
                return false;
            }
            pre_gcd = gcd;
        }
        return true;
    };

    // cout << id << "\n";
    vector<int> tmp;
    fu(i, 1, n) {
        if (i == id) continue;
        tmp.push_back(a[i]);
    }
    if (check(tmp)) {
        cout << "YES\n";
        return;
    }
    // fu(i, 1, n) cout << tmp[i] << " ";
    // cout << "\n";
    if (id < n) {
        tmp.clear();
        fu(i, 1, n) {
            if (i == id + 1) continue;
            tmp.push_back(a[i]);
        }
        // fu(i, 1, n) cout << tmp[i] << " ";
        // cout << "\n";
        if (check(tmp)) {
            cout << "YES\n";
            return;
        }
    }
    if (id < n - 1) {
        tmp.clear();
        fu(i, 1, n) {
            if (i == id + 2) continue;
            tmp.push_back(a[i]);
        }
        // fu(i, 1, n) cout << tmp[i] << " ";
        // cout << "\n";
        if (check(tmp)) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}