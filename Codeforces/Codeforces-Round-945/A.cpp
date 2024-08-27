
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
    int a, b, c;
    cin >> a >> b >> c;
    priority_queue<int> pq;
    if (a != 0) pq.push(a);
    if (b != 0) pq.push(b);
    if (c != 0) pq.push(c);
    int res = 0;
    while (pq.size() > 1) {
        int c = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        c--;
        b--;
        if (c >= 0 && b >= 0) res++;
        if (b > 0) pq.push(b);
        if (c > 0) pq.push(c);
    }
    while (!pq.empty()) {
        int x = pq.top();
        pq.pop();
        if (x % 2 != 0) {
            cout << -1 << "\n";
            return;
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