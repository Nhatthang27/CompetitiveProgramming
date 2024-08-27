
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pint pair<int, int>
#define ff first
#define ss second
using namespace std;
const int base = 31;
const int MOD = 1000000003;
const int maxn = 2e5 + 7;

using namespace std;

int POW[maxn], h1[maxn], h2[maxn];

int getS(int i, int j) {
    return (h1[j] - h1[i - 1] * POW[j - i + 1] + MOD * MOD) % MOD;
}

int getRev(int i, int j) {
    return (h2[j] - h2[i - 1] * POW[j - i + 1] + MOD * MOD) % MOD;
}

void solve() {
    string s, revs;
    int n, q;
    cin >> n >> q;
    cin >> s;
    revs = s;
    reverse(revs.begin(), revs.end());
    revs = ' ' + revs;
    s = ' ' + s;

    for (int i = 1; i <= n; i++)
        h1[i] = (h1[i - 1] * base + s[i] - 'a' + 1) % MOD;
    for (int i = 1; i <= n; i++)
        h2[i] = (h2[i - 1] * base + revs[i] - 'a' + 1) % MOD;

    auto checkPalin = [&](int l, int r) -> bool {
        return getS(l, r) == getRev(n - r + 1, n - l + 1);
    };

    auto checkNotPalin = [&](int len, int l, int r) -> bool {
        fu(i, l, r - len + 1) {
            if (checkPalin(i, i + len - 1) == false) {
                return true;
            }
        }
        return false;
    };
    while (q-- > 0) {
        int l, r;
        cin >> l >> r;
        int even = 2;
        int res = 0;
        while (even <= r - l + 1) {
            if (checkNotPalin(even, l, r)) {
                int dau = even;
                int cuoi = r - l + 1;
                cuoi -= cuoi % 2;
                res += (cuoi + dau) * ((cuoi - dau) / 2 + 1) / 2;
                break;
            }
            even += 2;
        }
        int odd = 3;
        while (odd <= r - l + 1) {
            if (checkNotPalin(odd, l, r)) {
                int dau = odd;
                int cuoi = r - l + 1;
                cuoi -= (cuoi % 2 == 0);
                res += (cuoi + dau) * ((cuoi - dau) / 2 + 1) / 2;
                break;
            }
            odd += 2;
        }
        cout << res << "\n";
    }
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    POW[0] = 1;
    for (int i = 1; i <= maxn; i++)
        POW[i] = (POW[i - 1] * base) % MOD;
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}