
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

bool isCorrect(int x) {
    if (x < 10)
        return true;
    if (x / 10 > x % 10) {
        return false;
    }
    return true;
}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<bool> tach(n + 1, false);

    fu(i, 1, n) cin >> a[i];

    fd(i, n - 1, 1) {
        // cout << i << "\n";
        if (tach[i + 1] == false) {
            if (a[i] > a[i + 1]) {
                if (!isCorrect(a[i]) || a[i] % 10 > a[i + 1]) {
                    cout << "NO\n";
                    return;
                }
                tach[i] = true;
            }
        } else {
            int x = a[i + 1] > 9 ? a[i + 1] / 10 : a[i + 1];
            if (a[i] > x) {
                if (!isCorrect(a[i]) || a[i] % 10 > x) {
                    cout << "NO\n";
                    return;
                }
                tach[i] = true;
            }
        }
    }
    cout << "YES\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}