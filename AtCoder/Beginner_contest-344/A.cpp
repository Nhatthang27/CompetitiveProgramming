
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
    cin >> s;

    int l, r;
    fu(i, 0, s.size() - 1) {
        if (s[i] == '|') {
            l = i;
            fu(j, i + 1, s.size() - 1) {
                if (s[j] == '|') {
                    r = j;
                    s.erase(i, j - i + 1);
                    cout << s << endl;
                    return;
                }
            }
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
}