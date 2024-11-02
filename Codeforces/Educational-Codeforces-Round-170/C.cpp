
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
    vector<int> a;
    unordered_map<int, int> cnt;
    fu(i, 1, n)
    {
        int x;
        cin >> x;
        if (cnt[x] == 0)
        {
            cnt[x] = 1;
            a.push_back(x);
        }
        else
        {
            cnt[x]++;
        }
    }

    sort(a.begin(), a.end());

    int ans = 0;
    int len = 0;
    int cur_sum = 0;
    // 2 3 4 5

    fu(i, 0, a.size() - 1)
    {
        if (i == 0)
        {
            len = 1;
            cur_sum = cnt[a[i]];
        }
        else
        {
            len++;
            cur_sum += cnt[a[i]];
            if (a[i] - a[i - 1] > 1)
            {
                len = 1;
                cur_sum = cnt[a[i]];
            }
            else if (len > k)
            {
                len--;
                cur_sum -= cnt[a[i - k]];
            }
        }
        ans = max(ans, cur_sum);
    }

    cout << ans << endl;
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