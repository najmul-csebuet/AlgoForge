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

/*
Kirito is stuck on a level of the MMORPG he is playing now. To move on in the game, he's got to defeat all n dragons that live on this level. Kirito and the dragons have strength, which is represented by an integer. In the duel between two opponents the duel's outcome is determined by their strength. Initially, Kirito's strength equals s.

If Kirito starts duelling with the i-th (1 ≤ i ≤ n) dragon and Kirito's strength is not greater than the dragon's strength xi, then Kirito loses the duel and dies. But if Kirito's strength is greater than the dragon's strength, then he defeats the dragon and gets a bonus strength increase by yi.

Kirito can fight the dragons in any order. Determine whether he can move on to the next level of the game, that is, defeat all dragons without a single loss.
*/
void solve() {
  int s, n;
  cin >> s >> n;
  vector<pair<int, int>> dragons(n);
  int x, y;
  rep(i, 0, n) {
    cin >> x >> y;
    dragons[i] = {x, y};
  }
  sort(all(dragons));
  rep(i, 0, n) {
    if (s <= dragons[i].first) {
      cout << "NO" << endl;
      return;
    }
    s += dragons[i].second;
  }

  cout << "YES" << endl;
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