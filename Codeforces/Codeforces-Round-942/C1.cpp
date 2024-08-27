#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;
using VI = vector<int>;

#define pb push_back
#define endl '\n'

void solve() {
    int n;
    LL k;
    cin >> n >> k;
    vector<LL> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    LL st = 0, en = (1ll << 45);
    while (st < en - 1) {
        LL md = (st + en) >> 1;
        LL sum = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] < md) sum += md - a[i];
        }
        if (sum <= k)
            st = md;
        else
            en = md;
    }
    for (int i = 0; i < n; i++) {
        if (a[i] < st) k -= st - a[i];
    }
    cerr << st << "\n";
    cerr << k << endl;
    LL res = 1 + (st - 1) * n;
    LL cnt = 0;
    for (int i = 0; i < n; i++)
        if (a[i] <= st) cnt++;
    res = res + 1ll * n - cnt + k;
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int Tc = 1;
    cin >> Tc;
    while (Tc--) solve();
    return 0;
}
