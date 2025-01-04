#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

// Function to compute GCD of two numbers
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to precompute sum of all subsets
vector<int> precomputeSubsetSums(const vector<int>& capabilities) {
    int n = capabilities.size();
    int subsetCount = 1 << n;
    vector<int> subsetSum(subsetCount, 0);

    for (int mask = 1; mask < subsetCount; ++mask) {
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                subsetSum[mask] += capabilities[i];
            }
        }
    }
    return subsetSum;
}

// Function to calculate the sum of GCDs for all divisions
long long calculateTotalEffectiveness(const vector<int>& subsetSum, int n) {
    long long totalEffectiveness = 0;
    int subsetCount = 1 << n;

    for (int mask = 1; mask < subsetCount; ++mask) {
        int currentGCD = 0;

        // Iterate over all submasks
        for (int submask = mask; submask > 0; submask = (submask - 1) & mask) {
            currentGCD = gcd(currentGCD, subsetSum[submask]);
        }

        totalEffectiveness += currentGCD;
    }

    return totalEffectiveness;
}

int main() {
    // Read input
    int n;
    cin >> n;
    vector<int> capabilities(n);
    for (int i = 0; i < n; ++i) {
        cin >> capabilities[i];
    }

    // Precompute subset sums
    vector<int> subsetSum = precomputeSubsetSums(capabilities);

    // Calculate the total effectiveness
    long long totalEffectiveness = calculateTotalEffectiveness(subsetSum, n);

    // Print the result
    cout << totalEffectiveness << endl;

    return 0;
}
