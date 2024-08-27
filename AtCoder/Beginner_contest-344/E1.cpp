
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

    map<int, int> lef;
    map<int, int> rig;
    fu(i, 1, n) {
        if (i == n)
            rig[a[i]] = -1;
        else
            rig[a[i]] = a[i + 1];
    }

    fd(i, n, 1) {
        if (i == 1) {
            lef[a[i]] = -1;
        } else
            lef[a[i]] = a[i - 1];
    }

    int head = a[1];

    int q;
    cin >> q;
    while (q-- > 0) {
        int t, x, y;
        cin >> t;
        if (t == 1) {
            cin >> x >> y;
            int next = rig[x];
            rig[x] = y;

            lef[y] = x;
            rig[y] = next;

            if (next != -1)
                lef[next] = y;
        } else {
            cin >> x;
            int next = rig[x];
            int prev = lef[x];

            if (prev != -1) {
                rig[prev] = next;
            }

            if (next != -1) {
                lef[next] = prev;
            }

            if (x == head) {
                head = next;
            }
        }
    }
    while (head != -1) {
        cout << head << " ";
        head = rig[head];
    }
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
}