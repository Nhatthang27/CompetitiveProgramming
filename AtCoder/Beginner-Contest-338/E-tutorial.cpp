#include <bits/stdc++.h>

using namespace std;

vector<int> f(long long x) {
  vector<int> res;
  if (x == 2) {
  	res.push_back(0);
  } else if (x & 1) {
    res = f(x - 1);
    res.push_back(*min_element(res.begin(), res.end()) - 1);
  } else {
    res = f(x / 2);
    res.push_back(*max_element(res.begin(), res.end()) + 1);
  }
  return res;
}

int main() {
//freopen("input.inp", "r", stdin);
  int t;
  cin >> t;
  while (t--) {
    long long x;
    cin >> x;
    auto ans = f(x);
    cout << ans.size() << '\n';
    for (int i : ans) cout << i << ' ';
    cout << '\n';
  }
}
