
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
    if (n < k) {
        cout << "NO\n";
        return;
    }
    vector<int> res;
    while (k > 0 || res.size() > 60) {
        int l = 1, r = n;
        int chose = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            int numJe = n / mid;
            if (numJe > k) {
                l = mid + 1;
            } else if (numJe < k) {
                r = mid - 1;
                chose = mid;
            } else {
                chose = mid;
                break;
            }
        }
        if (chose == -1) {
            cout << "NO\n";
            return;
        }
        res.push_back(chose);
        k -= n / chose;
        n %= chose;
    }
    if (n > 0) {
        res.push_back(n + 1);
    }
    if (res.size() > 60) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    cout << res.size() << "\n";
    for (int x : res) {
        cout << x << " ";
    }
    cout << "\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        // fu(n, 10, 100) {
        //     fd(k, n - 1, 1) {
        //         cout << n << " " << k << "\n";
        //         solve(n, k);
        //         cout << "\n";
        //     }
        // }
        solve();
    }
}