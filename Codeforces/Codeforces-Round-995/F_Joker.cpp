
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;

    vector<pair<int, int>> range;

    bool head_tail = false;
    while (q-- > 0)
    {
        int move;
        cin >> move;

        for (auto &[l, r] : range)
        {
            if (move < l)
            {
                l = max(1LL, l - 1);
            }
            else if (move > r)
            {
                r = min(n, r + 1);
            }
            else
            {
                if (!head_tail)
                {
                    head_tail = true;
                    range.push_back({1, 1});
                    range.push_back({n, n});
                }
            }
        }
        if (range.empty())
        {
            if (move < m)
                range.push_back({max(1LL, m - 1), m});
            else if (move > m)
                range.push_back({m, min(n, m + 1)});
            else
            {
                head_tail = true;
                range.push_back({1, 1});
                range.push_back({n, n});
            }
        }
        sort(range.begin(), range.end());
        int id = 0;
        int cnt = 0;
        while (id < range.size() && range.size() > 1)
        {
            if (id + 1 < range.size() && range[id].second >= range[id + 1].first)
            {
                range[id].second = range[id + 1].second;
                range.erase(range.begin() + id + 1);
            }
            else
            {
                id++;
            }
        }
        for (auto [l, r] : range)
        {
            // cerr << l << " " << r << "\n";
            cnt += r - l + 1;
        }
        cout << cnt << " ";
    }
    cout << "\n";
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