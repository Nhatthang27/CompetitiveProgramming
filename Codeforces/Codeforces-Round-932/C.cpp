
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

int dem;

void solve() {
    dem++;
    int n, limit;
    cin >> n >> limit;
    vector<pii> c(n + 1);
    fu(i, 1, n) { cin >> c[i].ff >> c[i].ss; }
    sort(c.begin() + 1, c.end(), [](pii a, pii b) { return a.ss < b.ss; });

    int res = 0;
    fu(l, 1, n) {
        int sum = 0;
        priority_queue<int> q;
        fu(r, l, n) {
            int cost = c[r].ss - c[l].ss;
            sum += c[r].ff;
            q.push(c[r].ff);
            while (!q.empty() && sum + cost > limit) {
                sum -= q.top();
                q.pop();
            }
            res = max(res, (int)q.size());
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