
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAX = 2e5 + 10;

struct custom_hash
{
    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        x ^= FIXED_RANDOM;
        return x ^ (x >> 16);
    }
};
void solve()
{
    int n, k;
    cin >> n >> k;
    unordered_map<int, int, custom_hash> cnt;
    int res = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[i] = x;
        if (cnt[k - x] != 0)
        {
            res++;
            cnt[k - x]--;
        }
        else
        {
            cnt[x]++;
        }
        // cerr << i << " " << res << endl;
    }
    // sort(a.begin(), a.end());
    // for (int i = 0; i < n; i++)
    // {
    //     cerr << a[i] << " ";
    // }
    // cerr << endl;
    cout << res << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
}