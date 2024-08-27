#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isGood(const vector<int> &nums, const vector<int> &changeIndices,
                int turns) {
        int n = (int)(nums.size());
        vector<pair<int, int>> lastAppearance(n, {-1, -1});
        for (int i = 0; i < turns; i++)
            lastAppearance[changeIndices[i] - 1] = {i, changeIndices[i] - 1};
        for (int i = 0; i < n; i++)
            if (lastAppearance[i].first == -1)
                return false;
        sort(lastAppearance.begin(), lastAppearance.end());

        int ops = 0;
        for (int i = 0; i < n; i++) {
            ops += nums[lastAppearance[i].second] + 1;
            if (ops > lastAppearance[i].first + 1)
                return false;
        }
        return true;
    }
    int earliestSecondToMarkIndices(vector<int> &nums,
                                    vector<int> &changeIndices) {
        int time = changeIndices.size();
        int n = nums.size();
        vector<int> a(n + 1);
        vector<int> c(time + 1);

        for (int i = 0; i < n; i++)
            a[i + 1] = nums[i];
        for (int i = 0; i < time; i++)
            c[i + 1] = changeIndices[i];

        auto isGood = [&](int sec) {
            vector<pair<int, int>> last(n + 1, {-1, -1});
            for (int i = 1; i <= sec; i++) {
                last[c[i]] = {i, c[i]};
            }
            for (int i = 1; i <= n; i++) {
                if (last[i].first == -1)
                    return false;
            }

            sort(last.begin() + 1, last.begin() + n + 1);
            int w = 0;
            for (int i = 1; i <= n; i++) {
                int id = last[i].second;
                int la = last[i].first;
                if (w + a[id] > la) {
                    return false;
                }
                w += a[id] + 1;
            }
            return true;
        };

        auto isGood2 = [&](int sec) {
            vector<pair<int, int>> last(n + 1, {-1, -1});
            vector<int> beg(n + 1, -1);

            for (int i = 1; i <= sec; i++) {
                last[c[i]] = {i, c[i]};
                if (beg[c[i]] == -1) {
                    beg[c[i]] = i;
                }
            }
            for (int i = 1; i <= n; i++) {
                if (beg[i] == -1)
                    return false;
            }

            sort(last.begin() + 1, last.begin() + n + 1);
            int w = 0;
            for (int i = 1; i <= n; i++) {
                int id = last[i].second;
                int la = last[i].first;

                int dam = a[id];
                if (beg[id] != id) {
                    dam = min(dam, (int)1);
                }
                if (w + dam >= la) {
                    return false;
                }
                w += dam + 1;
            }
            return true;
        };

        int l = 1, r = time;
        int res = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            // cout << mid << "\n";
            if (isGood(mid)) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return res;
    }
};