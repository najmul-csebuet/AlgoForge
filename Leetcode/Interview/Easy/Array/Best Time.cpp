#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)((v).size()))
#define rep(i, a, b) for (auto i = (a); i < (b); ++i)

// AC
class Solution {
 public:
  int maxProfit(vector<int> &prices) {
    int lastLow = prices[0], lastHigh = prices[0], profit = 0;
    rep(i, 1, sz(prices)) {
      if (lastHigh > prices[i]) {
        // sell
        profit += (lastHigh - lastLow);
        lastLow = lastHigh = prices[i];
      } else {
        lastHigh = prices[i];
      }
    }
    // sell
    profit += (lastHigh - lastLow);
    return profit;
  }
};

int main() {
  // activate fast io
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int testCount = 1;
  // testCount = io.nextInt();
  while (testCount > 0) {
    // Solution().solve();
    --testCount;
  }
  return 0;
}
