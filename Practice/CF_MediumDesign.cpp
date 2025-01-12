
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int numQ, n;
    cin >> numQ >> n;
    vector<pair<int, int>> segs(numQ);
    for (auto &[l, r] : segs)
    {
        cin >> l >> r;
    }
    sort(segs.begin(), segs.end());

    int res = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    int cnt = 0;
    // skip 1
    for (auto [l, r] : segs)
    {
        if (l == 1)
            continue;
        while(!pq.empty() && pq.top() < l)
        {
            cnt--;
            pq.pop();
        }
        cnt++;
        res = max(res, cnt);
        pq.push(r);
    }

    //skip n
    pq = priority_queue<int, vector<int>, greater<int>>();
    cnt = 0;
    for (auto [l, r] : segs)
    {
        if (r == n)
            continue;
        while(!pq.empty() && pq.top() < l)
        {
            cnt--;
            pq.pop();
        }
        cnt++;
        res = max(res, cnt);
        pq.push(r);
    }
    cout << res << endl;
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