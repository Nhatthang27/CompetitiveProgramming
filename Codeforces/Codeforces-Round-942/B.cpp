
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
    string s;
    int n;
    cin >> n;
    cin >> s;

    bool alice = false;
    while (!s.empty()) {
        int pos = -1;
        fu(i, 0, s.size() - 1) {
            if (s[i] == 'U') {
                if (pos == -1)
                    pos = i;
                else {
                    int r = (pos + 1) % (int)s.size();
                    int l = (pos - 1 + (int)s.size()) % (int)s.size();
                    if (s[l] == 'U' && s[r] == 'U') {
                        break;
                    }
                }
            }
        }
        if (pos == -1) break;
        int r = (pos + 1) % (int)s.size();
        int l = (pos - 1 + (int)s.size()) % (int)s.size();
        s[l] = (s[l] == 'D' ? 'U' : 'D');
        s[r] = (s[r] == 'D' ? 'U' : 'D');
        s.erase(pos, 1);
        alice ^= true;
    }
    // cout << s << "\n";
    if (alice) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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