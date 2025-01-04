#include <bits/stdc++.h>
#define int long long
using namespace std;

int fast_calc(int n, int k)
{
    int sum = 0;
    int l = 1, r = n;

    while ((r - l + 1) >= k)
    {
        int len = r - l + 1;
        if (len % 2 == 1)
        { // Nếu độ dài lẻ, cộng giá trị giữa
            sum += (l + r) / 2;
        }
        // Chia đoạn cho đến khi không đủ k phần tử
        r = (l + r) / 2 - (len % 2 == 0 ? 0 : 1);
    }

    return sum;
}

void solve()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, k;
        cin >> n >> k;
        cout << fast_calc(n, k) << "\n";
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}
