#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    // Biến lưu trữ kết quả
    int maxLength = 0;

    // Các biến đếm số 0 liên tiếp bên trái và bên phải của mỗi 1
    vector<int> leftZeros(n, 0), rightZeros(n, 0);

    // Tính số lượng 0 liên tiếp bên trái của mỗi 1
    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '0')
        {
            count++;
        }
        else
        {
            leftZeros[i] = count;
            count = 0;
        }
    }

    // Tính số lượng 0 liên tiếp bên phải của mỗi 1
    count = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        if (s[i] == '0')
        {
            count++;
        }
        else
        {
            rightZeros[i] = count;
            count = 0;
        }
    }

    // Duyệt qua các ký tự '1' và tính độ dài chuỗi "nice"
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '1')
        {
            int left = leftZeros[i];
            int right = rightZeros[i];
            maxLength = max(maxLength, 2 * min(left, right) + 1);
        }
    }

    cout << maxLength << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
