
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
    int n;
    cin >> n;
    vector<pii> a(n + 1);
    map<int, int> mpx, mpy;
    map<pii, int> countPair;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        a[i] = {x, y};
        mpx[x]++;
        mpy[y]++;
        countPair[a[i]]++;
    }

    int res1 = 0, res2 = 0;

    for (auto [x, cnt] : mpx)
    {
        int tmp = cnt * (cnt - 1) / 2;
        res1 += tmp * (n - cnt);
        if (cnt > 2)
        {
            res1 += cnt * (cnt - 1) * (cnt - 2) / 6;
        }
    }
    res1 = n * (n - 1) * (n - 2) / 6 - res1;

    for (auto [y, cnt] : mpy)
    {
        int tmp = cnt * (cnt - 1) / 2;
        res2 += tmp * (n - cnt);
        if (cnt > 2)
        {
            res2 += cnt * (cnt - 1) * (cnt - 2) / 6;
        }
    }
    res2 = n * (n - 1) * (n - 2) / 6 - res2;

    long long totalTriplets = (1LL * n * (n - 1) * (n - 2)) / 6;

    // Đếm số lượng mỗi giá trị x và y

    // Tính số bộ ba không hợp lệ với cùng x
    long long invalidTripletsX = 0;
    for (const auto &[x, count] : mpx)
    {
        if (count >= 2)
        {
            invalidTripletsX += (1LL * count * (count - 1) / 2) * (n - count);
        }
    }

    // Tính số bộ ba không hợp lệ với cùng y
    long long invalidTripletsY = 0;
    for (const auto &[y, count] : mpy)
    {
        if (count >= 2)
        {
            invalidTripletsY += (1LL * count * (count - 1) / 2) * (n - count);
        }
    }

    // Tính số bộ ba bị đếm 2 lần (cả x và y đều trùng)
    long long doubleCounted = 0;
    for (const auto &[pairXY, count] : countPair)
    {
        if (count >= 2)
        {
            doubleCounted += (1LL * count * (count - 1) / 2) * (n - count);
        }
    }

    // Số bộ ba hợp lệ là tổng số bộ ba trừ đi các bộ ba không hợp lệ
    long long validTriplets = totalTriplets - invalidTripletsX - invalidTripletsY + doubleCounted;

    cout << validTriplets << endl;
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