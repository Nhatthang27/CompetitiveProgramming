
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
    int res = 0;
    int n, m;
    cin >> n;
    vector<int> pos(n + 1), resi(n + 1);
    fu(i, 1, n) cin >> resi[i];
    fu(i, 1, n) cin >> pos[i];

    cin >> m;
    vector<pii> cloud(m + 1);
    fu(i, 1, m) cin >> cloud[i].ff;
    fu(i, 1, m)
    {
        int len;
        cin >> len;
        cloud[i].ss = cloud[i].ff + len;
        cloud[i].ff = cloud[i].ff - len;
    }
    vector<int> value;
    fu(i, 1, n)
    {
        value.push_back(pos[i]);
    }
    fu(i, 1, m)
    {
        value.push_back(cloud[i].ff);
        value.push_back(cloud[i].ss);
    }
    sort(value.begin(), value.end());
    value.resize(unique(value.begin(), value.end()) - value.begin());

    fu(i, 1, n)
    {
        pos[i] = lower_bound(value.begin(), value.end(), pos[i]) - value.begin() + 1;
    }
    fu(i, 1, m)
    {
        cloud[i].ff = lower_bound(value.begin(), value.end(), cloud[i].ff) - value.begin() + 1;
        cloud[i].ss = lower_bound(value.begin(), value.end(), cloud[i].ss) - value.begin() + 1;
    }
    // cout << "here\n";
    int maxSize = (int)value.size() + 3;
    vector<int> sum(maxSize + 1, 0);
    vector<int> pp(maxSize + 1, 0);
    fu(i, 1, n)
    {
        if (pp[pos[i]] == 0)
            pp[pos[i]] = resi[i];
    }

    fu(i, 1, m)
    {
        int l = cloud[i].ff;
        int r = cloud[i].ss;
        sum[l]++;
        sum[r + 1]--;
    }
    fu(i, 1, maxSize) sum[i] += sum[i - 1];
    vector<int> sunny(maxSize + 1, 0);
    fu(i, 1, n)
    {
        if (sum[pos[i]] == 1)
        {
            sunny[pos[i]] += pp[pos[i]];
        }
        if (sum[pos[i]] == 0)
            res += pp[pos[i]];
    }
    // cout << "hre]";

    fu(i, 1, maxSize) sunny[i] += sunny[i - 1];
    int ma = 0;
    fu(i, 1, m)
    {
        int l = cloud[i].ff;
        int r = cloud[i].ss;
        int tmp = sunny[r] - sunny[l - 1];
        ma = max(ma, tmp);
    }
    cout << res + ma;
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