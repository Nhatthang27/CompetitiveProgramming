
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    vector<int> cnt(4, 0);
    fu(i, 1, n) cin >> a[i], cnt[a[i]]++;

    int res = 0;
    fu(i, 1, 3)
    {
        res += cnt[i] / k;
        if (cnt[i] % k != 0)
            res++;
    }

    // factorial
    int fact = 1;
    fu(i, 1, res) fact *= i;
    cout << fact << endl;
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