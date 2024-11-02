#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> s(n + 1);         // 1-based index
    iota(s.begin(), s.end(), 0);  // Initialize s with 0, 1, 2, ..., n

    vector<int> team1, team2;
    vector<int> choose1(n / 2 + 1), choose2(n / 2 + 1);

    for (int i = 1; i <= n / 2; i++) cin >> choose1[i];
    for (int i = 1; i <= n / 2; i++) cin >> choose2[i];

    int availableElements = n;
    for (int i = 1; i <= n / 2; i++) {
        // Insert element into team1
        int selectedIndex = choose1[i];
        team1.push_back(s[selectedIndex]);

        // Shift all elements to remove the selected element
        for (int j = selectedIndex; j < availableElements; j++) {
            s[j] = s[j + 1];
        }
        availableElements--;

        // Insert element into team2
        selectedIndex = choose2[i];
        team2.push_back(s[selectedIndex]);

        // Shift elements again
        for (int j = selectedIndex; j < availableElements; j++) {
            s[j] = s[j + 1];
        }
        availableElements--;
    }

    // Output results
    for (int x : team1) printf("%d ", x);
    printf("\n");
    for (int x : team2) printf("%d ", x);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    while (t-- > 0) {
        solve();
    }
}
