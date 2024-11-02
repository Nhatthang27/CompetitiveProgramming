
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
    int ma_id = 1;
    vector<int> a(n + 1), b(n + 1);

    int vt_mi_tu, vt_mi_mau;
    int vt_ma_tu, vt_ma_mau;

    fu(i, 1, n)
    {
        cin >> a[i] >> b[i];
    }

    vt_mi_tu = 1;
    vt_mi_mau = b[1];

    vt_ma_tu = 1;
    vt_ma_mau = a[1];

    fu(i, 2, n)
    {
        if (i * vt_mi_mau > vt_mi_tu * b[i])
        {
            vt_mi_tu = i;
            vt_mi_mau = b[i];
        }
        if (i * vt_ma_mau < vt_ma_tu * a[i])
        {
            vt_ma_tu = i;
            vt_ma_mau = a[i];
        }
    }

    if (vt_mi_tu * vt_ma_mau > vt_ma_tu * vt_mi_mau)
    {
        cout << -1 << endl;
        return;
    }
    double res = (double)vt_mi_tu / vt_mi_mau;
    cout << fixed << setprecision(6) << res << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("subsonic_subway_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    fu(i, 1, t)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
}