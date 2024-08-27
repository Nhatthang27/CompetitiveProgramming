#include <bits/stdc++.h>
#define ll long long
#define fu(i,a,b) for(ll i =a ; i <= b; i++)
#define fd(i,a,b) for(ll i = a; i >= b; i--)
using namespace std;
const ll MAX = 3e5 + 7;

ll w, h, k;

vector<vector<char>> b, rb;

ll solve(vector<vector<char>> b, ll h, ll w, ll k) {
    vector<ll> ok, block;
    ok.assign(w + 1, 0);
    block.assign(w + 1, 0);
    ll res;
    bool flag = false;
    fu(i, 1, h) {
        fu(j, 1, w) {
            block[j] = block[j - 1] + (b[i][j] == 'x');
            ok[j] = ok[j - 1] + (b[i][j] == '.');
        }
//        cout << "row " << i << ": ";
//        fu(j, 1, w) {
//            cout << ok[j];
//        }
//        cout << "\n";
//        fu(j, 1, w) {
//            cout << block[j];
//        }
//        cout << "\n";
        fu(l, 1, w - k + 1) {
            ll r = l + k - 1;
            if (block[r] - block[l - 1] == 0) {
                if (flag == false) {
                    res = ok[r] - ok[l - 1];
//                    cout << i << " " << l << " " << r << "\n";
                    flag = true;
                } else {
//                    cout << i << " " << l << " " << r << "\n";
                    res = min(res, ok[r] - ok[l - 1]);
                }
            }
        }
    }
    if (flag) {
        return res;
    } else {
        return -1;
    }
}

int main() {
    ll n;
//    freopen("input.inp", "r", stdin);
    cin >> h >> w >> k;
    b.assign(h + 2, vector<char>(w + 3, ' '));
    fu(i, 1, h) {
        fu(j, 1, w) {
            cin >> b[i][j];
        }
    }
    ll res1 = solve(b, h, w, k);

    swap(h, w);
    rb.assign(h + 2, vector<char>(w + 3, ' '));
    fu(i, 1, h) {
        fu(j, 1, w) {
            rb[i][j] = b[j][i];
//            cout << rb[i][j];
        }
//        cout << "\n";
    }
    ll res2 = solve(rb, h, w, k);
    if(res1 != -1 && res2 != -1) {
        cout << min(res1, res2);
    } else {
        cout << max(res1, res2);
    }
}


