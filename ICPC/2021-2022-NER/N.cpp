
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

vector<bool> vowels(30, false);
vector<int> haiku({5, 7, 5});

void solve() {
    vector<int> num(3);
    fu(i, 0, 2) {
        cin >> num[i];
    }
    int id = 0;
    bool ok = true;
    while (id < 3) {
        int cnt_vowels = 0, cnt_y = 0;
        int n = num[id];
        // cout << n << "\n";
        string s;
        while (n-- > 0) {
            cin >> s;
            // to lower
            transform(s.begin(), s.end(), s.begin(), ::tolower);
            // cout << s << "\n";
            for (char c : s) {
                // cout << c - 'a' << " ";
                if (vowels[c - 'a']) {
                    cnt_vowels++;
                }
                if (c == 'y') {
                    cnt_y++;
                }
            }
            // cout << "\n";
        }
        if (ok) {
            if (cnt_vowels > haiku[id]) {
                ok = false;
            }
            if (cnt_vowels + cnt_y < haiku[id]) {
                ok = false;
            }
        }

        id++;
    }
    cout << (ok ? "YES" : "NO") << "\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vowels['a' - 'a'] = true;
    vowels['e' - 'a'] = true;
    vowels['i' - 'a'] = true;
    vowels['o' - 'a'] = true;
    vowels['u' - 'a'] = true;
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}