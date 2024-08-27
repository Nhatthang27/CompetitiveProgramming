
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
    vector<string> a(n + 1), b(n + 1);
    fu(i, 1, n) cin >> a[i];
    fu(i, 1, n) cin >> b[i];

    auto hexaToDec = [&](string s) {
        int res = 0;
        fu(i, 0, s.size() - 1) {
            res = res * 16 + (s[i] >= 'A' ? s[i] - 'A' + 10 : s[i] - '0');
        }
        return res;
    };

    struct Node {
        int x, y, z;
        Node(int x, int y, int z) : x(x), y(y), z(z) {}
        bool operator<(const Node &other) const {
            if (x != other.x) return x < other.x;
            if (y != other.y) return y < other.y;
            return z < other.z;
        }
    };
    map<Node, int> mp;
    fu(i, 1, n) {
        Node node(0, 0, 0);
        node.x = (hexaToDec(a[i].substr(1, 2)) - hexaToDec(b[i].substr(1, 2)) + 256) % 256;
        node.y = (hexaToDec(a[i].substr(3, 2)) - hexaToDec(b[i].substr(3, 2)) + 256) % 256;
        node.z = (hexaToDec(a[i].substr(5, 2)) - hexaToDec(b[i].substr(5, 2)) + 256) % 256;
        mp[node]++;
    }

    int maxNum = 0;
    for (auto p : mp) {
        if (p.ss > maxNum) {
            maxNum = p.ss;
        }
    }
    double res = (double)maxNum / n * 100;
    cout << fixed << setprecision(2) << res << "%" << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0) {
        solve();
    }
}