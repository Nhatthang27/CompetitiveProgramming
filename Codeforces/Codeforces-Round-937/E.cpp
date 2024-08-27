
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
    vector<char> s(n + 1);
    fu(i, 1, n) cin >> s[i];
    fu(k, 1, n) {
        if (n % k != 0)
            continue;
        int cnt = 0;
        fu(i, 1, k) {
            for (int j = i + k; j <= n; j += k) {
                if (s[j] != s[i]) {
                    cnt++;
                    if (cnt > 1) {
                        break;
                    }
                }
            }
        }
        if (cnt <= 1) {
            cout << k << "\n";
            return;
        }

        cnt = 0;
        fu(j, 1, k) {
            if (s[j] != s[j + k]) {
                cnt++;
                if (cnt > 1) {
                    break;
                }
            }
        }
        if (cnt > 1) {
            continue;
        }
        fu(i, k + 1, 2 * k) {
            for (int j = i + k; j <= n; j += k) {
                if (s[j] != s[i]) {
                    cnt++;
                    if (cnt > 1) {
                        break;
                    }
                }
            }
        }
        if (cnt <= 1) {
            cout << k << "\n";
            return;
        }
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