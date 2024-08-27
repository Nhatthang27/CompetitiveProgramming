
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

    auto ask = [&](int a, int b, int c, int d) {
        cout << "? " << a << " " << b << " " << c << " " << d << "\n";
        cout.flush();
        char res;
        cin >> res;
        return res;
    };
    int pmax = 0;
    fu(i, 1, n - 1) {
        if (ask(pmax, pmax, i, i) == '<') {
            pmax = i;
        }
    }

    vector<int> poten;
    int maxValue = (pmax == 0) ? 1 : 0;
    fu(i, 0, n - 1) {
        if (i != pmax) {
            if (ask(i, pmax, maxValue, pmax) == '>') {
                maxValue = i;
                poten.clear();
                poten.push_back(i);
            } else if (ask(i, pmax, maxValue, pmax) == '=') {
                poten.push_back(i);
            }
        }
    }
    int pmin = poten[0];
    fu(i, 1, poten.size() - 1) {
        if (ask(pmin, pmin, poten[i], poten[i]) == '>') {
            pmin = poten[i];
        }
    }
    cout << "! " << pmin << " " << pmax << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}