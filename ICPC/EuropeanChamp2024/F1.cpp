
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
    int n, m;
    cin >> n >> m;
    vector<pair<set<int>, int>> s(n + 1);
    fu(i, 1, n) {
        int k;
        cin >> k;
        s[i].ss = i;
        fu(j, 1, k) {
            int x;
            cin >> x;
            s[i].ff.insert(x);
        }
    }

    sort(s.begin() + 1, s.end(),
         [](pair<set<int>, int> a, pair<set<int>, int> b) {
             return a.ff.size() > b.ff.size();
         });

    fu(i, 2, n) {
        fd(j, i - 1, 1) {
            bool mutual = false;
            bool dif = false;
            for (int x : s[i].ff) {
                if (s[j].ff.find(x) != s[j].ff.end()) {
                    mutual = true;
                }

                if (s[j].ff.find(x) == s[j].ff.end()) {
                    dif = true;
                }

                if (mutual && dif) {
                    cout << "YES\n";
                    cout << s[i].ss << ' ' << s[j].ss << '\n';
                    return;
                }
            }
        }
    }
    cout << "NO\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0) {
        solve();
    }
}