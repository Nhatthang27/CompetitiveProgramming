
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 998244353;
const int MAX = 2e5 + 7;

int pw(int x, int k)
{
    int res = 1, mul = x;
    while (k > 0)
    {
        if (k & 1)
        {
            res = res * mul % MOD;
        }
        mul = mul * mul % MOD;
        k >>= 1;
    }
    return res;
}

int find_last_index(const vector<int> &vec, int x)
{
    auto it = upper_bound(vec.begin(), vec.end(), x);
    if (it == vec.begin())
    {
        return -1;
    }
    it--;
    if (*it == x)
    {
        return it - vec.begin();
    }
    return -1;
}

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    auto sa = a;
    auto sb = b;
    sort(sa.begin(), sa.end());
    sort(sb.begin(), sb.end());

    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        ans = ans * min(sa[i], sb[i]) % MOD;
    }
    cout << ans << " ";
    // cout << find_last_index(sa, 1) << "\n";
    for (int turn = 1; turn <= q; turn++)
    {
        int o, x;
        cin >> o >> x;
        --x;
        if (o == 1)
        {
            int idx = find_last_index(sa, a[x]);
            ans = ans * pw(min(sa[idx], sb[idx]), MOD - 2) % MOD;
            sa[idx]++;
            ans = ans * min(sa[idx], sb[idx]) % MOD;
            a[x]++;
        }
        else
        {
            int idx = find_last_index(sb, b[x]);
            ans = ans * pw(min(sa[idx], sb[idx]), MOD - 2) % MOD;
            sb[idx]++;
            ans = ans * min(sa[idx], sb[idx]) % MOD;
            b[x]++;
        }
        // cerr << "a: ";
        // for (int i = 0; i < n; i++)
        // {
        //     cerr << a[i] << " ";
        // }
        // cerr << "\n";
        // cerr << "sa: ";
        // for (int i = 0; i < n; i++)
        // {
        //     cerr << sa[i] << " ";
        // }
        // cerr << "\n";
        // cerr << "b: ";
        // for (int i = 0; i < n; i++)
        // {
        //     cerr << b[i] << " ";
        // }
        // cerr << "\n";
        // cerr << "sb: ";
        // for (int i = 0; i < n; i++)
        // {
        //     cerr << sb[i] << " ";
        // }
        // cerr << "\n";
        cout << ans << " ";
    }
    cout << "\n";
}
int32_t main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        solve();
    }
}