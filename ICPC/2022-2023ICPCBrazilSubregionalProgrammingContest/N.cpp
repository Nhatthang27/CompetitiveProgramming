
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
    vector<int> fr(n + 1), ba(n + 1);
    fu(i, 1, n)
    {
        int x;
        cin >> x;
        fr[i] = x;
    }
    fu(i, 1, n)
    {
        int x;
        cin >> x;
        ba[i] = x;
    }
    int k, l;
    cin >> k >> l;

    // multiset descrease value
    multiset<int> sBa;

    int sumFr = 0;
    int sumBa = 0;
    fu(i, 1, k)
    {
        sumBa += ba[i];
        sBa.insert(ba[i]), sumFr += fr[i];
        if (sBa.size() > l)
        {
            auto it = sBa.begin();
            sumBa -= *it;
            sBa.erase(it);
        }
    }

    int res = 0;
    int cnt = 0;
    while (cnt <= k)
    {
        // get sum of L biggest elements in sBa
        res = max(res, sumFr + sumBa);
        if (cnt == k)
            break;

                sBa.erase(sBa.find(ba[k - cnt]));
        sBa.insert(ba[n - cnt]);

        sumFr -= fr[k - cnt];
        sumFr += fr[n - cnt];

        cnt++;
    }
    cout << res << endl;
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