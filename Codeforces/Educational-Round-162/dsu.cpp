#include <bits/stdc++.h>
using namespace std;

struct Dsu {
    vector<int> root, sz;

    Dsu(int n) {
        root.assign(n, -1);
        for (int u = 0; u < n; u++) {
            root[u] = u;
            sz[u] = 1;
        }
    }

    int findRoot(int u) {
        return root[u] = (root[u] == u ? u : findRoot(root[u]));
    }

    bool join(int u, int v) {
        u = findRoot(u);
        v = findRoot(v);
        if (u != v) {
            if (sz[u] > sz[v])
                swap(u, v);
            root[v] = u;
            sz[u] += sz[v];
            return true;
        } else {
            return false;
        }
    }

    void reset(int u) {
        root[u] = u;
        sz[u] = 1;
    }
};

class Solution {
  public:
    vector<int> findAllPeople(int n, vector<vector<int>> &meetings,
                              int firstPerson) {
        sort(meetings.begin(), meetings.end(),
             [](auto& a, auto& b) {
                 return a[2] < b[2];
             });
        Dsu dsu(n);
        dsu.join(0, firstPerson);

        for (int l = 0; l < meetings.size(); l++) {
            int r = l;
            while (r < meetings.size() && meetings[r][2] == meetings[l][2]) {
                dsu.join(meetings[r][0], meetings[r][1]);
                r++;
            }
            r--;
            for (int i = l; i <= r; i++) {
                int u = meetings[i][0];
                int v = meetings[i][1];
                if (dsu.findRoot(u) != 0) {
                    dsu.reset(u);
                    dsu.reset(v);
                }
            }
            l = r;
        }
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (dsu.findRoot(i) == 0)
                res.push_back(i);
        }
        return res;
    }
};