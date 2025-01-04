
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

void solve()
{
    int a, b, m;
    cin >> a >> b >> m;

    int fa = 0, fb = 0;
    int len = max(a, b);
    vector<int> fibo(len + 1);
    fibo[0] = 0;
    fibo[1] = 1;
    for (int i = 2; i <= len; i++)
    {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
        // cout << i << " " << fibo[i] << "\n";
    }

    fa = fibo[a];
    fb = fibo[b];
    // cout << fa << " " << fb << "\n";
    int u = __gcd(fa, fb);
    cout << u % m;
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0)
    {
        solve();
    }
}