/*
  Code by: linvg
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define vector2d(var, y, z, type, x) vector<vector<type>> var(y, vector<type>(z, x))
#define vector3d(var, y, z, w, type, x) vector<vector<vector<type>>> var(y, vector<vector<type>>(z, vector<type>(w, x)))
#define vector4d(var, y, z, w, u, type, x) vector<vector<vector<vector<type>>>> var(y, vector<vector<vector<type>>>(z, vector<vector<type>>(w, vector<type>(u, x)))

string to_upper(string a) {
    for (int i = 0; i < (int)a.size(); ++i)
        if (a[i] >= 'a' && a[i] <= 'z') a[i] -= 'a' - 'A';
    return a;
}
string to_lower(string a) {
    for (int i = 0; i < (int)a.size(); ++i)
        if (a[i] >= 'A' && a[i] <= 'Z') a[i] += 'a' - 'A';
    return a;
}

template <class T>
T gcd(T a, T b) {
    T r;
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
template <class T>
T lcm(T a, T b) { return a / gcd(a, b) * b; }
template <class T>
T sqr(T x) { return x * x; }
template <class T>
T cube(T x) { return x * x * x; }

// #define DBG

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#endif

const int INF = 0x3f3f3f3f3f;

void solve() {
    int n, m;
    cin >> n >> m;
    map<string, string> DNS;
    deque<pair<string, string>> cache;

    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        if (t == 1) {
            string domain, ip;
            cin >> domain >> ip;
            DNS[domain] = ip;
        } else {
            string domain;
            cin >> domain;
        }
    }
    cout << "Everything looks ok!";
}

int32_t main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    // int t;
    // cin >> t;
    // while (t--)
    solve();
    return 0;
}