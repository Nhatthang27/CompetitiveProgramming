#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        string s;
        cin >> s;
        int n = s.size();
        auto is_palindrome = [&](int l, int r) -> bool {
            for (int i = l; i < r + l - i; ++i)
                if (s[i] != s[r + l - i]) return false;
            return true;
        };
        if (!is_palindrome(0, n - 1)) {
            cout << "YES\n1\n"
                 << s << "\n";
            continue;
        }
        int first_dif = -1;
        for (int i = 1; i < n; ++i)
            if (s[i] != s[0]) {
                first_dif = i;
                break;
            }
        if (first_dif == -1) {
            cout << "NO\n";
            continue;
        }
        if (!is_palindrome(0, first_dif) && !is_palindrome(first_dif + 1, n - 1)) {
            cout << "YES\n2\n"
                 << s.substr(0, first_dif + 1) << ' ' << s.substr(first_dif + 1) << "\n";
            continue;
        } else if (first_dif == 1 || first_dif == n / 2) {
            cout << "NO\n";
        } else {
            cout << "YES\n2\n"
                 << s.substr(0, first_dif + 2) << ' ' << s.substr(first_dif + 2) << "\n";
        }
    }
    return 0;
}