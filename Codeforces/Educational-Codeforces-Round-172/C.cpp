
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
    string s;
    cin >> s;
    s = " " + s;
    vector<int> suffix_sum(n + 1, 0);

    suffix_sum[n] = (s[n] == '1' ? 1 : -1);
    for (int i = n - 1; i >= 1; i--)
    {
        suffix_sum[i] += suffix_sum[i + 1] + (s[i] == '1' ? 1 : -1);
    }

    sort(suffix_sum.begin() + 2, suffix_sum.end(), greater<int>());
    int sum = 0;
    for (int i = 2; i <= n; i++)
    {
        sum += suffix_sum[i];
        if (sum >= k)
        {
            cout << i << "\n";
            return;
        }
    }
    cout << -1 << "\n";
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        solve();
    }
}