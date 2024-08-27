
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
    int pos = -1;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;
    vector<int> sum1(n + 1, 0), sum0(n + 1, 0);
    double ans = 10000000000000000;
    fu(i, 1, n) {
        if (s[i] == '1')
            sum1[i]++;
        if (s[i] == '0')
            sum0[i]++;
        // sum1[i] = (s[i] == '1');
        // sum0[i] = (s[i] == '0');
        sum1[i] += sum1[i - 1];
        sum0[i] += sum0[i - 1];
    }

    fu(i, 0, n) {
        int u = (sum1[i]);
        int v = (sum0[i]);
        int x = (sum1[n] - sum1[i]);
        int y = (sum0[n] - sum0[i]);
        if ((v >= (i + 1) / 2) && (x >= (n - i + 1) / 2) &&
            (ans > abs((double)n / (double)2 - (double)i))) {
            ans = abs((double)n / (double)2 - (double)i);
            pos = i;
        }
    }
    cout << pos << "\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}