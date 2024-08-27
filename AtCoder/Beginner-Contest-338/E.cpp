#include <bits/stdc++.h>
#define ll long long
#define fu(i,a,b) for(ll i = a; i <= b; i++)
#define fd(i,a,b) for(ll i = a; i >= b; i--)
#define pll pair<ll, ll>
#define ff first
#define ss second
#define MASK(i) (1LL << i)
using namespace std;
const ll MAX = 2e5 + 7;
const ll LOG = 19;
pll a[MAX];
ll n, one[MAX], two[MAX];

ll maxValue[MAX][LOG + 1];
ll limit, lg2[MAX];

ll getMax(ll l, ll r)
{
		ll k = lg2[r - l + 1];
		return max(maxValue[l][k], maxValue[r - MASK(k) + 1][k]);
}

void enter() {
    cin >> n;
    fu(i, 1, n) {
        cin >> a[i].ff >> a[i].ss;
        if(a[i].ff > a[i].ss) {
            swap(a[i].ff, a[i].ss);
        }
    }
}

void prepare() {
    sort(a + 1, a + n + 1);
    fu(i, 1, n) {
        one[i] = a[i].ff;
        two[i] = a[i].ss;
    }

    fu(i, 1, n)
        maxValue[i][0] = two[i];
    fu(j, 1, LOG)
        fu(i, 1, n - MASK(j) + 1) {
            maxValue[i][j] = max(maxValue[i][j - 1], maxValue[i + MASK(j - 1)][j - 1]);
        }
    fu(i, 1, n) {
        while(MASK(lg2[i]) <= i)
            lg2[i]++;
    lg2[i]--;
    }
}

bool check() {

    fu(i, 1, n) {
        ll j = lower_bound(one + i + 1, one + n + 1, two[i]) - one - 1;
        if (one[j] >= two[i] || j <= i || j > n) continue;
        if (getMax(i + 1, j) > two[i]) {
            return true;
        }
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//    freopen("input.inp", "r", stdin);
    enter();
    prepare();
//    fu(i, 1, n) {
//        cout << one[i] << " " << two[i] << "\n";
//    }
//    cout << getMax(2, 3) << " " << getMax(1, 3) << " " << getMax(3, 4);
    cout << (check() ? "Yes" : "No");
}


