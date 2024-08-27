#include<bits/stdc++.h>
#define ll long long
#define fu(i,a,b) for(int i = a; i <= b; i++)
#define fd(i,a,b) for(int i = a; i >= b; i--)
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;
const int MAX = 2e5;

int t, a[MAX + 7];
int n;

int sum(int x) {
    int res = 0;
    string s = to_string(x);
    fu(i, 0, s.size() - 1)
        res += (s[i] - '0');
    return res;
}


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//    freopen("input.inp", "r", stdin);
    cin >> t;
    fu(i, 1, MAX) {
        a[i] = a[i - 1] + sum(i);
    }
    while(t --> 0) {
        int x;
        cin >> x;
        cout << a[x] << "\n";
    }
}

