
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;
const int mod = 1e9 + 7;
const int MAX = 2e5;
vector<int> fact(MAX + 1, 1), inv(MAX + 1, 1);

int pow(int a, int b, int m)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    fu(i, 1, n)
    {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    vector<int> cnt(n + 2, 0);
    fd(i, n, 1)
    {
        cnt[i] = cnt[i + 1] + (a[i] == 1);
    }

    auto get_nCk = [&](int n, int k)
    {
        if (n < k)
            return 0LL;
        return fact[n] * inv[k] % mod * inv[n - k] % mod;
    };

    int res = 0;
    k /= 2;
    fu(i, 1, n)
    {
        if (a[i] == 1)
        {
            res = (res + get_nCk(i - 1, k) * get_nCk(cnt[i + 1], k)) % mod;
        }
    }
    cout << res << "\n";
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    fu(i, 1, MAX)
    {
        fact[i] = fact[i - 1] * i % mod;
        inv[i] = pow(fact[i], mod - 2, mod);
    }
    int t;
    cin >> t;
    while (t-- > 0)
    {
        solve();
    }
}