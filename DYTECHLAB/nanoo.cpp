
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
    vector<int> charCount(26, 0);
    int same = 1;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] != s[i - 1]) {
            same = false;
            break;
        }
    }
    if (same) {
        cout << "Amidala\n";
        return;
    }
    for (int i = 0; i < s.size(); ++i) {
        char c = s[i];
        charCount[c - 'a']++;
    }
    int oddCount = 0;
    for (int i = 0; i < 26; i++) {
        if (charCount[i] % 2 != 0) {
            oddCount++;
        }
    }
    cout << ((oddCount == 1) ? ("Amidala\n") : ("Skywalker\n"));
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}