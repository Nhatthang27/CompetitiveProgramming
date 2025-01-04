
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int LIMIT = 1e9;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> res;
    res.push_back(0);
    int id = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        res.push_back(a[i]);
        if (a[i] != -1 && a[i] != 1)
        {
            id = i;
        }
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        res.push_back(sum);
    }
    sum = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        sum += a[i];
        res.push_back(sum);
    }

    int miSum = 0, maSum = 0;
    int mi = 0, ma = 0;
    sum = 0;
    for (int i = 0; i < id; i++)
    {
        sum += a[i];
        mi = min(mi, sum);
        ma = max(ma, sum);
        miSum = min(miSum, sum - ma);
        maSum = max(maSum, sum - mi);
    }
    for (int v = miSum; v <= maSum; v++)
    {
        res.push_back(v);
    }
    miSum = 0, maSum = 0;
    mi = 0, ma = 0;
    sum = 0;
    for (int i = id + 1; i < n; i++)
    {
        sum += a[i];
        mi = min(mi, sum);
        ma = max(ma, sum);
        miSum = min(miSum, sum - ma);
        maSum = max(maSum, sum - mi);
    }
    for (int v = miSum; v <= maSum; v++)
    {
        res.push_back(v);
    }

    if (id != -1)
    {
        int pivot = a[id];
        int miSum = 0, maSum = 0;

        int mi1 = 0, mi2 = 0;
        int ma1 = 0, ma2 = 0;

        sum = 0;
        for (int j = id + 1; j < n; j++)
        {
            sum += a[j];
            mi1 = min(mi1, sum);
            ma1 = max(ma1, sum);
        }
        sum = 0;
        for (int j = id - 1; j >= 0; j--)
        {
            sum += a[j];
            mi2 = min(mi2, sum);
            ma2 = max(ma2, sum);
        }

        for (int i = -1; i >= min(mi1 + mi2, mi1); i--)
        {
            res.push_back(pivot + i);
        }

        for (int i = 1; i <= max(ma1, ma1 + ma2); i++)
        {
            res.push_back(pivot + i);
        }
    }

    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
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