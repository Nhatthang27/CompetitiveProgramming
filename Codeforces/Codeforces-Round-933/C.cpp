
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

string u = "map";
string v = "pie";

void solve() {
    int n;
    string s;
    cin >> n >> s;
    s = " " + s;
    vector<int> a;
    int res = 0;
    fu(i, 1, n) {
        if (s[i] == 'p')
            a.push_back(i);
    }
    fu(i, 0, (int)a.size() - 1) {
        int pos = a[i];
        if ((pos < n - 1 && s[pos + 1] == v[1] && s[pos + 2] == v[2]) ||
            (pos > 2 && s[pos - 2] == u[0] && s[pos - 1] == u[1])) {
            res++;
        }
    }
    cout << res << "\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}