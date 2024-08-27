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

string to_upper(string a)
{
    for (int i = 0; i < (int)a.size(); ++i)
        if (a[i] >= 'a' && a[i] <= 'z')
            a[i] -= 'a' - 'A';
    return a;
}
string to_lower(string a)
{
    for (int i = 0; i < (int)a.size(); ++i)
        if (a[i] >= 'A' && a[i] <= 'Z')
            a[i] += 'a' - 'A';
    return a;
}

template <class T>
T gcd(T a, T b)
{
    T r;
    while (b != 0)
    {
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

const int INF = 0x3f3f3f3f3f;
const int MOD = 1e8;

void solve()
{
    string a, b;
    cin >> a >> b;
    string s;
    int i = 0, j = 0;
    vector<char> nxt_a(a.size()), nxt_b(b.size());
    nxt_a[a.size() - 1] = a.back();
    nxt_b[b.size() - 1] = b.back();
    for (int i = a.size() - 2; i >= 0; --i)
    {
        if (a[i] == a[i + 1])
        {
            nxt_a[i] = nxt_a[i + 1];
        }
        else
        {
            nxt_a[i] = a[i + 1];
        }
    }
    for (int i = b.size() - 2; i >= 0; --i)
    {
        if (b[i] == b[i + 1])
        {
            nxt_b[i] = nxt_b[i + 1];
        }
        else
        {
            nxt_b[i] = b[i + 1];
        }
    }
    // for (int i = 0; i < a.size(); ++i) cerr << nxt_a[i] << ' ';
    // cerr << '\n';
    // for (int i = 0; i < b.size(); ++i) cerr << nxt_b[i] << ' ';
    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[j])
        {
            s += a[i];
            ++i;
        }
        else if (b[j] < a[i])
        {
            s += b[j];
            ++j;
        }
        else
        {
            if (nxt_a[i] < nxt_b[j])
            {
                s += a[i];
                ++i;
            }
            else
            {
                s += b[j];
                ++j;
            }
        }
    }
    while (i < a.size())
        s += a[i++];
    while (j < b.size())
        s += b[j++];
    cout << s << '\n';
}

int32_t main()
{

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}