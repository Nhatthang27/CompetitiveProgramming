
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> time(n), pen(n);
    int sumPen = 0;
    int sumTime = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> time[i] >> pen[i];
        sumPen += pen[i];
        sumTime += time[i];
    }

    vector<array<int, 3>> dish(n);
    for (int i = 0; i < n; i++)
    {
        dish[i] = {time[i], pen[i], i};
    }

    sort(dish.begin(), dish.end(), [&](array<int, 3> a, array<int, 3> b)
         {
        int one = a[0] * b[1];
        int two = a[1] * b[0];
        if (one == two)
            return a[2] < b[2];
        return one < two; });

    for (int i = 0; i < n; i++)
    {
        cout << dish[i][2] + 1 << " ";
    }
    cout << "\n";

    // vector<int> del(n, false);
    // int gg = 0;
    // for (int turn = 1; turn <= n; turn++)
    // {
    //     pair<int, int> best = {LLONG_MAX, -1};
    //     for (int i = 0; i < n; i++)
    //     {
    //         if (del[i])
    //             continue;
    //         if ((sumPen - pen[i]) * time[i] < best.first)
    //         {
    //             best = {(sumPen - pen[i]) * time[i], i};
    //         }
    //     }
    //     gg += (sumPen - pen[best.second]) * time[best.second];
    //     cerr << best.second + 1 << " " << (sumPen - pen[best.second]) * time[best.second] << "\n";
    //     del[best.second] = true;
    //     sumPen -= pen[best.second];
    // }
    // cout << gg << "\n";
    // cout << "\n";

    // vector<int> del(n, false);
    // int gg = 0;
    // for (int turn = 1; turn <= n; turn++)
    // {
    //     pair<int, int> best = {LLONG_MAX, -1};
    //     for (int i = 0; i < n; i++)
    //     {
    //         if (del[i])
    //             continue;
    //         if ((sumTime - pen[i]) * time[i] < best.first)
    //         {
    //             best = {(sumPen - pen[i]) * time[i], i};
    //         }
    //     }
    //     gg += (sumPen - pen[best.second]) * time[best.second];
    //     cerr << best.second + 1 << " " << (sumPen - pen[best.second]) * time[best.second] << "\n";
    //     del[best.second] = true;
    //     sumPen -= pen[best.second];
    // }
    // cout << gg << "\n";
    // cout << "\n";
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