#include <bits/stdc++.h>
using namespace std;


struct Dsu {
    vector<int> root, sz;

    Dsu(int n) {
        root.assign(n + 1, -1);
        sz.assign(n + 1, 1);
        for (int u = 1; u <= n; u++) {
            root[u] = u;
        }
    }

    int findRoot(int u) {
        return root[u] = (root[u] == u ? u : findRoot(root[u]));
    }

    bool join(int u, int v) {
        u = findRoot(u);
        v = findRoot(v);
        if (u != v) {
            if (sz[u] < sz[v])
                swap(u, v);
            root[v] = u;
            sz[u] += sz[v];
            return true;
        } else {
            return false;
        }
    }
};

bool canTraverseAllPairs(vector<int> &nums) {
    if (nums.size() == 1 || *min_element(nums.begin(), nums.end()) == 1) {
        return false;
    }
    const int MAX = 1e5;
    vector<int> sieve(MAX + 1, 0);
    for(int i = 2; i <= MAX; i++) {
        if (sieve[i] == 0) {
            for(int j = i; j <= MAX; j += i) {
                sieve[j] = i;
            }
        }
    } 

    auto getPrimeFactor = [&](int x) {
        vector<int> primes;
        while(x > 1) {
            int prime = sieve[x];
            primes.push_back(prime);
            while(x % prime == 0)
                x /= prime;
        }
        return primes;
    };

    Dsu dsu(MAX);
    for(int x : nums) {
        for(int p : getPrimeFactor(x)) {
            dsu.join(x, p);
        }
    }

    int cnt = 0;
    int root = dsu.findRoot(nums[0]);
    for(int i = 1; i < nums.size(); i++) {
        if (dsu.findRoot(nums[i]) != root) {
            return false;
        }
    }
    return true;
}
