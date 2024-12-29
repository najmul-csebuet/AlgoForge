#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

void solution(vi v) {
  int best = 0;
  for (int i = 0; i < v.size(); i++) {
    if (v[i] == v[i + 1]) continue;
    // now we have a different element
    // go back and forward to find the same pattern like  1122 or 2211
    int a = i, b = i + 1;
    while (v[a] != v[b] && v[a] == v[i] && a >= 0 && b < v.size()) {
      best = max(best, b - a + 1);
      --a;
      ++b;
    }
  }
  cout << best << endl;
}

int main() {
  int t = 1;
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  cin >> t;
#endif
  while (t--) {
    int n;
    cin >> n;
    // read n ints
    vi v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    solution(v);
  }
  return 0;
}