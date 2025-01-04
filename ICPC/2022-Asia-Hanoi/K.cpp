/*
  Code by: linvg
  Created: 27.11.2024 18:55:22
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

const int INF = 0x3f3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 2007;

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#endif

const int NM = 2e5 + 7;

int a[N], f[N][N];
int ans[NM];
array<int, 4> ques[NM];

struct Fenwick2D
{
    int bit[N][N];
    void update(int x, int y, int delta)
    {
        for (int i = x; i < N; i += i & -i)
        {
            for (int j = y; j < N; j += j & -j)
            {
                bit[i][j] += delta;
            }
        }
    }

    int query(int x, int y)
    {
        int sum = 0;
        for (int i = x; i > 0; i -= i & -i)
        {
            for (int j = y; j > 0; j -= j & -j)
            {
                sum += bit[i][j];
            }
        }
        return sum;
    }

    int rangeQuery(int x1, int y1, int x2, int y2)
    {
        return query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1);
    }
};

Fenwick2D fw2;

void solve()
{
    int n;
    scanf("%lld", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    vector<array<int, 3>> sets;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            if (f[j][i] > 1e18 - abs(a[i] - a[j]) - f[j][i - 1])
                break;
            else
                f[j][i] = f[j][i] + abs(a[i] - a[j]) + f[j][i - 1];
            sets.push_back({j, i, f[j][i]});
        }
    }
    sort(all(sets), [](array<int, 3> x, array<int, 3> y)
         { return x[2] < y[2]; });

    int q;
    scanf("%lld", &q);
    for (int i = 0; i < q; ++i)
    {
        int l, r, k;
        scanf("%lld%lld%lld", &l, &r, &k);
        ques[i] = {l, r, k, i};
    }
    sort(ques, ques + q, [](array<int, 4> &x, array<int, 4> &y)
         { return x[2] < y[2]; });
    int start = 0;
    for (int i = 0; i < q; ++i)
    {
        auto [l, r, k, id] = ques[i];
        for (; start < sz(sets) and sets[start][2] <= k; ++start)
        {
            fw2.update(sets[start][0], sets[start][1], 1);
        }
        ans[id] = fw2.rangeQuery(l, 1, n, r);
    }
    for (int i = 0; i < q; ++i)
        printf("%lld\n", ans[i]);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}