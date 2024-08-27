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
vector<int> phi(100000 + 1);

void phi_1_to_n(int n) {
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
        phi[i] = i - 1;

    for (int i = 2; i <= n; i++)
        for (int j = 2 * i; j <= n; j += i)
            phi[j] -= phi[i];
}

int ff(int x, int y) {
    int ans = phi[x];
    for (int i = 1; i < y; i++)
        ans = 2 * phi[ans];
    return ans;
}

int fff(int x, int y) {
    return x + y;
}

void solve() {
    string trash1, trash2, trash3, v1, v2;
    int x, y;
    cin >> trash1 >> trash2 >> trash3 >> v1;
    cin >> trash1 >> trash2 >> trash3 >> v2;
    v1[v1.size() - 1] = '\0';
    v2[v2.size() - 1] = '\0';
    x = stoi(v1);
    y = stoi(v2);
    string func;
    cin >> trash1 >> trash2 >> trash3 >> func;
    func[func.size() - 1] = '\0';

    int ans = 0;

    auto calcFunc = [&](int x, int y, int type) {
        if (type == 1) return phi[x];
        if (type == 2) return ff(x, y);
        if (type == 3) return fff(x, y);
    };

    stack<pair<char, int>> st;
    stack<int> val;
    st.push({'f', 0});
    for (int i = 0; i < sz(func); ++i) {
        if (func[i] == 'f') {
            auto [c, n] = st.top();
            st.pop();
            st.push({'f', n + 1});
        } else if (func[i] == ')') {
            if (sz(st) && st.top().second == 0) st.pop();

            auto [c, n] = st.top();
            st.pop();

            int u, v;
            u = v = 0;
            if (n == 1) {
                u = val.top();
                val.pop();
            } else {
                v = val.top();
                val.pop();
                u = val.top();
                val.pop();
            }

            val.push(calcFunc(u, v, n));
        } else if (func[i] == 'x' || func[i] == 'y') {
            if (func[i] == 'x') val.push(x);
            if (func[i] == 'y') val.push(y);
        } else if (func[i] == ',' || func[i] == '(') {
            if (sz(st) && st.top().second != 0) st.push({func[i], 0});
        }
    }

    cout << val.top() << endl;
}

int32_t main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    phi_1_to_n(100000);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}