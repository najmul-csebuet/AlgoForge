#include <bits/stdc++.h>
using namespace std;

#define var auto
#define pb push_back
#define vi vector<int>
#define vvi vector<vi>
#define si set<int>
#define mii map<int, int>
#define umii unordered_map<int, int>
#define sz(v) ((int)((v).size()))
#define all(v) ((v).begin()), ((v).end())
#define rep(i, a, b) for (var i = (a); i < (b); ++i)
#define tr(c, a) for (var & a : c)

class Solution {
 public:
  int maxProfit(vi& prices) {
    int minSoFar = prices[0];
    int maxProfit = 0;
    rep(i, 1, sz(prices)) {
      maxProfit = max(maxProfit, prices[i] - minSoFar);
      minSoFar = min(minSoFar, prices[i]);
    }
    return maxProfit;
  }
};

class Solution_AC {
 public:
  int maxProfit(vi& prices) {
    vi minSoFar(sz(prices));
    minSoFar[0] = prices[0];
    rep(i, 1, sz(prices)) { minSoFar[i] = min(minSoFar[i - 1], prices[i]); }
    int maxProfit = 0;
    rep(i, 1, sz(prices)) {
      maxProfit = max(maxProfit, prices[i] - minSoFar[i]);
    }
    return maxProfit;
  }
};

int main() {
  var s = Solution();
  return 0;
}
