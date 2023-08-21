#include <bits/stdc++.h>
using namespace std;

// AC
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    // prices = [7,1,5,3,6,4]
    int heelStart = 0;
    int profit = 0;

    for (int heelEnd = 0; heelEnd < prices.size(); ++heelEnd) {
      if (heelEnd == prices.size() - 1) {
        // reached end of prices
        profit += (prices[heelEnd] - prices[heelStart]);
        break;
      }

      if (prices[heelEnd] <= prices[heelEnd + 1]) {
        continue;
      }

      // heel ended
      profit += (prices[heelEnd] - prices[heelStart]);
      heelStart = heelEnd + 1;
    }

    return profit;
  }
};

int main() {
  // Solution().solve();
  return 0;
}
