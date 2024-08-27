#include<bits/stdc++.h>
#define ll long long
#define fu(i,a,b) for(ll i = a; i <= b; i++)
#define fd(i,a,b) for(ll i = a; i >= b; i--)
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;
const ll MAX = 1e6 + 7;

ll t;
ll n;
char a[100][100];

void enter() {
    cin >> n;
    fu(i, 1, n)
    fu(j, 1, n)
    cin >> a[i][j];
}

void solve() {
    ll oneX, oneY;
    ll twoX, twoY;
    oneX = oneY = twoX = twoY = -1;
//    cout << oneX << " " << oneY << " " << twoX << " "
    fu(i, 1, n) {
        fu(j, 1, n) {
            if (a[i][j] == '1') {
                oneX = i;
                oneY = j;
                break;
            }

        }
        if (oneX != -1) {
            break;
        }
    }

    fd(i, n, oneX + 1) {
        fu(j, 1, n) {
            if (a[i][j] == '1') {
                twoX = i;
                twoY = j;
                break;
            }

        }
        if (twoX != -1) {
            break;
        }
    }

//    cout << oneX << " " << oneY << "\n";
//    cout << twoX << " " << twoY << "\n";
    if (twoY != oneY) {
        cout << "TRIANGLE\n";
    } else {
        cout << "SQUARE\n";
    }

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//    freopen("input.inp", "r", stdin);
    cin >> t;
    while(t --> 0) {
        enter();
        solve();
    }
}

