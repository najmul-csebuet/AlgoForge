// simple template for competitive programming

#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vs = vector<string>;

#define sz(x) ((int)(x).size())
#define rep(i, a, b) for (int i = a; i < b; i++)

void solution(string s) {
  // find some patterns like 25, 50, 75, 100
  vs patterns = {"25", "50", "75", "00"};
  int ans = INT_MAX;

  rep(i, 0, sz(patterns)) {
    // "1200523"
    string p = patterns[i];

    // find last occurrence of p[1] in s
    int last = s.size() - 1;
    while (last >= 0 && s[last] != p[1]) {
      last--;
    }
    if (last < 0)
      continue;  // no occurrence of p[1] in s, so this pattern doesn't match

    // find first occurrence of p[0] in s before last
    int first = last - 1;
    while (first >= 0 && s[first] != p[0]) {
      first--;
    }
    if (first < 0)
      continue;  // no occurrence of p[0] in s, so this pattern doesn't match

    // now we have a match

    int distanceBetween = last - first - 1;
    int distanceLast = s.size() - last - 1;

    ans = min(ans, distanceBetween + distanceLast);
  }
  cout << ans << endl;
}

int main() {
  int t = 1;
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  cin >> t;
#endif

  int n;
  string s;
  while (t--) {
    cin >> n;
    while (n--) {
      cin >> s;
      solution(s);
    }
  }

  return 0;
}