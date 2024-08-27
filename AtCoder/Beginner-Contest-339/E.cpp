#include <bits/stdc++.h>
#define ll long long
#define fu(i, a, b) for (ll i = a; i <= b; i++)
#define fd(i, a, b) for (ll i = a; i >= b; i--)
using namespace std;
const ll MAX
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//    freopen("input.inp", "r", stdin);
    string s;
    cin >> s;

    string res = "";
    fd(i, s.size() - 1, 0) {
        if (s[i] == '.') {
            cout << res;
            break;
        } else {
            res = s[i] + res;
        }
    }
}

