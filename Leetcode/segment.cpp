
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

struct SegmentTree {
    int n;
    vector<int> mi;
    vector<int> nChild;

    SegmentTree(int _n) {
        n = _n;
        mi.assign(4 * n + 5, 0);
        nChild.assign(4 * n + 5, 0);
    }

    void update(int i, int val, int id, int l, int r) {
        if (i < l || i > r)
            return;
        if (l == r) {
            mi[id] = val;
            nChild[id] = 1;
            return;
        }
        int mid = (l + r) >> 1;
        if (i <= mid)
            update(i, val, id * 2, l, mid);
        else
            update(i, val, id * 2 + 1, mid + 1, r);
        mi[id] = min(mi[id * 2], mi[id * 2 + 1]);
        nChild[id] = nChild[id * 2] + nChild[id * 2 + 1];
    }

    int get(int val, int id, int l, int r) {
        if (mi[id] > val) {
            return nChild[id];
        }
        if (l == r) {
            return 0;
        }
        int mid = (l + r) >> 1;
        return get(val, id * 2, l, mid) + get(val, id * 2 + 1, mid + 1, r);
    }

    int get(int val) { return get(val, 1, 1, n); }

    void update(int i, int val) { update(i, val, 1, 1, n); }
};
vector<int> resultArray(vector<int> &nums) {
    vector<int> a, b, res;
    a.push_back(nums[0]);
    b.push_back(nums[1]);

    SegmentTree sa(nums.size() + 1), sb(nums.size() + 1);

    int na = 1, nb = 1;
    sa.update(na, nums[0]);
    sb.update(nb, nums[1]);

    for (int i = 2; i < nums.size(); i++) {
        int cnt_a = sa.get(nums[i]);
        int cnt_b = sb.get(nums[i]);

        if (cnt_a > cnt_b) {
            a.push_back(nums[i]);
            sa.update(++na, nums[i]);
        } else if (cnt_a < cnt_b) {
            b.push_back(nums[i]);
            sb.update(++nb, nums[i]);
        } else {
            if (a.size() <= b.size()) {
                sa.update(++na, nums[i]);
                a.push_back(nums[i]);
            } else {
                sb.update(++nb, nums[i]);
                b.push_back(nums[i]);
            }
        }
    }
    for (int x : a)
        res.push_back(x);
    for (int x : b)
        res.push_back(x);
    return res;
}