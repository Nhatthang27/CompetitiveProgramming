#include<bits/stdc++.h>
#define ll long long
#define fu(i,a,b) for(ll i = a; i <= b; i++)
#define fd(i,a,b) for(ll i = a; i >= b; i--)
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;
const ll MAX = 1e6 + 7;
const ll INF = 1e18;

ll t;
const ll N = 7;
ll res;
bool a[N + 1][N + 1];
vector<pll> odd, even;

void enter() {
    fu(i, 1, N) fu(j, 1, N) {
        char x;
        cin >> x;
        a[i][j] = (x == 'B');
    }
}

bool checkBoard(bool a[N +1][N + 1], bool isOdd) {
    fu(i, 2, N - 1) {
        fu(j, 2, N - 1) {
            if ((i + j) % 2 == isOdd && a[i][j]) {
                if (a[i - 1][j - 1] && a[i - 1][j + 1] && a[i + 1][j - 1] && a[i + 1][j + 1]) return false;
            }
        }
    }
    return true;
}

bool backtrack(bool a[N + 1][N + 1], vector<pll>& vec, ll numFlipLeft, ll idx, bool isOdd) {
    if (numFlipLeft == 0) {
        return checkBoard(a, isOdd);
    }
    if (idx == vec.size()) {
        return false;
    }

    ll x = vec[idx].ff;
    ll y = vec[idx].ss;
    if (a[x][y]) {
        if (backtrack(a, vec, numFlipLeft, idx + 1, isOdd)) {
            return true;
        }

        a[x][y] = 0;
        bool yes = backtrack(a, vec, numFlipLeft - 1, idx + 1, isOdd);
        a[x][y] = 1;
        return yes;
    } else {
        return backtrack(a, vec, numFlipLeft, idx + 1, isOdd);
    }
}

void solve() {
    ll res = 0;
    fu(i, 0, 4) {
        if (backtrack(a, even, i, 0, false)) {
            res += i;
            break;
        }
    }

    fu(i, 0, 4) {
        if (backtrack(a, odd, i, 0, true)) {
            res += i;
            break;
        }
    }
    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//    freopen("input.inp", "r", stdin);
    cin >> t;
    fu(i, 1, N) fu(j, 1, N)
    if ((i + j) % 2 == 0) {
        even.push_back(make_pair(i, j));
    } else {
        odd.push_back(make_pair(i, j));
    }
    while(t --> 0) {
        enter();
        solve();
    }
}

