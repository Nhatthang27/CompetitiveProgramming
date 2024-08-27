
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
    int l, r;
    cin >> l >> r;
    auto isPalindrome = [&](int x) {
        string s = to_string(x);
        int n = s.size();
        fu(i, 0, n / 2) {
            if (s[i] != s[n - i - 1])
                return false;
        }
        return true;
    };
    int res = 0;
    fu(i, l, r) {
        if (isPalindrome(i)) {
            res++;
        }
    }
    cout << "\n" << res;
    int
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}