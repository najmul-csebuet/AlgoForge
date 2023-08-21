#include <bits/stdc++.h>
using namespace std;

#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define pb push_back
#define eb emplace_back
#define fill(v, c) memset(v, c, sizeof(v))

#define var auto
#define endl "\n"
#define rep(i, a, b) for (auto i = (a); i < (b); ++i)

void solve() {
  unsigned int x;
  cin >> x;

  int ans = popcount(x);
  cout << ans << endl;

  /* while (x > 0) {
    int y = log2(x);
    x = x - pow(2, y);
    ans += 1;
  }

  cout << ans << endl; */
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int testCount = 1;
  // testCount = io.nextInt();
  while (testCount > 0) {
    solve();
    --testCount;
  }
  return 0;
}