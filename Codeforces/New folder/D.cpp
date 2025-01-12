
#include <bits/stdc++.h>
#define int long long
using namespace std;

struct SegmentTree
{
    vector<int> minTree, diffTree; // minTree để lưu min, diffTree để lưu max(a[i] - mi)
    int n;

    SegmentTree(int size)
    {
        n = size;
        minTree.assign(4 * n, INT_MAX);
        diffTree.assign(4 * n, INT_MIN);
    }

    // Xây dựng Segment Tree từ mảng ban đầu
    void build(int node, int start, int end, const vector<int> &a)
    {
        if (start == end)
        {
            minTree[node] = a[start];
        }
        else
        {
            int mid = (start + end) / 2;
            build(2 * node, start, mid, a);
            build(2 * node + 1, mid + 1, end, a);
            minTree[node] = min(minTree[2 * node], minTree[2 * node + 1]);
        }
    }

    // Cập nhật giá trị tại chỉ số idx trong Segment Tree
    void update(int node, int start, int end, int idx, int value)
    {
        if (start == end)
        {
            minTree[node] = value;
        }
        else
        {
            int mid = (start + end) / 2;
            if (idx <= mid)
                update(2 * node, start, mid, idx, value);
            else
                update(2 * node + 1, mid + 1, end, idx, value);
            minTree[node] = min(minTree[2 * node], minTree[2 * node + 1]);
        }
    }

    // Truy vấn giá trị nhỏ nhất trong đoạn [l, r]
    int queryMin(int node, int start, int end, int l, int r)
    {
        if (r < start || end < l)
            return INT_MAX;
        if (l <= start && end <= r)
            return minTree[node];
        int mid = (start + end) / 2;
        return min(queryMin(2 * node, start, mid, l, r),
                   queryMin(2 * node + 1, mid + 1, end, l, r));
    }

    // Tính giá trị maxDiff tại một thời điểm
    int calculateMaxDiff(int node, int start, int end, int l, int r, const vector<int> &a)
    {
        if (r < start || end < l)
            return INT_MIN;
        if (start == end)
        {
            int mi = queryMin(1, 0, n - 1, 0, start - 1); // min từ [1, start-1]
            return max(0LL, a[start] - mi);               // maxDiff tại nút lá
        }
        int mid = (start + end) / 2;
        return max(calculateMaxDiff(2 * node, start, mid, l, r, a),
                   calculateMaxDiff(2 * node + 1, mid + 1, end, l, r, a));
    }
};
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
        a[i] -= (i + 1);
        b[i] += (i + 1);
    }
    reverse(b.begin(), b.end());

    int ans = 0;
    int mi = a[0];
    for (int i = 1; i < n; i++)
    {
        ans = max(ans, a[i] - mi);
        mi = min(mi, a[i]);
    }
    mi = b[0];
    for (int i = 1; i < n; i++)
    {
        ans = max(ans, b[i] - mi);
        mi = min(mi, b[i]);
    }
    cout << ans << "\n";

    SegmentTree st_a(n), st_b(n);
    st_a.build(1, 0, n - 1, a);
    st_b.build(1, 0, n - 1, b);
    for (int turn = 0; turn < q; turn++)
    {
        int pos, newVal;
        cin >> pos >> newVal;
        pos--;
        a[pos] = newVal - (pos + 1);
        b[n - pos - 1] = newVal + (pos + 1);

        // ans = 0;
        // int mi = a[0];
        // for (int i = 1; i < n; i++)
        // {
        //     ans = max(ans, a[i] - mi);
        //     mi = min(mi, a[i]);
        // }
        // mi = b[n - 1];
        // for (int i = n - 2; i >= 0; i--)
        // {
        //     ans = max(ans, b[i] - mi);
        //     mi = min(mi, b[i]);
        // }
        st_a.update(1, 0, n - 1, pos, a[pos]);
        st_b.update(1, 0, n - 1, n - pos - 1, b[n - pos - 1]);
        int ans = max(st_a.calculateMaxDiff(1, 0, n - 1, 0, n - 1, a), st_b.calculateMaxDiff(1, 0, n - 1, 0, n - 1, b));
        cout << ans << "\n";
    }
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