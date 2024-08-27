#include <bits/stdc++.h>
#define int long long
#define ll long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;
const int MAX = 2e5;
int p[MAX + 7];

void sieve_prime() {
    fu(i, 2, MAX) {
        if (p[i] == 0)
            p[i] = i;
        if (p[i] == i)
            for (int j = 1; i * j <= MAX; j++) {
                p[i * j] = i;
            }
    }
    // cout << "hehe\n";
}

int get_odd_prime(int x) {
    int res = 1;
    vector<pair<int, int>> mul;
    mul.clear();
    while (x != 1) {
        if (mul.empty() || mul.back().ff != p[x]) {
            mul.push_back(make_pair(p[x], 1));
        } else {
            mul.back().ss++;
        }
        // cout << x << "\n";
        x /= p[x];
    }
    for (pair<int, int> m : mul) {
        if (m.ss % 2 == 1) {
            res *= m.ff;
        }
    }
    return res;
}

ll nC2(int n) { return n * (n - 1) / 2; }

void solve() {
    int n;
    cin >> n;
    int nZero = 0;
    map<int, int> mp;
    fu(i, 1, n) {
        int x;
        cin >> x;
        nZero += (x == 0);
        // cout << "hehe\n\n";
        if (x != 0) {
            mp[get_odd_prime(x)]++;
            // cout << x << " " << get_odd_prime(x) << "\n";
        }
    }
    ll res = 0;
    for (auto tmp : mp) {
        res += nC2(tmp.ss);
    }
    res += nC2(nZero) + nZero * (n - nZero);
    cout << res;
}

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    sieve_prime();
    solve();
    // cout << p[10] << "\n";
    // cout << get_odd_prime(12);
}