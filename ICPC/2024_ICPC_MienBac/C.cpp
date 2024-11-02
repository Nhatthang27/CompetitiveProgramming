#include <bits/stdc++.h>
using namespace std;

// Hàm tìm tổng dãy con 1D lớn nhất chia hết cho k
int maxSubarraySumDivByK(const vector<int> &arr, int k)
{
    unordered_map<int, int> mod_map;
    mod_map[0] = -1;
    int max_sum = INT_MIN, prefix_sum = 0;

    for (int i = 0; i < arr.size(); ++i)
    {
        prefix_sum += arr[i];
        int mod = ((prefix_sum % k) + k) % k;

        if (mod_map.find(mod) != mod_map.end())
        {
            int subarray_sum = prefix_sum - mod_map[mod];
            max_sum = max(max_sum, subarray_sum);
        }
        else
        {
            mod_map[mod] = prefix_sum;
        }
    }

    return max_sum == INT_MIN ? 0 : max_sum;
}

// Hàm tìm tổng lớn nhất của mảng con chia hết cho k
int maxSubMatrixSumDivisibleByK(const vector<vector<int>> &arr, int m, int n, int k)
{
    int max_sum = INT_MIN;

    for (int c1 = 0; c1 < n; ++c1)
    {
        vector<int> rowSum(m, 0);

        for (int c2 = c1; c2 < n; ++c2)
        {
            for (int row = 0; row < m; ++row)
            {
                rowSum[row] += arr[row][c2];
            }

            int current_max = maxSubarraySumDivByK(rowSum, k);
            max_sum = max(max_sum, current_max);
        }
    }

    return max_sum == INT_MIN ? 0 : max_sum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, n, k;
    cin >> m >> n >> k;

    vector<vector<int>> arr(m, vector<int>(n));
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> arr[i][j];
        }
    }

    int result = maxSubMatrixSumDivisibleByK(arr, m, n, k);
    cout << result << endl;

    return 0;
}
