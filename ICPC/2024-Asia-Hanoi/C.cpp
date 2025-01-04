
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;
const int MOD = 1e9 + 7;

const int MAX = 1e7;
int fact[MAX + 1];
void prepare()
{
    fact[0] = 1;
    for (int i = 1; i <= MAX; i++)
        fact[i] = fact[i - 1] * i % MOD;
}

void solve()
{
    auto pw = [&](int x, int k)
    {
        int res = 1, mul = x;
        while (k > 0)
        {
            if (k & 1)
            {
                res = res * mul % MOD;
            }
            k >>= 1;
            mul = mul * mul % MOD;
        }
        return res;
    };

    int n, m;
    cin >> n >> m;
    // cerr << pw(2, 3) << " " << fact[3] << "\n";
    cout << pw(fact[m], n) * pw(fact[n], m) % MOD << "\n";
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    prepare();
    int t;
    cin >> t;
    while (t-- > 0)
    {
        solve();
    }
}