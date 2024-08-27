
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

bool check(int x) {
    string s = to_string(x);
    int l = 0, r = s.size() - 1;
    while (l < r) {
        if (s[l] != s[r]) {
            return false;
        }
        l++;
        r--;
    }
    return true;
}
void solve() {
    int n;
    cin >> n;
    int res = -1;

    int root = 1;
    while (root * root * root <= n) {
        if (check(root * root * root)) {
            res = root * root * root;
        }
        root++;
    }
    cout << res;
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
}